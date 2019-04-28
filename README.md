# Chimes 
The code for the self-playing chimes for Maker Media's Live Build, April 2019.

## You Also Need to Download...
The "NewPing" library for Arduino. 
Open your Arduino editor, go to the menu for:
Sketch->Include Library->Manage Libraries
...then, in the window that pops up, enter NewPing in the search bar. 
An entry for NewPing appears. Click on it and then click the "Install" button that appears.

# Why I Wanted to Do This
I always like making little art with electronics, something just a little beautiful and quirky. I'd done an Arduino-driven chimeset before, as a demo project for Make's booth at MakerFaire Bay Area a few years before, but I was never fully happy with that version. The chimes were rung by solenoids, and that was pleasantly simple, but the 12V solenoids I'd found were sub-awesome. Mostly they were too quiet. 

I wanted to try a version 2 where the solenoids were replaced by trip-hammers. I figured it would be simple enough to grab a 12V motor with a built-in encoder, 3D print a cam to go on the end, and spin that to raise and drop the hammers on the chimes. 

Looking back on it, I know that if there's ever a version 3, I'll skip the motor encoders (as a way of knowing when the motor has finished resetting) and go with limit switches triggered by the cams. This version 2 could drift over time, if the encoders miss a signal or if I didn't debounce the signal enough.

# What I Like About This Project

It's a great demo project for many of the next-steps you should try after doing the very basics of Arduino. We've got MOSFETs driving motors. There are cams to turn the rotational motion of the motors into a linear striking motion on the chimes. 

It's also a good baby step into exploring objected-oriented coding. Most Arduino sample programs are written in the older "procedural" coding style, but as you get deeper into coding, especially if you start coding in teams, object oriented code is the norm. In this tiny program, I liked how clean and simple the main routine got when I tucked what little complexity there was away into an object to represent each musical note. Adding new and different songs should be intuitive enough; With the musical note object you only need to tell it which pins its attached to at setup, and then how long to wait after each note when you tell it to play.
