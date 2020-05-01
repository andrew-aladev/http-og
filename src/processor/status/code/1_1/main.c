// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#include "main.h"

const size_t HOG_PROCESSOR_STATUS_CODE_1_1_CONSTANTS_LENGTH = 73;

const hog_processor_state_fast_t HOG_PROCESSOR_STATUS_CODE_1_1_INITIAL_STATE = HOG_PROCESSOR_STATUS_CODE_1_1_CONSTANTS_LENGTH;

const size_t HOG_PROCESSOR_STATUS_CODE_1_1_ALPHABET_LENGTH     = 11;
const size_t HOG_PROCESSOR_STATUS_CODE_1_1_ALPHABET_MAX_LENGTH = HOG_MAX_SYMBOL + 1;

const hog_symbol_fast_t HOG_PROCESSOR_STATUS_CODE_1_1_UNDEFINED_SYMBOL = HOG_MAX_SYMBOL;

#define SYMBOL_BY_BYTES_LENGTH HOG_MAX_SYMBOL + 1

// clang-format off

const hog_symbol_t HOG_PROCESSOR_STATUS_CODE_1_1_SYMBOL_BY_BYTES[SYMBOL_BY_BYTES_LENGTH] = {
  [0 ... SYMBOL_BY_BYTES_LENGTH - 1] = HOG_PROCESSOR_STATUS_CODE_1_1_UNDEFINED_SYMBOL,
  [49] = 0,
  [48] = 1,
  [50] = 2,
  [51] = 3,
  [52] = 4,
  [45] = 5,
  [57] = 6,
  [53] = 7,
  [54] = 8,
  [55] = 9,
  [56] = 10};

// clang-format on

#define NEXT_STATE_BY_LAST_SYMBOLS_LENGTH (121 + 1) * HOG_PROCESSOR_STATUS_CODE_1_1_ALPHABET_LENGTH

// clang-format off

const hog_processor_status_code_1_1_state_t HOG_PROCESSOR_STATUS_CODE_1_1_NEXT_STATE_BY_LAST_SYMBOLS[NEXT_STATE_BY_LAST_SYMBOLS_LENGTH] = {
  [0 ... NEXT_STATE_BY_LAST_SYMBOLS_LENGTH - 1] = HOG_PROCESSOR_STATUS_CODE_1_1_INITIAL_STATE,
  [803] = 74,
  [805] = 80,
  [806] = 91,
  [807] = 97,
  [810] = 115,
  [815] = 75,
  [825] = 1,
  [826] = 0,
  [827] = 2,
  [828] = 3,
  [829] = 76,
  [841] = 77,
  [847] = 78,
  [864] = 79,
  [875] = 4,
  [881] = 81,
  [882] = 86,
  [891] = 6,
  [892] = 5,
  [893] = 7,
  [894] = 8,
  [895] = 9,
  [897] = 82,
  [898] = 10,
  [899] = 11,
  [900] = 12,
  [901] = 13,
  [907] = 83,
  [915] = 84,
  [926] = 85,
  [942] = 14,
  [954] = 15,
  [955] = 87,
  [962] = 88,
  [970] = 89,
  [985] = 90,
  [996] = 16,
  [1002] = 92,
  [1012] = 18,
  [1013] = 17,
  [1014] = 19,
  [1015] = 20,
  [1016] = 21,
  [1018] = 93,
  [1019] = 22,
  [1020] = 23,
  [1021] = 24,
  [1022] = 25,
  [1028] = 94,
  [1037] = 95,
  [1051] = 96,
  [1062] = 26,
  [1067] = 99,
  [1068] = 98,
  [1069] = 104,
  [1070] = 105,
  [1074] = 110,
  [1078] = 28,
  [1079] = 27,
  [1080] = 29,
  [1081] = 30,
  [1082] = 31,
  [1084] = 36,
  [1085] = 32,
  [1086] = 33,
  [1087] = 34,
  [1088] = 35,
  [1089] = 38,
  [1090] = 37,
  [1091] = 39,
  [1092] = 40,
  [1093] = 41,
  [1096] = 42,
  [1097] = 43,
  [1098] = 44,
  [1099] = 100,
  [1105] = 101,
  [1115] = 102,
  [1124] = 103,
  [1134] = 45,
  [1144] = 46,
  [1146] = 47,
  [1147] = 48,
  [1148] = 49,
  [1150] = 54,
  [1151] = 50,
  [1152] = 51,
  [1153] = 52,
  [1154] = 53,
  [1155] = 56,
  [1156] = 55,
  [1157] = 106,
  [1171] = 107,
  [1181] = 108,
  [1195] = 109,
  [1200] = 57,
  [1210] = 58,
  [1212] = 111,
  [1226] = 112,
  [1236] = 113,
  [1249] = 114,
  [1260] = 59,
  [1265] = 117,
  [1266] = 116,
  [1276] = 61,
  [1277] = 60,
  [1278] = 62,
  [1279] = 63,
  [1280] = 64,
  [1282] = 69,
  [1283] = 65,
  [1284] = 66,
  [1285] = 67,
  [1286] = 68,
  [1287] = 71,
  [1288] = 70,
  [1289] = 118,
  [1303] = 119,
  [1316] = 120,
  [1326] = 121,
  [1337] = 72};

// clang-format on

extern inline hog_processor_state_fast_t hog_processor_status_code_1_1_get_next_state(
  hog_processor_state_fast_t state, hog_symbol_fast_t byte);

extern inline bool hog_processor_status_code_1_1_is_finished(hog_processor_state_fast_t state);
