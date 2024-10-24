#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
  public:
    void setup();
    void update();
    void draw();
    void exit();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseScrolled(int x, int y, float scrollX, float scrollY);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    // 声明变量
    ofSoundPlayer sound;
    float* fft;
    int bands;
    ofxPanel gui;
    ofParameter<float> audioamplitude;
    ofParameter<float> visualdecay;
    vector<float> posY;
    vector<float> speedx;
    vector<float> speedy;
    float* soundSpectrum;

    int AMOUNT = 100; // 设置三角形数量
};
