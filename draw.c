#include "draw.h"
#include "turtlec.h"

void fractalTree(Turtle *turtle, float length, int depth, float reduction){
	if(depth <= 0 || length < 5.0f)
		return;

	turtleForward(turtle, length);
	
	turtleLeft(turtle, 30);
	fractalTree(turtle, length * reduction, depth - 1, reduction);

	turtleRight(turtle, 60);
	fractalTree(turtle, length * reduction, depth - 1, reduction);

	turtleLeft(turtle, 30);
	turtleBackward(turtle, length);
}
