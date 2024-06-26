You have got the job of installing street lights in your city. 
In your city, there are n junctions (numbered from 1 to n) and m directed roads
connecting two junctions which is given as 2d integer array Edges where Edges[i] = [x,y] 
means there exists an directed edge from x to y.

You want to install streetlights at these junctions.
The street light installed at junction i can light
all the junctions j such that there is a way to go 
from i to j and come back to i from j or i=j.

Each Junction has a cost associated with it for installing purpose.
You are given an array cost[] where cost[i] is the cost of installing a street light at junction i.
You need to find the minimum cost for lighting all the junctions.