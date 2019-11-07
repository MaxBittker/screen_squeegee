#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

  ofSetBackgroundAuto(false);
  ofEnableAlphaBlending();
  ofBackground(255, 255, 255);

  grabber.setup(1280, 720);
  ofBackground(0);
  slug.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
  slug.allocate(ofGetWidth(), ofGetHeight(), slug.getImageType());
}

//--------------------------------------------------------------
void ofApp::update() { grabber.update(); }

//--------------------------------------------------------------
void ofApp::draw() {

  // slug.grabScreen(0, 0, ofGetWidth(), ofGetHeight());

  for (int x = 0; x < grabber.getWidth(); x += 5) {
    for (int y = 0; y < grabber.getHeight(); y += 5) {
      ofColor currentColor = grabber.getPixels().getColor(x, y);
      ofSetColor(currentColor, 100);

      ofColor lastColor = slug.getPixels().getColor(x, y);

      // if (lastColor.b > 200 && lastColor.r < 50 && lastColor.g < 50) {
      if (lastColor.getBrightness() > 50) {
        ofDrawRectangle(x, y, 5, 5);

      } else {
        ofSetColor(0);

        ofDrawRectangle(x, y, 5, 5);
      }

      ofColor mutColor = ofColor(lastColor);
      // lastColor.setBrightness(lastColor.getBrightness()+1);
      if (((currentColor.r + currentColor.g + currentColor.b) / 3) > 233) {
        mutColor.setBrightness(mutColor.getBrightness() + 20);
        slug.setColor(x, y,
                      //  ofColor(255, 255, 255));
                      mutColor);
      } else if (ofRandom(100) > 80) {
        mutColor.setBrightness(mutColor.getBrightness() - 1);
        slug.setColor(x, y,
                      // ofColor(255, 255, 255));
                      mutColor);
      }
    }
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}