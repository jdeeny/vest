#include <stdint.h>

typedef uint32_t VEST_USize;
typedef uint32_t VEST_Time;
typedef uint32_t VEST_Data;

typedef struct VEST_Estimator* VEST_Estimator;

struct VEST_Config {
  VEST_USize window_size;
  VEST_Time period;
  VEST_USize window_min;
};

typedef struct VEST_Config VEST_Config;

typedef enum {
  VEST_OK,
} VEST_Result;

// Allocate memory for a VEST_Estimator
VEST_Estimator VEST_alloc(VEST_USize window_size);

// Initializes a VEST_VelocityEstimator
VEST_Result VEST_init(VEST_Estimator state, VEST_Config config);

// Push an element into the window, updating state as required
VEST_Result VEST_push(VEST_Estimator state, VEST_Data data);

// Return the current velocity estimate, by performing calculations on state
VEST_Result VEST_get_velocity(VEST_Estimator state, VEST_Data* result);

// Return the total number of bytes that need to be allocated
#define VEST_bytes_required(window_size) (sizeof(VEST_Config) + sizeof(VEST_Data) * window_size)
