#include "ofApp.h"

void ofApp::updateDir() {
    dir.listDir();
    dir = dir.getSorted();
}

//--------------------------------------------------------------
void ofApp::setup(){
    string path = "videos";
    dir = ofDirectory(path);
    updateDir();

    ofLogNotice() << "opening file " << dir.getPath(currentPlaying);
    myPlayer.load(dir.getPath(currentPlaying));
    myPlayer.play();
    myPlayer.setVolume(0.0);

    ofSetWindowTitle("ofxSyphon Example");

    ofSetWindowShape(myPlayer.getWidth(), myPlayer.getHeight());

    syphonOut.setName("Texture Output");
}

//--------------------------------------------------------------
void ofApp::update(){
    myPlayer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    myPlayer.draw(0,0, ofGetWidth(), ofGetHeight());
    if (myPlayer.isFrameNew()) {
        syphonOut.publishTexture(&myPlayer.getTexture());
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    updateDir();
    if (key == OF_KEY_LEFT) {
        currentPlaying--;
        currentPlaying = currentPlaying % dir.size();
        ofLogNotice() << "opening file " << dir.getPath(currentPlaying);
        myPlayer.load(dir.getPath(currentPlaying));
        myPlayer.play();
        return;
    }
    if (key == OF_KEY_RIGHT) {
        currentPlaying++;
        currentPlaying = currentPlaying % dir.size();
        ofLogNotice() << "opening file " << dir.getPath(currentPlaying);
        myPlayer.load(dir.getPath(currentPlaying));
        myPlayer.play();
        return;
    }
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
