```c++
int a = 277 // stored in 32 bit integer
00000000 00000000 00000001 00010101
```
- 2 bytes are padded here
- by using variable length encoding we can store 277 in only 2 bytes

### Variable length encoding 
- In variable length encoding 277 is represented as
![image](https://github.com/Sat30/data_encoding_for_db/assets/101095981/f1769c9e-5b1f-456e-8f2b-c0a2ac0369b5)

- `Orange bits : bits of 277`  
- `Green bit : continuation bit` 
	- `1` indicate there is another `byte` following it. : `1xxx xxxx`
	- `0` indicate current byte is last `byte`. :  `0xxx xxxx`

So we can represent 277 in 2 bytes instead of 4 bytes

**Note :**
1. If integer data is 2 bytes, there is standard 2-byte int type in C++.
2. What If integer data is 6 bytes, no standard 6-byte int type in C++.
