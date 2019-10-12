# Data_Logger
Console Application co-developed with an environment test chamber to log test data sent over COM port(s).

******************************************************************************************************************************************
@Author 
 Chahbaz Aman
@Brief
 The application establishes communication over a set COM port and stores the received data in a CSV file in a set destination.
@Detailed
 The application was developed specifically to log data sent over a USB or Bluetooth port. Data received is assumed to be of string type 
 and all data are processed as CSV strings. 
 Currently the COM port is set as COM5. Automatic port identification facility will be added later.
 Data is logged into a file named DataLog. 
  Note: Destination of the file is currently fixed to C:/Users/Asus/Documents/Thermal Chamber/DataLog.csv
        Additional functionality to select the destination will be added later.
  Important: If a second data logging session is started without renaming the previous log file, the previous file will be overwritten.

*****************************************************************************************************************************************
 
