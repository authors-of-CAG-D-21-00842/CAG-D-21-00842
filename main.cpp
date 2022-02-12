#include "CCreoPointCloud.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int k = atoi(argv[2]);
    float lambda = atof(argv[3]);
    float mu = atof(argv[4]);
    int isRegularized = 0;
    string fileName  = "smoothed.txt";
	isRegularized = atoi(argv[5]);
    if (argc > 6) fileName = string(argv[6]);
    printf("Reading point cloud...");
    CCreoPointCloud pc(argv[1], false);
    printf("done.\n");
    printf("smoothing...");
    //mollification...uncomment
	//pc.smooth_iterative(10, lambda, mu, 0.65, isRegularized);
    pc.smooth_iterative(k, lambda, mu, 0.65, isRegularized);
    printf("done.\n");
    pc.savePointCloud(fileName.c_str(), false);
    return 0;
}