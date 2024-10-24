# I Choosed to do the FFT for this project

## to prepare fot that I did for this:
- the first thing for me to do is th review what we did in the class.
- then I found that I need to find a .wav file for this project
- creative a Project Generator

### add the .wav file in the folder
- base on the classnote, I put the music into the `bin/data` folder in my projct.

### doing the setup things based on the 04oFxFFT file

### make it run, to make sure everything is good.

# Change the shape for it!
- I want to have a circle that moving around, so I change the draw part to the float circle and take a try for this code:

```
void ofApp::draw(){

    float time = ofGetElapsedTimef();
    for (int i = 0; i < 12; i++){
      float x = ofGetWidth() * ofNoise(time * 0.3);
      float y = ofGetWidth() * ofNoise(time * 0.6);

  ofDrawCircle(x, y, 32);
}
gui.draw();
}
```
- you can see in the code, I want to have 12 circles that moving around, but I only have one using this code, after search I found that I may need to add random for this
- so what I did is change lots of things
- first I go to the ofApp.h, add a 
`#define AMOUNT 12` in that
- then I add 
```
vector<float> speedx;
vector<float> speedy;
```
these are declarations of two dynamic arrays (vectors) that hold floating-point numbers (float).

- then go to the ofApp.cpp change:

```

void ofApp::draw(){

    float time = ofGetElapsedTimef();
    for (int i = 0; i < AMOUNT; i++){
      float x = ofGetWidth() * ofNoise(time * fft[i]);
      float y = ofGetWidth() * ofNoise(time * fft[i]);

  ofDrawCircle(x, y, 32);
}
gui.draw();
}
```