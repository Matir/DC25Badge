
#include <compiler.h>
#include "pattern.h"

const uint16_t consts_num_steps = 1440;
const uint16_t consts_resolution = 30;
const uint8_t sin_table[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 19, 19, 19, 19, 20, 20, 20, 21, 21, 21, 22, 22, 22, 22, 23, 23, 23, 24, 24, 24, 25, 25, 25, 26, 26, 26, 27, 27, 27, 28, 28, 29, 29, 29, 30, 30, 30, 31, 31, 31, 32, 32, 32, 33, 33, 34, 34, 34, 35, 35, 36, 36, 36, 37, 37, 37, 38, 38, 39, 39, 39, 40, 40, 41, 41, 42, 42, 42, 43, 43, 44, 44, 44, 45, 45, 46, 46, 47, 47, 47, 48, 48, 49, 49, 50, 50, 51, 51, 51, 52, 52, 53, 53, 54, 54, 55, 55, 55, 56, 56, 57, 57, 58, 58, 59, 59, 60, 60, 61, 61, 62, 62, 63, 63, 63, 64, 64, 65, 65, 66, 66, 67, 67, 68, 68, 69, 69, 70, 70, 71, 71, 72, 72, 73, 73, 74, 74, 75, 75, 76, 76, 77, 77, 78, 78, 79, 79, 80, 80, 81, 82, 82, 83, 83, 84, 84, 85, 85, 86, 86, 87, 87, 88, 88, 89, 89, 90, 90, 91, 91, 92, 93, 93, 94, 94, 95, 95, 96, 96, 97, 97, 98, 98, 99, 100, 100, 101, 101, 102, 102, 103, 103, 104, 104, 105, 106, 106, 107, 107, 108, 108, 109, 109, 110, 110, 111, 112, 112, 113, 113, 114, 114, 115, 115, 116, 117, 117, 118, 118, 119, 119, 120, 120, 121, 122, 122, 123, 123, 124, 124, 125, 125, 126, 127, 127, 128, 128, 129, 129, 130, 130, 131, 131, 132, 133, 133, 134, 134, 135, 135, 136, 136, 137, 138, 138, 139, 139, 140, 140, 141, 141, 142, 143, 143, 144, 144, 145, 145, 146, 146, 147, 147, 148, 149, 149, 150, 150, 151, 151, 152, 152, 153, 153, 154, 155, 155, 156, 156, 157, 157, 158, 158, 159, 159, 160, 160, 161, 162, 162, 163, 163, 164, 164, 165, 165, 166, 166, 167, 167, 168, 168, 169, 169, 170, 170, 171, 171, 172, 173, 173, 174, 174, 175, 175, 176, 176, 177, 177, 178, 178, 179, 179, 180, 180, 181, 181, 182, 182, 183, 183, 184, 184, 185, 185, 186, 186, 187, 187, 188, 188, 189, 189, 190, 190, 190, 191, 191, 192, 192, 193, 193, 194, 194, 195, 195, 196, 196, 197, 197, 198, 198, 198, 199, 199, 200, 200, 201, 201, 202, 202, 202, 203, 203, 204, 204, 205, 205, 206, 206, 206, 207, 207, 208, 208, 209, 209, 209, 210, 210, 211, 211, 211, 212, 212, 213, 213, 214, 214, 214, 215, 215, 216, 216, 216, 217, 217, 217, 218, 218, 219, 219, 219, 220, 220, 221, 221, 221, 222, 222, 222, 223, 223, 223, 224, 224, 224, 225, 225, 226, 226, 226, 227, 227, 227, 228, 228, 228, 229, 229, 229, 230, 230, 230, 231, 231, 231, 231, 232, 232, 232, 233, 233, 233, 234, 234, 234, 234, 235, 235, 235, 236, 236, 236, 236, 237, 237, 237, 238, 238, 238, 238, 239, 239, 239, 239, 240, 240, 240, 240, 241, 241, 241, 241, 242, 242, 242, 242, 243, 243, 243, 243, 243, 244, 244, 244, 244, 244, 245, 245, 245, 245, 245, 246, 246, 246, 246, 246, 247, 247, 247, 247, 247, 247, 248, 248, 248, 248, 248, 248, 249, 249, 249, 249, 249, 249, 249, 250, 250, 250, 250, 250, 250, 250, 250, 251, 251, 251, 251, 251, 251, 251, 251, 251, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 254, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 251, 251, 251, 251, 251, 251, 251, 251, 251, 250, 250, 250, 250, 250, 250, 250, 250, 249, 249, 249, 249, 249, 249, 249, 248, 248, 248, 248, 248, 248, 247, 247, 247, 247, 247, 247, 246, 246, 246, 246, 246, 245, 245, 245, 245, 245, 244, 244, 244, 244, 244, 243, 243, 243, 243, 243, 242, 242, 242, 242, 241, 241, 241, 241, 240, 240, 240, 240, 239, 239, 239, 239, 238, 238, 238, 238, 237, 237, 237, 236, 236, 236, 236, 235, 235, 235, 234, 234, 234, 234, 233, 233, 233, 232, 232, 232, 231, 231, 231, 231, 230, 230, 230, 229, 229, 229, 228, 228, 228, 227, 227, 227, 226, 226, 226, 225, 225, 224, 224, 224, 223, 223, 223, 222, 222, 222, 221, 221, 221, 220, 220, 219, 219, 219, 218, 218, 217, 217, 217, 216, 216, 216, 215, 215, 214, 214, 214, 213, 213, 212, 212, 211, 211, 211, 210, 210, 209, 209, 209, 208, 208, 207, 207, 206, 206, 206, 205, 205, 204, 204, 203, 203, 202, 202, 202, 201, 201, 200, 200, 199, 199, 198, 198, 198, 197, 197, 196, 196, 195, 195, 194, 194, 193, 193, 192, 192, 191, 191, 190, 190, 190, 189, 189, 188, 188, 187, 187, 186, 186, 185, 185, 184, 184, 183, 183, 182, 182, 181, 181, 180, 180, 179, 179, 178, 178, 177, 177, 176, 176, 175, 175, 174, 174, 173, 173, 172, 171, 171, 170, 170, 169, 169, 168, 168, 167, 167, 166, 166, 165, 165, 164, 164, 163, 163, 162, 162, 161, 160, 160, 159, 159, 158, 158, 157, 157, 156, 156, 155, 155, 154, 153, 153, 152, 152, 151, 151, 150, 150, 149, 149, 148, 147, 147, 146, 146, 145, 145, 144, 144, 143, 143, 142, 141, 141, 140, 140, 139, 139, 138, 138, 137, 136, 136, 135, 135, 134, 134, 133, 133, 132, 131, 131, 130, 130, 129, 129, 128, 128, 127, 127, 126, 125, 125, 124, 124, 123, 123, 122, 122, 121, 120, 120, 119, 119, 118, 118, 117, 117, 116, 115, 115, 114, 114, 113, 113, 112, 112, 111, 110, 110, 109, 109, 108, 108, 107, 107, 106, 106, 105, 104, 104, 103, 103, 102, 102, 101, 101, 100, 100, 99, 98, 98, 97, 97, 96, 96, 95, 95, 94, 94, 93, 93, 92, 91, 91, 90, 90, 89, 89, 88, 88, 87, 87, 86, 86, 85, 85, 84, 84, 83, 83, 82, 82, 81, 80, 80, 79, 79, 78, 78, 77, 77, 76, 76, 75, 75, 74, 74, 73, 73, 72, 72, 71, 71, 70, 70, 69, 69, 68, 68, 67, 67, 66, 66, 65, 65, 64, 64, 63, 63, 63, 62, 62, 61, 61, 60, 60, 59, 59, 58, 58, 57, 57, 56, 56, 55, 55, 55, 54, 54, 53, 53, 52, 52, 51, 51, 51, 50, 50, 49, 49, 48, 48, 47, 47, 47, 46, 46, 45, 45, 44, 44, 44, 43, 43, 42, 42, 42, 41, 41, 40, 40, 39, 39, 39, 38, 38, 37, 37, 37, 36, 36, 36, 35, 35, 34, 34, 34, 33, 33, 32, 32, 32, 31, 31, 31, 30, 30, 30, 29, 29, 29, 28, 28, 27, 27, 27, 26, 26, 26, 25, 25, 25, 24, 24, 24, 23, 23, 23, 22, 22, 22, 22, 21, 21, 21, 20, 20, 20, 19, 19, 19, 19, 18, 18, 18, 17, 17, 17, 17, 16, 16, 16, 15, 15, 15, 15, 14, 14, 14, 14, 13, 13, 13, 13, 12, 12, 12, 12, 11, 11, 11, 11, 10, 10, 10, 10, 10, 9, 9, 9, 9, 9, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const uint8_t gamma_table[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, 11, 11, 12, 12, 12, 13, 13, 14, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 23, 23, 24, 24, 25, 26, 26, 27, 28, 28, 29, 30, 30, 31, 32, 32, 33, 34, 35, 35, 36, 37, 38, 39, 39, 40, 41, 42, 43, 44, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 70, 71, 72, 73, 74, 75, 77, 78, 79, 80, 82, 83, 84, 85, 87, 88, 89, 91, 92, 93, 95, 96, 98, 99, 100, 102, 103, 105, 106, 108, 109, 111, 112, 114, 115, 117, 118, 120, 121, 123, 125, 126, 128, 130, 131, 133, 135, 136, 138, 140, 142, 143, 145, 147, 149, 151, 152, 154, 156, 158, 160, 162, 164, 165, 167, 169, 171, 173, 175, 177, 179, 181, 183, 185, 187, 190, 192, 194, 196, 198, 200, 202, 204, 207, 209, 211, 213, 216, 218, 220, 222, 225, 227, 229, 232, 234, 236, 239, 241, 244, 246, 249, 251, 254};
const uint8_t gamma_min_idx = 22;
const struct_rgb colorwheel[] = {{255,0,0}, {255,1,0}, {255,2,0}, {255,3,0}, {255,4,0}, {255,5,0}, {255,6,0}, {255,7,0}, {255,8,0}, {255,9,0}, {255,10,0}, {255,11,0}, {255,12,0}, {255,13,0}, {255,14,0}, {255,15,0}, {255,16,0}, {255,18,0}, {255,19,0}, {255,20,0}, {255,21,0}, {255,22,0}, {255,23,0}, {255,24,0}, {255,25,0}, {255,26,0}, {255,27,0}, {255,28,0}, {255,29,0}, {255,30,0}, {255,31,0}, {255,32,0}, {255,33,0}, {255,35,0}, {255,36,0}, {255,37,0}, {255,38,0}, {255,39,0}, {255,40,0}, {255,41,0}, {255,42,0}, {255,43,0}, {255,44,0}, {255,45,0}, {255,46,0}, {255,47,0}, {255,48,0}, {255,49,0}, {255,50,0}, {255,52,0}, {255,53,0}, {255,54,0}, {255,55,0}, {255,56,0}, {255,57,0}, {255,58,0}, {255,59,0}, {255,60,0}, {255,61,0}, {255,62,0}, {255,63,0}, {255,64,0}, {255,65,0}, {255,66,0}, {255,67,0}, {255,69,0}, {255,70,0}, {255,71,0}, {255,72,0}, {255,73,0}, {255,74,0}, {255,75,0}, {255,76,0}, {255,77,0}, {255,78,0}, {255,79,0}, {255,80,0}, {255,81,0}, {255,82,0}, {255,83,0}, {255,84,0}, {255,86,0}, {255,87,0}, {255,88,0}, {255,89,0}, {255,90,0}, {255,91,0}, {255,92,0}, {255,93,0}, {255,94,0}, {255,95,0}, {255,96,0}, {255,97,0}, {255,98,0}, {255,99,0}, {255,100,0}, {255,102,0}, {255,103,0}, {255,104,0}, {255,105,0}, {255,106,0}, {255,107,0}, {255,108,0}, {255,109,0}, {255,110,0}, {255,111,0}, {255,112,0}, {255,113,0}, {255,114,0}, {255,115,0}, {255,116,0}, {255,117,0}, {255,119,0}, {255,120,0}, {255,121,0}, {255,122,0}, {255,123,0}, {255,124,0}, {255,125,0}, {255,126,0}, {255,127,0}, {255,128,0}, {255,129,0}, {255,130,0}, {255,131,0}, {255,132,0}, {255,133,0}, {255,134,0}, {255,136,0}, {255,137,0}, {255,138,0}, {255,139,0}, {255,140,0}, {255,141,0}, {255,142,0}, {255,143,0}, {255,144,0}, {255,145,0}, {255,146,0}, {255,147,0}, {255,148,0}, {255,149,0}, {255,150,0}, {255,151,0}, {255,153,0}, {255,154,0}, {255,155,0}, {255,156,0}, {255,157,0}, {255,158,0}, {255,159,0}, {255,160,0}, {255,161,0}, {255,162,0}, {255,163,0}, {255,164,0}, {255,165,0}, {255,166,0}, {255,167,0}, {255,168,0}, {255,170,0}, {255,171,0}, {255,172,0}, {255,173,0}, {255,174,0}, {255,175,0}, {255,176,0}, {255,177,0}, {255,178,0}, {255,179,0}, {255,180,0}, {255,181,0}, {255,182,0}, {255,183,0}, {255,184,0}, {255,185,0}, {255,187,0}, {255,188,0}, {255,189,0}, {255,190,0}, {255,191,0}, {255,192,0}, {255,193,0}, {255,194,0}, {255,195,0}, {255,196,0}, {255,197,0}, {255,198,0}, {255,199,0}, {255,200,0}, {255,201,0}, {255,202,0}, {255,204,0}, {255,205,0}, {255,206,0}, {255,207,0}, {255,208,0}, {255,209,0}, {255,210,0}, {255,211,0}, {255,212,0}, {255,213,0}, {255,214,0}, {255,215,0}, {255,216,0}, {255,217,0}, {255,218,0}, {255,219,0}, {255,220,0}, {255,222,0}, {255,223,0}, {255,224,0}, {255,225,0}, {255,226,0}, {255,227,0}, {255,228,0}, {255,229,0}, {255,230,0}, {255,231,0}, {255,232,0}, {255,233,0}, {255,234,0}, {255,235,0}, {255,236,0}, {255,238,0}, {255,239,0}, {255,240,0}, {255,241,0}, {255,242,0}, {255,243,0}, {255,244,0}, {255,245,0}, {255,246,0}, {255,247,0}, {255,248,0}, {255,249,0}, {255,250,0}, {255,251,0}, {255,252,0}, {255,253,0}, {255,255,0}, {253,255,0}, {252,255,0}, {251,255,0}, {250,255,0}, {249,255,0}, {248,255,0}, {247,255,0}, {246,255,0}, {245,255,0}, {244,255,0}, {243,255,0}, {242,255,0}, {241,255,0}, {240,255,0}, {239,255,0}, {238,255,0}, {236,255,0}, {235,255,0}, {234,255,0}, {233,255,0}, {232,255,0}, {231,255,0}, {230,255,0}, {229,255,0}, {228,255,0}, {227,255,0}, {226,255,0}, {225,255,0}, {224,255,0}, {223,255,0}, {222,255,0}, {221,255,0}, {219,255,0}, {218,255,0}, {217,255,0}, {216,255,0}, {215,255,0}, {214,255,0}, {213,255,0}, {212,255,0}, {211,255,0}, {210,255,0}, {209,255,0}, {208,255,0}, {207,255,0}, {206,255,0}, {205,255,0}, {204,255,0}, {202,255,0}, {201,255,0}, {200,255,0}, {199,255,0}, {198,255,0}, {197,255,0}, {196,255,0}, {195,255,0}, {194,255,0}, {193,255,0}, {192,255,0}, {191,255,0}, {190,255,0}, {189,255,0}, {188,255,0}, {187,255,0}, {185,255,0}, {184,255,0}, {183,255,0}, {182,255,0}, {181,255,0}, {180,255,0}, {179,255,0}, {178,255,0}, {177,255,0}, {176,255,0}, {175,255,0}, {174,255,0}, {173,255,0}, {172,255,0}, {171,255,0}, {170,255,0}, {168,255,0}, {167,255,0}, {166,255,0}, {165,255,0}, {164,255,0}, {163,255,0}, {162,255,0}, {161,255,0}, {160,255,0}, {159,255,0}, {158,255,0}, {157,255,0}, {156,255,0}, {155,255,0}, {154,255,0}, {153,255,0}, {151,255,0}, {150,255,0}, {149,255,0}, {148,255,0}, {147,255,0}, {146,255,0}, {145,255,0}, {144,255,0}, {143,255,0}, {142,255,0}, {141,255,0}, {140,255,0}, {139,255,0}, {138,255,0}, {137,255,0}, {136,255,0}, {134,255,0}, {133,255,0}, {132,255,0}, {131,255,0}, {130,255,0}, {129,255,0}, {128,255,0}, {127,255,0}, {126,255,0}, {125,255,0}, {124,255,0}, {123,255,0}, {122,255,0}, {121,255,0}, {120,255,0}, {118,255,0}, {117,255,0}, {116,255,0}, {115,255,0}, {114,255,0}, {113,255,0}, {112,255,0}, {111,255,0}, {110,255,0}, {109,255,0}, {108,255,0}, {107,255,0}, {106,255,0}, {105,255,0}, {104,255,0}, {103,255,0}, {101,255,0}, {100,255,0}, {99,255,0}, {98,255,0}, {97,255,0}, {96,255,0}, {95,255,0}, {94,255,0}, {93,255,0}, {92,255,0}, {91,255,0}, {90,255,0}, {89,255,0}, {88,255,0}, {87,255,0}, {86,255,0}, {84,255,0}, {83,255,0}, {82,255,0}, {81,255,0}, {80,255,0}, {79,255,0}, {78,255,0}, {77,255,0}, {76,255,0}, {75,255,0}, {74,255,0}, {73,255,0}, {72,255,0}, {71,255,0}, {70,255,0}, {69,255,0}, {68,255,0}, {66,255,0}, {65,255,0}, {64,255,0}, {63,255,0}, {62,255,0}, {61,255,0}, {60,255,0}, {59,255,0}, {58,255,0}, {57,255,0}, {56,255,0}, {55,255,0}, {54,255,0}, {53,255,0}, {52,255,0}, {50,255,0}, {49,255,0}, {48,255,0}, {47,255,0}, {46,255,0}, {45,255,0}, {44,255,0}, {43,255,0}, {42,255,0}, {41,255,0}, {40,255,0}, {39,255,0}, {38,255,0}, {37,255,0}, {36,255,0}, {35,255,0}, {33,255,0}, {32,255,0}, {31,255,0}, {30,255,0}, {29,255,0}, {28,255,0}, {27,255,0}, {26,255,0}, {25,255,0}, {24,255,0}, {23,255,0}, {22,255,0}, {21,255,0}, {20,255,0}, {19,255,0}, {18,255,0}, {16,255,0}, {15,255,0}, {14,255,0}, {13,255,0}, {12,255,0}, {11,255,0}, {10,255,0}, {9,255,0}, {8,255,0}, {7,255,0}, {6,255,0}, {5,255,0}, {4,255,0}, {3,255,0}, {2,255,0}, {1,255,0}, {0,255,0}, {0,255,1}, {0,255,2}, {0,255,3}, {0,255,4}, {0,255,5}, {0,255,6}, {0,255,7}, {0,255,8}, {0,255,9}, {0,255,10}, {0,255,11}, {0,255,12}, {0,255,13}, {0,255,14}, {0,255,15}, {0,255,17}, {0,255,18}, {0,255,19}, {0,255,20}, {0,255,21}, {0,255,22}, {0,255,23}, {0,255,24}, {0,255,25}, {0,255,26}, {0,255,27}, {0,255,28}, {0,255,29}, {0,255,30}, {0,255,31}, {0,255,32}, {0,255,33}, {0,255,35}, {0,255,36}, {0,255,37}, {0,255,38}, {0,255,39}, {0,255,40}, {0,255,41}, {0,255,42}, {0,255,43}, {0,255,44}, {0,255,45}, {0,255,46}, {0,255,47}, {0,255,48}, {0,255,49}, {0,255,51}, {0,255,52}, {0,255,53}, {0,255,54}, {0,255,55}, {0,255,56}, {0,255,57}, {0,255,58}, {0,255,59}, {0,255,60}, {0,255,61}, {0,255,62}, {0,255,63}, {0,255,64}, {0,255,65}, {0,255,66}, {0,255,67}, {0,255,69}, {0,255,70}, {0,255,71}, {0,255,72}, {0,255,73}, {0,255,74}, {0,255,75}, {0,255,76}, {0,255,77}, {0,255,78}, {0,255,79}, {0,255,80}, {0,255,81}, {0,255,82}, {0,255,83}, {0,255,85}, {0,255,86}, {0,255,87}, {0,255,88}, {0,255,89}, {0,255,90}, {0,255,91}, {0,255,92}, {0,255,93}, {0,255,94}, {0,255,95}, {0,255,96}, {0,255,97}, {0,255,98}, {0,255,99}, {0,255,100}, {0,255,101}, {0,255,103}, {0,255,104}, {0,255,105}, {0,255,106}, {0,255,107}, {0,255,108}, {0,255,109}, {0,255,110}, {0,255,111}, {0,255,112}, {0,255,113}, {0,255,114}, {0,255,115}, {0,255,116}, {0,255,117}, {0,255,119}, {0,255,120}, {0,255,121}, {0,255,122}, {0,255,123}, {0,255,124}, {0,255,125}, {0,255,126}, {0,255,127}, {0,255,128}, {0,255,129}, {0,255,130}, {0,255,131}, {0,255,132}, {0,255,133}, {0,255,134}, {0,255,135}, {0,255,137}, {0,255,138}, {0,255,139}, {0,255,140}, {0,255,141}, {0,255,142}, {0,255,143}, {0,255,144}, {0,255,145}, {0,255,146}, {0,255,147}, {0,255,148}, {0,255,149}, {0,255,150}, {0,255,151}, {0,255,153}, {0,255,154}, {0,255,155}, {0,255,156}, {0,255,157}, {0,255,158}, {0,255,159}, {0,255,160}, {0,255,161}, {0,255,162}, {0,255,163}, {0,255,164}, {0,255,165}, {0,255,166}, {0,255,167}, {0,255,168}, {0,255,169}, {0,255,171}, {0,255,172}, {0,255,173}, {0,255,174}, {0,255,175}, {0,255,176}, {0,255,177}, {0,255,178}, {0,255,179}, {0,255,180}, {0,255,181}, {0,255,182}, {0,255,183}, {0,255,184}, {0,255,185}, {0,255,187}, {0,255,188}, {0,255,189}, {0,255,190}, {0,255,191}, {0,255,192}, {0,255,193}, {0,255,194}, {0,255,195}, {0,255,196}, {0,255,197}, {0,255,198}, {0,255,199}, {0,255,200}, {0,255,201}, {0,255,202}, {0,255,203}, {0,255,205}, {0,255,206}, {0,255,207}, {0,255,208}, {0,255,209}, {0,255,210}, {0,255,211}, {0,255,212}, {0,255,213}, {0,255,214}, {0,255,215}, {0,255,216}, {0,255,217}, {0,255,218}, {0,255,219}, {0,255,221}, {0,255,222}, {0,255,223}, {0,255,224}, {0,255,225}, {0,255,226}, {0,255,227}, {0,255,228}, {0,255,229}, {0,255,230}, {0,255,231}, {0,255,232}, {0,255,233}, {0,255,234}, {0,255,235}, {0,255,236}, {0,255,237}, {0,255,239}, {0,255,240}, {0,255,241}, {0,255,242}, {0,255,243}, {0,255,244}, {0,255,245}, {0,255,246}, {0,255,247}, {0,255,248}, {0,255,249}, {0,255,250}, {0,255,251}, {0,255,252}, {0,255,253}, {0,255,255}, {0,253,255}, {0,252,255}, {0,251,255}, {0,250,255}, {0,249,255}, {0,248,255}, {0,247,255}, {0,246,255}, {0,245,255}, {0,244,255}, {0,243,255}, {0,242,255}, {0,241,255}, {0,240,255}, {0,239,255}, {0,237,255}, {0,236,255}, {0,235,255}, {0,234,255}, {0,233,255}, {0,232,255}, {0,231,255}, {0,230,255}, {0,229,255}, {0,228,255}, {0,227,255}, {0,226,255}, {0,225,255}, {0,224,255}, {0,223,255}, {0,222,255}, {0,221,255}, {0,219,255}, {0,218,255}, {0,217,255}, {0,216,255}, {0,215,255}, {0,214,255}, {0,213,255}, {0,212,255}, {0,211,255}, {0,210,255}, {0,209,255}, {0,208,255}, {0,207,255}, {0,206,255}, {0,205,255}, {0,203,255}, {0,202,255}, {0,201,255}, {0,200,255}, {0,199,255}, {0,198,255}, {0,197,255}, {0,196,255}, {0,195,255}, {0,194,255}, {0,193,255}, {0,192,255}, {0,191,255}, {0,190,255}, {0,189,255}, {0,188,255}, {0,187,255}, {0,185,255}, {0,184,255}, {0,183,255}, {0,182,255}, {0,181,255}, {0,180,255}, {0,179,255}, {0,178,255}, {0,177,255}, {0,176,255}, {0,175,255}, {0,174,255}, {0,173,255}, {0,172,255}, {0,171,255}, {0,169,255}, {0,168,255}, {0,167,255}, {0,166,255}, {0,165,255}, {0,164,255}, {0,163,255}, {0,162,255}, {0,161,255}, {0,160,255}, {0,159,255}, {0,158,255}, {0,157,255}, {0,156,255}, {0,155,255}, {0,154,255}, {0,153,255}, {0,151,255}, {0,150,255}, {0,149,255}, {0,148,255}, {0,147,255}, {0,146,255}, {0,145,255}, {0,144,255}, {0,143,255}, {0,142,255}, {0,141,255}, {0,140,255}, {0,139,255}, {0,138,255}, {0,137,255}, {0,136,255}, {0,134,255}, {0,133,255}, {0,132,255}, {0,131,255}, {0,130,255}, {0,129,255}, {0,128,255}, {0,127,255}, {0,126,255}, {0,125,255}, {0,124,255}, {0,123,255}, {0,122,255}, {0,121,255}, {0,120,255}, {0,119,255}, {0,117,255}, {0,116,255}, {0,115,255}, {0,114,255}, {0,113,255}, {0,112,255}, {0,111,255}, {0,110,255}, {0,109,255}, {0,108,255}, {0,107,255}, {0,106,255}, {0,105,255}, {0,104,255}, {0,103,255}, {0,101,255}, {0,100,255}, {0,99,255}, {0,98,255}, {0,97,255}, {0,96,255}, {0,95,255}, {0,94,255}, {0,93,255}, {0,92,255}, {0,91,255}, {0,90,255}, {0,89,255}, {0,88,255}, {0,87,255}, {0,86,255}, {0,84,255}, {0,83,255}, {0,82,255}, {0,81,255}, {0,80,255}, {0,79,255}, {0,78,255}, {0,77,255}, {0,76,255}, {0,75,255}, {0,74,255}, {0,73,255}, {0,72,255}, {0,71,255}, {0,70,255}, {0,69,255}, {0,67,255}, {0,66,255}, {0,65,255}, {0,64,255}, {0,63,255}, {0,62,255}, {0,61,255}, {0,60,255}, {0,59,255}, {0,58,255}, {0,57,255}, {0,56,255}, {0,55,255}, {0,54,255}, {0,53,255}, {0,52,255}, {0,51,255}, {0,49,255}, {0,48,255}, {0,47,255}, {0,46,255}, {0,45,255}, {0,44,255}, {0,43,255}, {0,42,255}, {0,41,255}, {0,40,255}, {0,39,255}, {0,38,255}, {0,37,255}, {0,36,255}, {0,35,255}, {0,33,255}, {0,32,255}, {0,31,255}, {0,30,255}, {0,29,255}, {0,28,255}, {0,27,255}, {0,26,255}, {0,25,255}, {0,24,255}, {0,23,255}, {0,22,255}, {0,21,255}, {0,20,255}, {0,19,255}, {0,18,255}, {0,17,255}, {0,15,255}, {0,14,255}, {0,13,255}, {0,12,255}, {0,11,255}, {0,10,255}, {0,9,255}, {0,8,255}, {0,7,255}, {0,6,255}, {0,5,255}, {0,4,255}, {0,3,255}, {0,2,255}, {0,1,255}, {0,0,255}, {1,0,255}, {2,0,255}, {3,0,255}, {4,0,255}, {5,0,255}, {6,0,255}, {7,0,255}, {8,0,255}, {9,0,255}, {10,0,255}, {11,0,255}, {12,0,255}, {13,0,255}, {14,0,255}, {15,0,255}, {16,0,255}, {18,0,255}, {19,0,255}, {20,0,255}, {21,0,255}, {22,0,255}, {23,0,255}, {24,0,255}, {25,0,255}, {26,0,255}, {27,0,255}, {28,0,255}, {29,0,255}, {30,0,255}, {31,0,255}, {32,0,255}, {34,0,255}, {35,0,255}, {36,0,255}, {37,0,255}, {38,0,255}, {39,0,255}, {40,0,255}, {41,0,255}, {42,0,255}, {43,0,255}, {44,0,255}, {45,0,255}, {46,0,255}, {47,0,255}, {48,0,255}, {49,0,255}, {50,0,255}, {52,0,255}, {53,0,255}, {54,0,255}, {55,0,255}, {56,0,255}, {57,0,255}, {58,0,255}, {59,0,255}, {60,0,255}, {61,0,255}, {62,0,255}, {63,0,255}, {64,0,255}, {65,0,255}, {66,0,255}, {67,0,255}, {69,0,255}, {70,0,255}, {71,0,255}, {72,0,255}, {73,0,255}, {74,0,255}, {75,0,255}, {76,0,255}, {77,0,255}, {78,0,255}, {79,0,255}, {80,0,255}, {81,0,255}, {82,0,255}, {83,0,255}, {84,0,255}, {86,0,255}, {87,0,255}, {88,0,255}, {89,0,255}, {90,0,255}, {91,0,255}, {92,0,255}, {93,0,255}, {94,0,255}, {95,0,255}, {96,0,255}, {97,0,255}, {98,0,255}, {99,0,255}, {100,0,255}, {102,0,255}, {103,0,255}, {104,0,255}, {105,0,255}, {106,0,255}, {107,0,255}, {108,0,255}, {109,0,255}, {110,0,255}, {111,0,255}, {112,0,255}, {113,0,255}, {114,0,255}, {115,0,255}, {116,0,255}, {117,0,255}, {119,0,255}, {120,0,255}, {121,0,255}, {122,0,255}, {123,0,255}, {124,0,255}, {125,0,255}, {126,0,255}, {127,0,255}, {128,0,255}, {129,0,255}, {130,0,255}, {131,0,255}, {132,0,255}, {133,0,255}, {134,0,255}, {135,0,255}, {137,0,255}, {138,0,255}, {139,0,255}, {140,0,255}, {141,0,255}, {142,0,255}, {143,0,255}, {144,0,255}, {145,0,255}, {146,0,255}, {147,0,255}, {148,0,255}, {149,0,255}, {150,0,255}, {151,0,255}, {152,0,255}, {154,0,255}, {155,0,255}, {156,0,255}, {157,0,255}, {158,0,255}, {159,0,255}, {160,0,255}, {161,0,255}, {162,0,255}, {163,0,255}, {164,0,255}, {165,0,255}, {166,0,255}, {167,0,255}, {168,0,255}, {170,0,255}, {171,0,255}, {172,0,255}, {173,0,255}, {174,0,255}, {175,0,255}, {176,0,255}, {177,0,255}, {178,0,255}, {179,0,255}, {180,0,255}, {181,0,255}, {182,0,255}, {183,0,255}, {184,0,255}, {185,0,255}, {187,0,255}, {188,0,255}, {189,0,255}, {190,0,255}, {191,0,255}, {192,0,255}, {193,0,255}, {194,0,255}, {195,0,255}, {196,0,255}, {197,0,255}, {198,0,255}, {199,0,255}, {200,0,255}, {201,0,255}, {202,0,255}, {203,0,255}, {205,0,255}, {206,0,255}, {207,0,255}, {208,0,255}, {209,0,255}, {210,0,255}, {211,0,255}, {212,0,255}, {213,0,255}, {214,0,255}, {215,0,255}, {216,0,255}, {217,0,255}, {218,0,255}, {219,0,255}, {220,0,255}, {222,0,255}, {223,0,255}, {224,0,255}, {225,0,255}, {226,0,255}, {227,0,255}, {228,0,255}, {229,0,255}, {230,0,255}, {231,0,255}, {232,0,255}, {233,0,255}, {234,0,255}, {235,0,255}, {236,0,255}, {238,0,255}, {239,0,255}, {240,0,255}, {241,0,255}, {242,0,255}, {243,0,255}, {244,0,255}, {245,0,255}, {246,0,255}, {247,0,255}, {248,0,255}, {249,0,255}, {250,0,255}, {251,0,255}, {252,0,255}, {253,0,255}, {255,0,255}, {255,0,253}, {255,0,252}, {255,0,251}, {255,0,250}, {255,0,249}, {255,0,248}, {255,0,247}, {255,0,246}, {255,0,245}, {255,0,244}, {255,0,243}, {255,0,242}, {255,0,241}, {255,0,240}, {255,0,239}, {255,0,238}, {255,0,236}, {255,0,235}, {255,0,234}, {255,0,233}, {255,0,232}, {255,0,231}, {255,0,230}, {255,0,229}, {255,0,228}, {255,0,227}, {255,0,226}, {255,0,225}, {255,0,224}, {255,0,223}, {255,0,222}, {255,0,220}, {255,0,219}, {255,0,218}, {255,0,217}, {255,0,216}, {255,0,215}, {255,0,214}, {255,0,213}, {255,0,212}, {255,0,211}, {255,0,210}, {255,0,209}, {255,0,208}, {255,0,207}, {255,0,206}, {255,0,205}, {255,0,203}, {255,0,202}, {255,0,201}, {255,0,200}, {255,0,199}, {255,0,198}, {255,0,197}, {255,0,196}, {255,0,195}, {255,0,194}, {255,0,193}, {255,0,192}, {255,0,191}, {255,0,190}, {255,0,189}, {255,0,188}, {255,0,187}, {255,0,185}, {255,0,184}, {255,0,183}, {255,0,182}, {255,0,181}, {255,0,180}, {255,0,179}, {255,0,178}, {255,0,177}, {255,0,176}, {255,0,175}, {255,0,174}, {255,0,173}, {255,0,172}, {255,0,171}, {255,0,170}, {255,0,168}, {255,0,167}, {255,0,166}, {255,0,165}, {255,0,164}, {255,0,163}, {255,0,162}, {255,0,161}, {255,0,160}, {255,0,159}, {255,0,158}, {255,0,157}, {255,0,156}, {255,0,155}, {255,0,154}, {255,0,152}, {255,0,151}, {255,0,150}, {255,0,149}, {255,0,148}, {255,0,147}, {255,0,146}, {255,0,145}, {255,0,144}, {255,0,143}, {255,0,142}, {255,0,141}, {255,0,140}, {255,0,139}, {255,0,138}, {255,0,137}, {255,0,135}, {255,0,134}, {255,0,133}, {255,0,132}, {255,0,131}, {255,0,130}, {255,0,129}, {255,0,128}, {255,0,127}, {255,0,126}, {255,0,125}, {255,0,124}, {255,0,123}, {255,0,122}, {255,0,121}, {255,0,120}, {255,0,119}, {255,0,117}, {255,0,116}, {255,0,115}, {255,0,114}, {255,0,113}, {255,0,112}, {255,0,111}, {255,0,110}, {255,0,109}, {255,0,108}, {255,0,107}, {255,0,106}, {255,0,105}, {255,0,104}, {255,0,103}, {255,0,102}, {255,0,100}, {255,0,99}, {255,0,98}, {255,0,97}, {255,0,96}, {255,0,95}, {255,0,94}, {255,0,93}, {255,0,92}, {255,0,91}, {255,0,90}, {255,0,89}, {255,0,88}, {255,0,87}, {255,0,86}, {255,0,84}, {255,0,83}, {255,0,82}, {255,0,81}, {255,0,80}, {255,0,79}, {255,0,78}, {255,0,77}, {255,0,76}, {255,0,75}, {255,0,74}, {255,0,73}, {255,0,72}, {255,0,71}, {255,0,70}, {255,0,69}, {255,0,67}, {255,0,66}, {255,0,65}, {255,0,64}, {255,0,63}, {255,0,62}, {255,0,61}, {255,0,60}, {255,0,59}, {255,0,58}, {255,0,57}, {255,0,56}, {255,0,55}, {255,0,54}, {255,0,53}, {255,0,52}, {255,0,51}, {255,0,49}, {255,0,48}, {255,0,47}, {255,0,46}, {255,0,45}, {255,0,44}, {255,0,43}, {255,0,42}, {255,0,41}, {255,0,40}, {255,0,39}, {255,0,38}, {255,0,37}, {255,0,36}, {255,0,35}, {255,0,34}, {255,0,32}, {255,0,31}, {255,0,30}, {255,0,29}, {255,0,28}, {255,0,27}, {255,0,26}, {255,0,25}, {255,0,24}, {255,0,23}, {255,0,22}, {255,0,21}, {255,0,20}, {255,0,19}, {255,0,18}, {255,0,16}, {255,0,15}, {255,0,14}, {255,0,13}, {255,0,12}, {255,0,11}, {255,0,10}, {255,0,9}, {255,0,8}, {255,0,7}, {255,0,6}, {255,0,5}, {255,0,4}, {255,0,3}, {255,0,2}, {255,0,1}};
