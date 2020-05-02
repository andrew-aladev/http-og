// HTTP old generation (v0.9, v1.0, v1.1) C library.
// Copyright (c) 2019 AUTHORS, MIT License.

// This file was generated, do not edit manually.

// It may not be possible to run generator while cross compiling.
// So generated file should be shipped with its template.

#include "main.h"

const size_t HOG_PROCESSOR_STATUS_CODE_1_1_CONSTANTS_LENGTH = 62;

const hog_processor_state_fast_t HOG_PROCESSOR_STATUS_CODE_1_1_INITIAL_STATE = HOG_PROCESSOR_STATUS_CODE_1_1_CONSTANTS_LENGTH;

const size_t HOG_PROCESSOR_STATUS_CODE_1_1_ALPHABET_LENGTH     = 10;
const size_t HOG_PROCESSOR_STATUS_CODE_1_1_ALPHABET_MAX_LENGTH = HOG_MAX_SYMBOL + 1;

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

#define NEXT_STATE_BY_LAST_SYMBOLS_LENGTH (78 + 1) * HOG_PROCESSOR_STATUS_CODE_1_1_ALPHABET_LENGTH

// clang-format off

const hog_processor_status_code_1_1_state_t HOG_PROCESSOR_STATUS_CODE_1_1_NEXT_STATE_BY_LAST_SYMBOLS[NEXT_STATE_BY_LAST_SYMBOLS_LENGTH] = {
  [0 ... NEXT_STATE_BY_LAST_SYMBOLS_LENGTH - 1] = HOG_PROCESSOR_STATUS_CODE_1_1_INITIAL_STATE,
  [620] = 63,
  [622] = 65,
  [623] = 68,
  [624] = 70,
  [625] = 76,
  [631] = 64,
  [640] = 1,
  [641] = 0,
  [642] = 2,
  [643] = 3,
  [651] = 66,
  [652] = 67,
  [660] = 5,
  [661] = 4,
  [662] = 6,
  [663] = 7,
  [664] = 8,
  [665] = 9,
  [666] = 10,
  [667] = 11,
  [668] = 12,
  [676] = 13,
  [681] = 69,
  [690] = 15,
  [691] = 14,
  [692] = 16,
  [693] = 17,
  [694] = 18,
  [695] = 19,
  [696] = 20,
  [697] = 21,
  [698] = 22,
  [700] = 72,
  [701] = 71,
  [702] = 73,
  [703] = 74,
  [705] = 75,
  [710] = 24,
  [711] = 23,
  [712] = 25,
  [713] = 26,
  [714] = 27,
  [715] = 28,
  [716] = 29,
  [717] = 30,
  [718] = 31,
  [719] = 32,
  [720] = 34,
  [721] = 33,
  [722] = 35,
  [723] = 36,
  [724] = 37,
  [725] = 38,
  [726] = 39,
  [727] = 40,
  [730] = 41,
  [732] = 42,
  [733] = 43,
  [734] = 44,
  [735] = 45,
  [736] = 46,
  [738] = 47,
  [739] = 48,
  [740] = 49,
  [750] = 50,
  [760] = 78,
  [761] = 77,
  [770] = 52,
  [771] = 51,
  [772] = 53,
  [773] = 54,
  [774] = 55,
  [775] = 56,
  [776] = 57,
  [777] = 58,
  [778] = 59,
  [780] = 61,
  [781] = 60};

// clang-format on

extern inline hog_processor_state_fast_t hog_processor_status_code_1_1_get_next_state(
  hog_processor_state_fast_t state, hog_symbol_fast_t byte);

extern inline bool hog_processor_status_code_1_1_is_valid(hog_processor_state_fast_t state);
