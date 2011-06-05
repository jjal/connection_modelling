#include "testApp.h"
#include "Splodge.h"
#include "Initiator.h"
#include "Connector.h"

//--------------------------------------------------------------
void testApp::setup(){
	counter = 0;
	ofSetCircleResolution(50);
	ofBackground(0,0,0);
	bSmooth = true;
	ofSetWindowTitle("connection modelling");
	Splodge* spl;
	srand(time(NULL));
	for(int i=0;i<WIDTH*HEIGHT;i++)
	{
		if(rand()%1000 < CHANCE_INITIATOR)
			spl = new Initiator();
		else
			spl = new Connector();
		spl->cooldown = rand() % 100; //make them irregular!
		spl->index = i;
		splodges[i] = spl;
	}
	for(int i=0;i<WIDTH*HEIGHT;i++)
	{
		for(int j=-1;j<=1;j++)
		{
			for(int k=-1;k<=1;k++)
			{
				if(j != 0 || k != 0)
				{
					int n = i+k+(j*WIDTH);
					if(n/WIDTH == (i/WIDTH)+j && 
						n >= 0 && n <WIDTH*HEIGHT) //neighbour is not off the board and not a wrapping rows
						splodges[i]->neighbours[splodges[i]->numNeighbours++] = splodges[n];
				}
			}
		}
	}
	ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
}

//--------------------------------------------------------------
void testApp::update(){
	//counter = counter + 0.033f;
	//need a new world of splodges
	//for each splodge
		//count all the changed neighbours
		//pick a changed neighbour at random and copy them
	for(int i=0;i<WIDTH*HEIGHT;i++)
	{
		splodges[i]->update();
	}
	for(int i=0;i<WIDTH*HEIGHT;i++)
	{
		splodges[i]->blip();
	}
}

//--------------------------------------------------------------
void testApp::draw()
{
	for(int i=0;i<WIDTH*HEIGHT;i++)
	{
		splodges[i]->draw((i%WIDTH)*20,(i/WIDTH)*20);
	}
	//---------------------------  transparency
	//ofSetColor(0x00FF33);
	//ofRect(400,350,100,100);
	//// alpha is usually turned off - for speed puposes.  let's turn it on!
	//ofEnableAlphaBlending();
	//ofSetColor(255,0,0,127);   // red, 50% transparent
	//ofRect(450,430,100,33);
	//ofSetColor(255,0,0,(int)(counter * 10.0f) % 255);   // red, variable transparent
	//ofRect(450,370,100,33);
	//ofDisableAlphaBlending();

	//ofSetColor(0x000000);
	//ofDrawBitmapString("transparency", 410,500);

	//---------------------------  lines
	// a bunch of red lines, make them smooth if the flag is set

	if (bSmooth){
		ofEnableSmoothing();
	}
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	if (key == 's'){
		bSmooth = !bSmooth;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}


//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}
