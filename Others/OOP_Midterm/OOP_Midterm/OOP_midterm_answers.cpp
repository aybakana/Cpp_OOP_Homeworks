#include <iostream>
#include <fstream>
using namespace std;

class Element
{
public:
  int row, col;
  float value;
  Element() {};
  Element(int r, int c, float v) : row(r),col(c), value(v) {};
};

class Compact
{
  friend void  operator <<(ostream&,  Compact&);
  int array_size;
  Element * Array;
  float get_value(int, int) const;
  void set_value(int, int, float);
  int max_rows, max_cols;

  public:
  Compact() {Array=NULL;array_size=0;max_rows=0; max_cols=0;};
  ~Compact() { if (Array) delete [] Array;};
  Compact(char *);          // constructor from filename
  Compact(const Compact &); // copy constructor
  Compact operator*(const Compact &);
};

Compact::Compact(char * filename)
{
  int i;

  // Initialize the array from data file.
  ifstream  dosya;
  dosya.open(filename);

  if (! dosya.is_open()) {
     cout << "File can not be opened!\n\n";
     return;
  }

  max_rows=0; max_cols=0;

  dosya >> array_size;
  Array = new Element[array_size];

  for (i=0; i<array_size; i++)
  {
      dosya >> Array[i].row >> Array[i].col >> Array[i].value;

      if (Array[i].row > max_rows)
         max_rows = Array[i].row;
      if (Array[i].col > max_cols)
         max_cols = Array[i].col;
  }


}

// Copy constructor
Compact::Compact(const Compact & M)
{
  array_size = M.array_size;
  max_rows = M.max_rows;
  max_cols = M.max_cols;
  Array = new Element[array_size];
  for (int i=0; i<array_size; i++)
      Array[i] = M.Array[i];
}

float Compact::get_value(int row, int col) const
{
  int k;
  for (k=0; k<array_size; k++)
      if (Array[k].row == row && Array[k].col == col)
         return Array[k].value;

  return 0; // not found
}

void Compact::set_value(int row, int col, float value)
{
  int k;
  for (k=0; k<array_size; k++)
      if (Array[k].row == row && Array[k].col == col)
      {
         Array[k].value = value;
         return; // Element found
      }

  // Element not found, so expand the Array by adding a new Element
  Element * tmp_Array = new Element[array_size+1];
  for (int i=0; i<array_size; i++)
      tmp_Array[i] = Array[i];
  delete [] Array; // Delete old array

  Array = tmp_Array; // Update new array
  Array[array_size] = Element(row, col, value); // add new item
  array_size++; // Increase the size
}


Compact Compact::operator*(const Compact & M)
{
  int i,j,k;
  float sum;

  Compact R; // Result matrix

  if (max_cols != M.max_rows)
  {
      cout << "Warning : Dimensions must be compatible for matrix multiplication!\n";
      return R;
  }

 // Compute the multiplication
    for (i = 0; i < max_rows; i++)
    {
        for (j = 0; j < M.max_rows; j++)
        {
            sum = 0;
            for (k = 0; k < max_cols; k++)
                sum += get_value(i,k) * M.get_value(k,j);

		    if (sum != 0)
               // Only nonzero values are stored
  		       R.set_value(i,j,sum);
        }

    }

  R.max_rows = max_rows;
  R.max_cols = M.max_cols;
  return Compact(R); // invoke copy-constructor
}

void  operator <<(ostream&   nesne,  Compact& M)
{
  int i,j;

  for (i=0; i < M.max_rows; i++)
  {
      for (j=0; j < M.max_cols; j++)
          nesne << M.get_value(i,j) << "\t";
      nesne << endl;
  }
  nesne << "------------------------------\n";
};


int main () {
  Compact M1("COMPACT1.TXT");
  Compact M2("COMPACT2.TXT");
  Compact M3 = M1*M2;

  cout << "M1=\n" << M1;
  cout << "M2=\n" << M2;
  cout << "M1*M2=\n" << M3;

  return 0;
}
