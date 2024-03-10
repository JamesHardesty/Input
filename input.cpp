/****************************
    Coded by James Hardesty
    template class Input
    version 1
    Feb. 17, 2024
****************************/

#include <iostream> 
#include <string>
using namespace std;

template <typename T>
class Input {
private:
    T input;
    int size;
public:
    Input() : input(nullptr), size(0) {}
    ~Input() {};
    Input(const T& type);
    /*Input(const T& type) {
        if (input != type)
        {
            size = sizeof(type);
            input = type;
        }
    }*/
    Input(const Input& obj);
    /*Input(const Input& obj) {
        if (this != &obj)
        {
            size = sizeof(obj.input);
            input = obj.input;
        }
    }*/
    string& operator = (const T& str)
    {
        if (input == str) return input;
        size = sizeof(str);
        input = str;
        return input;
    }
    T& operator = (const Input& obj)
    {
        if (input == &obj.input) return *this;
        size = sizeof(obj.input);
        input = obj.input;
        return *this;
    }
    T& operator = (Input& obj)
    {
        if (input == obj.input) return input;
        size = sizeof(obj.input);
        input = obj.input;
        return input;
    }
    std::string& operator () (std::string& s)
    {
        if (*this == s) return input;
        input = s;
        size = sizeof(s);
        return input;
    }

    const std::string& operator () (const std::string& s)
    {
        if (*this == s) return input;
        input = s;
        size = sizeof(s);
        return input;
    }

    T& operator () (Input& obj)
    {
        if (input == obj.input) return input;
        size = sizeof(obj.input);
        input = obj.input;
        return input;
    }

    const T& operator () (const Input& obj)
    {
        if (input == obj.input) return input;
        size = sizeof(obj.input);
        input = obj.input;
        return input;
    }

    const bool operator == (Input& obj)
    {
        if (input == obj.input) return true;
        return false;
    }
    const bool operator == (const Input& obj)
    {
        if (input == obj.input) return true;
        return false;
    }
    std::ostream& operator << (std::ostream& os)
    {
        return os;
    }
    void show();
    const T& getinput() const;
    const int& getsizeof() const;
};
template <typename T>
Input<T>::Input(const T& type)
{
    if (input != type)
    {
        size = sizeof(type);
        input = type;
    }
}

template<typename T>
Input<T>::Input(const Input& obj)
{
    if (this != &obj)
    {
        size = sizeof(obj.input);
        input = obj.input;
    }
}

template <typename T>
void Input<T>::show() { std::cout << input; }

template <typename T>
const T& Input<T>::getinput() const { return input; }

template <typename T>
const int& Input<T>::getsizeof() const { return size; }

int integer_operations(const int& int_number)
{
    return int_number * int_number;
}

const int getlength(const string& str)
{
    //const char* p = str.c_str();    return strlen(p);
    return str.length();
}

bool validate_integer_input(const std::string& str)
{
    bool valid = true;
    int i = 0;
    while (valid && i < str.length())
    {
        if (!isdigit(str.at(i)))
        {
            valid = false;
        }
        i++;
    }
    return valid;
}

bool validate_fractional_input(const std::string& str)
{
    bool valid = true;
    bool isPoint = false;
    int i = 0;
    while (valid && i < str.length())
    {
        if (!isdigit(str.at(i)))
        {
            if (str.at(i) == '.')
                isPoint = true;
            else
                valid = false;
        }
        i++;
    }
    if (valid && isPoint)
        return true;
    return false;
}

bool validate_float_number(const std::string str)
{
    return false;
}

int main() {
    std::string str1;
    std::cout << "\nEnter data below." << endl;
    std::getline(std::cin, str1);
    std::cout << endl;
    for (auto& n : str1) {
        std::cout << "[" << n << "] ";
    }
    std::cout << endl << "Length:" << str1.length() << endl;
    Input <std::string> input1(str1);
    std::cout << "\ninput1(str) => " << input1.getinput();

    std::string str2 = "Sample 2";
    Input <std::string> input2 = str2;
    std::cout << "\ninput2 = str2 = " << input2.getinput();
    input1 = input2;
    std::cout << "\ninput1 = input2 => " << input1.getinput();

    bool eqbool = input1 == input2;
    std::cout << "\ninput1 size = " << input1.getsizeof();
    std::cout << "\neqbool {" << eqbool << "}";

    Input<std::string>input3(input1);
    std::cout << "\ninput3(input1) => " << input3.getinput();

    std::string str4 = "chained assignment";
    input1 = input2 = input3 = str4;
    std::cout << "\ninput1 => " << input1.getinput();

    std::string str5 = "chained composite";

    Input<std::string>input4(input1(input2(input3(str5))));
    std::cout << "\ninput4 => " << input4.getinput();

    std::cout << "\n\nEnter a number below.\n";
    std::string strNumber;
    std::getline(std::cin, strNumber);
    bool isInteger = validate_integer_input(strNumber);
    std::cout << "isInteger = " << isInteger;
    if (isInteger) // number test 
    {
        int inumber = std::stoi(strNumber);
        Input <int> int_input(inumber);
        std::cout << "\nInteger now at = " << integer_operations(int_input.getinput());
    }
    else
    {
        double rnumber = std::stod(strNumber);
        std::cout << "\nRational number now at = " << rnumber * rnumber;
    }
    bool isFractional = validate_fractional_input(strNumber);
    std::cout << "\nisFractional = " << isFractional << '\n';
    return 0;
}

