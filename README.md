# chronos
![stability-wip](https://img.shields.io/badge/stability-work_in_progress-lightgrey.svg)
![GitHub](https://img.shields.io/github/license/avramidis/chronos)
[![Gitlab pipeline status](https://img.shields.io/gitlab/pipeline/avramidis/chronos)](https://gitlab.com/avramidis/chronos/pipelines)

Chronos is a library for measuring the wall time of different parts of C++ applications.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

To get the code you will need git. To install git on Ubuntu use the following commands in a terminal

```
sudo apt update
sudo apt install git
```

To clone the repository from github use the following command in a terminal
```
git clone https://github.com/avramidis/chronos.git
```

### Installing

A step by step series of examples that tell you have to get a development environment running

To generate the makefiles use the following commands in a terminal in the chronos folders

```
mkdir build
cd build
cmake ..
```

To build chronos use the following command

```
make
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details