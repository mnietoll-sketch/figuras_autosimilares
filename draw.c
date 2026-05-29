#include "draw.h"
#include "turtlec.h"
#include <math.h>

struct color color_init(float r, float g, float b){
	struct color result;
	result.r = r;
	result.g = g;
	result.b = b;
	return result;
}

struct color color_sum(struct color c1, struct color c2){
	struct color result;
	result.r = c1.r + c2.r;
	result.g = c1.g + c2.g;
	result.b = c1.b + c2.b;
	return result;
}

struct color color_sub(struct color c1, struct color c2){
	struct color result;

	result.r = c1.r - c2.r;
	result.g = c1.g - c2.g;
	result.b = c1.b - c2.b;
	return result;
}

struct color color_div(struct color c, float f){
	struct color result;

	result.r = c.r / f;
	result.g = c.g / f;
	result.b = c.b / f;
	return result;
}

void fractalTree(Turtle *turtle, float length, int depth, float reduction, float angle){
	if(depth <= 0 || length < 5.0f)
		return;

	if(depth < 5)
		turtleSetColor(turtle, 0.0f, 255.0f, 0.0f);

	turtleForward(turtle, length);
	
	turtleLeft(turtle, angle);
	fractalTree(turtle, length * reduction, depth - 1, reduction, angle);
	
	turtleRight(turtle, angle * 2);
	fractalTree(turtle, length * reduction, depth - 1, reduction, angle);
	
	if(depth >= 5)
		turtleSetColor(turtle, 150.0f, 75.0f, 0.0f);

	turtleLeft(turtle, angle);
	turtleBackward(turtle, length);
}

void fractalTreeVariation(Turtle *turtle, float length, int depth, struct color from, struct color to){
	if(depth <= 0 || length < 5.0f)
		return;

	struct color grad;
	grad = color_init(0.0f, 0.0f, 0.0f);
	if(depth >= 2)
		grad = color_div(color_sub(to, from), depth - 1);
	
	turtleSetColor(turtle, from.r, from.g, from.b);
	turtleForward(turtle, length);
	
	turtleLeft(turtle, 30.0f);
	fractalTreeVariation(turtle, length * 0.7, depth - 1, color_sum(from, grad), to);
	
	turtleRight(turtle, 60.0f);
	fractalTreeVariation(turtle, length * 0.7, depth - 1, color_sum(from, grad), to);
	
	turtleSetColor(turtle, from.r, from.g, from.b);
	turtleLeft(turtle, 30.0f);
	turtleBackward(turtle, length);
}

void levy(Turtle *turtle, float length, int depth){
	if(depth == 0){
		turtleForward(turtle, length);
		return ;
	}

	turtleLeft(turtle, 45.0f);
	levy(turtle, length / sqrt(2), depth - 1);

	turtleRight(turtle, 90.0f);
	levy(turtle, length / sqrt(2), depth - 1);
	
	turtleLeft(turtle, 45.0f);
}


void levyVariation(Turtle *turtle, float length, int depth, struct color from, struct color to){
	if(depth == 0){
		turtleSetColor(turtle, from.r, from.g, from.b);
		turtleForward(turtle, length);
		return ;
	}

	struct color grad, mid;
	grad = color_div(color_sub(to, from), 2);
	mid = color_sum(from, grad);

	turtleLeft(turtle, 45.0f);
	levyVariation(turtle, length / sqrt(2), depth - 1, from, mid);

	turtleRight(turtle, 90.0f);
	levyVariation(turtle, length / sqrt(2), depth - 1, mid, to);
	
	turtleLeft(turtle, 45.0f);
}
