#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

  ofSetBackgroundAuto(false);
  ofEnableAlphaBlending();
  ofBackground(255, 255, 255);

  // image = ofImage img("anImage.png");
  // slug.load("chicken.jpg");
  // slug.load("slug.jpg");
  grabber.setup(1280, 720);
  ofBackground(0);
  slug.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
  slug.allocate(ofGetWidth(), ofGetHeight(), slug.getImageType());
}

//--------------------------------------------------------------
void ofApp::update() { grabber.update(); }

//--------------------------------------------------------------
void ofApp::draw() {

  // slug.grabScreen(0, 0, 500, 500);
  // ofBackground(0);
  // ofSetColor(255);
  // slug.draw(0, 0);
  // ofSetColor(slug.getColor(mouseX, mouseY));
  // ofDrawRectangle(mouseX, mouseY, 50, 50);
  // grabber.draw(0, 0);
  // int res = 1 + (mouseX / 20.0);
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

      // ofSetColor(
      // unsigned char data =
      // grabber.getPixels().getData()[x + int(grabber.getWidth() * y)];
      // ofSetColor(grabber.getPixels()
      //                .getData()[0 + 3 * (x + int(grabber.getWidth() * y))],
      //            grabber.getPixels()
      //                .getData()[1 + 3 * (x + int(grabber.getWidth() * y))],
      //            grabber.getPixels()
      //                .getData()[2 + 3 * (x + int(grabber.getWidth() * y))],
      //            80);
      // //  [x + (y * grabber.getWidth())],
      // //  10);
      // ofSetColor(grabber.getPixels()
      //                .getData()[0 + 3 * (x + int(grabber.getWidth() * y))],
      //            0, 0, 120);

      // ofDrawRectangle(x, y, 4, 12);
      // ofSetColor(0,
      //            grabber.getPixels()
      //                .getData()[2 + 3 * (x + int(grabber.getWidth() * y))],
      //            0, 120);

      // ofDrawRectangle(x + 4, y, 4, 12);
      // ofSetColor(0, 0,
      //            grabber.getPixels()
      //                .getData()[2 + 3 * (x + int(grabber.getWidth() * y))],
      //            120);

      // ofDrawRectangle(x + 8, y, 4, 12);

      // ofDrawCircle(x + ofRandomf() * mouseY, y + ofRandomf() * mouseY, res /
      // 2); ofDrawCircle(x + ofRandomf() * mouseY, y + ofRandomf() * mouseY,
      // res / 2); ofDrawCircle(x + ofRandomf() * mouseY, y + ofRandomf() *
      // mouseY, res / 2);
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