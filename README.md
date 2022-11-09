# Welcome to talk-cpp :smile:
---
### description :heart:
This Repository about study and communication cpp.

### scope :rainbow:
- cpp grammar
- cpp stl
- cpp 11 or latest
- cpp library

### comment
You can creat issue to open a new question.

### build project
#### windows + visual studio 2019 
**according to visual studio version config**
1. git clone https://github.com/hummingo/talk-cpp.git
2. mkdir build
3. cd build
4. cmake -G "Visual Studio 16 2019" -A x64 ..
5. cmake --build . --config Debug -v
6. open talk-cpp.sln
7. set talk-cpp as startup project

#### linux + gcc/g++
1. git clone https://github.com/hummingo/talk-cpp.git
2. mkdir build
3. cd build
4. cmake ..
5. make

### opengl
You can select use opengl library with USE_OPENGL of CMakeLists.txt 
Defualt USE_OPENGL is ON
add -DUSE_OPENGL=ON open switch to use OpenGL library
- In Windows Platfrom
- Linux/GUN hasn't OpenGL library
