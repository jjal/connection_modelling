#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "splodge.h"

class testApp : public ofBaseApp{
	
	static const int WIDTH = 30;
	static const int HEIGHT = 30;
	static const int CHANCE_INITIATOR = 10;
	public:
		Splodge* splodges[7600];

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
		
		float counter;
		bool bSmooth;
};

#endif
	
