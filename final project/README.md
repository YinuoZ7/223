# making a music patch

# I want to do a dark music for this assignment
1. I choose to use the note 0,1,3,6,11
2. add the metro for 200, and sel
3. I want the note plays random, so I add a random on the patch

# I feel like the music is not that good for me, so I search a tutorial to learn how to make this more interesting.

- I add a f for floating and let this %5 so the number will move and all %5 which is getting interesting

# The tutorial said that to making more fun is add a moses
-  so I add a moses, if the number is less than control value will go to left, if it's greater or equal will go to right.

## there is a question is that the sound is no more like dark music is like a helicopters, so at first I try to change a sound in logic
- right now I am using a synthesizers in kontakt, so what am I going to do is change to another sound for this. after trying so many times, I use the one that I have right now, which is in analog dream called Mona Liza,

# to make the shape
1. I read the help on in the pd, but then I don't know how to solve that, I made lots of bugs
2. what I did is then I wen to search on youtube for the tutorial  for the shape.

# use the external GEM
##  after watch a lots of videos, I want to choose the external tools in pd which is GEM to help me to draw the picture

# first thing is to creative a gemmwin 
- then i found that I only can do the sparate thing, I changed a lot but can't solve it

## ask chatgpt for help....
- I put the question in that and let chatgpt to help me to fix this
- finally I solve that with the help

## how it works
1. let the Gem initialization:
- use gemwin to creates the readering windon(i learned from the video)

2. made the lines like the music patch
- frist put a (gemhead) to starts the readering chain.
- as the shape we have to have the xyz for that, so use the (translateXYZ)to put the object in the center.
- (rotateXYZ) applies rotation to the object and make it connect to the music
- use (circle)to draw a realy simple circle

## seems like didn't move with the music
- watched a tutorial, that said I need to add the (t b f) and modify the rotation angle based on the MIDI note data, and also prevent the rotation angle
- so I add the (t b f) and {+1} (%360)

# seems like all the thing is working right now