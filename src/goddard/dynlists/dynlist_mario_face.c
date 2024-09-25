#include <PR/ultratypes.h>

#include "macros.h"
#include "dynlist_macros.h"
#include "dynlists.h"
#include "../dynlist_proc.h"

static s16 mario_Face_VtxData[][3] = {
    { 434, 326, -209 },   { 283, 371, -268 },   { 344, 531, -97 },    { 360, 187, -363 },
    { 162, -260, 265 },   { 172, -251, 175 },   { 218, -191, 287 },   { 173, 279, 296 },
    { 192, 226, 279 },    { 233, 346, 216 },    { 135, -283, 182 },   { 165, -299, 114 },
    { 283, -7, -283 },    { 252, -41, -396 },   { 339, 63, -209 },    { 128, 20, 390 },
    { 203, -50, 366 },    { 219, 24, 358 },     { 127, -74, 423 },    { 0, -125, 459 },
    { 125, -76, 401 },    { 83, 86, 359 },      { 124, 85, 409 },     { 144, 91, 567 },
    { 151, 5, 459 },      { 65, -67, 636 },     { 106, -104, 567 },   { 117, 1, 636 },
    { 0, 141, 459 },      { 0, 139, 567 },      { 66, 80, 636 },      { 99, -284, 284 },
    { 125, -295, 252 },   { 343, -31, 227 },    { 296, 35, 287 },     { 267, -115, 314 },
    { 374, -65, 73 },     { 366, -103, 153 },   { 369, -90, 62 },     { 77, -339, 122 },
    { 94, -363, 22 },     { 0, -123, 567 },     { 63, -198, 357 },    { 115, -178, 351 },
    { 53, -167, 398 },    { 311, 79, 200 },     { 265, 141, 195 },    { 242, 98, 288 },
    { 54, 306, 339 },     { 127, 314, 325 },    { 123, 383, 276 },    { 195, 158, 286 },
    { 490, 222, -179 },   { 410, 149, -123 },   { 281, 383, 493 },    { 349, 313, 311 },
    { 243, 407, 458 },    { 323, 286, 131 },    { 445, 241, -29 },    { 466, 126, -176 },
    { 432, 145, -125 },   { 465, 96, -107 },    { 327, -122, -180 },  { 348, -73, -156 },
    { 297, -152, -126 },  { 496, 52, -220 },    { 424, 90, -198 },    { 431, 480, -59 },
    { 356, 611, 78 },     { 119, 770, 199 },    { 243, 714, 165 },    { 183, 744, 77 },
    { 117, 190, -556 },   { 206, 36, -541 },    { 273, -85, -230 },   { 132, 423, 573 },
    { 263, 636, 246 },    { 236, 536, 288 },    { 318, 452, 218 },    { 114, 573, -114 },
    { 49, 394, -230 },    { 127, 365, -303 },   { 41, 126, 357 },     { 0, 127, 368 },
    { 342, -114, -82 },   { 144, -241, 291 },   { 128, -226, 276 },   { 0, -112, 421 },
    { 385, 17, -116 },    { 430, 29, -155 },    { 484, -69, -165 },   { 436, -20, -205 },
    { 504, 4, -195 },     { 308, -167, 222 },   { 288, -237, 119 },   { 341, -164, 56 },
    { 257, -234, -64 },   { 143, 91, 333 },     { 35, -227, 201 },    { 0, -293, 274 },
    { 66, -283, 272 },    { 91, -149, 273 },    { 50, -217, 325 },    { 74, -107, 155 },
    { 75, -227, 201 },    { 74, -321, 190 },    { 186, -226, -173 },  { 97, -313, -200 },
    { 159, -331, 5 },     { 157, -164, 336 },   { 162, -139, 369 },   { 164, -190, 319 },
    { 156, -150, 317 },   { 41, -314, 282 },    { 62, -329, 252 },    { 0, -342, 252 },
    { 0, -339, 190 },     { 0, -371, 136 },     { 379, 21, -58 },     { 345, -32, -2 },
    { 375, -21, -59 },    { 314, 331, 289 },    { 425, -38, -132 },   { 483, 49, -147 },
    { 177, 107, 315 },    { 311, 216, 143 },    { 56, 131, 305 },     { 82, 87, 283 },
    { 59, 268, 295 },     { 0, 383, 308 },      { 46, 224, 357 },     { 73, 297, 289 },
    { 124, 305, 270 },    { 161, 275, 258 },    { 181, 226, 248 },    { 167, 123, 248 },
    { 138, 92, 249 },     { 348, -76, -25 },    { 416, -115, -95 },   { 396, 155, -77 },
    { 345, 5, -6 },       { 407, 80, -78 },     { 399, 192, -5 },     { 351, 211, 49 },
    { 385, -16, 93 },     { 471, 410, 0 },      { 406, 344, 72 },     { 299, 642, -9 },
    { 99, 678, -16 },     { 61, 746, 77 },      { 0, 662, 326 },      { 144, 693, 290 },
    { 367, 553, 169 },    { 246, -69, -335 },   { 179, 521, 305 },    { 145, 447, 317 },
    { 67, 655, 314 },     { 148, 624, 303 },    { 237, 378, 229 },    { 127, -190, 213 },
    { 168, 2, 567 },      { 0, 1, 662 },        { 209, 314, -391 },   { 41, 354, -332 },
    { 406, 115, -313 },   { 260, -175, -198 },  { 90, -361, -92 },    { 401, -99, -132 },
    { 470, -19, -130 },   { 355, 55, 133 },     { 325, 107, 130 },    { 411, 73, 85 },
    { 362, 145, 57 },     { 83, 298, -450 },    { -41, 354, -332 },   { -83, 298, -450 },
    { -112, 190, -556 },  { -2, -382, 60 },     { -90, -361, -92 },   { -97, -313, -200 },
    { 108, -241, -280 },  { 0, -238, -280 },    { -67, 80, 636 },     { -66, -67, 636 },
    { -113, 529, 326 },   { -179, 521, 305 },   { -145, 447, 317 },   { -74, -107, 155 },
    { -50, -217, 325 },   { -35, -227, 201 },   { 0, 3, -569 },       { 0, -42, -443 },
    { -119, 770, 199 },   { -99, 678, -16 },    { -114, 573, -114 },  { -61, 746, 77 },
    { -54, 306, 339 },    { -46, 224, 357 },    { -63, -198, 357 },   { -53, -167, 398 },
    { 98, -67, -392 },    { 127, 441, 523 },    { 0, 423, 573 },      { 292, -219, -231 },
    { 78, -230, -456 },   { 56, -257, -404 },   { 32, -210, -431 },   { 124, -217, -428 },
    { 125, -185, -370 },  { 97, -166, -483 },   { 56, -159, -486 },   { -3, -72, -404 },
    { -3, -174, -377 },   { 303, -200, -423 },  { 243, -262, -358 },  { 204, -203, -428 },
    { 241, -139, -464 },  { 166, -110, -445 },  { 277, -93, -416 },   { 174, -205, -404 },
    { 294, -239, -381 },  { 258, -243, -302 },  { 345, -172, -370 },  { 342, -132, -280 },
    { 382, 54, -197 },    { 439, 41, -227 },    { 389, 29, -202 },    { 390, -13, -203 },
    { 412, -69, -184 },   { 422, -63, -95 },    { 0, 440, 529 },      { 364, 16, 148 },
    { 424, 39, 39 },      { 401, 29, 97 },      { 391, 132, 5 },      { 395, 101, -33 },
    { 172, -260, -335 },  { 103, -257, -404 },  { 295, -131, -457 },  { 403, 171, -41 },
    { -471, 410, 0 },     { -490, 222, -179 },  { -445, 241, -29 },   { -410, 149, -123 },
    { -396, 155, -77 },   { -403, 171, -41 },   { -323, 286, 131 },   { -406, 344, 72 },
    { -399, 192, -5 },    { -318, 452, 218 },   { -209, 314, -391 },  { -283, 371, -268 },
    { -127, 365, -303 },  { -98, -67, -392 },   { -125, -185, -370 }, { -166, -110, -445 },
    { -246, -69, -335 },  { -277, -93, -416 },  { -342, -132, -280 }, { -292, -219, -231 },
    { -258, -243, -302 }, { -113, -243, -280 }, { -172, -260, -335 }, { -358, 57, 132 },
    { -363, 17, 151 },    { -311, 79, 200 },    { -407, 29, 97 },     { -345, 5, -6 },
    { -395, 101, -33 },   { -391, 132, 5 },     { -351, 211, 49 },    { -362, 145, 57 },
    { -385, -16, 93 },    { -343, -31, 227 },   { -283, -7, -287 },   { -273, -85, -230 },
    { -360, 187, -363 },  { -206, 36, -541 },   { -406, 115, -313 },  { -303, -200, -423 },
    { -345, -172, -370 }, { -295, -131, -457 }, { -241, -139, -464 }, { -204, -203, -428 },
    { -294, -239, -381 }, { -243, -262, -358 }, { -78, -230, -456 },  { -56, -159, -486 },
    { -32, -210, -431 },  { -97, -166, -483 },  { -124, -217, -428 }, { -103, -257, -404 },
    { -56, -257, -404 },  { -174, -205, -404 }, { -311, 216, 143 },   { -418, 39, 39 },
    { -411, 73, 85 },     { -327, 106, 129 },   { -374, -65, 73 },    { -348, -76, -25 },
    { -345, -167, 56 },   { -369, -90, 62 },    { -345, -32, -2 },    { -237, 378, 229 },
    { -314, 331, 289 },   { -243, 407, 458 },   { -127, 441, 523 },   { -439, 41, -227 },
    { -436, -20, -205 },  { -504, 4, -195 },    { -416, -115, -95 },  { -422, -63, -95 },
    { -339, 63, -209 },   { -348, -73, -156 },  { -390, -13, -203 },  { -401, -99, -132 },
    { -342, -114, -82 },  { -484, -69, -165 },  { -412, -69, -184 },  { -470, -19, -130 },
    { -425, -38, -132 },  { -375, -21, -59 },   { -407, 80, -78 },    { -385, 17, -116 },
    { -379, 21, -58 },    { -424, 90, -198 },   { -382, 54, -197 },   { -389, 29, -202 },
    { -496, 52, -220 },   { -483, 49, -147 },   { -466, 126, -176 },  { -432, 145, -125 },
    { -465, 96, -107 },   { -186, -226, -173 }, { -260, -175, -198 }, { -132, 423, 573 },
    { -94, -363, 22 },    { -77, -339, 122 },   { -123, 383, 276 },   { -252, -20, -373 },
    { -430, 29, -155 },   { -254, -230, -63 },  { -159, -331, 5 },    { -297, -152, -126 },
    { -322, -122, -180 }, { -49, 394, -230 },   { -145, 91, 567 },    { -124, 85, 409 },
    { -169, 2, 567 },     { -151, 5, 459 },     { -119, -69, 429 },   { -106, -104, 567 },
    { -118, 1, 636 },     { -128, 20, 390 },    { -115, -178, 351 },  { -157, -164, 336 },
    { -155, -149, 317 },  { -127, -190, 214 },  { -75, -227, 201 },   { -367, 553, 169 },
    { -236, 536, 288 },   { -263, 636, 246 },   { -148, 624, 303 },   { -144, 693, 290 },
    { -67, 655, 314 },    { -434, 326, -209 },  { -243, 714, 165 },   { -356, 611, 78 },
    { -183, 744, 77 },    { -299, 642, -9 },    { -344, 531, -97 },   { -366, -103, 153 },
    { -267, -115, 314 },  { -296, 35, 287 },    { -242, 98, 288 },    { -192, 221, 279 },
    { -162, -139, 369 },  { -91, -147, 273 },   { -288, -237, 119 },  { -165, -299, 114 },
    { -172, -251, 176 },  { -219, 24, 358 },    { -143, 91, 333 },    { -203, -50, 366 },
    { -125, -76, 401 },   { -82, 87, 288 },     { -83, 86, 359 },     { -41, 126, 357 },
    { -138, 92, 254 },    { -177, 107, 311 },   { -167, 120, 250 },   { -198, 155, 286 },
    { -181, 221, 239 },   { -161, 268, 247 },   { -169, 277, 296 },   { -124, 298, 270 },
    { -127, 314, 325 },   { -73, 290, 291 },    { -56, 128, 309 },    { -59, 261, 299 },
    { -265, 141, 195 },   { -233, 346, 207 },   { -281, 383, 493 },   { -349, 313, 311 },
    { -308, -167, 222 },  { -135, -283, 182 },  { -74, -321, 190 },   { -218, -191, 287 },
    { -164, -187, 321 },  { -162, -260, 265 },  { -144, -241, 291 },  { -99, -284, 283 },
    { -62, -329, 252 },   { -41, -314, 282 },   { -66, -284, 272 },   { -125, -295, 252 },
    { -127, -226, 276 },  { -431, 480, -59 },   { 0, -320, 282 },     { -181, 161, 238 },
    { 0, 461, 348 },      { -72, 454, 336 },    { 72, 454, 336 },     { 181, 165, 241 },
    { 0, 529, 345 },      { 113, 529, 326 },    { -59, 524, 333 },    { 59, 524, 333 },
    { 0, 306, 339 },      { 0, 224, 357 },      { 162, 48, 567 },     { 156, -52, 567 },
    { -77, 126, 434 },    { -156, -52, 567 },   { -90, 127, 567 },    { 88, 127, 567 },
    { -67, -114, 567 },   { 66, -114, 567 },    { 76, 126, 434 },     { -157, 46, 567 },
};

