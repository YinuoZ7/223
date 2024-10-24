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

## i got a strange movement for this, so I search a lot, it stil not random, so I ask chatgpt for help..

```
void ofApp::setup(){
  sound.load("sound.wav");
sound.play();
sound.setLoop(true);

gui.setup();
gui.add(audioamplitude.set("audioamplitude", 0.5, 0.0, 1.0));
gui.add(visualdecay.set("visualdecay", 0.5, 0.0, 1.0));

fft = new float[128];
for (int i = 0; i < AMOUNT; i++){
  fft[i] = ofRandom(0.001,0.9);
}
bands = 64;

speedx.resize(AMOUNT);
speedy.resize(AMOUNT);


}

//--------------------------------------------------------------
void ofApp::update(){
  ofSoundUpdate();

sound.setVolume(audioamplitude);
soundSpectrum = ofSoundGetSpectrum(bands);
for (int i = 0; i < bands; i++){
  fft[i] *= visualdecay;
  if (fft[i] < soundSpectrum[i]){
    fft[i] = soundSpectrum[i];
  }
}

}

//--------------------------------------------------------------
void ofApp::draw(){

    float time = ofGetElapsedTimef();
    for (int i = 0; i < AMOUNT; i++){
      float x = ofGetWidth() * ofNoise(time * fft[i]);
      float y = ofGetWidth() * ofNoise(time * fft[i]);
      float z = ofGetWidth() * ofNoise(time * fft[i]);

  ofDrawCircle(x, y, z);
}
gui.draw();
}

```
- these are the code that I have for righ now.
- then after chatgpt's help I change my code into these:
```
void ofApp::setup(){
  sound.load("sound.wav");
  sound.play();
  sound.setLoop(true);

  gui.setup();
  gui.add(audioamplitude.set("audioamplitude", 0.5, 0.0, 1.0));
  gui.add(visualdecay.set("visualdecay", 0.5, 0.0, 1.0));

  fft = new float[128];
  for (int i = 0; i < AMOUNT; i++){
    fft[i] = ofRandom(0.001, 0.9);
  }
  bands = 64;

  speedx.resize(AMOUNT);
  speedy.resize(AMOUNT);
}

//--------------------------------------------------------------
void ofApp::update(){
  ofSoundUpdate();

  sound.setVolume(audioamplitude);
  soundSpectrum = ofSoundGetSpectrum(bands);
  for (int i = 0; i < bands; i++){
    fft[i] *= visualdecay;
    if (fft[i] < soundSpectrum[i]){
      fft[i] = soundSpectrum[i];
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw(){

  for (int i = 0; i < AMOUNT; i++){
    
    float x = ofRandom(ofGetWidth());
    float y = ofRandom(ofGetHeight());

    float radius = fft[i] * 100; 

    ofDrawCircle(x, y, radius);
  }

  gui.draw();
}
```
- finally I got the shape that I want to have. 

### new question come out, I want to make the circle bigger
- the code `float radius = fft[i] * 100;` helps me to control the circle's size, so I change that bigger to `float radius = fft[i] * 200;`
- this is what I want to get, so next step is change color

# change color for this!
- as the shape, I want to have a random color for this.
` fSetColor(ofRandom(255), ofRandom(255), ofRandom(255))`
I add this code to try if this work. 
- it's work, I got what I want to have for this.

# want to add a background for this 
- i want to have yellow for this so the code is `ofBackground(255, 239, 186);`

# this is all I want to have in this project.

## I want to try change a slow music so I creative a new folder for a slow music use the same code.
