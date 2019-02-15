#include "lab1_io.h"

void dataset_in (const char* dataset_filename, int* N, int** data_points){
	FILE *fin = fopen(dataset_filename, "r");

	fscanf(fin, "%d", N);
	
	*data_points = (int*)malloc(sizeof(int)*((*N)*3));
	
	for (int i = 0; i < (*N)*3; i++){
		fscanf(fin, "%d", (*data_points + i));
	}

	fclose(fin);
}

void clusters_out (const char* cluster_filename, int N, int* cluster_points){
	FILE *fout = fopen(cluster_filename, "w");

	for (int i = 0; i < N; i++){
		fprintf(fout, "%d %d %d %d\n", 
			*(cluster_points+(i*4)), *(cluster_points+(i*4)+1), 
			*(cluster_points+(i*4)+2), *(cluster_points+(i*4)+3));
	}

	fclose(fout);
}

void centroids_out (const char* centroid_filename, int K, int num_iterations, float* centroids){
	FILE *fout = fopen(centroid_filename, "w");

	for (int i = 0; i < num_iterations+1; i++){				//ith iteration
		for (int j = 0; j < K; j++){			//jth centroid of ith iteration
			fprintf(fout, "%f %f %f, ", 
									*(centroids+(i*K+j)*3), 	 //x coordinate
									*(centroids+(i*K+j)*3+1),  //y coordinate
									*(centroids+(i*K+j)*3+2)); //z coordinate
		}
		fprintf(fout, "\n");
	}

	fclose(fout);
}