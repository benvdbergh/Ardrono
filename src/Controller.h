class PID
{
    private:
        float err;
        float mem_I_out;
        float mem_err;
    
    public:
        float Kp = 3;
        float Ki = 0;
        float Kd = 2;
    
        float Regulate(float sensVal, float setPoint);
};

class Controller
{
    public:
        PID yawController;
        PID pitchController;
        PID rollController;
        PID throtController;
        PID controllers[4] = {yawController, pitchController, pitchController, throtController};

        void Init();
        void YprController(float setPoint[], float sensYpr[], float motorYpr[]);
        void ThrottleController(float setPoint, float sensVal, float &motorThrottle);
        void AxisController();
        void Tune(int nr, float param[]);
        void TunePitchRoll(float param[]);
        void TuneThrottle(float param[]);
};