#include "draw.h"
#include "turtlec.h"

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
