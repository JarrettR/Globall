Tools
================


## convert.py

### Usage

This is a tool that takes in image files, processes them, and then exports them into PNG, CSV, or C code formats.

First, install the only prerequisite, the Python Imaging Library:
`pip install pillow`
You might need to run that with `sudo` or as an administrator on Windows.

For this particular project, the command to generate the final files is:
` python convert.py -i World_map.png -t c -n -v -c blueMap -x 60 -y 20 -o blue `

Type `python convert.py --help` for full list of options. At present, this is the output:

```
> python convert.py --help

usage: convert.py [-h] [-x WIDTH] [-y HEIGHT] [-i INPUT] [-o OUTPUT] [-t TYPE]
                  [-n] [-c CONST] [-f] [-l] [-v]

optional arguments:
  -h, --help            show this help message and exit
  -x WIDTH, --width WIDTH
                        Pixel density horizontal
  -y HEIGHT, --height HEIGHT
                        Pixel density vertical
  -i INPUT, --input INPUT
                        Input file
  -o OUTPUT, --output OUTPUT
                        Output file, no extension
  -t TYPE, --type TYPE  Output format(csv, png, or c)
  -n, --invert          Invert pixel weight
  -c CONST, --const CONST
                        (C output only) Const var name
  -f, --fragmented      Split up data for fragmented memory
  -l, --large           Larger, 12-bit pixels
  -v, --verbose         Print out internal variables
```

This was intended to be reusable, and is fairly robust.

It should take any image format and convert it to greyscale, although different formats have not been tested exhaustively. PNG files work well.

For this project, sensible defaults (and the ones included in the firmware) are generated using `./gen.sh`


### Sample Inputs

These are some good images for testing various setups.

#### simple.png

![simple](simple.png)

Simple, small image of multiple colours, intended to test the conversion process only.


#### scrolltest.png

![scrolltest](scrolltest.png)

A human-recognisable pattern to easily check correct pixel order on the physical test bench.

#### cycle.png

![cycle](cycle.png)

A similar human-recognisable pattern to the above.


#### right-align.png and left-align.png

![left-align](left-align.png)

![right-align](right-align.png)


With one of these on each side, tests the code speed and maximum input frequency.
At a comfortable speed, all LEDs on both sides will be blinking. As soon as speed increases enough that the processor is no longer able to keep up, half of one or both sides will start sticking. As the input pulses is fed in faster, the LEDs will stop working entirely.

This is a quick way to tune for "max frequency".


#### World_map.png

![World_map](World_map.png)

The goal.
