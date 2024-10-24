#include "ofApp.h"

//--------------------------------------------------------------
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

    for (int y = 0; y < ofGetHeight(); y++){

        float hue = ofMap(y, 0, ofGetHeight(), 0, 255);
        ofColor color = ofColor::fromHsb(hue, 255, 255);
        ofSetColor(color);
        ofDrawRectangle(0, y, ofGetWidth(), 1);
    }


    for (int i = 0; i < AMOUNT; i++){
        float x = ofRandom(ofGetWidth());
        float y = ofRandom(ofGetHeight());
        float radius = fft[i] * 100;

        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        ofDrawCircle(x, y, radius);
    }

    gui.draw();
}
//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
