// 
// GenericOption.h

#ifndef __CppOptions__GenericOption__
#define __CppOptions__GenericOption__

#include <stdio.h>
enum OptionType { // Option types based on direction: call or put
    OptionType_Call,
    OptionType_Put
};
class GenericOption { // Class that represents a generic option
public:
    GenericOption(double strike, OptionType type, double cost); // Constructor
    GenericOption(const GenericOption &p); // Copy Constructor
    ~GenericOption(); // Destructor
    GenericOption &operator=(const GenericOption &p); //

    double valueAtExpiration(double underlyingAtExpiration);
    double profitAtExpiration(double underlyingAtExpiration);
private:
    double     m_strike;
    OptionType m_type;
    double     m_cost;
};

#endif /* defined(__CppOptions__GenericOption__)*/

