HostString
    [mode]/[datasize]/[data] [data] ...


Modes (int):
    1   Manual flyMode
    2   Automatic flyMode
    3   PID Tuning
    4   Idle
    5   Switch log level -> Selection parameter

Selection (int):
    optional indicator to indicte which parameter is being tuned

Data (float):
    number of data points being sent form the hostComm separated by spaces
    data is being saved in a data array 

eg: 
    3/2/1.2 0.1 0.03

    3: operation mode = PID Tuning
    2: indicator for controller [2] = roll
        [0]=yaw  [1]=pitch  [2]=roll
    1.2 0.1 0.03: PID values for Kp, Ki, Kd respectively


MPU Details
yaw pitch roll
 -1.6 -> 1.6 
 3.2 tics / 180°


PROP Details
0 - 1000
