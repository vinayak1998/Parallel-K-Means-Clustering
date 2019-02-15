# Parallel-K-Means-Clustering
Sequential and Parallel(using Open MP and Pthreads) Implementations(c++) of the K Means Clustering Algorithm and visualizing the results for a comparative study of the Speedup and Efficiency achieved in 3 different implementations

## Execution
- **Sequential**
  - cd into Sequential folder
  - `g++ main_sequential.c lab1_io.c Kmeans-Sequential.cpp -fopenmp -o seq.out`
  - `./seq.out 4 sample_dataset_50000_4.txt b.txt c.txt`
  - 4 is for the number of clusters. Can be changed.
  - To Visualize the results :- `python visualise.py b.txt`
    
- **OpenMP**
  - cd into OpenMP folder
  - `g++ main_omp.c lab1_io.c Kmeans-OpenMP.cpp -fopenmp -o omp.out`
  - `./omp.out 4 2 sample_dataset_5000_3.txt b.txt c.txt`
  - 4 is for the number of clusters and 2 is for the number of threads. Both can be changed.
  - To Visualize the results :- `python visualise.py b.txt`
  
- **P-Threads**
  - cd into P-Threads folder
  - `g++ lab1_io.c main_pthread.c Kmeans-Pthreads.cpp -o ptry.out -fopenmp`
  - `./ptry.out 4 2 sample_dataset_50000_4.txt b.txt c.txt`
  - 4 is for the number of clusters and 2 is for the number of threads. Both can be changed.
  - To Visualize the results :- `python visualise.py b.txt`
  
### Sample Visualization
  
![alt text](https://github.com/vinayak1998/Parallel-K-Means-Clustering/blob/master/Sample_Visualization(K%3D3).png)
