/*
 *  Star.cpp
 *  emptyExample
 *

// This work is licensed under the Creative Commons
// Attribution-NonCommercial-ShareAlike 3.0 Unported License. To view a
// copy of this license, visit
// http://creativecommons.org/licenses/by-nc-sa/3.0/ or send a letter to
// Creative Commons, 444 Castro Street, Suite 900, Mountain View,
// California, 94041, USA.
//

 *
 */

#include "Star.h"
#include "ofApp.h"

int Star::screenLowWidth = 0;
int Star::screenLowHeight = 0;

Star::Star(){
    cout << "empty constructor called." << endl;
}

Star::Star(ofVec2f p){
    loaded = false;
	pos = p;
	ticks = 0;
	rad = 0.001;//+0.01 * ofRandomuf();
    float randomVal = ofRandomuf();
	color = MColor(randomVal*TWO_PI,1.0,1.0,"HSB");
    char fname[64];
    soundIndex = (int)(randomVal * 4);
    strength = 1;
    loaded = true;
    rotation = (ofRandomuf()-0.5) * 0.05;
}


void Star::step(){
	ticks++;
	rad += 0.00001;
	rad = fmin(rad,10.0);
    strength = fmax((0.02-rad)/0.019,0);
    //snd0.setVolume(strength);
    
    float easeSpeed = 0.001f;
    
    pos.x += (screenLowWidth / 2 - pos.x) * easeSpeed;
    pos.y += (screenLowHeight / 2 - pos.y) * easeSpeed;
    
    //rotate
    pos.x -= screenLowWidth / 2;
    pos.y -= screenLowHeight / 2;
    
    float theta = atan2(pos.y,pos.x) + rotation;
    float rad = sqrt(pos.x*pos.x+pos.y*pos.y);
    pos.x = screenLowWidth / 2 + rad * cos(theta);
    pos.y = screenLowHeight / 2 + rad * sin(theta);

}

float Star::getRadius(){
	return rad / (fmin(ticks,10.0)*0.1);
}

