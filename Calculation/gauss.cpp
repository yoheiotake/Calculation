#include<iostream>
using namespace std;

class Gaussian_Elimination{
private:
  const static int v_size = 4;
  const static int h_size = 5;
  double array[v_size][h_size];
  void forward(int v_pivot,int h_pivot);
  void backward(int v_pivot,int h_pivot);
  void answer();
public:
  Gaussian_Elimination(double *node);
  ~Gaussian_Elimination();
  void show();
  void eliminate();
};

Gaussian_Elimination::Gaussian_Elimination(double *node){
  for(int v=0,z=0; v < v_size; v++){
    for(int h=0; h < h_size; h++,z++){
      array[v][h] = node[z];
    }
  }
}

Gaussian_Elimination::~Gaussian_Elimination(){
  
}

void Gaussian_Elimination::show(){
  for(int v=0; v < v_size; v++){
    for(int h=0; h < h_size; h++){
      if(h == h_size-1) cout <<"|";
      cout << array[v][h] <<" ";
    }
    cout << endl;
  }
  cout << endl;
}

void Gaussian_Elimination::eliminate(){
  int v_pivot = 0;
  int h_pivot = 0;
  
  cout <<"-----Start Forward Elimination----- "<< endl;
  forward(v_pivot,h_pivot);

  cout <<"-----Start Backward Substitution----- "<< endl;
  backward(v_size-1,h_size-2);

  cout <<"-----Answer----- "<< endl;
  answer();
}

void Gaussian_Elimination::forward(int v_pivot,int h_pivot ){
  int v=v_pivot;
  int h=h_pivot;

  while(v < v_size-1){
    for(int layer = 1; layer < v_size ;layer++){
      for(double div_p=array[v][h],div_c=array[v+layer][h]; h < h_size ; h++){
	array[v+layer][h] -= array[v][h]/div_p*div_c;
      }
      h = h_pivot;
    }
    show();
    v++;
    h_pivot++;
    h = h_pivot;
  }
}

void Gaussian_Elimination::backward(int v_pivot,int h_pivot ){
  int v=v_pivot;
  int h=h_pivot;

  for(int layer=v; h > 0;h--,layer=v){
  
    for(double div_p=array[v][h];layer > 0;layer--){
      double div_c= array[v-layer][h];
      array[v-layer][h] -= array[v][h]/div_p*div_c;
      array[v-layer][h_size-1] -= array[v][h_size-1]/div_p*div_c;
    }
    show();
    v_pivot--;
    v=v_pivot;
  }
}

void Gaussian_Elimination::answer(){
  for(int n=0; n < v_size; n++){
    cout <<" x"<< n+1 <<" = "<< array[n][h_size-1]/array[n][n] << endl;
  }
}

int main(){
  double node[20]={1,2,-12,8,27,5,4,7,-2,4,-3,7,9,5,11,6,-12,-9,3,49};
  Gaussian_Elimination obj(node);
  obj.show();
  obj.eliminate();
  return 0;
}
