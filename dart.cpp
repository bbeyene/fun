#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {

	srand48(0);
	double x;
	double y;
	double pt;
	int dartsInCircle = 0;
	double probability;

	int nDarts = 1000000;

	for(int i = 0; i < nDarts; i++) {
		x = drand48();
		y = drand48();



		pt = sqrt((x*x) + (y*y));

		if(pt < 1.0)
			dartsInCircle++;
	}

	probability = (dartsInCircle/(double)nDarts);

	cout << "P(NOT IN CIRCLE) = " << 1 - probability << endl;
 	cout << "Pi = " << 4.0 * probability << endl;

	return 0;
}