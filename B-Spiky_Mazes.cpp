#include <iostream>
using namespace std;

bool possible(short int m, short int n, short int A, char** maze, bool** marked, short int s_r, short int s_c){
	if(A<0 || s_r<0 || s_r>=m || s_c<0 || s_c>=n || maze[s_r][s_c] == '#' ) 
        return false;
    if(maze[s_r][s_c] == 'x' ) 
        return true;
    if(maze[s_r][s_c] == 's')
        A = A-1;    
	
	if(!marked[s_r][s_c]){
	    marked[s_r][s_c] = true;

	    if(possible(m, n, A, maze, marked, s_r+1, s_c)) 
            return true;
	    if(possible(m, n, A, maze, marked, s_r-1, s_c)) 
            return true;
	    if(possible(m, n, A, maze, marked, s_r, s_c+1)) 
            return true;
	    if(possible(m, n, A, maze, marked, s_r, s_c-1)) 
            return true;

	    maze[s_r][s_c]= '#';
	    marked[s_r][s_c] = false;
    }
	return false;
}
int main() {
    short int m, n, avoids;
	short int start_r, start_c;
    char curr;
	cin >> m >> n >> avoids;
    char** maze;
    bool** marked;
    maze = new char*[m];
    marked = new bool*[m];

	for(short int i=0; i<m; i++){
        maze[i] = new char[n];
        marked[i] = new bool[n];
		for(short int j=0; j<n; j++){
			cin >> curr;
            maze[i][j] = curr;
            marked[i][j] = false;
			if(maze[i][j] == '@'){
				start_r = i;
				start_c = j;
			}			
		}	
	}

    short int half_A = avoids/2;
	if(possible(m, n, half_A, maze, marked, start_r, start_c))
	    cout << "SUCCESS" << "\n";
	else
	    cout <<"IMPOSSIBLE"<< "\n";

    for(short int i=0; i<m; i++){
        delete[] maze[i];
        delete[] marked[i];
    }
    delete[] maze;
    delete[] marked;

	return 0;
}
