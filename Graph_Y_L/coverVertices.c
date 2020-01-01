
typedef struct List_t{
    int status;
    struct List_t* next;
}List;


/* checking by linked list */
int isCoverVerteces(List* graph , int graph_N , int group[] , int group_N ){
    int i;
    int size = graph_N*graph_N;
    for(i = 0 ; i < size ; i++){
        if( graph->status == 1){
            if( !isInGroup( i/graph_N , i%graph_N , group , group_N ) ) return 0;
        }
        graph = graph->next;
    }
    return 1;
}

/* cheking by 2D array */
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

/*checking if the vertice is in the cover group */
int isInGroup(int i , int j , int group[] , int group_N){
    int k;
    for( k=0 ; k<group_N ; k++ ) {
        if( i == group[k] || j == group[k]){
            return 1;
        }
    }
    return 0;
}