#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define trail 5
int contagion_constant=trail-1;
int iterations=10;

struct Person {
    
    float contagion_probability; 
    int status; // 0 healthy, 1 cured, 2 diseased, -1 dead
    int illness; // define some chronic disease, not chronic, doesn't hace illnes
    int time_left; //counter for time to be cured or death basen on the stats above 
    int x[trail];
    int y[trail];
};

int vertical_movement(){
	return rand()%2;
}

void move_trail(int n, int m,int grid[n][m], int population,
				struct Person person[population]){

	for (int i=0;i<population;i++){
		
		for (int j=trail-1;j>0;j--){
			person[i].x[j]=person[i].x[j-1];
			person[i].y[j]=person[i].y[j-1];
			grid[person[i].x[j]][person[i].y[j]]=contagion_constant-j;
			printf("%d:%d,%d\n", j, person[i].x[j],person[i].y[j]);
		}
	}
}
void move_points(int n, int m,int grid[n][m], int population,
				 struct Person person[population]){

	move_trail(n,m,grid,population,person);
	//move the point one place
	for (int i=0;i<population;i++){
		if (vertical_movement()){
			person[i].x[0]+=rand()%3-1;
		}
		else{
			person[i].x[0]+=rand()%3-1;
		}
		grid[person[i].x[0]][person[i].y[0]]=contagion_constant;
	} 
	//update the grid

}
void test(int population,struct Person person[population]){
	for (int i=0;i<population;i++){
		printf("%d\n",person[i].x[0]);
	}

}
void print_grid(int n,int m,int grid[n][m]){
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			printf("%d ",grid[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	srand(time(0));
	int n=10;
	int m=10;
	int grid[n][m];
	memset(grid, 0, sizeof(grid));
	
	int population=1;
	struct Person person[population];
	printf("%ld\n",sizeof(person)/sizeof(person[0]));
	
	for (int i= 0; i<population;i++){
		person[i].x[0]=rand()%n;
		person[i].y[0]=rand()%m;
		grid[person[i].x[0]][person[i].y[0]]=contagion_constant;
	}
	
	//we move the points
	for (int i=0;i<iterations;i++){
		sleep(1);
		move_points(n,m,grid,population,person);
		print_grid(n,m,grid);
		printf("\n");
	}

	
	
	//rand()% (65 + 1 - 0) + 0;

	

    return 0;
}
