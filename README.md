#GPS Position Calculation


GPS Position Calculation is a command-line utility written in C. In this program, we're taking a text file with data of user's position and time and comparing to find the shortest distance relative to the user. This README provies a brief overview of how to use this program and what it returns. 



 ##Usage


```bash
./gps filename



To build the gps utility, follow these steps:
Ensure you have a C compiler installed on your system (e.g., GCC).
Compile the code using the provided source file:

```bash
gcc gps.c -o gps


Run the program with the appropriate command-line arguments (see "Usage" above).



##Sample Output

Name:Elijah
Latitude:100 
Longitude:100
Altitude:100
Time:4023.54
----------------------------

Reference User:
User Elijah:
Latitude: 100.00
Longitude: 100.00
Altitude: 100.00

List of other users:
User Aaron:
Latitude: 9794.17
Longitude: 6158.17
Altitude: 5196.34
User Baruch:
Latitude: 9554.21
Longitude: 2712.89
Altitude: 2764.86
User Conaniah:
Latitude: 3132.68
Longitude: 5914.01
Altitude: 7556.87
User Daniel:
Latitude: 2080.81
Longitude: 3152.68
Altitude: 8525.46
User Eliakim:
Latitude: 6763.31
Longitude: 5704.52
Altitude: 3535.88
User Felix:
Latitude: 6857.66
Longitude: 7575.19
Altitude: 1692.95
User Gideon:
Latitude: 7094.88
Longitude: 2108.39
Altitude: 7900.26
User Habakkuk:
Latitude: 8922.40
Longitude: 2447.50
Altitude: 4862.84
User Isaiah:
Latitude: 2476.16
Longitude: 3179.06
Altitude: 765.07
User Jacob:
Latitude: 8549.42
Longitude: 9346.85
Altitude: 1557.92

Actual distances from our user were:
User number: 0 at distance 12516.031205 named Aaron
User number: 1 at distance 10164.190066 named Baruch
User number: 2 at distance 9929.993477 named Conaniah
User number: 3 at distance 9177.736085 named Daniel
User number: 4 at distance 9360.321360 named Eliakim
User number: 5 at distance 10202.054887 named Felix
User number: 6 at distance 10667.991033 named Gideon
User number: 7 at distance 10297.093904 named Habakkuk
User number: 8 at distance 3945.765443 named Isaiah
User number: 9 at distance 12610.410936 named Jacob

Nearest user to reference user:
User Isaiah:
Latitude 2476.16
Longitude 3179.06
Altitude 765.07