static struct GdVtxData mario_Face_VtxInfo = { ARRAY_COUNT(mario_Face_VtxData), 0x1, mario_Face_VtxData };

static u16 mario_Face_FaceData[][4] = {
    { 0, 43, 102, 112 },  { 0, 102, 42, 188 },  { 0, 354, 356, 188 }, { 0, 188, 198, 354 },
    { 0, 198, 188, 42 },  { 0, 43, 42, 102 },   { 1, 4, 5, 6 },       { 1, 7, 8, 9 },
    { 1, 10, 11, 5 },     { 1, 15, 16, 17 },    { 1, 18, 19, 20 },    { 1, 21, 22, 15 },
    { 1, 23, 24, 22 },    { 1, 27, 25, 26 },    { 1, 27, 26, 431 },   { 1, 435, 23, 22 },
    { 1, 30, 23, 435 },   { 1, 4, 31, 32 },     { 1, 33, 34, 35 },    { 1, 36, 37, 38 },
    { 1, 11, 39, 40 },    { 1, 437, 26, 25 },   { 1, 18, 26, 19 },    { 1, 42, 43, 44 },
    { 1, 45, 46, 47 },    { 1, 48, 49, 50 },    { 1, 47, 46, 51 },    { 1, 59, 60, 61 },
    { 1, 62, 63, 64 },    { 1, 59, 65, 66 },    { 1, 34, 33, 45 },    { 1, 24, 15, 22 },
    { 1, 20, 15, 18 },    { 1, 82, 83, 28 },    { 1, 82, 28, 438 },   { 1, 84, 64, 63 },
    { 1, 85, 86, 31 },    { 1, 87, 20, 19 },    { 1, 35, 16, 20 },    { 1, 88, 89, 61 },
    { 1, 90, 91, 92 },    { 1, 6, 5, 93 },      { 1, 94, 95, 37 },    { 1, 96, 95, 94 },
    { 1, 21, 15, 97 },    { 1, 10, 32, 105 },   { 1, 87, 44, 20 },    { 1, 106, 96, 107 },
    { 1, 96, 64, 95 },    { 1, 94, 108, 96 },   { 1, 109, 35, 110 },  { 1, 35, 109, 6 },
    { 1, 111, 109, 112 }, { 1, 100, 99, 113 },  { 1, 114, 113, 115 }, { 1, 114, 32, 31 },
    { 1, 113, 31, 100 },  { 1, 5, 4, 10 },      { 1, 105, 114, 116 }, { 1, 4, 85, 31 },
    { 1, 109, 111, 6 },   { 1, 6, 85, 4 },      { 1, 37, 93, 94 },    { 1, 35, 6, 93 },
    { 1, 35, 93, 37 },    { 1, 20, 44, 110 },   { 1, 20, 110, 35 },   { 1, 38, 37, 95 },
    { 1, 84, 95, 64 },    { 1, 105, 117, 39 },  { 1, 10, 39, 11 },    { 1, 108, 94, 11 },
    { 1, 94, 93, 5 },     { 1, 118, 119, 120 }, { 1, 57, 9, 8 },      { 1, 88, 122, 89 },
    { 1, 123, 59, 61 },   { 1, 49, 7, 9 },      { 1, 47, 51, 124 },   { 1, 47, 124, 97 },
    { 1, 125, 8, 46 },    { 1, 50, 129, 48 },   { 1, 126, 130, 82 },  { 1, 128, 131, 48 },
    { 1, 131, 49, 48 },   { 1, 132, 7, 49 },    { 1, 133, 8, 7 },     { 1, 134, 51, 8 },
    { 1, 135, 124, 51 },  { 1, 136, 97, 124 },  { 1, 127, 21, 97 },   { 1, 127, 82, 21 },
    { 1, 34, 17, 35 },    { 1, 35, 17, 16 },    { 1, 15, 20, 16 },    { 1, 97, 15, 17 },
    { 1, 47, 97, 17 },    { 1, 34, 47, 17 },    { 1, 137, 84, 138 },  { 1, 88, 120, 122 },
    { 1, 84, 137, 95 },   { 1, 94, 5, 11 },     { 1, 110, 44, 43 },   { 1, 60, 53, 139 },
    { 1, 140, 141, 139 }, { 1, 57, 8, 125 },    { 1, 118, 140, 119 }, { 1, 34, 45, 47 },
    { 1, 37, 144, 33 },   { 1, 37, 33, 35 },    { 1, 18, 15, 24 },    { 1, 431, 26, 18 },
    { 1, 30, 27, 23 },    { 1, 161, 27, 30 },   { 1, 161, 25, 27 },   { 1, 430, 23, 27 },
    { 1, 431, 160, 27 },  { 1, 19, 26, 437 },   { 1, 19, 437, 41 },   { 1, 430, 160, 24 },
    { 1, 106, 64, 96 },   { 1, 40, 166, 108 },  { 1, 166, 107, 108 }, { 1, 96, 108, 107 },
    { 1, 84, 63, 167 },   { 1, 89, 168, 123 },  { 1, 123, 61, 89 },   { 1, 59, 123, 65 },
    { 1, 88, 118, 120 },  { 1, 59, 66, 53 },    { 1, 61, 139, 141 },  { 1, 61, 141, 88 },
    { 1, 169, 170, 45 },  { 1, 39, 177, 40 },   { 1, 178, 166, 177 }, { 1, 107, 166, 179 },
    { 1, 180, 107, 181 }, { 1, 161, 30, 182 },  { 1, 183, 25, 161 },  { 1, 129, 196, 428 },
    { 1, 428, 196, 197 }, { 1, 429, 197, 387 }, { 1, 198, 44, 199 },  { 1, 199, 44, 87 },
    { 1, 182, 30, 29 },   { 1, 41, 25, 183 },   { 1, 180, 165, 106 }, { 1, 180, 106, 107 },
    { 1, 139, 61, 60 },   { 1, 59, 53, 60 },    { 1, 65, 123, 92 },   { 1, 224, 66, 225 },
    { 1, 226, 225, 91 },  { 1, 227, 91, 228 },  { 1, 63, 227, 228 },  { 1, 63, 228, 167 },
    { 1, 91, 90, 228 },   { 1, 66, 224, 53 },   { 1, 118, 141, 140 }, { 1, 141, 118, 88 },
    { 1, 90, 92, 168 },   { 1, 120, 229, 122 }, { 1, 119, 137, 120 }, { 1, 90, 229, 138 },
    { 1, 168, 122, 229 }, { 1, 90, 167, 228 },  { 1, 90, 138, 167 },  { 1, 167, 138, 84 },
    { 1, 138, 229, 137 }, { 1, 225, 92, 91 },   { 1, 231, 45, 33 },   { 1, 140, 144, 119 },
    { 1, 137, 119, 38 },  { 1, 137, 38, 95 },   { 1, 125, 170, 172 }, { 1, 36, 119, 144 },
    { 1, 57, 125, 143 },  { 1, 144, 231, 33 },  { 1, 169, 45, 231 },  { 1, 263, 264, 265 },
    { 1, 272, 273, 264 }, { 1, 246, 270, 294 }, { 1, 298, 272, 267 }, { 1, 294, 271, 297 },
    { 1, 299, 300, 301 }, { 1, 299, 301, 302 }, { 1, 302, 298, 267 }, { 1, 264, 273, 265 },
    { 1, 307, 308, 309 }, { 1, 310, 299, 311 }, { 1, 315, 316, 310 }, { 1, 317, 315, 310 },
    { 1, 317, 318, 315 }, { 1, 319, 311, 320 }, { 1, 317, 310, 311 }, { 1, 302, 321, 299 },
    { 1, 321, 320, 311 }, { 1, 317, 319, 309 }, { 1, 322, 323, 324 }, { 1, 324, 267, 322 },
    { 1, 325, 243, 326 }, { 1, 308, 318, 317 }, { 1, 313, 315, 318 }, { 1, 313, 318, 314 },
    { 1, 314, 318, 308 }, { 1, 327, 308, 307 }, { 1, 326, 307, 325 }, { 1, 328, 309, 329 },
    { 1, 330, 331, 243 }, { 1, 244, 331, 332 }, { 1, 261, 179, 333 }, { 1, 261, 333, 334 },
    { 1, 336, 177, 337 }, { 1, 178, 177, 336 }, { 1, 263, 265, 297 }, { 1, 332, 323, 322 },
    { 1, 332, 322, 244 }, { 1, 330, 243, 325 }, { 1, 323, 321, 324 }, { 1, 330, 328, 329 },
    { 1, 329, 340, 332 }, { 1, 340, 329, 319 }, { 1, 316, 315, 313 }, { 1, 341, 179, 342 },
    { 1, 178, 342, 179 }, { 1, 336, 342, 178 }, { 1, 333, 341, 343 }, { 1, 434, 29, 28 },
    { 1, 349, 350, 433 }, { 1, 436, 351, 19 },  { 1, 436, 19, 41 },   { 1, 433, 351, 352 },
    { 1, 161, 352, 183 }, { 1, 161, 182, 352 }, { 1, 350, 349, 353 }, { 1, 354, 355, 356 },
    { 1, 371, 372, 273 }, { 1, 371, 273, 272 }, { 1, 373, 374, 265 }, { 1, 324, 302, 267 },
    { 1, 246, 294, 375 }, { 1, 267, 244, 322 }, { 1, 331, 244, 243 }, { 1, 376, 354, 199 },
    { 1, 378, 379, 380 }, { 1, 316, 300, 299 }, { 1, 323, 320, 321 }, { 1, 299, 310, 316 },
    { 1, 373, 381, 374 }, { 1, 374, 381, 382 }, { 1, 382, 381, 353 }, { 1, 353, 383, 384 },
    { 1, 372, 383, 381 }, { 1, 373, 372, 381 }, { 1, 385, 386, 387 }, { 1, 385, 382, 386 },
    { 1, 388, 389, 382 }, { 1, 390, 391, 389 }, { 1, 392, 375, 391 }, { 1, 393, 394, 375 },
    { 1, 395, 396, 394 }, { 1, 397, 196, 396 }, { 1, 399, 197, 196 }, { 1, 398, 387, 197 },
    { 1, 338, 196, 129 }, { 1, 401, 394, 396 }, { 1, 294, 400, 375 }, { 1, 374, 382, 389 },
    { 1, 374, 389, 391 }, { 1, 329, 332, 330 }, { 1, 323, 340, 320 }, { 1, 246, 375, 401 },
    { 1, 324, 321, 302 }, { 1, 378, 380, 404 }, { 1, 342, 379, 378 }, { 1, 405, 379, 337 },
    { 1, 406, 337, 117 }, { 1, 316, 343, 300 }, { 1, 301, 300, 371 }, { 1, 384, 372, 376 },
    { 1, 384, 376, 199 }, { 1, 372, 371, 404 }, { 1, 372, 404, 407 }, { 1, 371, 378, 404 },
    { 1, 356, 355, 408 }, { 1, 407, 409, 410 }, { 1, 355, 407, 408 }, { 1, 409, 411, 410 },
    { 1, 406, 116, 412 }, { 1, 380, 405, 409 }, { 1, 413, 414, 411 }, { 1, 412, 411, 415 },
    { 1, 412, 115, 413 }, { 1, 414, 413, 99 },  { 1, 372, 407, 355 }, { 1, 355, 376, 372 },
    { 1, 300, 341, 378 }, { 1, 341, 300, 343 }, { 1, 333, 179, 341 }, { 1, 87, 384, 199 },
    { 1, 405, 406, 415 }, { 1, 386, 382, 353 }, { 1, 342, 378, 341 }, { 1, 378, 371, 300 },
    { 1, 407, 404, 380 }, { 1, 317, 309, 308 }, { 1, 323, 332, 340 }, { 1, 372, 384, 383 },
    { 1, 87, 19, 384 },   { 1, 347, 432, 387 }, { 1, 410, 411, 416 }, { 1, 384, 350, 353 },
    { 1, 349, 347, 353 }, { 1, 373, 265, 273 }, { 1, 330, 325, 328 }, { 1, 343, 316, 313 },
    { 1, 330, 332, 331 }, { 1, 374, 391, 400 }, { 1, 196, 338, 396 }, { 1, 265, 374, 400 },
    { 1, 198, 199, 354 }, { 1, 350, 19, 351 },  { 1, 436, 41, 183 },  { 1, 379, 336, 337 },
    { 1, 298, 301, 371 }, { 1, 273, 372, 373 }, { 1, 409, 415, 411 }, { 1, 434, 346, 182 },
    { 1, 183, 352, 351 }, { 1, 346, 347, 349 }, { 1, 386, 353, 347 }, { 1, 350, 384, 19 },
    { 1, 353, 381, 383 }, { 1, 405, 380, 379 }, { 1, 394, 401, 375 }, { 1, 409, 407, 380 },
    { 1, 342, 336, 379 }, { 1, 307, 328, 325 }, { 1, 414, 416, 411 }, { 1, 412, 415, 406 },
    { 1, 418, 99, 413 },  { 1, 418, 413, 115 }, { 1, 413, 411, 412 }, { 1, 415, 409, 405 },
    { 1, 115, 412, 116 }, { 1, 116, 406, 117 }, { 1, 406, 405, 337 }, { 1, 391, 375, 400 },
    { 1, 399, 398, 197 }, { 1, 395, 397, 396 }, { 1, 393, 395, 394 }, { 1, 392, 393, 375 },
    { 1, 419, 392, 391 }, { 1, 419, 391, 390 }, { 1, 390, 389, 388 }, { 1, 388, 382, 385 },
    { 1, 398, 385, 387 }, { 1, 355, 354, 376 }, { 1, 298, 371, 272 }, { 1, 334, 333, 343 },
    { 1, 320, 340, 319 }, { 1, 400, 297, 265 }, { 1, 117, 337, 177 }, { 1, 327, 307, 326 },
    { 1, 314, 308, 327 }, { 1, 329, 309, 319 }, { 1, 319, 317, 311 }, { 1, 321, 311, 299 },
    { 1, 328, 307, 309 }, { 1, 298, 302, 301 }, { 1, 400, 294, 297 }, { 1, 271, 294, 270 },
    { 1, 172, 143, 125 }, { 1, 46, 170, 125 },  { 1, 36, 38, 119 },   { 1, 65, 92, 225 },
    { 1, 120, 137, 229 }, { 1, 168, 229, 90 },  { 1, 123, 168, 92 },  { 1, 227, 226, 91 },
    { 1, 226, 224, 225 }, { 1, 42, 44, 198 },   { 1, 117, 177, 39 },  { 1, 179, 181, 107 },
    { 1, 261, 181, 179 }, { 1, 178, 179, 166 }, { 1, 46, 45, 170 },   { 1, 122, 168, 89 },
    { 1, 165, 64, 106 },  { 1, 112, 109, 43 },  { 1, 36, 144, 37 },   { 1, 109, 110, 43 },
    { 1, 126, 82, 127 },  { 1, 136, 127, 97 },  { 1, 135, 136, 124 }, { 1, 423, 135, 51 },
    { 1, 423, 51, 134 },  { 1, 134, 8, 133 },   { 1, 133, 7, 132 },   { 1, 132, 49, 131 },
    { 1, 128, 130, 126 }, { 1, 51, 46, 8 },     { 1, 105, 39, 10 },   { 1, 116, 117, 105 },
    { 1, 115, 116, 114 }, { 1, 32, 10, 4 },     { 1, 113, 114, 31 },  { 1, 418, 115, 113 },
    { 1, 418, 113, 99 },  { 1, 114, 105, 32 },  { 1, 100, 31, 86 },   { 1, 225, 66, 65 },
    { 1, 108, 11, 40 },   { 1, 166, 40, 177 },  { 1, 64, 165, 62 },   { 1, 343, 313, 344 },
    { 1, 343, 344, 334 }, { 1, 111, 85, 6 },    { 1, 112, 86, 111 },  { 1, 408, 410, 416 },
    { 1, 407, 410, 408 }, { 1, 416, 356, 408 }, { 1, 86, 85, 111 },   { 1, 428, 48, 129 },
    { 1, 428, 429, 130 }, { 1, 130, 429, 83 },  { 1, 387, 83, 429 },  { 1, 83, 82, 130 },
    { 1, 130, 48, 428 },  { 1, 197, 429, 428 }, { 1, 438, 22, 21 },   { 1, 432, 28, 83 },
    { 1, 432, 83, 387 },  { 1, 387, 386, 347 }, { 1, 21, 82, 438 },   { 1, 347, 346, 434 },
    { 1, 28, 29, 435 },   { 1, 183, 351, 436 }, { 1, 25, 41, 437 },   { 1, 27, 160, 430 },
    { 1, 24, 23, 430 },   { 1, 431, 18, 24 },   { 1, 24, 160, 431 },  { 1, 350, 351, 433 },
    { 1, 433, 348, 349 }, { 1, 352, 348, 433 }, { 1, 435, 29, 30 },   { 1, 182, 29, 434 },
    { 1, 28, 432, 434 },  { 1, 435, 438, 28 },  { 1, 434, 432, 347 }, { 1, 22, 438, 435 },
    { 1, 396, 338, 401 }, { 1, 9, 50, 49 },     { 1, 196, 397, 399 }, { 1, 48, 130, 128 },
    { 1, 349, 348, 439 }, { 1, 439, 348, 352 }, { 1, 439, 346, 349 }, { 1, 439, 348, 352 },
    { 1, 439, 352, 182 }, { 1, 182, 346, 439 }, { 2, 12, 13, 14 },    { 2, 153, 13, 12 },
    { 2, 153, 191, 13 },  { 2, 153, 200, 191 }, { 2, 256, 191, 253 }, { 2, 256, 274, 339 },
    { 2, 274, 312, 339 }, { 2, 256, 339, 191 }, { 3, 184, 185, 186 }, { 3, 156, 150, 424 },
    { 3, 155, 154, 425 }, { 3, 426, 421, 420 }, { 3, 420, 422, 427 }, { 3, 184, 364, 362 },
    { 3, 157, 156, 425 }, { 3, 150, 364, 424 }, { 3, 362, 185, 184 }, { 3, 425, 154, 157 },
    { 4, 126, 127, 128 }, { 4, 398, 399, 385 }, { 4, 388, 385, 399 }, { 4, 390, 388, 399 },
    { 4, 419, 390, 399 }, { 4, 392, 419, 399 }, { 4, 393, 392, 399 }, { 4, 395, 393, 399 },
    { 4, 397, 395, 399 }, { 4, 136, 128, 127 }, { 4, 135, 128, 136 }, { 4, 423, 128, 135 },
    { 4, 134, 128, 423 }, { 4, 133, 128, 134 }, { 4, 132, 128, 133 }, { 4, 131, 128, 132 },
    { 5, 14, 63, 74 },    { 5, 14, 74, 12 },    { 5, 142, 57, 143 },  { 5, 74, 62, 165 },
    { 5, 170, 171, 172 }, { 5, 180, 203, 165 }, { 5, 204, 205, 206 }, { 5, 207, 200, 208 },
    { 5, 209, 210, 200 }, { 5, 211, 206, 212 }, { 5, 181, 212, 206 }, { 5, 213, 214, 215 },
    { 5, 216, 217, 218 }, { 5, 216, 219, 217 }, { 5, 220, 221, 214 }, { 5, 222, 223, 221 },
    { 5, 222, 218, 223 }, { 5, 14, 224, 226 },  { 5, 14, 226, 227 },  { 5, 14, 53, 224 },
    { 5, 14, 227, 63 },   { 5, 232, 171, 233 }, { 5, 232, 233, 144 }, { 5, 234, 172, 171 },
    { 5, 233, 231, 144 }, { 5, 171, 170, 169 }, { 5, 232, 234, 171 }, { 5, 140, 235, 232 },
    { 5, 140, 232, 144 }, { 5, 210, 206, 211 }, { 5, 180, 207, 208 }, { 5, 236, 219, 214 },
    { 5, 205, 181, 206 }, { 5, 209, 200, 207 }, { 5, 237, 207, 180 }, { 5, 205, 180, 181 },
    { 5, 237, 180, 205 }, { 5, 211, 200, 210 }, { 5, 204, 237, 205 }, { 5, 204, 207, 237 },
    { 5, 204, 209, 207 }, { 5, 204, 210, 209 }, { 5, 204, 206, 210 }, { 5, 213, 220, 214 },
    { 5, 213, 222, 220 }, { 5, 216, 238, 213 }, { 5, 213, 215, 216 }, { 5, 213, 238, 222 },
    { 5, 12, 74, 153 },   { 5, 143, 172, 234 }, { 5, 239, 234, 235 }, { 5, 239, 235, 139 },
    { 5, 139, 235, 140 }, { 5, 169, 231, 233 }, { 5, 180, 208, 236 }, { 5, 180, 236, 203 },
    { 5, 203, 221, 223 }, { 5, 153, 223, 218 }, { 5, 200, 153, 217 }, { 5, 200, 217, 208 },
    { 5, 253, 254, 255 }, { 5, 253, 255, 256 }, { 5, 256, 257, 258 }, { 5, 259, 258, 260 },
    { 5, 261, 259, 262 }, { 5, 261, 262, 254 }, { 5, 263, 266, 264 }, { 5, 244, 267, 268 },
    { 5, 245, 244, 268 }, { 5, 245, 268, 269 }, { 5, 270, 269, 271 }, { 5, 274, 256, 275 },
    { 5, 279, 280, 281 }, { 5, 279, 282, 283 }, { 5, 282, 279, 281 }, { 5, 279, 284, 280 },
    { 5, 279, 285, 284 }, { 5, 286, 287, 288 }, { 5, 286, 289, 287 }, { 5, 286, 290, 289 },
    { 5, 286, 291, 290 }, { 5, 286, 292, 291 }, { 5, 211, 287, 253 }, { 5, 291, 292, 261 },
    { 5, 292, 181, 261 }, { 5, 291, 261, 290 }, { 5, 289, 290, 253 }, { 5, 292, 288, 181 },
    { 5, 212, 288, 211 }, { 5, 262, 285, 293 }, { 5, 261, 254, 290 }, { 5, 287, 211, 288 },
    { 5, 267, 272, 295 }, { 5, 267, 295, 268 }, { 5, 295, 296, 269 }, { 5, 296, 263, 297 },
    { 5, 266, 272, 264 }, { 5, 269, 296, 271 }, { 5, 295, 272, 266 }, { 5, 295, 266, 296 },
    { 5, 312, 313, 314 }, { 5, 312, 326, 243 }, { 5, 312, 314, 327 }, { 5, 312, 327, 326 },
    { 5, 280, 258, 257 }, { 5, 280, 260, 258 }, { 5, 285, 262, 260 }, { 5, 282, 255, 293 },
    { 5, 282, 257, 255 }, { 5, 279, 283, 285 }, { 5, 181, 288, 212 }, { 5, 289, 253, 287 },
    { 5, 290, 254, 253 }, { 5, 286, 288, 292 }, { 5, 261, 334, 259 }, { 5, 297, 271, 296 },
    { 5, 275, 334, 344 }, { 5, 312, 275, 313 }, { 5, 248, 270, 246 }, { 5, 275, 344, 313 },
    { 5, 312, 274, 275 }, { 5, 284, 285, 260 }, { 5, 236, 214, 221 }, { 5, 259, 334, 275 },
    { 5, 211, 253, 191 }, { 5, 281, 257, 282 }, { 5, 283, 282, 293 }, { 5, 284, 260, 280 },
    { 5, 281, 280, 257 }, { 5, 266, 263, 296 }, { 5, 268, 295, 269 }, { 5, 283, 293, 285 },
    { 5, 248, 269, 270 }, { 5, 248, 245, 269 }, { 5, 293, 254, 262 }, { 5, 260, 262, 259 },
    { 5, 275, 258, 259 }, { 5, 275, 256, 258 }, { 5, 257, 256, 255 }, { 5, 293, 255, 254 },
    { 5, 219, 208, 217 }, { 5, 218, 217, 153 }, { 5, 74, 223, 153 },  { 5, 74, 203, 223 },
    { 5, 221, 203, 236 }, { 5, 219, 236, 208 }, { 5, 142, 234, 239 }, { 5, 142, 143, 234 },
    { 5, 191, 200, 211 }, { 5, 215, 214, 219 }, { 5, 235, 234, 232 }, { 5, 233, 171, 169 },
    { 5, 238, 218, 222 }, { 5, 220, 222, 221 }, { 5, 215, 219, 216 }, { 5, 238, 216, 218 },
    { 5, 203, 74, 165 },  { 5, 74, 63, 62 },    { 6, 98, 99, 100 },   { 6, 101, 102, 103 },
    { 6, 104, 100, 86 },  { 6, 112, 101, 103 }, { 6, 103, 98, 104 },  { 6, 103, 104, 159 },
    { 6, 103, 159, 112 }, { 6, 102, 101, 112 }, { 6, 103, 102, 187 }, { 6, 99, 98, 189 },
    { 6, 189, 98, 103 },  { 6, 189, 103, 187 }, { 6, 187, 356, 357 }, { 6, 187, 357, 358 },
    { 6, 187, 358, 189 }, { 6, 356, 187, 377 }, { 6, 358, 416, 414 }, { 6, 377, 187, 188 },
    { 6, 189, 414, 99 },  { 6, 358, 414, 189 }, { 6, 357, 416, 358 }, { 6, 357, 356, 416 },
    { 6, 356, 377, 188 }, { 6, 188, 187, 102 }, { 6, 159, 86, 112 },  { 6, 159, 104, 86 },
    { 6, 104, 98, 100 },  { 7, 0, 1, 2 },       { 7, 3, 1, 0 },       { 7, 52, 53, 14 },
    { 7, 54, 55, 56 },    { 7, 55, 9, 57 },     { 7, 53, 52, 58 },    { 7, 67, 2, 68 },
    { 7, 69, 70, 71 },    { 7, 72, 3, 73 },     { 7, 54, 56, 75 },    { 7, 76, 77, 78 },
    { 7, 2, 1, 79 },      { 7, 80, 1, 81 },     { 7, 75, 50, 54 },    { 7, 57, 121, 55 },
    { 7, 54, 50, 55 },    { 7, 145, 78, 146 },  { 7, 2, 79, 147 },    { 7, 71, 70, 147 },
    { 7, 147, 148, 71 },  { 7, 71, 149, 69 },   { 7, 150, 151, 69 },  { 7, 52, 0, 145 },
    { 7, 152, 145, 68 },  { 7, 76, 68, 70 },    { 7, 151, 70, 69 },   { 7, 52, 3, 0 },
    { 7, 80, 79, 1 },     { 7, 77, 154, 155 },  { 7, 151, 156, 157 }, { 7, 151, 157, 76 },
    { 7, 155, 158, 77 },  { 7, 158, 57, 78 },   { 7, 152, 78, 145 },  { 7, 72, 162, 3 },
    { 7, 80, 81, 163 },   { 7, 52, 14, 164 },   { 7, 52, 164, 3 },    { 7, 72, 173, 162 },
    { 7, 173, 174, 163 }, { 7, 175, 72, 176 },  { 7, 72, 73, 190 },   { 7, 150, 69, 192 },
    { 7, 69, 149, 192 },  { 7, 193, 79, 194 },  { 7, 195, 148, 193 }, { 7, 79, 80, 194 },
    { 7, 50, 75, 129 },   { 7, 75, 201, 202 },  { 7, 155, 230, 201 }, { 7, 155, 201, 56 },
    { 7, 155, 56, 121 },  { 7, 158, 121, 57 },  { 7, 3, 164, 73 },    { 7, 175, 174, 173 },
    { 7, 162, 173, 81 },  { 7, 162, 81, 1 },    { 7, 57, 146, 78 },   { 7, 239, 58, 142 },
    { 7, 57, 142, 146 },  { 7, 139, 58, 239 },  { 7, 53, 58, 139 },   { 7, 145, 58, 52 },
    { 7, 240, 241, 242 }, { 7, 243, 244, 242 }, { 7, 244, 245, 242 }, { 7, 246, 247, 248 },
    { 7, 245, 248, 242 }, { 7, 246, 249, 247 }, { 7, 250, 251, 252 }, { 7, 250, 252, 175 },
    { 7, 276, 277, 278 }, { 7, 303, 246, 304 }, { 7, 186, 304, 305 }, { 7, 186, 305, 306 },
    { 7, 186, 306, 230 }, { 7, 335, 202, 306 }, { 7, 338, 129, 335 }, { 7, 339, 277, 191 },
    { 7, 176, 250, 175 }, { 7, 241, 276, 278 }, { 7, 241, 278, 312 }, { 7, 345, 174, 252 },
    { 7, 176, 276, 250 }, { 7, 359, 240, 249 }, { 7, 303, 249, 246 }, { 7, 186, 360, 303 },
    { 7, 361, 185, 362 }, { 7, 363, 364, 150 }, { 7, 360, 186, 185 }, { 7, 345, 251, 194 },
    { 7, 241, 365, 276 }, { 7, 339, 278, 277 }, { 7, 363, 192, 366 }, { 7, 361, 366, 367 },
    { 7, 359, 367, 240 }, { 7, 241, 240, 365 }, { 7, 150, 192, 363 }, { 7, 368, 192, 195 },
    { 7, 369, 368, 193 }, { 7, 368, 369, 366 }, { 7, 370, 369, 194 }, { 7, 240, 247, 249 },
    { 7, 402, 403, 338 }, { 7, 246, 403, 304 }, { 7, 335, 402, 338 }, { 7, 345, 252, 251 },
    { 7, 370, 194, 251 }, { 7, 361, 249, 360 }, { 7, 402, 335, 305 }, { 7, 176, 277, 276 },
    { 7, 192, 368, 366 }, { 7, 417, 367, 370 }, { 7, 243, 242, 241 }, { 7, 403, 246, 401 },
    { 7, 402, 305, 403 }, { 7, 241, 312, 243 }, { 7, 276, 365, 251 }, { 7, 365, 370, 251 },
    { 7, 417, 370, 365 }, { 7, 250, 276, 251 }, { 7, 304, 403, 305 }, { 7, 369, 370, 367 },
    { 7, 306, 305, 335 }, { 7, 359, 249, 361 }, { 7, 401, 338, 403 }, { 7, 193, 194, 369 },
    { 7, 367, 366, 369 }, { 7, 195, 193, 368 }, { 7, 417, 365, 240 }, { 7, 417, 240, 367 },
    { 7, 359, 361, 367 }, { 7, 361, 363, 366 }, { 7, 360, 185, 361 }, { 7, 249, 303, 360 },
    { 7, 163, 174, 80 },  { 7, 190, 191, 277 }, { 7, 202, 335, 129 }, { 7, 230, 306, 202 },
    { 7, 421, 186, 230 }, { 7, 421, 230, 420 }, { 7, 303, 304, 186 }, { 7, 174, 175, 252 },
    { 7, 242, 248, 247 }, { 7, 247, 240, 242 }, { 7, 146, 58, 145 },  { 7, 58, 146, 142 },
    { 7, 163, 81, 173 },  { 7, 158, 155, 121 }, { 7, 230, 155, 422 }, { 7, 230, 422, 420 },
    { 7, 230, 202, 201 }, { 7, 202, 129, 75 },  { 7, 345, 194, 80 },  { 7, 149, 148, 195 },
    { 7, 148, 79, 193 },  { 7, 195, 192, 149 }, { 7, 190, 73, 191 },  { 7, 176, 72, 190 },
    { 7, 277, 176, 190 }, { 7, 173, 72, 175 },  { 7, 78, 77, 158 },   { 7, 77, 76, 154 },
    { 7, 76, 70, 151 },   { 7, 152, 68, 76 },   { 7, 67, 68, 145 },   { 7, 67, 145, 0 },
    { 7, 149, 71, 148 },  { 7, 68, 147, 70 },   { 7, 148, 147, 79 },  { 7, 9, 55, 50 },
    { 7, 152, 76, 78 },   { 7, 201, 75, 56 },   { 7, 147, 68, 2 },    { 7, 121, 56, 55 },
    { 7, 164, 14, 13 },   { 7, 162, 1, 3 },     { 7, 67, 0, 2 },      { 7, 345, 80, 174 },
    { 7, 73, 13, 191 },   { 7, 73, 164, 13 },   { 7, 312, 278, 339 }, { 7, 186, 421, 184 },
    { 7, 420, 424, 426 }, { 7, 422, 425, 427 }, { 7, 426, 424, 364 }, { 7, 425, 156, 427 },
    { 7, 363, 361, 362 }, { 7, 362, 364, 363 }, { 7, 157, 154, 76 },  { 7, 151, 150, 156 },
    { 7, 421, 426, 184 }, { 7, 422, 155, 425 }, { 7, 420, 427, 424 }, { 7, 364, 184, 426 },
    { 7, 156, 424, 427 },
};

