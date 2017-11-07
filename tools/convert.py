#!/usr/bin/python
# -*- coding: utf-8 -*-

from PIL import Image

inFile = 'simple.png'
outFile = 'out'

vPixels = 20
hPixels = 50

class ConvertToGlobe(object):

    def __init__(self, inFile, outFile, hPixels, vPixels):
    
        img = (Image.open(inFile)
            .convert(mode="L")
            .resize(size=(hPixels, vPixels), resample=Image.BILINEAR))
            
        self.output = ImageMap(hPixels, vPixels)
        image = self.Read_Lines(img)
        
        self.output.save(outFile, ImageMap.CSV)

    def Read_Lines(self, img):
        image = []
        
        for x in range(img.size[0]):
            start = -1
            print(x)
            frame = self.output.create_frame()
            
            for y in range(img.size[1]):
                pixel = img.getpixel((x, y))
                frame = self.output.write_pixel(frame, y, pixel)
                print(pixel)
            
            self.output.add_frame(frame)
        return(image)

                

class ImageMap(object):  
    CSV = 1
    PNG = 2
    C = 3

    def __init__(self, hPixels, vPixels):
    
        self.hPixels = hPixels
        self.vPixels = vPixels
        
        self.image = []
        
    def create_frame(self):
        frame = [0] * vPixels
        return(frame)
        
    def write_pixel(self, frame, pixel, value):
        frame[pixel] = value
        return frame
        
    def add_frame(self, frame):
        self.image.append(frame)
        
    def save(self, filename, filetype):
        if filetype == self.CSV:
            f = open(filename + '.csv','w')
            for i in range(len(self.image)):
                for x in range(len(self.image[i])):
                    f.write(str(self.image[i][x]) + ',')
                f.write('\n')
            f.close()
        elif filetype == self.PNG:
            f = open(filename + '.png','w')
            f.write('hello world')
            f.close()
        elif filetype == self.PNG:
            f = open(filename + '.h','w')
            f.write('hello world')
            f.close()
        
if __name__ == "__main__":
    obj = ConvertToGlobe(inFile, outFile, hPixels, vPixels)