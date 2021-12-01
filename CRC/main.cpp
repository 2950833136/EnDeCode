#include "crc.h"
#include "type.h"
#include <malloc.h>
#include <stdio.h>

/*****************************************************************************
 * @details 8bit 数据
 * @result A128EA35
 ******************************************************************************/
u8 data[] = {
    0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, // 目的 MAC 地址
    0x54, 0xe1, 0xad, 0x7e, 0xc5, 0x11, // 源 MAC 地址
    0x08, 0x00,                         // 帧类型
    0x45,                               // 版本号 4，首部长度 20 字节 ==> 5
    0x00,                               // 服务类型，默认
    0x00, 0x2e,                         // 总长度（首部 + 数据）
    0x12, 0x34,                         // 16 标识位
    0x40, 0x00,                         // 3 比特标志不分片 010 ，13 比特片偏移
    0x40,                               // 生存时间 64
    0x11,                               // 上层协议，以 UDP 为例 17
    0xa4, 0x43,                         // IP 首部检验和
    0xc0, 0xa8, 0x01, 0x51,             // 源 IP 地址		192.168.1.81
    0xc0, 0xa8, 0x01, 0xa6,             // 目的地 IP 地址 	192.168.1.166
    0x17, 0xc1,                         // 源端口
    0x1b, 0xa9,                         // 目的地端口
    0x00, 0x1a,                         // UDP 长度
    0x6c, 0x2c,                         // UDP 检验和
    0x51, 0x51, 0x51, 0x51, 0x51, 0x51, // 传输数据
    0x51, 0x51, 0x51, 0x51, 0x51, 0x51,
    0x51, 0x51, 0x51, 0x51, 0x51, 0x51
};

int main() {
    int len = sizeof(data) / sizeof(data[0]);
    u32 crc = crc32(data, len, crc_32);
    printf("%X\n", crc);
    return 0;
}
