#include <stdio.h>
#define V 4
#define G 1

int isCoverVerteces(int* graph[] , int graph_N , int group[] , int group_N );
int isInGroup(int i , int j , int group[] , int group_N);


//Add edge. set arr[src][dest] = 1
void addEdge(int* arr[],int src, int dest)
{
     *(arr[src]+dest) = 1;
}


//print the adjMatrix
int main()
{
    int i;
    int arr[G] = {1};
    int *adjMatrix[V] ;
    for( i = 0 ; i < V ; i++){
      
    adjMatrix[i] = (int*)malloc(4*V) ;
    }
    
    for(i=0 ; i<V ; i++){
      for(int j=0 ; j<V ; j++){
        *(adjMatrix[i]+j) = 0;
      }
    }
    
    addEdge(adjMatrix,0,1);
    addEdge(adjMatrix,1,0);
    addEdge(adjMatrix,1,2);
    addEdge(adjMatrix,2,1);
    addEdge(adjMatrix,0,2);
    addEdge(adjMatrix,2,0);
    addEdge(adjMatrix,0,3);
    addEdge(adjMatrix,3,0);

    printf("khdjkghhdsfkjg  ::::  %d \n", isCoverVerteces( adjMatrix , V ,arr , G));

    return 0;
}


int isCoverVerteces(int* graph[] , int graph_N , int group[] , int group_N ){
    int i , j ;
    if( graph_N < 1 || group_N < 1) return 0;
    for( i = 0 ; i < graph_N ; i++ )
        for( j = i ; j < graph_N ; j++){
            if( *(graph[i]+j) == 1){
                if( !isInGroup( i , j , group , group_N ) ) return 0;
            }
        }
    return 1;
}

int isInGroup(int i , int j , int group[] , int group_N){
    int k;
    for( k=0 ; k<group_N ; k++ ) {
        if( i == group[k] || j == group[k]){
            return 1;
        }
    }
    return 0;
}