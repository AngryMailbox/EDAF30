#ifndef NOCOPY_H
#define NOCOPY_H
#include <stdexcept>


/* A class that behaves like an int but cannot be copied. 
 * Intended to be used for verifying that operations on
 * containers do not cause copying.
 * */
class NoCopy{
public:
    NoCopy() =default;
    NoCopy(int x) :val(x) {}
    NoCopy(const NoCopy&) {throw std::runtime_error("NoCopy cannot be copy constructed");}
    NoCopy& operator=(const NoCopy&) {throw std::runtime_error("NoCopy cannot be copy assigned");}
    operator int() const {return val;}
private:
    int val{0};
};


#endif

