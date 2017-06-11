#ifndef _GRAPH_INTERFACE
#define _GRAPH_INTERFACE

template<class LabelType>
class GraphInterface
{
public:
  /** Gets the number of vertices in this graph.
  @pre None.
  @return The number of vertices.*/
  virtual int getNumVertices() const = 0;

  /** Gets the number of edges.
  @pre None.
  @return The number of edges */
  virtual int getNumEdges() const = 0;

  /** Adds a new vertex to the grap.
  @param vertex New vertex
  @return true if addition vas succesfull false otherwise.*/
  virtual bool addVertex(LabelType s) = 0;

  /** Adds and edge between to vertices
  @param start First vertex
  @param end Second vertex
  @param edgeWeight The weight of the edge
  @return true if the new edge is created, false otherwise */
  virtual void addEdge(LabelType start, LabelType end, int edgeWeight) = 0;

  /** Removes the edge between given vertices
  @param start First vertex
  @param end Second vertex
  @return True if the edge is removed, false otherwise */
  virtual bool removeEdge(LabelType start, LabelType end) = 0;

  /** Gets the weight of the edge between given vertices
  @param start First vertex
  @param end Second vertex
  @return weight of the edge. If no such edge exists, returns -1 */
  virtual int getEdgeWeight(LabelType start, LabelType end)  = 0;

  /** Performs a depth-first search of this graph beginning at the given
    vertex and calls a given fucntion once for each vertex visited.
  @param start First vertex.
  @param visit user-defined fucntion that operates on or with each visited
    vertex.*/
  virtual void depthFirstTraversal(LabelType start, void visit(LabelType&)) = 0;

  /** Performs a breath-first search of this graph beginning at the given
    vertex and calls a given fucntion once for each vertex visited.
  @param start First vertex.
  @param visit user-defined fucntion that operates on or with each visited
    vertex.*/
  virtual void breathFirstTraversal(LabelType start, void visit(LabelType&)) = 0;
}; // end GraphInterface
#endif
