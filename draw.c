#include "draw.h"
#include "turtlec.h"

void fractalTree(Turtle *turtle, float length, int depth){
	if(depth <= 0 || legth < 5.0f)
		return;

	float reduction = 0.7f;

	turtleForward(turtle, length);
	
	turtleLeft(turtle, 30);
	fractalTree(turtle, length * reduction, depth - 1);

	turtleRight(turtle, 60);
	fractalTree(turtle, length * reduction, depth - 1);

	turtleLeft(turtle, 30);
	turtleBackward(turtle, length);
}
