#include "draw.h"
#include "turtlec.h"

void fractalTree(Turtle *turtle, float length, int depth, float reduction, float angle){
	if(depth <= 0 || length < 5.0f)
		return;

	turtleForward(turtle, length);
	
	turtleLeft(turtle, angle);
	fractalTree(turtle, length * reduction, depth - 1, reduction, angle);

	turtleRight(turtle, angle * 2);
	fractalTree(turtle, length * reduction, depth - 1, reduction, angle);

	turtleLeft(turtle, angle);
	turtleBackward(turtle, length);
}
