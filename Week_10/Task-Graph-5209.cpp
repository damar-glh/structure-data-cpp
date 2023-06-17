#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int matrix[MAX_SIZE][MAX_SIZE];
int temp_vertex;
char name_vertex[MAX_SIZE];
bool nolsemua;

void buildMatrix() {
    for (int i = 1; i <= temp_vertex; i++) {
        for (int j = 1; j <= temp_vertex; j++) {
            matrix[i][j] = 0;
        }
    }
}

void insertMatrixUndirected() {
    int temp_edge, source, objective;
    cout << " Jumlah vertex: ";
    cin >> temp_vertex;
    cout << " Jumlah tepi: ";
    cin >> temp_edge;
    cout << "--------------------------------- \n";
    for (int i = 1; i <= temp_vertex; i++){
    	cout << " Nama Vertex - [" << i << "] : ";
    	cin >> name_vertex[i];
	}
	cout << "--------------------------------- \n";
	for (int i = 1; i <= temp_edge; i++) {
        cout << " Vertex sumber " << i << ": ";
        cin >> source;
        cout << " Vertex tujuan " << i << ": ";
        cin >> objective;
        matrix[source][objective] = 1;
        matrix[objective][source] = 1;
    }
}

void insertMatrixDirected() {
    int temp_edge, source, objective;
    cout << " Jumlah vertex: ";
    cin >> temp_vertex;
    cout << " Jumlah tepi: ";
    cin >> temp_edge;
    cout << "--------------------------------- \n";
    for (int i = 1; i <= temp_vertex; i++){
    	cout << " Nama Vertex - [" << i << "] : ";
    	cin >> name_vertex[i];
	}
	cout << "--------------------------------- \n";
    for (int i = 1; i <= temp_edge; i++) {
        cout << " Vertex sumber " << i << ": ";
        cin >> source;
        cout << " Vertex tujuan " << i << ": ";
        cin >> objective;
        matrix[source][objective] = 1;
    }
}


void insertMatrixWeighted() {
    int temp_edge, source, objective, weight;
    cout << " Jumlah tepi: ";
    cin >> temp_edge;
    for (int i = 1; i <= temp_edge; i++) {
        cout << " Vertex sumber " << i << ": ";
        cin >> source;
        cout << " Vertex tujuan " << i << ": ";
        cin >> objective;
        cout << " Weight " << i << ": ";
        cin >> weight;
        matrix[source][objective] = weight;
        matrix[objective][source] = weight;
    }
}

void traversingGraph() {
    int i = 1;
    bool ketemu;
    nolsemua = false;
    while (i <= temp_vertex && !nolsemua) {
        int j = 1;
        ketemu = false;
        while (j <= temp_vertex && !ketemu) {
            if (matrix[i][j] != 0) {
                ketemu = true;
            } else {
                j++;
            }
        }
        if (!ketemu) {
            nolsemua = true;
        } else {
            i++;
        }
    }
}

void printUndigraph() {
    if (nolsemua == true) {
        cout << " Graph not connected." << endl;
    } else {
    	cout << "--------------------------------- \n";
        cout << " Garis yang dapat dibentuk : ";
        for (int i = 1; i <= temp_vertex; i++) {
        for (int j = 1; j <= temp_vertex; j++) {
            if (matrix[i][j] != 0) {
                cout << name_vertex[i] << name_vertex[j] << ",";
            }
        }
    }
  }
}

void printDigraph(){
	if (nolsemua == false) {
        cout << " Graph not connected." << endl;
    } else {
    	cout << "--------------------------------- \n";
        cout << " Garis yang dapat dibentuk : ";
        for (int i = 1; i <= temp_vertex; i++) {
        for (int j = 1; j <= temp_vertex; j++) {
            if (matrix[i][j] != 0) {
                cout << name_vertex[i] << "->"<< name_vertex[j] << ",";
            }
        }
    
    }
  }
}

int main() {
    int choice;
    menu:
    cout << "============ Graph ============== \n\n";
    cout << " Menu Graph : \n";
    cout << " 1. Undirected Graph \n";
    cout << " 2. Directed Graph \n";
    cout << " 3. Weighted Graph \n";
    cout << " 4. Selesai \n";
    cout << "--------------------------------- \n";
    cout << " Masukkan pilihan Anda : ";
    cin >> choice;

    switch(choice) {
        case 1:
            system("cls");
            cout << "======= Undirected Graph ========= \n";
            buildMatrix();
            insertMatrixUndirected();
            traversingGraph();
            printUndigraph();
            break;
        case 2:
            system("cls");
            cout << "======= Directed Graph ========= \n";
            buildMatrix();
            insertMatrixDirected();
            traversingGraph();
            printDigraph();
            break;
        case 3:
            system("cls");
            cout << "======= Weighted Graph ========= \n";
            buildMatrix();
            insertMatrixWeighted();
            traversingGraph();
//            print();
            break;
        case 4:
            return 0;
        default:
            cout << "Pilihan tidak tersedia!\n";
            goto menu;
    }

    return 0;
}

