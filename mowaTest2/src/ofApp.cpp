#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    string path = "";
    ofDirectory dir(path);
    dir.allowExt("jpg");
    dir.listDir();
    for(int i = 0; i < dir.numFiles(); i++){
        ofLogNotice(dir.getPath(i));
        ofImage image;
        image.loadImage(dir.getPath(i));
        imageVector.push_back(image);
    }
    currentImageid = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    imageVector[currentImageid].draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    currentImageid = currentImageid+1 > imageVector.size()-1 ? 0 : currentImageid+1;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
