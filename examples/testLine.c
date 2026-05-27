#include "../turtlec.h"
#include "../draw.h"
#include <stdlib.h>

int main(void){
	TurtleApp *app = turtleAppCreate(800, 600, "Test Line");
	if(app == NULL)
		return 1;

	Turtle *t = turtleAppGetTurtle(app);
	
	turtlePenUp(t);
	turtleGoTo(t, 150.0f, 200.0f);
	turtlePenDown(t);

	turtleSetColor(t, 255, 100, 0);
	turtleSetSpeed(t, 10.0f);
	//square(t, 100.0f);
	//turtleForward(t, 100.0f);
	//splitLine(t, 2000.0f, 10, 10, 255.0f, 255.0f, 255.0f);

	long int* count;
	float *r, *g, *b;
	
	count = (long int*)malloc(sizeof(long int));
	r = (float*)malloc(sizeof(float));
	g = (float*)malloc(sizeof(float));
	b = (float*)malloc(sizeof(float));
	
	*count = 0, *r = 0.0f, *g = 255.0f, *b = 255.0f;
	for(int i = 0; i < 3; i++){
		koch(t, 400.0f, 5, 5, count, r, g, b);
		turtleRight(t, 120.0f);	
	}

	free(count);
	free(r);
	free(g);
	free(b);

	turtleAppRun(app);
	turtleAppDestroy(app);
	return 0;
}
