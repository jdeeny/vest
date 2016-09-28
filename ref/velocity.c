// The naive implementation

#include "vest.h"
#include <stdlib.h>

struct VEST_Estimator {
  VEST_Config config;
  VEST_Data data[];
};


VEST_Estimator VEST_alloc(VEST_USize window_size) {
  return malloc( VEST_bytes_required(window_size) );
}

VEST_Result VEST_init(VEST_Estimator state, VEST_Config config) {
  state->config = config;

  return VEST_OK;
}

VEST_Result VEST_push(VEST_Estimator state, VEST_Data data) {
  return VEST_OK;
}

VEST_Result VEST_get_velocity(VEST_Estimator state, VEST_Data* result) {
  *result = 0;
  return VEST_OK;
}
