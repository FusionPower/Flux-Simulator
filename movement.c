#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include "person_struct.h"

int contagion_constant=trail-1;
int iterations=20;
//grid parameters
int n=20;
int m=30;
//population parameters
int population=50;
int initial_diseased=1;


void expand_radius(int grid[m][n], struct Person person[population]){
	for (int i = 0; i < population; ++i){
		if (person[i].status == 2){
			if (person[i].x[0] - 1 >= 0)
				grid[person[i].x[0] - 1][person[i].y[0]] = contagion_constant - 1;
			
			if (person[i].x[0] + 1 < n)
				grid[person[i].x[0] + 1][person[i].y[0]] = contagion_constant - 1;

			if (person[i].y[0] + 1 < m)
				grid[person[i].x[0]][person[i].y[0] + 1] = contagion_constant - 1;
		
			if (person[i].y[0] - 1 >= 0)
				grid[person[i].x[0]][person[i].y[0] - 1] = contagion_constant - 1;

			if (person[i].y[0] - 1 >= 0 && person[i].y[0] + 1 < m && person[i].x[0] - 1 >= 0 && person[i].x[0] + 1 < n){
				grid[person[i].x[0] - 1][person[i].y[0] - 1] = contagion_constant - 1;
				grid[person[i].x[0] - 1][person[i].y[0] + 1] = contagion_constant - 1;
				grid[person[i].x[0] + 1][person[i].y[0] - 1] = contagion_constant - 1;
				grid[person[i].x[0] + 1][person[i].y[0] + 1] = contagion_constant - 1;
					
			}	
			
		}
	}
}


void initialize_coordinates(int i,int grid[n][m], int population,
							struct Person person[population]){

	for (int j=1;j<trail;j++){ 
		person[i].x[j]=person[i].x[j-1];
		person[i].y[j]=person[i].y[j-1];		
	}
}
void initialize_population(int grid[n][m],struct Person person[population]){
		
	for (int i = 0; i<population;i++){
		person[i].x[0]=rand()%n;
		person[i].y[0]=rand()%m;
		initialize_coordinates(i,grid,population,person);
		if (i<initial_diseased){
			person[i].status = 2;
			grid[person[i].x[0]][person[i].y[0]] = contagion_constant;
					
		}
		else{
			person[i].status = 1;
			grid[person[i].x[0]][person[i].y[0]] = 1;		
		}

	}



}


void move_trail(int i,int grid[n][m], int population,struct Person person[population]){

		for (int j=trail-1;j>0;j--){
			person[i].x[j]=person[i].x[j-1];
			person[i].y[j]=person[i].y[j-1];
			grid[person[i].x[j]][person[i].y[j]]=contagion_constant-j;
			//printf("%d:%d,%d\n", j, person[i].x[j],person[i].y[j]);
		}
}


int new_coordinates(int x, int y,int *newx, int *newy){
	int movement=rand()%5;
	switch (movement){
		case 0:
			*newx=x;
			*newy=y;
			break;
		case 1:
			*newx=(x+1)%n;
			*newy=y;
			break;
		case 2:
			*newx=x-1;
			if (*newx<0)
				*newx=n-1;
			*newy=y;
			break;
		case 3:
			*newx=x;
			*newy=(y+1)%m;
			break;
		case 4:
			*newy=y-1;
			if (*newy<0)
				*newy=m-1;
			*newx=x;
			break;
	}
}

bool contagion(int square){
	//if contact is smaller that the square value, disease spreads
	int contact=rand()%contagion_constant;
	if (contact<square)
		return true;
	return false;
}

void move_points(int grid[n][m], int population,struct Person person[population],
				int *diseased,int *healthy){
	//solve points: getting on top of each other, no concentration zones.
	
	for (int i=0;i<population;i++){
		//get new coordinates	
		int newx,newy;
		new_coordinates(person[i].x[0],person[i].y[0],&newx,&newy);	
		if (person[i].status==2){
			//move the point one place to make space for new coordinates
			move_trail(i,grid,population,person);
			person[i].x[0]=newx;
			person[i].y[0]=newy;
			grid[person[i].x[0]][person[i].y[0]]=contagion_constant;
		}
		else{
			if (grid[person[i].x[0]][person[i].y[0]]==1)
				grid[person[i].x[0]][person[i].y[0]]=0;
			person[i].x[0]=newx;
			person[i].y[0]=newy;
			if (grid[person[i].x[0]][person[i].y[0]]==0)
				grid[person[i].x[0]][person[i].y[0]]=1;
			else{
				if(contagion(grid[person[i].x[0]][person[i].y[0]])){
					person[i].status=2;
					*diseased+=1;
					*healthy-=1;
				}
			}		
		}	
	} 
	//update the grid
}

void print_grid(int grid[n][m]){
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			printf("%d ",grid[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	srand(time(0));
	
	int grid[n][m];
	memset(grid, 0, sizeof(grid));
	
	struct Person person[population];
	//printf("%ld\n",sizeof(person)/sizeof(person[0]));
	initialize_population(grid,person);
	expand_radius(grid, person);
	print_grid(grid);
	//iterations
	int diseased=initial_diseased;
    int healthy=population-diseased;
	printf("diseased: %d,healthy: %d\n", diseased,healthy);
	for (int i=0;i<iterations;i++){
		sleep(1);
		move_points(grid,population,person,&diseased,&healthy);
		expand_radius(grid, person);
		print_grid(grid);
		printf("diseased: %d,healthy: %d\n", diseased,healthy);

	}

    return 0;
}
