# Hard Clustering Algorithm

This repository implements in c++ a dynamic hard clustering algorithm based on multiple dissimilarity matrices, calculating relevance weights for each one.

## The Algorithm

It is described in the section 2.2.2 of the "Partitioning Hard Clustering Algorithms
Based On Multiple Dissimilarity Matrices" paper, avaiable (here)[https://pdfs.semanticscholar.org/564a/49359eda9f9b3212c68c2b3f23c16cb15ef6.pdf].

## Testing

For evaluating the algorithms performace, the "Image Segmentation" repository from the (uci machine learning website)[http://archive.ics.uci.edu/ml/index.php] was used. It is avaiable (here)[http://archive.ics.uci.edu/ml/machine-learning-databases/image/]

The table "segmentation.test" contains 2100 objects divided in 7 classes. The objects are described by 19 variables splitted in 2 views:
* Shape View: the first 9 variables
* RGB View: the last 10 variables

Two dissimilarity matrices were computed, one for each view.

## Results

The results evaluated for this dataset utilizes the (Adjusted Rand Index)[https://en.wikipedia.org/wiki/Rand_index] to compare it's results with other known hard clustering algorithms.
