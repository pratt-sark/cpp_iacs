//Problem 3 (i)
//Pratyay Sarkar

enum class TL { red, green, blue };
enum TS { red, yellow, green };

void f() 
{
    TL x = TL::green;
    TS y = TS::green;
    int ix;
    int iy;
    x = TL::red;
    x = red; // a value of type "TS" cannot be assigned to an entity of type "TL"
    x = 1; // a value of type "int" cannot be assigned to an entity of type "TL"
    x = y; // a value of type "TL" cannot be assigned to an entity of type "int"
    ix = TL::red; // a value of type "TL" cannot be assigned to an entity of type "int"
    y = TS::red;
    y = red;
    y = 1; // a value of type "int" cannot be assigned to an entity of type "TS"
    y = x; // a value of type "TL" cannot be assigned to an entity of type "TS"
    iy = red;
}