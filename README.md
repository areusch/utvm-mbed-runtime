# microTVM mBED Runtime

**Under construction** -- don't use this for now.

At `main`, the supported runtime is currently Zephyr. This runtime could also be supported with the following work.

TODOs:
 * The mBED Compiler, Flasher, and Debugger implementation lives [here](https://github.com/areusch/incubator-tvm/blob/utvm-runtime/python/tvm/micro/contrib/mbed.py). They need to get updated against the changes made in merging the lower part of the stack against TVM's main branch.
 * The code in `main.cpp` (in this repo) also needs to be updated to use the merged uTVM runtime APIs. See the [Zephyr main](https://github.com/apache/tvm/blob/main/tests/micro/qemu/zephyr-runtime/src/main.c) for more.
