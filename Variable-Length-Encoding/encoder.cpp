// if i store 259 will only take 2 byte, not 4 byte

#include "encoder.h"
#include "bits/stdc++.h"
using namespace std;

vector<int8_t>  Encoder:: encode(int64_t n){
        vector<int8_t> bytes;
        int8_t i = 0;
        for(i = 0; i < 9; i++){
            int8_t mask = (i == 8)? mask1 : mask7;
            int8_t currByte = (n & mask) | 0b10000000;
            n = n >> 7;
            if(n == 0){
                currByte =  currByte &  mask7;// setting 8th bit 0
                bytes.push_back(currByte);
                break;
            }
            bytes.push_back(currByte);
        }
        return bytes;
}

int64_t Encoder::decode(int8_t* ptr){
    int8_t shifts = 0;
    int64_t ans = 0;

    while(true){
        int64_t currByte = (*ptr & mask7) ;
        currByte = currByte << shifts;
        ans = ans | (currByte);
        if(((*ptr >> 7) & 1) == 0){
            break;
        }
        ptr = ptr + 1;
        shifts += 7;
    }
    return ans ;
}

void Encoder::print(vector<int8_t> &bytes){
    cout << "Bytes: ";
    for(int i = 0; i < bytes.size(); i++){
        cout << static_cast<int>(bytes[i]) << " ";
    }
}


int main(){
    int64_t x;
    cin >> x; 
    vector<int8_t> bytes = Encoder.encode(x);
    Encoder.print(bytes);
    int xDecoded = Encoder.decode(bytes.data());
    cout << endl << "Decoded: "<< xDecoded << endl;
    if(x != xDecoded){
        cout << "Mismatch\n";
    }
    return 0;
}