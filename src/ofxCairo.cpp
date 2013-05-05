#include "ofxCairo.h"

ofxCairo::ofxCairo()
{
    _renderCollection = ofPtr<ofRendererCollection>(new ofRendererCollection);
    _imageRenderer = ofPtr<ofCairoRenderer>(new ofCairoRenderer);
    _imageRenderer->setupMemoryOnly(ofCairoRenderer::IMAGE);
    _renderCollection->renderers.push_back(_imageRenderer);
    
    _tex.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    _tex.texData.glType = GL_BGRA;
}



void ofxCairo::begin()
{
    _origRenderer = ofGetCurrentRenderer();
    ofSetCurrentRenderer(_renderCollection);
}

void ofxCairo::setLineCap(_cairo_line_cap lineCap)
{
    cairo_set_line_cap(_imageRenderer->getCairoContext(), lineCap);
}

void ofxCairo::end()
{
    _renderCollection->update();
    ofSetCurrentRenderer(_origRenderer);
    
    ofPixels &pix = _imageRenderer->getImageSurfacePixels();
    _tex.loadData(pix.getPixels(), pix.getWidth(), pix.getHeight(), GL_BGRA);
}

void ofxCairo::draw()
{
    if (_tex.isAllocated()) _tex.draw(0, 0);
}