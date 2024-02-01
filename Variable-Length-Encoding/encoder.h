#ifndef ENCODER 
#define ENCODER

#include <vector> 
#include <cstdint>

class Encoder { 
public:
    static const int mask7 = 0b01111111;
    static const int mask1 = 0b00000001;

    static std::vector<int8_t> encode(int64_t ); 
    static int64_t decode(int8_t* );
    static void print(std::vector<int8_t> &);
}Encoder;

#endif // ENCODER
