#include "../turtlec.h"
#include "../draw.h"
#include <stdlib.h>

int main(void){
	TurtleApp *app = turtleAppCreate(800, 600, "Test Line");
	if(app == NULL)
		return 1;

	Turtle *t = turtleAppGetTurtle(app);
	
	turtlePenUp(t);
	turtleGoTo(t, 150.0f, 300.0f);
	turtlePenDown(t);

	turtleSetColor(t, 255, 100, 0);
	turtleSetSpeed(t, 10.0f);
	
	fractalTree(t, 50.0f, 25, 0.7f);

	turtleAppRun(app);
	turtleAppDestroy(app);
	return 0;
}
