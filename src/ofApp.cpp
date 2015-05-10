#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
	polySimplifyAmount = 2.5;
	image.load("joanie_BW.jpg");	// load image
	colorCvImage.setFromPixels(image.getPixels()); // copy into color cvimage, allocate if nessecary
	greyCvImage.setFromColorImage(colorCvImage);	// convert to greyscale, allocate if nessecary
	greyCvImage.threshold(50, true);	// threshold image (play with threshold)
	contourFinder.findContours(greyCvImage, 1, greyCvImage.getWidth() * greyCvImage.getHeight(), 100000, true, true);	// find contours
	simplifyPolys();	// simplify

	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::simplifyPolys() {
	polys.resize(contourFinder.blobs.size());
	mesh.clear();

	for(int i=0; i<contourFinder.blobs.size(); i++) { 	// loop blobs
		ofPolyline &poly = polys[i];	// get i'th poly 
		poly.clear();	// clear poly
		poly.addVertices(contourFinder.blobs[i].pts);	// add all points from blob to poly
		poly.simplify(polySimplifyAmount); // simplify poly straight(ish) lines
		for(auto pt : poly) mesh.addVertex(pt); // loop points on simplified poly and add to mesh
	}
}


//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	contourFinder.draw(0, 0);		// draw contourfinder

	ofSetColor(255);
	ofPushMatrix();
	ofTranslate(greyCvImage.getWidth(), 0);
	for(auto poly : polys) poly.draw();		// draw simplified polys

	glPointSize(2);
	ofSetColor(255, 0, 0);
	mesh.drawVertices();	// draw just vertices
	ofPopMatrix();

	ofSetColor(255);
	ofDrawBitmapString("polySimplifyAmount: " + ofToString(polySimplifyAmount) + " ( <> to change )", 10, greyCvImage.getHeight() + 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key) {
		case '<': if(polySimplifyAmount > 0.0) polySimplifyAmount -= 0.5; simplifyPolys(); break;
		case '>': polySimplifyAmount += 0.5; simplifyPolys(); break;
	}

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
