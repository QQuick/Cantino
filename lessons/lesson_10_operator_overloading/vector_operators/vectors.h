#include <cantino.h>

using namespace cantino;

class Vector {
    friend SerialStream &operator<< (SerialStream &serialStream, Vector &vector);
    
    public:
        static int const size = 3;

        Vector ();
        Vector (float x, float y, float z);
        Vector (float components [size]);
        Vector (Vector &vector);        
        Vector (Vector &&vector);
        float &operator[] (int index);
        Vector operator+ (Vector &vector);
        Vector &operator= (Vector const &vector);

    private:
        float components [size];
};

extern SerialStream &operator<< (SerialStream &serialStream, Vector &vector);  

