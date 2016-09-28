#include <stdint.h>

typedef struct VEST_VelocityEstimator* VEST_VelocityEstimator;

// Type used for counting element numbers and indexes within the data structure
typedef uint32_t VEST_USize;
typedef uint32_t VEST_Time;
typedef uint32_t VEST_Data;

typedef enum {
  OK,
} VEST_Result;

// Allocate memory for a VEST_VelocityEstimator
VEST_VelocityEstimator VEST_alloc();

// Initializes a VEST_VelocityEstimator
VEST_Result VEST_init(VEST_VelocityEstimator state, VEST_USize window_size, VEST_Time period);

// Push an element into the window, updating state as required
VEST_Result VEST_push(VEST_VelocityEstimator state, VEST_Data data);

// Return the current velocity estimate, by performing calculations on state
VEST_Result VEST_get_velocity(VEST_VelocityEstimator state, VEST_Data* result);
