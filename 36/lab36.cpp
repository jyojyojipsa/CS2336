// CS 2336
// Lab 36
// Kangmin Kim

#include <lab36.h>
#include <iomanip>
  // Overloaded output operator - displays the two-dimensional matrix
  // data of spiral row-by-row to output stream out.  The columns of
  // the display should align on the right, and there should be one
  // space separating the columns.  The columns should all be of the
  // same width, equal to the width of the largest element.
ostream& operator<<(ostream& out, const Spiral& spiral)
{	
	int width = to_string(spiral.data.rows() * spiral.data.rows()).length();
	
	for(int i = 0; i < spiral.data.rows(); i++)
	{
		for(int j = 0; j < spiral.data.rows(); j++)
		{
			if(j == spiral.data.rows()-1)
				out << setw(width) << right << spiral.data[i][j];
			else
				out << setw(width) << right << spiral.data[i][j] << " ";
		}
			out << "\n";
	}	

   return out;
}


 
   // Member function Initialize resizes the two-dimensional matrix
  // data to be n rows by n columns and then initializes each element
  // to 0
 void Spiral::initialize(int n)
 {
	 data.resize(n, n);
 }

  // Populates the two-dimensional matrix data as described in the lab
  // handout
 void Spiral::build()
 {
	 int n = data.rows();
	 int r = -1, c = -1, k = 1;

	  while(k <= n * n)
	  { 
		  r++;
		  c++;
		  // Go east
		  while((c < n) && (data[r][c] == 0))
		  {
			  data[r][c] = k;
			  k++;
			  c++;
			
		  }
			c--; 
			r++;
		  // Go south
		  while((r < n) && (data[r][c]) == 0)
		  {
			  data[r][c] = k;
			  k++;
			  r++;

		  }
		  r--;
		  c--;
		  // Go west
		 while((c > -1) && (data[r][c] == 0))
		 {
			 data[r][c] = k;
			 k++;
			 c--;

		 }
		 c++;
		 r--;
		  // Go north
		 while((r > 0) && (data[r][c] == 0))
		 {
			data[r][c] = k;
			k++;
			r--;
		 }
		 
	  }
}

