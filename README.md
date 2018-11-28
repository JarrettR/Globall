Globall
================


### What's this?

This is a persistence-of-vision globe.

### What's that?

Persistence of vision is the phenomenon where something moving very fast appears to be an entire collection of objects. Generally involving light, it can fool our eyes into believing that we're seeing a single line of light when there's really only one, or a 2D image, when there's really only a single line of lights turning on and off quickly.

### Cool! How does that relate?

By arranging LEDs around a circle and spinning it very rapidly, an image can be created. The primary use-case of this repo is to create a globe (using green and blue LEDs), but it can easily be used for text or any other arbitrary image.

### Pictures

Mechanical, PCB, and spinning globe:


<img src="/docs/1-mechanical.png" alt="" data-canonical-src="/docs/1-mechanical.png" width="250" /><img src="/docs/2-pcb.jpg" alt="" data-canonical-src="/docs/2-pcb.jpg" width="250" /><img src="/docs/3-world.jpg" alt="" data-canonical-src="/docs/3-world.jpg" width="250" />


Pattern-making:

<img src="/docs/4-pattern1.jpg" alt="" data-canonical-src="/docs/4-pattern1.jpg" width="250" /><img src="/docs/5-pattern2.jpg" alt="" data-canonical-src="/docs/5-pattern2.jpg" width="250" /><img src="/docs/6-pattern3.jpg" alt="" data-canonical-src="/docs/6-pattern3.jpg" width="250" />


### Status

This is under sporadic development.
The firmware is compilable, and it can generate passable images.
The PCB works, but will eventually go through a redesign. More LEDs, smaller LEDs, and a bunch of the power supply features can be stripped out.
The mechanical design has always been intended to be a minimum viable product, and is very functional. A redesign to make it prettier will eventually happen.
The image converter in the tools page might be useful for other POV systems at this change, check it out.

### Contributing

This is a (mostly) hardware project! I don't know what contributions are possible! Hardware pull requests are unlikely to be accepted, but give anything else a shot, I guess. I'm open to it.

### Further Reading

I have written a summary post about this on my website, [here](https://jrainimo.com/build/?p=1176).
