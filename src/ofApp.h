#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{
public:
	ofImage				image;
	ofxCvColorImage		colorCvImage;
	ofxCvGrayscaleImage greyCvImage;
	ofxCvContourFinder 	contourFinder;

	vector<ofPolyline> polys;	// stores polys, for simplifying straight lines
	ofMesh mesh;	// store in a mesh, to draw just vertices

	float polySimplifyAmount;	// optimize points on polys

	void simplifyPolys();

	//---------------------------------------

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

};
