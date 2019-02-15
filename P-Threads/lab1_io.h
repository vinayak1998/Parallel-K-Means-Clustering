#ifndef LAB1_IO_H
#define LAB1_IO_H

#include <stdio.h>
#include <malloc.h>

/*
	N : dataset size
	data_points : Array containing data points, using 3 index per
                  data point as:
     -----------------------------------------------
	| pt1_x | pt1_y | pt1_z | pt2_x | pt2_y | pt2_z | ...
	 -----------------------------------------------
*/
void dataset_in (const char* dataset_filename, int* N, int** data_points);

/*
	N : dataset size
	cluster_points : Array containing data points, using 4 index per
                     data point as:
     -------------------------------------------------------------------------------
	| pt1_x | pt1_y | pt1_z | pt1_clusterid | pt2_x | pt2_y | pt2_z | pt2_clusterid | ...
	 -------------------------------------------------------------------------------
	cluster_id : between 0 to K-1

	output format : 1 data point per line containing space separated
					x_coord y_coord z_coord cluster_id

	eg.
	(N = 3)
	pt1_x pt1_y pt1_z pt1_clusterid
	pt2_x pt2_y pt2_z pt2_clusterid
	pt3_x pt3_y pt3_z pt3_clusterid
*/
void clusters_out (const char* cluster_filename, int N, int* cluster_points);

/*
	N : no of iterations
	K : no of centroids (given as input)
	centroids : Array containing centroids of each iteration, using K
				index per iteration
	 -------------------------------------------------------------------------------------
	| cent1_it1_x | cent1_it1_y | cent1_it1_z | ... | centK_it1_x centK_it1_y centK_it1_z |
	 -------------------------------------------------------------------------------------
	| cent1_it2_x | cent1_it2_y | cent1_it2_z | ... | centK_it2_x centK_it2_y centK_it2_z | ...
	 -------------------------------------------------------------------------------------

	output format : centroids of 1 iteration in 1 line separated by commas
	eg.
	(N = 3, K = 2)
	cent1_it1_x cent1_it1_y cent1_it1_z, cent2_it1_x cent2_it1_y cent2_it1_z,
	cent1_it2_x cent1_it2_y cent1_it2_z, cent2_it2_x cent2_it2_y cent2_it2_z,
	cent1_it3_x cent1_it3_y cent1_it3_z, cent2_it3_x cent2_it3_y cent2_it3_z,
*/
void centroids_out (const char* centroid_filename, int K, int num_iterations, float* centroids);

#endif