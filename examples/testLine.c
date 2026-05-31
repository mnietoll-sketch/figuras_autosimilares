#include "../turtlec.h"
#include "../draw.h"
#include <stdlib.h>

int main(void){
	TurtleApp *app = turtleAppCreate(800, 600, "Test Line");
	if(app == NULL)
		return 1;

	Turtle *t = turtleAppGetTurtle(app);
	
	turtlePenUp(t);
	turtleGoTo(t, 150.0f, 400.0f);
	turtlePenDown(t);

	turtleSetColor(t, 255, 150, 0);
	turtleSetSpeed(t, 10.0f);
	
	//fractalTree(t, 100.0f, 10);
	//fractalTreeGeneralized(t, 150.0f, 12, 0.7f, 30.0f);
	
	/*
	struct color from, to;
	from = color_init(150.0f, 75.0f, 0.0f);
	to = color_init(0.0f, 255.0f, 0.0f);
	fractalTreeVariation(t, 150.0f, 12, from, to);
	*/
	
	
	//levy(t, 200.0f, 10);
	/*
	struct color from, to;
	from = color_init(255.0f, 0.0f, 0.0f);
	to = color_init(0.0f, 255.0f, 255.0f);
	levyVariation(t, 300.0f, 10, from, to);
	*/
	
	fractalTreeChallenge(t, 200.0f, 8, 0.6f);
	
	turtleAppRun(app);
	turtleAppDestroy(app);
	return 0;
}