static struct GdFaceData mario_Face_FaceInfo = { ARRAY_COUNT(mario_Face_FaceData), 0x1, mario_Face_FaceData };

struct DynList dynlist_mario_face_shape[] = {
    BeginList(),

    MakeDynObj(D_DATA_GRP, DYNOBJ_MARIO_FACE_VTX_GROUP),
        LinkWithPtr(&mario_Face_VtxInfo),

    MakeDynObj(D_DATA_GRP, DYNOBJ_MARIO_FACE_TRI_GROUP),
        LinkWithPtr(&mario_Face_FaceInfo),

    StartGroup(DYNOBJ_MARIO_FACE_MTL_GROUP),
        // Teeth color
        MakeDynObj(D_MATERIAL, 0),
            SetId(0),
            SetAmbient(1.0, 1.0, 1.0),
            SetDiffuse(1.0, 1.0, 1.0),
        // Face color
        MakeDynObj(D_MATERIAL, 0),
            SetId(1),
            SetAmbient(0.883, 0.602, 0.408),
            SetDiffuse(0.883, 0.602, 0.408),
        // Shadow on back of hat
        MakeDynObj(D_MATERIAL, 0),
            SetId(2),
            SetAmbient(0.0, 0.362, 0.0),
            SetDiffuse(0.0, 0.362, 0.0),
        // Cap emblem color
        MakeDynObj(D_MATERIAL, 0),
            SetId(3),
            SetAmbient(1.0, 1.0, 1.0),
            SetDiffuse(1.0, 1.0, 1.0),
        // Eye color
        MakeDynObj(D_MATERIAL, 0),
            SetId(4),
            SetAmbient(1.0, 1.0, 1.0),
            SetDiffuse(1.0, 1.0, 1.0),
        // Hair color
        MakeDynObj(D_MATERIAL, 0),
            SetId(5),
            SetAmbient(0.362, 0.0, 0.0),
            SetDiffuse(0.362, 0.0, 0.0),
        // Mouth color
        MakeDynObj(D_MATERIAL, 0),
            SetId(6),
            SetAmbient(0.526, 0.0, 0.0),
            SetDiffuse(0.526, 0.0, 0.0),
        // Cap color
        MakeDynObj(D_MATERIAL, 0),
            SetId(7),
            SetAmbient(0.0, 1.0, 0.0),
            SetDiffuse(0.0, 1.0, 0.0),
    EndGroup(DYNOBJ_MARIO_FACE_MTL_GROUP),

    MakeDynObj(D_SHAPE, DYNOBJ_MARIO_FACE_SHAPE),
        SetNodeGroup(DYNOBJ_MARIO_FACE_VTX_GROUP),
        SetPlaneGroup(DYNOBJ_MARIO_FACE_TRI_GROUP),
        SetMaterialGroup(DYNOBJ_MARIO_FACE_MTL_GROUP),

    EndList(),
};
