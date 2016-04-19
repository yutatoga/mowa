#pragma once

#include "ofMain.h"
#include "Star.h"

#define RESOLUTION_RATIO 32.0f

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    void blankLoresScreen();
    ofVec2f screen2lores(ofVec2f in);
    void reset();
    
    ofImage loresScreen;
    unsigned char*pixels;
    ofSoundPlayer snd[4];
    bool mouseIsDown;
    vector<Star*> stars;
};
