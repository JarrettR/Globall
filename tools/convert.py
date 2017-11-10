#!/usr/bin/python
# -*- coding: utf-8 -*-

from PIL import Image
import argparse


class PixelConverter(object):

    def __init__(self, inFile, outFile, hPixels, vPixels):
        img = Image.open(inFile)

        img = self.remove_alpha(img).convert('L')

        img = img.resize(size=(hPixels, vPixels), resample=Image.LANCZOS)

        self.output = ImageField(hPixels, vPixels, img)
        image = self.read_lines(img)

        self.output.save(outFile, ImageField.C)

    def read_lines(self, img):
        image = []

        for x in range(img.size[0]):
            start = -1
            frame = self.output.create_frame()

            for y in range(img.size[1]):
                pixel = img.getpixel((x, y))
                frame = self.output.write_pixel(frame, y, pixel)

            self.output.add_frame(frame)
        return image

    def remove_alpha(self, img):
        img = img.convert('RGBA')
        alpha = img.convert('RGBA').split()[-1]
        bg = Image.new("RGBA", img.size, (255, 255, 255, 255,))
        bg.paste(img, mask=alpha)
        return bg


class ImageField(object):
    CSV = 1
    PNG = 2
    C = 3

    def __init__(self, hPixels, vPixels, imageData):
        self.hPixels = hPixels
        self.vPixels = vPixels
        self.image = []
        self.imageData = imageData

    def create_frame(self):
        frame = [0] * self.vPixels
        return frame

    def write_pixel(self, frame, pixel, value):
        frame[pixel] = value
        return frame

    def add_frame(self, frame):
        self.image.append(frame)

    def save(self, filename, filetype):
        if filetype == self.CSV:
            f = open(filename + '.csv', 'w')
            for i in range(len(self.image)):
                for x in range(len(self.image[i])):
                    f.write(str(self.image[i][x]) + ',')
                f.write('\n')
            f.close()

        elif filetype == self.PNG:
            self.imageData.save(filename + '.png')

        elif filetype == self.C:
            f = open(filename + '.c', 'w')
            self.generate_c_code(f)
            f.close()

    def generate_c_code(self, f):
        f.write('\n#define HPIXELS ' + str(self.hPixels))
        f.write('\n#define VPIXELS ' + str(self.vPixels))

        f.write('\n\nconst uint8_t bitfield[][] = {')
        for i in range(len(self.image)):
            f.write('\n    { ')
            f.write(", ".join("0x%02x" % self.image[i][x]
                              for x in range(len(self.image[i]))))
            f.write(' }')
            if i < len(self.image) - 1:
                f.write(',')
        f.write('\n};\n')

if __name__ == '__main__':
    # Defaults
    width = 80
    height = 40
    inFile = 'simple.png'
    outFile = 'out'
    format = 'c'

    parser = argparse.ArgumentParser()
    parser.add_argument('-x', '--width',
                        help='Pixel density horizontal',
                        type=int, default=40)
    parser.add_argument('-y', '--height',
                        help='Pixel density vertical',
                        type=int, default=40)
    parser.add_argument('-i', '--input',
                        help='Input file',
                        type=str, default='simple.png')
    parser.add_argument('-o', '--output',
                        help='Output file, no extension',
                        type=str, default='out')
    parser.add_argument('-f', '--format',
                        help='Output format(csv, png, or c)',
                        type=str, default='csv')
    parser.add_argument('-n', '--invert',
                        help='Invert pixel weight',
                        action='store_true')
    parser.add_argument('-v', '--verbose',
                        help='Print out internal variables',
                        action='store_true')

    args = parser.parse_args()

    if args.width:
        width = args.width
    if args.height:
        height = args.height
    if args.verbose:
        print('Verbose')
        print("Width: {}".format(width))
        print("Height: {}".format(height))

    obj = PixelConverter(inFile, outFile, width, height)
