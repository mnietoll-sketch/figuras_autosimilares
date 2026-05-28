#ifndef DRAW_H
#define DRAW_H

#include "turtlec.h"

struct color{
	float r;
	float g;
	float b;
}


struct color color_init(void);

struct color color_sum(struct color c1, struct color c2);

struct color color_sub(struct color c1, struct color c2);

struct color color_div(struct color c, float f);

void fractalTree(Turtle *turtle, float length, int depth, float reduction, float angle);

void fractalTreeVariation(Turtle *turtle, float length, int depth, struct color from, struct color to);

#endif
