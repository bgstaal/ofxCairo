#ifndef __ofxCairoExample__ofxCairo__
#define __ofxCairoExample__ofxCairo__

#include "ofMain.h"

class ofxCairo
{
	public:
    	ofxCairo();
    	void begin();
    	void end();
	    void draw();
	    void setLineCap(_cairo_line_cap lineCap);
    
	private:
	    ofTexture _tex;
	    ofPtr<ofBaseRenderer> _origRenderer;
	    ofPtr<ofRendererCollection> _renderCollection;
        ofPtr<ofCairoRenderer> _imageRenderer;
        ofPtr<ofCairoRenderer> _pdfRenderer;
};

#endif /* defined(__ofxCairoExample__ofxCairo__) */
