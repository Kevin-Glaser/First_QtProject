# First_QtProject

## Background of the project

This project is used as an exercise project for learning QT. In the Windows10 environment, using Clion and QT Designer as development tools requires the environment variables of QT6 and MinGW64, and uses CMake instead of qmake.

这个项目是作为学习QT的练习项目，在Windows10环境下，使用Clion和QT Designer作为开发工具，需要有QT6和MinGW64的环境变量，使用CMake而非qmake。

### Project Features

The project only implements a simple GUI program, and you can learn simple QWidget-related operations through these hundreds of lines of code, such as simple addition, deletion, and modification operations. Regarding database or advanced operations, if there is time, the author will continue to iterate and follow up.

项目只实现了简单的GUI程序，可以通过这几百行的代码了解学习简单的QWidget相关操作，比如简单的增删改操作。关于数据库或者进阶的操作，如果有时间会继续迭代跟进。

### Install

1. The project requires QT 6, MinGW and CMake 3.15 or above.
2. If you use Clion as a development tool, open CMakeLists.txt by opening the project with Clion, and then wait for the IDE to find and configure the project environment by itself.
3. If you use Visual Studio as a development tool, Visual Studio 2019 is recommended.
4. If you use Visual Studio2019 as the development IDE, you need to install the qt-vsaddin-msvc2019 plug-in online or offline after closing Visual Studio, and then restart the IDE.
   After restarting the IDE, follow the steps in the two screenshots below. You can create a QT project in Visual Studio. Actually the author does not recommend using Visual Studio. I'll explain why at the bottom.

1. 项目需要QT 6，MinGW和CMake 3.15以上版本。
2. 如果使用Clion作为开发工具，Clion用打开项目的方式打开CMakeLists.txt，然后等待IDE自己寻找和配置项目环境即可。
3. 如果使用Visual Studio作为开发工具，建议使用Visual Studio2019作为开发工具或以上版本。
4. 若使用Visual Studio2019作为开发IDE，需要在线或者关闭Visual Studio后离线安装qt-vsaddin-msvc2019插件，然后重启这个IDE。
   重启IDE后按照下面两幅截图的步骤来操作。即可在Visual Studio中创建QT工程 。实际上作者不推荐使用Visual Studio。在最下面我会说明原因。

![image](https://user-images.githubusercontent.com/57394574/157248211-b75ae46d-008a-4afa-92ca-4fd3109d6026.png)

![image](https://user-images.githubusercontent.com/57394574/157248280-d3dc5e1c-fff2-4a2f-9836-9678d6248462.png)

### Usage

1. After configuring the CMake, MinGW and QT 6 environments, use Clion to open CmakeLists.txt by opening the project to run.

2. If you want to use Visual Studio 2019, you need a version of CMake 3.15 or above, open the terminal and enter the root directory of the project, which is the first-level directory with the source code, run

   ````cmake
   cmake .
   ````

Then use Visual Studio to open the rms.sln file or the rms.vcxproj file, where rms is the name of the program.

1. 配置好CMake，MinGW以及QT 6环境后，使用Clion用打开项目的方式打开CmakeLists.txt即可运行。

2. 如果要使用Visual Studio2019，那么需要有CMake3.15以上的版本，打开终端进入项目的根目录，也就是有源代码的那一级目录，运行

   ```cmake
   cmake .
   ```

   然后用Visual Studio打开rms.sln文件或者rms.vcxproj文件即可，rms是程序的名字。

### There are still defects in the project

For this project, the author currently uses Clion as the development IDE. For Visual Studio2019, there are still some strange problems. 
I think this is a problem of Visual Studio. When creating the project, I have checked the options of MinGW and MSVC2019. There should be no error, but different errors will always appear when opening the same project with this IDE at different times. 
While these problems do not exist in Clion and QT creator.

对于该项目，作者目前使用Clion作为开发IDE，对于Visual Studio2019，目前还存在一些奇怪的问题，我觉得这是Visual Studio的问题，在创建项目的时候我已经勾选了MinGW和MSVC2019两个选项，应该是不会出错的，但是不同的时间用这个IDE打开同一个项目，总会出现不同的错误。但在Clion和QT creator不存在这些问题。

### The effect of the project running
The effect of the project after running is as follows.

项目运行的效果如下图。

<img src="https://user-images.githubusercontent.com/57394574/157249296-ecbdb482-a508-44ae-8e21-4b0360ee1c1c.png" width="900px">

### Last and most imoportant
The last and most important thing, this project is only used to learn how to use git and github. If any senior sees this project and is willing to give some pointers, it will be my honor.

