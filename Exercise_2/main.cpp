# include <iostream>
# include <fstream>
# include <sstream>
# include <cmath>
# include <iomanip>
# include <vector>
# include "Utils.hpp"
using namespace std;

int main()
{
    string nameFileInput = "data.csv";
    ifstream ifstr(nameFileInput);
    string nameFileOutput = "result.txt";
    ofstream ofs(nameFileOutput);

    if (!ifstr.is_open())
    {
        std::cerr << "Error in opening input file" << std::endl;
        return 1;
    }

    if (ofs.fail())
    {
        std::cerr << "Error in opening output file" << std::endl;
        return 2;
    }


    string sum;
    getline(ifstr,sum);
    double val = UtilsLibrary::lettura_val(sum);

    string number;
    getline(ifstr,number);
    double num = UtilsLibrary::lettura_val(number);

    ofs << sum[0] << " = " << fixed << setprecision(2) << val << ", "<< setprecision(0) << number[0] << " = " << num << endl;
    cout << sum[0] << " = " << fixed << setprecision(2) << val << ", " << setprecision(0) << number[0] << " = " << num << endl;


    auto vettori = UtilsLibrary::lettura_array(ifstr);
    vector<double> w = vettori.first;
    vector<double> r = vettori.second;

    ofs << "w = [ ";
    cout << "w = [ ";
    for (double numero : w) {
        ofs << fixed << setprecision(2) << numero << " ";
        cout << fixed << setprecision(2) << numero << " ";
    }
    ofs << "]" << endl;
    cout << "]" << endl;


    ofs << "r = [ ";
    cout << "r = [ ";
    for (double numero : r) {
        ofs << fixed << setprecision(2) << numero << " ";
        cout << fixed << setprecision(2) << numero << " ";
    }
    ofs << "]" << endl;
    cout << "]" << endl;


    double final_portfolio = UtilsLibrary::val_portfolio(val, w, r);
    double rate_portfolio = final_portfolio/val -1;
    ofs << "Rate of return of the portfolio: " << fixed << setprecision(4) << rate_portfolio << endl;
    cout << "Rate of return of the portfolio: " << fixed << setprecision(4) << rate_portfolio  << endl;

    ofs << "V: " << fixed << setprecision(2) << final_portfolio << endl;
    cout << "V: " << fixed << setprecision(2) << final_portfolio << endl;


    ifstr.close();
    ofs.close();

    return 0;
}
