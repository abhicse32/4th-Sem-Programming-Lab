
  typedef struct Deap_ deap;
  struct Deap_{
      deap* parent ;
      int key;
      deap* left;
      deap* right;
  };
  
  typedef struct array_and_index{
      int *ar;
      int index;
}ar_ind;

  bool Check_max(int n);
 // bool Check_min(int n);
  void Insert_deap(int *, int );
  int Find_Min(int *arr, int );
  int Find_Max(int *arr, int );
  void Delete_Min(int *arr, int );
  void Delete_Max(int *, int);
  
