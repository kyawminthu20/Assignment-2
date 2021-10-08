// Kyaw Min Thu
#include <fstream> // file access
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctype.h>
#include <bits/stdc++.h>

using namespace std;
//Functions
int count_line(string);



// for string delimiter
vector<string> split_string (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}


//Global Variables

void read_line(int line_count, string filename, vector<string> &line_data)
{
  ifstream dataIn;	// defines an input stream for a data file
  int i = 0, j = 0;
  string test;
  dataIn.open(filename);
  

  if (dataIn)
  {
    while(getline(dataIn, test))
    {
      line_data.push_back((test));
      //cout << data[i] << endl;
      i++;
    }
  }

  dataIn.close();
  return;

}

// function to change vector to string
string vector_to_string(vector<char> temp)
{
  string s;
  for(char c: temp){
        s.push_back(c);
      }
  return s;

};


//--------------------------------------

class Disaster
{
    // Access specifier
    public:
    vector<char> name, time, type, year, damage, death_no;
    string sname, stime, stype, syear, sdamage, sdeath_no;

  
    // Member Functions()
    string show_name()
    {
  
       return sname;
    }

    string show_time()
    {
       return stime;
    }

    string show_type()
    {
       return stype;
    }

    string show_year()
    {
       return syear;
    }

    string show_death_no()
    {
       return sdeath_no;
    }


};


//Function for year range
void look_up_year_range(int number_of_data,Disaster data[])
{

  int year, b_year, e_year;

        cout << "   Enter beginning year: ";
        cin >> b_year; 
        cout << "   Enter ending year: ";
        cin >> e_year;
  cout << "All Disasters between " << b_year << " and " << e_year << " :" << endl;
  for(int l = 0; l < number_of_data; l++)
  {
    stringstream geek(data[l].syear);
    geek >> year;
   
    //string sname, stime, stype, syear, sdamage, sdeath_no
    if(year >= b_year && year <= e_year)
    {
      cout << "   " << data[l].sname << endl;
    }
    

  }

  
}

void look_up_name(int number_of_data,Disaster data[]) 
{
  string s;
  vector<string> result;
  cin.ignore();
  cout << "   Enter a Disaster name: ";
  getline(cin,s);
  cout << s << endl;
  cout << number_of_data << endl;
  int count_result = 0;
  cout << "Years when disaster happened are: " << endl;
  for(int i=0; i < number_of_data; i++ )
  {
    cout << data[i].stype << "    " << data[i].syear <<  endl;
    cout << "----------------" << endl;
  
    if (data[i].stype .find(s) != string::npos) {
    cout <<  data[i].syear << endl;
    if(find(result.begin(), result.end(), data[i].syear) != result.end())
    {
      cout << "Not in the array" << endl;
      result.push_back(data[i].syear);
    }
    count_result++;
    }
  }

  for(int i=0; i < result.size(); i++)
  {
    cout << "result   ----" << endl;
    cout << result.at(i) << endl;
  }
  
  

  




}

void generate_summary(int number_of_data,Disaster data[])
{
  string f_output_name;
  cin.ignore();
  cout << "   Enter output file name: ";
  getline(cin,f_output_name);
  


  
}


int main()
{
  string file_name = "catastrophe.txt";   //file name
  vector<string> line_data;               // vector array to accept the data from reading the file
	int number_of_data = count_line(file_name); // called a function to open the file and count the data to use to construct the array class of data
  read_line(number_of_data, file_name,line_data); //Read the data and store it in the vector array with reference

  string comma_delim = ",";   // delimiter for the text
  Disaster data[number_of_data];  // declare class Disaster with the name Data[number_of_data]


//Read the data and store it in the object array
  for(int i=0; i < number_of_data; i++ )
  {
    vector<char> temp;
    temp.clear();
    for(int j= 0; j < line_data[i].size(); j++)
    {
      //remove double quote
      if (line_data[i][j] == '\"')
        line_data[i].erase(line_data[i].begin()+j);
      temp.push_back (line_data[i][j]);
    }
    string temp_string = vector_to_string(temp);
    vector<string> v;
    v.clear();
    v = split_string(temp_string,comma_delim);
    //int double_quote_position = v.find('\"');
    for(int k=0; k < v.size(); k++)
    {
      if(k == 0)
        data[i].sname = v[0];
      else if(k == 1)
        data[i].stype = v[1];
      else if(k == 2)
        data[i].syear = v[2];
      else if(k == 3)
        data[i].sdamage = v[3];
      else if(k == 4)
        data[i].sdeath_no = v[4];
    }
    //cout << endl;
  }
  
  

// Menu 
  int c = 0;
  char s, f_output_name;
  while(c != 1 && c != 2 && c != 3)
  {
    cout << endl; 
    cout << "What would you like to do?" << endl;
    cout << "   1: Look up year range" << endl; 
    cout << "   2: Look up disaster"  << endl;
    cout << "   3: Generate summary report" << endl << endl;
    cout << "Select an option : " ;
    cin.clear();
    cin >> s;
    cout << isalpha(s) << endl;

    if(isdigit(s))
      cout << "Enter Integer" << endl;
    }
    else
    {
      
      switch(c)
      {
        case 1:
          look_up_year_range(number_of_data,data);
          break;
        
        case 2:
          look_up_name(number_of_data,data);
          break;
        
        case 3:
          generate_summary(number_of_data, data);
          break;
        
        default :
          cout << "Invalid input" << endl;
          break;
      }
      c = 0;


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
    while(getline(dataIn, line))
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
