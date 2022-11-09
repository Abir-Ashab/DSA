#include <stdio.h>

const int max_size = 7;

int G[max_size][max_size];
char C[max_size];
int Lev[max_size];
int par[max_size];
int path[max_size];



int main()
{
    int edgeCount;
    scanf("%d",&edgeCount);
    for (int i = 0; i < edgeCount; ++i) {
        int u, v;
        scanf("%d%d",&u,&v);

        G[u][v] = 1;
    }

    int sourceNode;
     scanf("%d",&sourceNode);
     path[0]=sourceNode;
    //step-1-initialization
    for (int i = 0; i < max_size; ++i) {
        C[i] = 'w';
        Lev[i] = 99999999;
        par[i] = -1;
    }

    //step-2
    int Queue[max_size];
    int startP, endP ,j=1;
    startP = 0;
    endP = 0;
    Queue[endP] = sourceNode;
    
    endP = endP + 1;
    C[sourceNode] = 'g';
    Lev[sourceNode] = 0;
    par[sourceNode] = -1;

    while (endP - startP > 0) {
        int u = Queue[startP];  
              
        for (int i = 0; i < max_size; ++i) {
            int v = i;
            if (G[u][v] == 1 && C[v] == 'w') {
                path[j]=v;
                Queue[endP] = v;
                endP = endP + 1;
                C[v] = 'g';
                Lev[v] = Lev[u] + 1;
                par[v] = u;
                j++;
            }
        }
        startP = startP + 1;
        C[u] = 'b';
    }

    for (int i = 0; i < max_size; ++i) {
       printf("Level[%d] =%d \n",i,Lev[i]);
       printf("Parent[%d] =%d \n",i,par[i]);
       printf("color[%d] =%c \n",i,C[i]);
       printf("\n");
    }
    //printing path
    printf("\nPath of the BFS is :\n");
    for(int i=0;i<max_size-1;i++){
        printf("%d->",path[i]);
    }
    printf("Finish\n");
    int v;
    printf("For which element do want its shortest path?\n");
    scanf("%d",&v);
    
    printf("Shortest path:");
    while (v != sourceNode) {
    printf("%d->",v);
    v = par[v];
    }
    printf("%d\n",sourceNode);


}

/*
6
5 2
6 1
5 3
1 3
1 4
4 2
5
*/
