// The naive implementation

#include "vest.h"
#include <stdlib.h>

struct VEST_Estimator {
  VEST_Config config;
  VEST_Data data[];
};

// Return the number of bytes that will be used for an estimator
static VEST_USize _VEST_bytes(VEST_USize window_size) {
  VEST_USize header_size = sizeof(VEST_Config) + sizeof(VEST_USize) * 2;
  VEST_USize data_size = sizeof(VEST_Data) * window_size;
  return header_size + data_size;
}

VEST_Estimator VEST_alloc(VEST_USize window_size) {
  return malloc( _VEST_bytes(window_size) );
}

VEST_Result VEST_init(VEST_Estimator state, VEST_Config config) {
  state->config = config;
}

VEST_Result VEST_push(VEST_Estimator state, VEST_Data data) {
  return VEST_OK;
}

VEST_Result VEST_get_velocity(VEST_Estimator state, VEST_Data* result) {
  *result = 0;
  return VEST_OK;
}
