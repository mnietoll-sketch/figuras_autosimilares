#ifndef DRAW_H
#define DRAW_H

#include "turtlec.h"

struct color{
	float r;
	float g;
	float b;
}

struct color color_sub(struct color to, struct color from);

void fractalTree(Turtle *turtle, float length, int depth, float reduction, float angle);

void fractalTreeVariation(Turtle *turtle, float length, int depth, struct color from, struct color to);

#endif
