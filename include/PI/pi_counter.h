/* Copyright 2013-present Barefoot Networks, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Antonin Bas (antonin@barefootnetworks.com)
 *
 */

#ifndef PI_INC_PI_PI_COUNTER_H_
#define PI_INC_PI_PI_COUNTER_H_

#include <PI/pi_base.h>
#include <PI/pi_tables.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint64_t pi_counter_value_t;

#define PI_COUNTER_UNIT_PACKETS (1 << 0)
#define PI_COUNTER_UNIT_BYTES (1 << 1)

typedef struct {
  int valid;
  pi_counter_value_t bytes;
  pi_counter_value_t packets;
} pi_counter_data_t;

#define PI_COUNTER_FLAGS_NONE 0
// do a sync with the hw when reading a counter
#define PI_COUNTER_FLAGS_HW_SYNC (1 << 0)

pi_status_t pi_counter_read(pi_session_handle_t session_handle,
                            pi_dev_tgt_t dev_tgt, pi_p4_id_t counter_id,
                            size_t index, int flags,
                            pi_counter_data_t *counter_data);

pi_status_t pi_counter_write(pi_session_handle_t session_handle,
                             pi_dev_tgt_t dev_tgt, pi_p4_id_t counter_id,
                             size_t index,
                             const pi_counter_data_t *counter_data);

pi_status_t pi_counter_read_direct(pi_session_handle_t session_handle,
                                   pi_dev_tgt_t dev_tgt, pi_p4_id_t counter_id,
                                   pi_entry_handle_t entry_handle, int flags,
                                   pi_counter_data_t *counter_data);

pi_status_t pi_counter_write_direct(pi_session_handle_t session_handle,
                                    pi_dev_tgt_t dev_tgt, pi_p4_id_t counter_id,
                                    pi_entry_handle_t entry_handle,
                                    const pi_counter_data_t *counter_data);

#ifdef __cplusplus
}
#endif

#endif  // PI_INC_PI_PI_COUNTER_H_