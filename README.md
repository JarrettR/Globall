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

![Mechanical Design](/docs/1-mechanical.png =300x)
![PCB Design](/docs/2-pcb.jpg =300x)
![Spin](/docs/3-world.jpg =300x)

Pattern-making:

![Pattern 1](/docs/4-pattern1.jpg =300x)
![Pattern 2](/docs/5-pattern2.jpg =300x)
![Pattern 3](/docs/6-pattern3.jpg =300x)


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
