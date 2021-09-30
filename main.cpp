// Kyaw Min Thu
#include <fstream> // file access
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//Functions
int count_line(string);


//Global Variables

void read_line(int line_count, string filename, vector<string> &line_data)
{
  ifstream dataIn(filename);	// defines an input stream for a data file
  int i = 0;
  string test;
  

  if (dataIn)
  {
    while(getline(dataIn, test, ','))
    {
      line_data.push_back(test);
      //cout << data[i] << endl;
      i++;
    }
  }
  return;

}


int main()
{
  string file_name = "catastrophe.txt";
  vector<string> line_data;
  
	int number_of_data = count_line(file_name);
  cout << "--" << number_of_data << "--" << endl;

  read_line(number_of_data, file_name,line_data);

  int i;
  for (i = 0; i < number_of_data; i++)
  {
    cout << line_data[i] << " | ";
    //cout << i << "   ";
    if((i)%5 == 4)
    {
      cout << endl;
      //cout << "Line" << endl;
    }
    
    
  }
	return 0;
}
//-----------------------------------
// Functions 
//-----------------------------------

int count_line(string filename)
{
  ifstream dataIn;	// defines an input stream for a data file	
	int line_count = 0;
	string line;
  dataIn.open(filename);
  if(dataIn)
  {
    while(getline(dataIn, line, ','))
    {
      line_count++;
      //cout << line << endl;
    }
    return line_count;
  }
  else
    cout << "Unable to open the file" << endl;
  dataIn.close();
  return 0;
}

//-----------------------------------
