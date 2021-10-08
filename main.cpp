// Kyaw Min Thu
#include <fstream> // file access
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctype.h>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
//Functions
int count_line(string);

// for string delimiter
vector<string> split_string (string s, string delimiter) 
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) 
    {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}


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
  cout << endl << "All Disasters between " << b_year << " and " << e_year << " :" << endl;
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
  result.clear();
  cin.ignore();
  cout << "   Enter a Disaster name: ";
  getline(cin,s);
  //cout << s << endl;
  //cout << number_of_data << endl;
  int count_result = 0;
  cout << endl;
  cout << "   Years when disaster happened are: " ;
  for(int i=0; i < number_of_data; i++ )
  {
    //cout << data[i].stype << "    " << data[i].syear <<  endl;
    //cout << "----------------" << endl;
  
    if (data[i].stype .find(s) != string::npos) 
    {
      //cout <<  data[i].syear << endl;
      //result.push_back(data[i].syear);
      
      if(find(result.begin(), result.end(), data[i].syear) != result.end())
      {
        //cout << "added" << endl;
      }
      else
      {
        //cout << "Not in the array" << endl;
        result.push_back(data[i].syear);
      }
      count_result++;
    }
    //cout << endl;
  }
  //cout << result.size() << endl;

      for (auto k = 0; k < result.size(); k++)
      {
        cout << result[k];
        if (k < (result.size()-1))
          cout << ", ";
      }
    
    cout << endl << endl;


}

void generate_summary(int number_of_data,Disaster data[])
{
  string f_output_name;
  vector<vector<string>> result;
  vector<string> year;
  cin.ignore();
  cout << "   Enter output file name: ";
  getline(cin,f_output_name);


  ofstream myfile;
  myfile.open (f_output_name);
  
  double n=1;
  int colWidth=15;

// get unique Year
  for(int i = 0; i < number_of_data; i++)
  {
    //cout << data[i].syear << endl;
    if(find(year.begin(), year.end(), data[i].syear) != year.end())
    {
        //cout << data[i].syear << "  added" << endl;
    }
    else
    {
        //cout << data[i].syear << "  Not in the array" << endl;
        year.push_back(data[i].syear);
    }
    //cout << year.size() << endl;
  }
// Gather List of Disaster
int year_count = 0;
vector<string> list_of_disaster;
int yearly_death[year.size()];

//Outermost loop is for all unique year

  for (int d = 0; d < year.size(); d++)
  {
    string s ="";
    int d_no = 0;
    yearly_death[d] = 0;

    //This loop is for all data

    for(int c = 0; c < number_of_data; c++)
    {
      string searchstring = data[c].stype;
      
      // checking year and appending it to the string to display
      if(year[d] == data[c].syear)
      {

        size_t found = s.find(searchstring);

        if (s.empty())
        {
          s = s + data[c].stype;
        }
        else if(found!=std::string::npos)
            s = s;
        else
            s = s + ", " + data[c].stype;
      

        stringstream geek(data[c].sdeath_no);
        geek >> d_no;

        yearly_death[d] = yearly_death[d] + d_no;

      }
    }
    //cout << s << endl;
    //cout << yearly_death[d] << endl;
    list_of_disaster.push_back(s);
  }

  myfile << "Years; Disasters;  Total deaths" << endl;

  for(int d = 0; d < year.size(); d++)
  {
    myfile << year[d] << "; " << list_of_disaster[d] << "; " << yearly_death[d] << "." << endl;

  }

    myfile.close();
  
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
  string s, f_output_name;
  while(c != 1 && c != 2 && c != 3)
  {
    cout << endl; 
    cout << "What would you like to do?" << endl;
    cout << "   1: Look up year range" << endl; 
    cout << "   2: Look up disaster"  << endl;
    cout << "   3: Generate summary report" << endl;
    cout << "   x: To exist from the program" << endl << endl;
    cout << "Select an option : " ;
    cin.clear();
    cin >> s;


    // Quit the program
    if(s == "x" || s == "X")
    {
      return 0;
    }

    stringstream geek(s);
    geek >> c;
    
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
        cout << endl << "     **Invalid input**" << endl;
        cout << endl << "     **Enter (1 or 2 or 3) and x for exit**" << endl;
        break;
    }
    c = 0;
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
