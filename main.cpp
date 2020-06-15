/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#include <cstdio>
#include <tvm/runtime/crt/logging.h>
#include <tvm/runtime/micro/micro_rpc_server.h>

#define WAIT_TIME_MS 500
DigitalOut led1(LED1);

extern "C" {
ssize_t write_serial(void* unused_context, const uint8_t* data, size_t size) {
  ssize_t to_return = write(fileno(stdout), data, size);
  if (to_return > 0) {
    fflush(stdout);
    fsync(STDOUT_FILENO);
  }

  return to_return;
}

void TVMPlatformAbort(int error) {
  for (;;) ;
}
}

constexpr const size_t kWorkspaceSizeBytes = 60 * 1024;
constexpr const size_t kWorkspacePageSizeBytesLog2 = 8;

uint8_t workspace[kWorkspaceSizeBytes];


int main()
{
    led1 = 1;
    utvm_rpc_server_t server = utvm_rpc_server_init(workspace, kWorkspaceSizeBytes, kWorkspacePageSizeBytesLog2,
                                                    write_serial, nullptr);
    TVMLogf("uTVM On-Device Runtime");

    while (true)
    {
        led1 = !led1;
        uint8_t c;
        ssize_t bytes_read = read(fileno(stdin), &c, 1);
        if (bytes_read > 0) {
          TVMLogf("r: %02x", c);
          utvm_rpc_server_receive_byte(server, c);
          utvm_rpc_server_loop(server);
          TVMLogf("ld");
        }
    }
}
