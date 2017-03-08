//HIDE

#include "geometrydrawing.h"
#include "bmp.h"
#include <cmath>
#include <cstdlib>

using namespace std;

GeometryDrawing::GeometryDrawing(size_t surfaceWidth, size_t surfaceHeight)
    :surfaceWidth(surfaceWidth), surfaceHeight(surfaceHeight)
{
    img.resize(getImageWidth()*getImageHeight(), Color::Empty);
}

GeometryDrawing::GeometryDrawing(size_t surfaceWidth, size_t surfaceHeight, size_t ppcm)
    :ppcm(ppcm)
{
    GeometryDrawing(surfaceWidth, surfaceHeight);
}

const std::vector<uint8_t> &GeometryDrawing::getImage() const
{
    return img;
}

size_t GeometryDrawing::getImageWidth() const
{
    return surfaceWidth*ppcm;
}

size_t GeometryDrawing::getImageHeight() const
{
    return surfaceHeight*ppcm;
}

size_t GeometryDrawing::getImagePixelPerCentimeter() const
{
    return ppcm;
}

size_t GeometryDrawing::getPenThickness() const
{
    return penThickness;
}

void GeometryDrawing::setPenThickness(size_t thickness)
{
    penThickness = thickness;
}

bool GeometryDrawing::saveToBmp(const string path)
{
    return bmp_write(path, getImage(), getImageWidth(), getImageHeight());
}

size_t GeometryDrawing::getSurfaceWidth() const
{
    return surfaceWidth;
}

size_t GeometryDrawing::getSurfaceHeight() const
{
    return surfaceHeight;
}

bool GeometryDrawing::draw(const Point &p)
{
    size_t pixelCenterX, pixelCenterY;

    if (p.getX() >= getSurfaceWidth() || p.getY() >= getSurfaceHeight())
        return false;

    // convert point coordinates to pixels indexes
    pointToPixel(p, pixelCenterX, pixelCenterY);

    // constrain ourself within unsigned range
    size_t offsetXMin = min(pixelCenterX, penThickness);
    size_t offsetYMin = min(pixelCenterY, penThickness);

    // draw the point but taking the pen thickness into account
    for (size_t y=pixelCenterY-offsetYMin; y<=pixelCenterY+penThickness; y++)
        for (size_t x=pixelCenterX-offsetXMin; x<=pixelCenterX+penThickness; x++)
            drawPixel(x, y, Color::Full);

    return true;
}

#if LAB3_VERSION >= 2
bool GeometryDrawing::draw(const Segment &s)
{
    // https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
    Point a, b;
    size_t x0,y0,x1,y1;

    // get segment points values
    pointToPixel(s.getA(), x0, y0);
    pointToPixel(s.getB(), x1, y1);

    // swap starting x value if necessary
    double tmp;
    if (x0 > x1) {
        tmp=x0;
        x0=x1;
        x1=tmp;
        tmp=y0;
        y0=y1;
        y1=tmp;
    }

    double dx = (double)x1-x0;
    double dy = (double)y1-y0;
    double err = 0;
    double derr = 0;

    if (dx != 0) {
        derr = fabs(dy/dx);
    } else {
        derr = fabs(dy); // if no dx then error is dy
    }

    double y=y0;
    for (double x=x0; x<=x1; x++) {
        drawPixel(x,y,Color::Full);
        err = err + derr;
        while (err >= 0.5) {
            drawPixel(x,y, Color::Full);
            y = y + ((dy > 0) ? 1 : ((dy < 0) ? -1 : 0));
            err = err - 1.0;
        }
    }

    return true;
}
#endif

#if LAB3_VERSION >= 3
bool GeometryDrawing::draw(const Triangle &s)
{
    draw(s.getAB());
    draw(s.getBC());
    draw(s.getCA());

    return true;
}
#endif

size_t GeometryDrawing::pointToPixel(double val)
{
    return val*ppcm;
}

bool GeometryDrawing::pointToPixel(const Point &p, size_t &x, size_t &y)
{
    x = pointToPixel(p.getX());
    y = pointToPixel(p.getY());

    return true;
}

bool GeometryDrawing::drawPixel(size_t x, size_t y, GeometryDrawing::Color color)
{
    if (x >= getImageWidth() || y >= getImageHeight())
        return false;

    // we start the drawing from bottom-left of the image
    img[getImageWidth()*(getImageHeight()-y)+x] = color;

    return true;
}
