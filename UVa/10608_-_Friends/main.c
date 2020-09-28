/* 10608 - Friends */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct Edge {

  unsigned int nodeA;
  unsigned int nodeB;
};

struct Graph {

  unsigned int numOfEdges;
  unsigned int numOfNodes;
  struct Edge *edges;
};

struct Graph *allocateGraph(unsigned int sizeNode, unsigned int sizeEdge) {

  struct Graph *newGraph = (struct Graph *)malloc(sizeof(struct Graph));
  newGraph->numOfEdges = sizeEdge;
  newGraph->numOfNodes = sizeNode;

  newGraph->edges = (struct Edge *)malloc(sizeof(struct Edge) * sizeEdge);

  return (newGraph);
}

void graphFree(struct Graph *rmvGraph) {

  free(rmvGraph->edges);
  free(rmvGraph);
}

struct SubSet {

  unsigned int rank;
  unsigned int parent;
};
struct Set {

  unsigned int size;
  struct SubSet *sets;
};

struct Set *allocateSet(unsigned int count) {

  struct Set *new = (struct Set *)malloc(sizeof(struct Set));
  new->size = count;

  new->sets = (struct SubSet *)malloc(sizeof(struct SubSet) * (count + 1));

  unsigned int i;
  for (i = 1; i <= count; i++) {
    new->sets[i].rank = 1;
    new->sets[i].parent = i;
  }
  return new;
}

void setFree(struct Set *rmvSet) {

  free(rmvSet->sets);
  free(rmvSet);
  rmvSet = NULL;
}
unsigned int SetFind(unsigned int toFind, struct Set *set) {

  while (toFind != set->sets[toFind].parent) {
    toFind = set->sets[toFind].parent;
  }
  return toFind;
}
void setUnite(struct Edge uniEd, struct Set *set) {

  unsigned int source = SetFind(uniEd.nodeA, set);
  unsigned int target = SetFind(uniEd.nodeB, set);

  if (source != target) {

    if (set->sets[target].rank < set->sets[source].rank) {

      set->sets[source].rank += set->sets[target].rank;
      set->sets[target].parent = source;

    } else {
      set->sets[target].rank += set->sets[source].rank;
      set->sets[source].parent = target;
    }
  }
}

int main(void) {

  unsigned int casesCount, numOfPairs, numOfCitizen, nodeFrom, nodeTo,
      maximumInGroup;
  assert(scanf("%u", &casesCount));

  while (casesCount--) {

    assert(scanf("%u %u", &numOfCitizen, &numOfPairs));
    struct Graph *graphIn = allocateGraph(numOfCitizen, numOfPairs);

    struct Set *setIn = allocateSet(numOfCitizen);
    int i;
    for (i = 0; i < numOfPairs; i++) {

      assert(scanf("%u %u", &nodeFrom, &nodeTo));
      graphIn->edges[i].nodeA = nodeFrom;
      graphIn->edges[i].nodeB = nodeTo;
      setUnite(graphIn->edges[i], setIn);
    }

    maximumInGroup = 0;

    int j;
    for (j = 1; j <= numOfCitizen; j++) {
      if (setIn->sets[j].rank > maximumInGroup)
        maximumInGroup = setIn->sets[j].rank;
    }
    printf("%u\n", maximumInGroup);
    setFree(setIn);
    graphFree(graphIn);
  }

  return (EXIT_SUCCESS);
}

