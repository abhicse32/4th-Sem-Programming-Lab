
#include<string>
using namespace std;

typedef struct Skew_H {
     //struct Skew_H* parent;
     int data;
     struct Skew_H *left;
     struct Skew_H *right;
}SK_H;
typedef struct array_and_index{
      int *ar;
      int index;
}ar_ind;


ar_ind* string_to_int_array(string& str);

SK_H* SK_H_Create_Node(int num);
SK_H* SK_H_Merge(SK_H*, SK_H*);
SK_H* SK_H_Insert(SK_H*, int data);
SK_H* SK_H_DeleteMax(SK_H*);
