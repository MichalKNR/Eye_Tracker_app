# Eye_Tracker_server
Server application for eye tracker system for mobile robots control

# Comunication Flow

There are 3 different objects in program: Connection, Control and Robot. 

### Connection

Conection module is for TCP/IP connection in server role. It sends and receives given data in a form of a following frames, each frame type starts with it's own special character.

* Control
  * *Character:* '!'
* Telemetrics
  * *Character:* '@'
* Video Stream *TO BE DEVELOPED*
  * *Character:* '$'

##### Control frames

There are 3 control frames

* Enable/Disable movement permission - permission is lathed and confirmed

| Byte0 | Byte1 |
| ----- | ---- |
| '!' | permission [boolean] |


* Robot movement - *only accepting differential drive system*

| Byte0 | Byte1 | Byte2 |
| ----- | ---- | ---- |
| '!' | Left  | Rigth|

*Left* and *Right* are [-100 ; 100] meaning -100 is max value backward for side and 100 max value for one side. 
Coded as unsinged int, so 0 is read as -100 control value and 200 is 100 control value. 

* Manipulator movement - 3 axis

| Byte0 | Byte1 | Byte2 | Byte3 | Byte4 | Byte5 | Byte6 |
| ----- | ---- | ---- | ---- | ---- | ---- | ---- |
| '!' | axis 1 high | axis 1 low | axis 2 high | axis 2 low |axis 3 high | axis 3 low |

axis x high and axis x low are treated as unsinged int16 and are [0 ; 360], sent value is the exact desired angle.

#### Telemetrics

*TO BE DEVELOPED*

#### Video Stream

*TO BE DEVELOPED*
