Tools
================


## convert.py

This is a tool that takes in image files, processes them, and then exports them into PNG, CSV, or C code formats.

Type `python convert.py --help` for full list of options. At present, this is the output:

```
> python convert.py --help

usage: convert.py [-h] [-x WIDTH] [-y HEIGHT] [-i INPUT] [-o OUTPUT]
                  [-f FORMAT] [-n] [-c CONST] [-v]

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
  -f FORMAT, --format FORMAT
                        Output format(csv, png, or c)
  -n, --invert          Invert pixel weight
  -c CONST, --const CONST
                        (C output only) Const var name
  -v, --verbose         Print out internal variables
```

This was intended to be reusable, and is fairly robust.

It should take any image format and convert it to greyscale, although this has not been tested exhaustively. PNG files work well.

For this project, sensible defaults (and the ones included in the firmware) are generated using `sh gen.sh`