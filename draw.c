#include "draw.h"
#include "turtlec.h"

struct color color_sub(struct color to, struct color from){
	struct color result;

	result.r = to.r - from.r;
	result.g = to.g - from.g;
	result.b = to.b - from.b;
}

struct color color_div(struct color c, float f){
	struct color result;

	result.r = c.r / f;
	result.g = c.g / f;
	result.b = c.b / f;
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

	struct color grad = color_div(color_sub(to, from), 2);

	turtleForward(turtle, length);
	
	turtleLeft(turtle, 30);
	fractalTree(turtle, length * 0.7, depth - 1, , );
	
	turtleRight(turtle, 60);
	fractalTree(turtle, length * 0.7, depth - 1, , );
	
	turtleLeft(turtle, 30);
	turtleBackward(turtle, length);
}
