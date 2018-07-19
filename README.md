# GraphMaximalSimplePath
Let G=(V,E) be directed graph, let (x,y) be an edge belonging to E and let P be a simple Path in G  
We say the simple path P is maximal if no vertex exists such that the additon of it to any side of P creates a new simple path  

Here I implemented an algorithm with C++ that finds a maximal path for an arbteriy directed graph G which contains some edge (x,y) which runs in O(V+E) (fordense graphs the bound is O(V^2))

# How to Install
Deploy contents to any folder, run .sln file 
# How to use
There is a word file which describes the algorithm in psedo code with some explaintions.    
The input to the algorithm is given via console, here is an example for some execution:    

Please enter the number of nodes in the directed graph:  
>> 5  
Please enter the list of neighbors for each node of the graph:  
>> {5, 2, 3}, {1,5}, { }, { }, {3}  
Please enter the nodes of the edge:  
>> 1, 3  
The output is  
<< (2, 1, 3)  
Do you want to continue (y/n):  
>> y  
Please enter the nodes of the edge:  
>> 2, 5  
The output is  
<< (1, 2, 5, 3)  


