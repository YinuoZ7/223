#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  sound.load("haha.wav");
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

  // 初始化三角形的初始 y 坐标和下落速度
  speedx.resize(AMOUNT);
  speedy.resize(AMOUNT);
  posY.resize(AMOUNT); // 存储每个三角形的 y 坐标
  for (int i = 0; i < AMOUNT; i++) {
    posY[i] = ofRandom(-ofGetHeight(), 0); // 随机初始化 y 坐标
    speedy[i] = ofRandom(1.0, 5.0); // 随机速度
  }
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

  // 更新三角形的位置（下落效果）
  for (int i = 0; i < AMOUNT; i++){
    posY[i] += speedy[i]; // 让三角形下落
    if (posY[i] > ofGetHeight()) { // 如果三角形超出屏幕底部，重置到顶部
      posY[i] = ofRandom(-ofGetHeight(), 0);
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  // 设置背景颜色为蛋黄色
  ofBackground(255, 239, 186);

  for (int i = 0; i < AMOUNT; i++){
    float x = ofRandom(ofGetWidth()); // 随机 x 坐标
    float size = fft[i] * 100;        // 根据音频 fft 值控制三角形的大小

    // 设置随机颜色
    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));

    // 计算三角形的三个顶点位置
    ofPoint p1(x, posY[i]);                       // 顶点
    ofPoint p2(x - size / 2, posY[i] + size);     // 左下角
    ofPoint p3(x + size / 2, posY[i] + size);     // 右下角

    // 绘制三角形
    ofDrawTriangle(p1, p2, p3);
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
