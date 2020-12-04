#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(0);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofSetFrameRate(200);
    
    fftLive.setMirrorData(false);
    fftLive.setup();
    
    string guiPath = "audio.xml";
    gui.setup("audio", guiPath, 20, 20);
    gui.add(audioThreshold.setup("audioThreshold", 1.0, 0.0, 1.0));
    gui.add(audioPeakDecay.setup("audioPeakDecay", 0.915, 0.0, 1.0));
    gui.add(audioMaxDecay.setup("audioMaxDecay", 0.995, 0.0, 1.0));
    gui.add(audioMirror.setup("audioMirror", true));
    gui.loadFromFile(guiPath);
    //
    //ofPushMatrix();
    //ofRotateX(90);
    //ofRotateZ(ofGetElapsedTimef() * 10);
    //for (int i = 0; i < 30; i++) {
    //    float x = mesh.getVertex(i).x;
    //    float y = mesh.getVertex(i).y;
    //    mesh.setVertex(i, ofVec3f(x, y, 100));
    //}

    sphere = ofMesh::sphere(200, 10);
    box = ofMesh::box(300, 260, 300, 7, 7, 7);
    cylinder = ofMesh::cylinder(140, 360);
    cone = ofMesh::cone(260, 260, 12, 10);
    sphere_c = true;
    cylinder_c, cone_c ,box_c= false;
    n = 0;
    clear = false;
    refresh = false;
    color = (100, 100, 100);
    line = true;
    face = false;

}

//--------------------------------------------------------------
void ofApp::update() {
    if (sphere_c == true) {
        meshOriginal = meshWarped = sphere;
    }
    if (cone_c == true) {
        meshOriginal = meshWarped = cone;
    }
    if (cylinder_c == true) {
        meshOriginal = meshWarped = cylinder;
    }
    if (box_c == true) {
        meshOriginal = meshWarped = box;
    }
    fftLive.setThreshold(audioThreshold);
    fftLive.setPeakDecay(audioPeakDecay);
    fftLive.setMaxDecay(audioMaxDecay);
    fftLive.setMirrorData(audioMirror);
    fftLive.update();

    vector<glm::vec3> & vertsOriginal = meshOriginal.getVertices();
    vector<glm::vec3> & vertsWarped = meshWarped.getVertices();
    int numOfVerts = meshOriginal.getNumVertices();
    
    float * audioData = new float[numOfVerts];
    fftLive.getFftPeakData(audioData, numOfVerts);
    
    float meshDisplacement = 100;
    
    for(int i=0; i<numOfVerts; i++) {
        float audioValue = audioData[i];
        glm::vec3& vertOriginal = vertsOriginal[i];
        glm::vec3& vertWarped = vertsWarped[i];
        glm::vec3 direction = glm::normalize(vertOriginal);
        vertWarped = vertOriginal + direction * meshDisplacement * audioValue;

    }

    meshWarped.addColor(color);

    //for (size_t i = 0; i < mesh.getNumColors(); i = i+10) {
    //    //mesh.getColors()[i];// Use this to get the current color
    //    mesh.setColor(i, ofFloatColor(34,46,126));// pass which ever ofFloatColor you want to.
    //}


    delete[] audioData;

 


}

//--------------------------------------------------------------
void ofApp::draw() {
    color = ofFloatColor(100, 100, 100);
    cout << color << endl;
    ofSetColor(255);
    int w = OFX_FFT_WIDTH;
    int h = OFX_FFT_HEIGHT;
    int x = 20;
    int y = ofGetHeight() - h - 20;
    fftLive.draw(x, y, w, h);

    cam.begin();

    if (clear == true) {
        meshWarped.clearColors();
    }
    if (refresh == true) {
        meshWarped.addColor(color);
    }

    //if (face == true) {
    //    meshWarped.drawFaces();
    //}
    meshWarped.drawWireframe();
    cam.end();
    
    gui.draw();

    string _help = "[1][2][3][4]key: change center objects.";
    ofDrawBitmapString(_help, 10, 150);
    string _help1 = "[c][r]key: change color.";
    ofDrawBitmapString(_help1, 10, 170);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') {
        sphere_c = true;
        cone_c = false;
        cylinder_c = false;
        box_c = false;
    }
    if (key == '2') {
        cone_c = true;
        cylinder_c = false;
        sphere_c = false;
        box_c = false;
    }
    if (key == '3') {
        cylinder_c = true;
        sphere_c = false;
        cone_c = false;
        box_c = false;
    }
    if (key == '4') {
        cylinder_c = false;
        sphere_c = false;
        cone_c = false;
        box_c = true;
    }
    if (key == 's') {
        glReadBuffer(GL_FRONT);
        ofSaveScreen("savedScreenshot_" + ofGetTimestampString() + ".png");
    }
    if (key == 'c') {
        clear = true;
        refresh = false;
        //meshWarped.addColor(color);
    }
    if (key == 'r') {
        meshWarped.addColor(color);
        refresh = true;
        clear = false;
    }
    //if (key == 'f') {
    //    face == true;
    //}
    //if (key == 'l') {
    //    line == true;
    //    face == false;
    //}

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