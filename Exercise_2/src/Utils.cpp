# include "Utils.hpp"
# include <vector>
# include <fstream>
# include <sstream>
# include <string>
# include <iostream>

using namespace std;

namespace UtilsLibrary{

double lettura_val(string values){
    istringstream convert(values);
    double val = 0;
    char digit;
    bool punto_virgola = false;

    while(convert >> digit)
    {
        if(digit == ';')
        {
            punto_virgola = true;
            continue;
        }
        if(punto_virgola){
            val = val * 10 + (digit - '0');
        }
    }
    return val;
}

pair <vector<double>, vector <double>> lettura_array(ifstream& ifstr){
    vector<double> w_values;
    vector<double> r_values;
    string line;

    int i = 0;

    while (getline(ifstr, line)){
        i ++;
        if(i>1)
        {
            stringstream convert(line);
            string digit;
            getline(convert, digit, ';');
            w_values.push_back(stod(digit));
            getline(convert, digit, ';');
            r_values.push_back(stod(digit));
        }  
    }
    return make_pair(w_values, r_values);
}

double val_portfolio(double S,vector<double> arr1, vector<double> arr2)
{
    unsigned int length = arr1.size();
    double dot_prod = 0;
    for(unsigned int i=0 ; i < length; i ++)
    {
        dot_prod += S*(arr1[i])*(1 + arr2[i]);
    }
    return dot_prod;
}
}

