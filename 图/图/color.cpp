#include"color.h"

int main() {
	int V, E;
	cin >> V >> E;
	/*
	���磺
		5 7
	*/
	graph Graph(V,E);
	/*
	���磺
		0 1 0 3 2 1 2 3 2 4 3 4 4 0
	*/
	Graph.paint();

	return 0;
}