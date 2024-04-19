# ifndef Utils_H
# define Utils_H
# include <iostream>
# include <sstream>
# include <string>

using namespace std;

namespace UtilsLibrary
{
double lettura_val(string values);

pair <vector<double>, vector <double>> lettura_array(ifstream& ifstr);

double val_portfolio(double S,vector<double> arr1, vector<double> arr2);
}

# endif

