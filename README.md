# NetAssistant
A network debugging assistant based on Qt GUI.

## Features
1. UDP；
2. TCP client；
3. TCP server；
4. File transfer;
5. Group chat mode；
6. Multi-language;

## Build

### Windows
passed.

### Linux
```
git clone https://github.com/busyluo/NetAssistant.git
cd NetAssistant
qmake
make
```

如果是Arm环境的话，需要交叉编译，可参考以下教程，有了环境后希望能搞一下，因为ARM下也需要网络调试助手哇：
[1](https://doc.embedfire.com/linux/qt/embed/zh/latest/ebf_qt/install/install_cross.html)
[2](https://yuanze.wang/posts/build-qt-embedded-linux/#%E5%AE%89%E8%A3%85qt)
[3](https://blog.csdn.net/qq_43286311/article/details/118998717)
