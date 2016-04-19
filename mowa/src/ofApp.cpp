#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDirectory dict;
    for(int i=0;i<4;i++){
        char fname[64];
        sprintf(fname,"galaxy%i.mp3",i);
        snd[i].loadSound(dict.getAbsolutePath()+fname);
        snd[i].setMultiPlay(true);
    }
    
    int lowW = ofGetScreenWidth() / RESOLUTION_RATIO;
    int lowH = ofGetScreenHeight() / RESOLUTION_RATIO;
    
    Star::screenLowWidth = lowW;
    Star::screenLowHeight = lowH;
    
    loresScreen.allocate(lowW, lowH + 1, OF_IMAGE_COLOR);
    pixels = loresScreen.getPixels();
    
    blankLoresScreen();
    
    mouseIsDown = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    vector<Star*>::iterator it;
    
    bool foundOne = true;
    while(foundOne){
        foundOne = false;
        for(it=stars.begin();it!=stars.end();it++){
            //advance through dead ones
            if(it != stars.end()){
                if((*it)->strength<=0){
                    delete (*it);
                    it = stars.erase(it);
                    foundOne = true;
                    if(it==stars.end()){
                        break;
                    }
                }
            }
        }
    }
    
    for(int i=0;i<stars.size();i++){
        stars[i]->step();
    }
    
    blankLoresScreen();
    
    
    ofVec2f loresMouse = screen2lores(ofVec2f(mouseX, mouseY));
    int loresW = ofGetScreenWidth() / RESOLUTION_RATIO;
    for(it=stars.begin();it!=stars.end();it++){
        
        for(int y=0; y < ofGetScreenHeight() / RESOLUTION_RATIO; y++ ){
            for(int x= 0; x < loresW; x++ ){
                int pxpos = (y*loresW+x)*3;
                
                float dist =  ofDist((*it)->pos.x, (*it)->pos.y, x, y) * RESOLUTION_RATIO;
                //float rad =  (cos((ofGetFrameNum())*0.01 + i*10)+1.0)*0.1 + 0.001;
                
                int v = fmax(0,1.0 - dist * (*it)->getRadius()) * 0xAA * (*it)->strength;
                
                pixels[ pxpos+0 ] = min(pixels[ pxpos+0 ]+(int)round(v * (*it)->color.red()   ) , 0xFF );
                pixels[ pxpos+1 ] = min(pixels[ pxpos+1 ]+(int)round(v * (*it)->color.green() ) , 0xFF );
                pixels[ pxpos+2 ] = min(pixels[ pxpos+2 ]+(int)round(v * (*it)->color.blue()  ) , 0xFF );
                
            }
        }
    }
    
    loresScreen.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,0,0);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofSetColor(255,255,255,200*255);
    ofPushMatrix();
    ofScale(RESOLUTION_RATIO,RESOLUTION_RATIO , 1);
    loresScreen.draw(0,0);
    ofPopMatrix();
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
    if(stars.size()>0){
        stars.back()->pos = screen2lores( ofVec2f(x,y) );
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    stars.push_back(new Star(screen2lores(ofVec2f(x,y))) );
}

void ofApp::reset(){
    for(int i=0;i<stars.size();i++){
        delete stars[i];
    }
    stars.clear();
    ofSoundStopAll();
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

ofVec2f ofApp::screen2lores(ofVec2f in){
    ofVec2f out;
    out.x = in.x / RESOLUTION_RATIO;
    out.y = in.y / RESOLUTION_RATIO;
    return out;
}

void ofApp::blankLoresScreen(){
    int loresW = ofGetScreenWidth() / RESOLUTION_RATIO;
    for(int y=0; y < ofGetScreenHeight() / RESOLUTION_RATIO; y++ ){
        for(int x= 0; x < loresW; x++ ){
            int pos = (y*loresW+x)*3;
            pixels[pos+0] = 0;
            pixels[pos+1] = 0;
            pixels[pos+2] = 0;
        }
    }
    
}