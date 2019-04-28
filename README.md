# Chimes 
The code for the self-playing chimes for Maker Media's Live Build, April 2019.

# Why I Wanted to Do This
I always like making little art with electronics, something just a little beautiful and quirky. I'd done an Arduino-driven chimeset before, as a demo project for Make's booth at MakerFaire Bay Area a few years before, but I was never fully happy with that version. The chimes were rung by solenoids, and that was pleasantly simple, but the 12V solenoids I'd found were sub-awesome. Mostly they were too quiet. 

I wanted to try a version 2 where the solenoids were replaced by trip-hammers. I figured it would be simple enough to grab a 12V motor with a built-in encoder, 3D print a cam to go on the end, and spin that to raise and drop the hammers on the chimes. 

Looking back on it, I know that if there's ever a version 3, I'll skip the motor encoders (as a way of knowing when the motor has finished resetting) and go with limit switches triggered by the cams. This version 2 could drift over time, if the encoders miss a signal or if I didn't debounce the signal enough.
