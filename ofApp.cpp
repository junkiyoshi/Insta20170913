#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();

	//ofNoFill();

	this->light.setAreaLight(2048, 2048);
	this->light.setAmbientColor(ofFloatColor(0.0, 0.0, 0.0, 1.0));
	this->light.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	this->light.setSpecularColor(ofFloatColor(1.0, 0.0, 0.0));

	this->noise_source = ofRandom(10);
	this->noise_step = 0.01;
}

//--------------------------------------------------------------
void ofApp::update(){
	this->noise_source += this->noise_step;
}

//--------------------------------------------------------------
void ofApp::draw(){
	this->cam.begin();

	this->light.setPosition(this->cam.getPosition().normalize() * 2048);
	ofEnableLighting();
	this->light.enable();

	float radius = 100;
	float height = 150;
	float tmp_height;
	float x, y;
	float tmp_noise = this->noise_source;
	float noise_value;

	for (int x = -ofGetWidth() / 2; x < ofGetWidth() / 2; x += 10){
		for (int y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += 10) {
			ofPushMatrix();
			ofTranslate(x, 0, y);
			
			noise_value = ofNoise(x * this->noise_step, y * this->noise_step, ofGetFrameNum() * this->noise_step);
			tmp_height = height * noise_value;
			ofBox(ofVec3f(0, tmp_height / -2, 0), 10, tmp_height, 10);

			ofPopMatrix();
		}

		tmp_noise += this->noise_step * 15;
	}
	
	this->cam.end();
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
