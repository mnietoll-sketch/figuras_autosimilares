#include "draw.h"
#include "turtlec.h"


struct color color_init(void){
	struct color result;
	result.r = 0;
	result.g = 0;
	result.b = 0;
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
		turtleSetColor(turtle, 0, 255, 0);

	turtleForward(turtle, length);
	
	turtleLeft(turtle, angle);
	fractalTree(turtle, length * reduction, depth - 1, reduction, angle);
	
	turtleRight(turtle, angle * 2);
	fractalTree(turtle, length * reduction, depth - 1, reduction, angle);
	
	if(depth >= 5)
		turtleSetColor(turtle, 150, 75, 0);

	turtleLeft(turtle, angle);
	turtleBackward(turtle, length);
}

void fractalTreeVariation(Turtle *turtle, float length, int depth, struct color from, struct color to){
	if(depth <= 0 || length < 5.0f)
		return;

	struct color grad;
	grad = color_init();
	if(depth >= 2)
		grad = color_div(color_sub(to, from), depth - 1);
	
	turtleSetColor(turtle, from.r, from.g, from.b);
	turtleForward(turtle, length);
	
	turtleLeft(turtle, 30);
	fractalTree(turtle, length * 0.7, depth - 1, color_sum(from + grad), to);
	
	turtleRight(turtle, 60);
	fractalTree(turtle, length * 0.7, depth - 1, color_sum(from + grad), to);
	
	turtleSetColor(turtle, from.r, from.g, from.b)
	turtleLeft(turtle, 30);
	turtleBackward(turtle, length);
}
