// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#include "main.h"

const hog_processor_state_fast_t HOG_PROCESSOR_STATUS_CODE_1_1_CONSTANTS_LENGTH = 69;

const hog_processor_state_fast_t HOG_PROCESSOR_STATUS_CODE_1_1_INITIAL_STATE = HOG_PROCESSOR_STATUS_CODE_1_1_CONSTANTS_LENGTH;

const uint_fast16_t HOG_PROCESSOR_STATUS_CODE_1_1_ALPHABET_LENGTH     = 10;
const uint_fast16_t HOG_PROCESSOR_STATUS_CODE_1_1_ALPHABET_MAX_LENGTH = HOG_MAX_SYMBOL + 1;

const hog_symbol_fast_t HOG_PROCESSOR_STATUS_CODE_1_1_UNDEFINED_SYMBOL = HOG_MAX_SYMBOL;

#define SYMBOL_BY_BYTES_LENGTH HOG_PROCESSOR_STATUS_CODE_1_1_ALPHABET_MAX_LENGTH

// clang-format off

const hog_symbol_t HOG_PROCESSOR_STATUS_CODE_1_1_SYMBOL_BY_BYTES[SYMBOL_BY_BYTES_LENGTH] = {
  [0 ... SYMBOL_BY_BYTES_LENGTH - 1] = HOG_PROCESSOR_STATUS_CODE_1_1_UNDEFINED_SYMBOL,
  [49] = 0,
  [48] = 1,
  [50] = 2,
  [51] = 3,
  [52] = 4,
  [53] = 5,
  [54] = 6,
  [55] = 7,
  [56] = 8,
  [57] = 9};

// clang-format on

#define NEXT_STATE_BY_LAST_SYMBOLS_LENGTH (89 + 1) * HOG_PROCESSOR_STATUS_CODE_1_1_ALPHABET_LENGTH

// clang-format off

const hog_processor_status_code_1_1_state_t HOG_PROCESSOR_STATUS_CODE_1_1_NEXT_STATE_BY_LAST_SYMBOLS[NEXT_STATE_BY_LAST_SYMBOLS_LENGTH] = {
  [0 ... NEXT_STATE_BY_LAST_SYMBOLS_LENGTH - 1] = HOG_PROCESSOR_STATUS_CODE_1_1_INITIAL_STATE,
  [690] = 70,
  [692] = 72,
  [693] = 75,
  [694] = 77,
  [695] = 83,
  [700] = 86,
  [701] = 71,
  [709] = 87,
  [710] = 1,
  [711] = 0,
  [712] = 2,
  [713] = 3,
  [720] = 88,
  [721] = 73,
  [722] = 74,
  [729] = 89,
  [730] = 5,
  [731] = 4,
  [732] = 6,
  [733] = 7,
  [734] = 8,
  [735] = 9,
  [736] = 10,
  [737] = 11,
  [738] = 12,
  [746] = 13,
  [751] = 76,
  [760] = 15,
  [761] = 14,
  [762] = 16,
  [763] = 17,
  [764] = 18,
  [765] = 19,
  [766] = 20,
  [767] = 21,
  [768] = 22,
  [770] = 79,
  [771] = 78,
  [772] = 80,
  [773] = 81,
  [775] = 82,
  [780] = 24,
  [781] = 23,
  [782] = 25,
  [783] = 26,
  [784] = 27,
  [785] = 28,
  [786] = 29,
  [787] = 30,
  [788] = 31,
  [789] = 32,
  [790] = 34,
  [791] = 33,
  [792] = 35,
  [793] = 36,
  [794] = 37,
  [795] = 38,
  [796] = 39,
  [797] = 40,
  [800] = 41,
  [802] = 42,
  [803] = 43,
  [804] = 44,
  [805] = 45,
  [806] = 46,
  [808] = 47,
  [809] = 48,
  [810] = 49,
  [820] = 50,
  [830] = 85,
  [831] = 84,
  [840] = 52,
  [841] = 51,
  [842] = 53,
  [843] = 54,
  [844] = 55,
  [845] = 56,
  [846] = 57,
  [847] = 58,
  [848] = 59,
  [850] = 61,
  [851] = 60,
  [860] = 63,
  [861] = 62,
  [862] = 64,
  [863] = 65,
  [879] = 66,
  [884] = 67,
  [899] = 68};

// clang-format on

extern inline hog_processor_state_fast_t hog_processor_status_code_1_1_get_next_state(
  hog_processor_state_fast_t state, hog_symbol_fast_t byte);

extern inline bool hog_processor_status_code_1_1_is_valid(hog_processor_state_fast_t state);
