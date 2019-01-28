# leaffs
It refers to my distributed file system, which aims to achieve high performance and fault-tolerance.

It is inspired by Octopus, which is developed by Storage Research Group @ Tsinghua Universty.(source code: https://github.com/thustorage/octopus)

=========

Installation:

- OS: ubuntu
- Dependencies: fuse-devel,g++（4.9 and
higher),libibverbs

Build lightfs:
- create a new folder "build"
- run "cmake .. & make -j"
- run lightfs: "./server"

Configuration:
leaffs.conf: configuration of the cluster
