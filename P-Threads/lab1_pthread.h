#ifndef LAB1_PTHREAD_H
#define LAB1_PTHREAD_H

#include <malloc.h>

/*
	Arguments:

	num_threads		   : no. of threads to be used (input)
	N 				   : no. of data points (input)
	K 				   : no. of clusters (input)
	data_points 	   : 1D array of data_points (input)
						 format - 1 data point uses 3 consecutive indices, ie
	     				 -----------------------------------------------
						| pt1_x | pt1_y | pt1_z | pt2_x | pt2_y | pt2_z | ...
		 				 -----------------------------------------------
	data_point_cluster : 1D array of data_points and their cluster id (to be computed)
						 format - 1 data point uses 4 consecutive indices, ie
						  -------------------------------------------------------------------------------
						 | pt1_x | pt1_y | pt1_z | pt1_clusterid | pt2_x | pt2_y | pt2_z | pt2_clusterid | ...
	 					  -------------------------------------------------------------------------------
	 					  cluster_id - range between 0 to K-1
	centroids		   : 1D array of centroids of each iteration (to be computed)
						 format - 1 iteration uses K consecutive indices
						 *include initial centroids in the array (the 1st K entries of the array), ie
						  -------------------------------------------------------------------------------------
						 | cent0_init_x | cent0_init_y | cent0_init_z | ... | centK_init_x centK_init_y centK-1_init_z |
						  -------------------------------------------------------------------------------------
						 | cent0_it1_x | cent0_it1_y | cent0_it1_z | ... | centK_it1_x centK_it1_y centK-1_it1_z |
						  -------------------------------------------------------------------------------------
						 | cent0_it2_x | cent0_it2_y | cent0_it2_z | ... | centK_it2_x centK_it2_y centK-1_it2_z | ...
						  -------------------------------------------------------------------------------------
	num_iterations     : no of iterations of k-means algo = (length of centroids array / K) - 1 (to be computed)

*/

void kmeans_pthread(int num_threads,
					int N,
					int K,
					int* data_points,
					int** data_point_cluster,
					float** centroids,
					int* num_iterations
					);

#endif