#include <stdio.h>

int path_finder(int *map, char *dir, int dir_num,int row, int col){

    printf("\033[1;1H\033[2J");
    for(int i = 0; i < 9; i++){

        for(int j = 0; j < 9; j++){

        if((i == row)&&(j ==col)){
            if((*(map + 9 * i + j) != 2)){
                printf("\033[1;94m");
                printf("%c ", dir[dir_num]);
            }else printf("%d ", *(map + 9 * i + j));
        }
        else if(*(map + 9 * i + j) == 1){
            printf("\033[1;92m");
            printf("%d ", *(map + 9 * i + j));
        }
        else if(*(map + 9 * i + j) == 2){
            printf("\033[1;91m");
            printf("%d ", *(map + 9 * i + j));
        }
        else if(*(map + 9 * i + j) == 3){
            printf("\033[1;96m");
            printf("%d ", *(map + 9 * i + j));
        }
        else{
        
            printf("%d ", *(map + 9 * i + j));
        }

        printf("\033[0m");
        }printf("\n");
    }


    getchar();

    if((*(map + 9 * row + col) == 1)||*(map + 9 * row + col) == 2)return 0;

    if((row < 0) || (row > 8) || (col < 0) || (col > 8))return 0;

    if(*(map + 9 * row + col) == 3){
        printf("\nEND FOUND!");
        return 1;
    }

    *(map + 9 * row + col) = 1;


    
    return path_finder(map, dir, 0, row-1, col) ||
          path_finder(map, dir, 1, row, col + 1)||
          path_finder(map, dir, 2, row + 1, col)||
          path_finder(map, dir, 3, row, col-1);

}


int main(void){

    char dir[4] = {'^', '>', 'V', '<'};
    int map[9][9] = {
                    
        {0,0,0,0,2,0,0,0,0},
        {0,0,0,0,2,0,2,2,0},
        {0,0,2,0,2,0,0,2,0},
        {0,2,0,0,2,2,2,0,0},
        {0,2,0,2,2,0,0,0,0},
        {0,2,0,2,0,0,2,2,0},
        {0,0,2,2,0,0,2,0,0},
        {0,2,0,2,0,2,2,0,0},
        {0,0,0,0,0,2,3,0,0},
    };

    path_finder((int*)map, dir, 0, 0, 0);



}
