# Program that calculates students results

## 1.0 version tests

#### 1st strategy (whole test time)
##### loop through all students check if result is above or below 5 and add to files accordingly
| Container | 1 000  | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
| --------- | ------:| ------:| -------:| ---------:| ----------:|
| vector    | 0.0303 | 0.0931 | 0.7135  | 8.1077    | 73.2763    |
| list      | 0.0213 | 0.0872 | 0.7848  | 9.4935    | 80.6039    |
#### 2nd strategy (whole test time)
##### sort students and find splitpoint, using that iterator split into 2 files
| Container | 1 000  | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
| --------- | ------:| ------:| -------:| ---------:| ----------:|
| vector    |        |        |         |           |            |
| list      |        |        |         |           |            |



## Speed tests (in seconds) - v0.3

### Reading data from file time
| Container | 1 000  | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
| --------- | ------:| ------:| -------:| ---------:| ----------:|
| vector    | 0.0017 | 0.0563 | 0.1825  | 1.8113    | 15.6419    |
| list      | 0.0022 | 0.0198 | 0.1709  | 1.9085    | 17.9368    |

### Student separation into 2 categories time (using average method)
| Container | 1 000  | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
| --------- | ------:| ------:| -------:| ---------:| ----------:|
| vector    | 0.0036 | 0.0366 | 0.4238  | 5.7179    | 54.9843    |
| list      | 0.0034 | 0.0406 | 0.5044  | 6.3049    | 63.9047    |

### Data output to files time
| Container | 1 000  | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
| --------- | ------:| ------:| -------:| ---------:| ----------:|
| vector    | 0.0035 | 0.0133 | 0.0871  | 0.7466    | 6.6629     |
| list      | 0.0034 | 0.0113 | 0.1242  | 0.9998    | 10.6156    |

#### Findings
From tests, we see LIST container has similar efficiency with VECTOR when reading files,
however when separating huge lists like 10 000 000 there is almost 10 seconds difference in speed.

#### Some examples of the tests
![alt text](<tests/Screenshot 2024-10-25 135841.png>)
![alt text](<tests/Screenshot 2024-10-25 151113.png>)

##### Time tests were made with this computer:
* Processor	AMD Ryzen 3 5300U with Radeon Graphics, 2600 Mhz, 4 Core(s), 8 Logical Processor(s)
* Installed Physical Memory (RAM)	16.0 GB
* DISK SSD
* OS Microsoft Windows 11 Home
