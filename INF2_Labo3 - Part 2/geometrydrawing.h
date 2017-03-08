/*
 * Author: Romain Maffina
 * Date: 03.03.2016
 *
 * Geometry drawing surface.s
 */

#pragma once

#include "config.h"

#if LAB3_VERSION >= 3
#include "triangle.h"
#endif
#if LAB3_VERSION >= 2
#include "segment.h"
#endif

#include "point.h"

#include <cstdlib>
#include <cstdint>
#include <vector>
#include <string>

class GeometryDrawing
{
public:
    GeometryDrawing(size_t surfaceWidth, size_t surfaceHeight);
    GeometryDrawing(size_t surfaceWidth, size_t surfaceHeight, size_t ppcm);

    size_t getSurfaceWidth() const;
    size_t getSurfaceHeight() const;

    const std::vector<uint8_t>& getImage() const;
    size_t getImageWidth() const;
    size_t getImageHeight() const;
    size_t getImagePixelPerCentimeter() const;

    size_t getPenThickness() const;
    void setPenThickness(size_t thickness);

    bool saveToBmp(const std::string path);

    bool draw(const Point &p);
#if LAB3_VERSION >= 2
    bool draw(const Segment &s);
#endif
#if LAB3_VERSION >= 3
    bool draw(const Triangle &s);
#endif

private:

    enum Color {
        Empty = 255,
        Full = 0,
    };

    const size_t ppcm = 60; // pixels per centimeter
    size_t penThickness = 2;

    std::vector<uint8_t> img;
    size_t surfaceWidth, surfaceHeight;

    size_t pointToPixel(double val);
    bool pointToPixel(const Point &p, size_t &x, size_t &y);
    bool drawPixel(size_t x, size_t y, Color color);
};