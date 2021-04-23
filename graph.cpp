#include "stdio.h"
#include "stdlib.h"

struct Graph {
    int numberOfNodes;
    int **edgesAdjMatrix;
};

struct Graph buildEmptyGraphWithNodes(int numberOfNodes) {
    struct Graph retGraph;
    retGraph.numberOfNodes = numberOfNodes;
    retGraph.edgesAdjMatrix = (int **) malloc(numberOfNodes * sizeof(int *));
    for(int i = 0; i < numberOfNodes; i++) {
        retGraph.edgesAdjMatrix[i] = (int *) calloc(numberOfNodes, sizeof(int));
    }
    return retGraph;
}

void addEdge(struct Graph *graph, int nodeA, int nodeB) {
    graph->edgesAdjMatrix[nodeA-1][nodeB-1] = 1;
    graph->edgesAdjMatrix[nodeB-1][nodeA-1] = 1;
}

// Prints the adj matrix of a graph
void printEdgeAdjMatrix(struct Graph graph) {
    int i = 0, j;
    while(i < graph.numberOfNodes) {
        j = 0;
        while (j < graph.numberOfNodes) {
            printf("%d ", graph.edgesAdjMatrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

// Prints neighbours of a node n-1
void printNeighboursOfNode(struct Graph graph, int node) {
    if(node < 1 || node > graph.numberOfNodes) {
        printf("Invalid value of node\n");
        return;
    }
    int flag = 0;
    printf("Neighbours of cell phone %d : ", node);
    node--;
    for(int i = 0; i < graph.numberOfNodes; i++) {
        if(graph.edgesAdjMatrix[node][i] == 1) {
            flag = 1;
            printf("%d ", (i+1));
        }
    }
    if(!flag) {
        printf("None");
    }
    printf("\n");
}

int main() {
    int command;
    struct Graph graph;
    printf("Enter number of cell phones in the graph :");
    int numberOfNodes;
    scanf("%d", &numberOfNodes);
    graph = buildEmptyGraphWithNodes(numberOfNodes);
    printf("Menu :-\n1. Add an edge in the current graph\n2. Print the Adjacent Matrix of Edges in the current graph\n");
    printf("3. Print Neighbours of a cell phone\n4. Exit\n");
    while(1) {
        printf("Enter Command :");
        scanf("%d", &command);
        if(command == 1) {
            int nodeA = -1, nodeB = -1;
            printf("Enter cell phone A and cell phone B (1 to %d)\n", numberOfNodes);
            while(nodeA > numberOfNodes || nodeA < 1) {
                printf("cell phone A :");
                scanf("%d", &nodeA);
            }
            while(nodeB > numberOfNodes || nodeB < 1) {
                printf("cell phone B :");
                scanf("%d", &nodeB);
            }
            addEdge(&graph, nodeA, nodeB);
        } else if(command == 2) {
            printEdgeAdjMatrix(graph);
        } else if(command == 3) {
            printf("Enter the cell phone number whose neighbour you want to see :");
            int node;
            scanf("%d", &node);
            printNeighboursOfNode(graph, node);
        } else if (command == 4) {
            exit(0);
        } else {
            printf("Invalid Command\n");
            continue;
        }
    }
}
