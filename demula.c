#include <stdio.h>
#include <stdint.h>

#define MEM_SIZE 256
#define REG_COUNT 4

uint8_t memory[MEM_SIZE];
int32_t reg[REG_COUNT];
int pc = 0;
int running = 1;

enum {
    OP_HALT = 0x00,
    OP_LOAD = 0x01,  // LOAD Rx, value
    OP_ADD  = 0x02,  // ADD Rx, Ry
    OP_SUB  = 0x03,  // SUB Rx, Ry
    OP_PRINT= 0x04,  // PRINT Rx
    OP_JMP  = 0x05   // JMP addr
};

void run() {
    while (running) {
        uint8_t opcode = memory[pc++];
        switch (opcode) {
            case OP_HALT:
                running = 0;
                break;
            case OP_LOAD: {
                uint8_t rx = memory[pc++];
                uint8_t val = memory[pc++];
                reg[rx] = val;
                break;
            }
            case OP_ADD: {
                uint8_t rx = memory[pc++];
                uint8_t ry = memory[pc++];
                reg[rx] += reg[ry];
                break;
            }
            case OP_SUB: {
                uint8_t rx = memory[pc++];
                uint8_t ry = memory[pc++];
                reg[rx] -= reg[ry];
                break;
            }
            case OP_PRINT: {
                uint8_t rx = memory[pc++];
                printf("R%d = %d\n", rx, reg[rx]);
                break;
            }
            case OP_JMP: {
                uint8_t addr = memory[pc++];
                pc = addr;
                break;
            }
            default:
                printf("Bilinmeyen opcode: 0x%02X\n", opcode);
                running = 0;
        }
    }
}

int main() {
    // Örnek program: R0'a 5 yükle, R1'e 3 yükle, topla, yazdır
    uint8_t program[] = {
        OP_LOAD, 0, 5,
        OP_LOAD, 1, 3,
        OP_ADD, 0, 1,
        OP_PRINT, 0,
        OP_HALT
    };

    for (int i = 0; i < sizeof(program); i++)
        memory[i] = program[i];

    run();
    return 0;
}