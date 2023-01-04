#include "Propeller.h"
#include "Definitions.h"

class Motors
{
    private:
        Propeller propellers[PROPS];
    public:
        float idleOffset[PROPS] = {3, 3, 3, 3};
        float throttle;
        int k;
        float motorYpr[3];
        float outputsRead[4];
        bool Init();
        void Main();
        void Test();

};
