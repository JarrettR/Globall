#!/usr/bin/python
# -*- coding: utf-8 -*-

from PIL import Image, ImageOps
import argparse


class PixelConverter(object):
    CSV = 1
    PNG = 2
    C = 3

    def __init__(self, input):
        self.img = Image.open(input)

    def process(self, hPixels, vPixels, invert):
        self.img = self.remove_alpha(self.img).convert('L')
        if invert is True:
            self.img = ImageOps.invert(self.img)
        self.img = self.img.resize(size=(hPixels, vPixels),
                                   resample=Image.LANCZOS)
        self.imageField = ImageField(hPixels, vPixels)
        self.imageField = self.translate_pixels(self.img, self.imageField)

    def save(self, filename, filetype, constName, fragmented, large):
        if filetype == 'csv':
            f = open(filename + '.csv', 'w')
            for i in range(self.imageField.length()):
                for x in range(self.imageField.length(i)):
                    f.write(self.imageField.value(i, x) + ',')
                f.write('\n')
            f.close()

        elif filetype == 'png':
            self.img.save(filename + '.png')

        elif filetype == 'c':
            f = open(filename + '.h', 'w')
            self.imageField.generate_c_code(constName, f, fragmented, large)
            f.close()

    def translate_pixels(self, img, imageField):
        for x in range(img.size[0]):
            frame = imageField.create_new_line()

            for y in range(img.size[1]):
                pixel = img.getpixel((x, y))
                frame = imageField.write_pixel(frame, y, pixel)

            imageField.add_line(frame)

        return imageField

    def remove_alpha(self, img):
        img = img.convert('RGBA')
        alpha = img.convert('RGBA').split()[-1]
        bg = Image.new("RGBA", img.size, (255, 255, 255, 255,))
        bg.paste(img, mask=alpha)
        return bg


class ImageField(object):

    def __init__(self, hPixels, vPixels):
        self.hPixels = hPixels
        self.vPixels = vPixels
        self.image = []

    def create_new_line(self):
        line = [0] * self.vPixels
        return line

    def write_pixel(self, line, pixel, value):
        line[pixel] = value
        return line

    def add_line(self, line):
        self.image.append(line)

    def length(self, i=None):
        if i is None:
            return len(self.image)
        return len(self.image[i])

    def value(self, a, b):
        return str(self.image[a][b])

    def generate_c_code(self, constName, f, fragmented, large):
        f.write('/*******************************\n')
        f.write('*        Generated code        *\n')
        f.write('*******************************/\n\n')
        f.write('#include <stdint.h>        /* For uint8_t definition */\n\n')
        f.write('#ifndef HPIXELS\n')
        f.write('#define HPIXELS {}\n'.format(self.hPixels))
        f.write('#endif\n')
        f.write('#ifndef VPIXELS\n')
        f.write('#define VPIXELS {}\n'.format(self.vPixels))
        f.write('#endif\n')

        if not fragmented:
        
            f.write('\nconst uint8_t {}[HPIXELS][VPIXELS] = {{'.format(constName))
            for i in range(len(self.image)):
                if i > 0:
                    f.write(',')
                f.write('\n    { ')
                f.write(", ".join("0x%02x" % self.image[i][x]
                                  for x in range(len(self.image[i]))))
                f.write(' }')
            f.write('\n};')
            f.write('\n\n')
            
        else:
            ledMapLines = ""

            for i in range(len(self.image)):
                f.write('\nconst uint8_t {}_{}[VPIXELS] = {{'.format(constName, i))
                f.write(", ".join("0x%02x" % self.image[i][x]
                                  for x in range(len(self.image[i]))))
                f.write(' };')
            f.write('\n\n')
            
            f.write('\nconst uint8_t *ledMapFragments[HPIXELS] = {\n    ')
            f.write(",\n    ".join("{}_{}".format(constName, x)
                                  for x in range(len(self.image))))
            f.write('\n};\n\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser()

    parser.add_argument('-x', '--width',
                        help='Pixel density horizontal',
                        type=int, default=80)
    parser.add_argument('-y', '--height',
                        help='Pixel density vertical',
                        type=int, default=40)
    parser.add_argument('-i', '--input',
                        help='Input file',
                        type=str, default='simple.png')
    parser.add_argument('-o', '--output',
                        help='Output file, no extension',
                        type=str, default='out')
    parser.add_argument('-t', '--type',
                        help='Output format(csv, png, or c)',
                        type=str, default='csv')
    parser.add_argument('-n', '--invert',
                        help='Invert pixel weight',
                        action='store_true')
    parser.add_argument('-c', '--const',
                        help='(C output only) Const var name',
                        type=str, default='bitfield')
    parser.add_argument('-f', '--fragmented',
                        help='Split up data for fragmented memory',
                        action='store_true')
    parser.add_argument('-l', '--large',
                        help='Larger, 12-bit pixels',
                        action='store_true')
    parser.add_argument('-v', '--verbose',
                        help='Print out internal variables',
                        action='store_true')

    args = parser.parse_args()

    if args.verbose:
        print('Verbose')
        print("Width: {}".format(args.width))
        print("Height: {}".format(args.height))
        print("Input: {}".format(args.input))
        print("Output: {}".format(args.output))
        print("Type: {}".format(args.type))
        print("Invert: {}".format(args.invert))
        print("Const: {}".format(args.const))
        print("Frag: {}".format(args.fragmented))
        print("Large: {}".format(args.large))

    obj = PixelConverter(args.input)
    obj.process(args.width, args.height, args.invert)
    obj.save(args.output, args.format, args.const, args.fragmented, args.large)
