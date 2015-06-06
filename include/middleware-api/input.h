/* (c) Copyright 2011-2014 Felipe Magno de Almeida
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MIDDLEWARE_API_PROPOSAL_INPUT_H
#define MIDDLEWARE_API_PROPOSAL_INPUT_H

#include <middleware-api/declaration.h>

#ifdef __cplusplus
extern "C" {
#endif

enum middleware_api_input_keys
{
  middleware_api_input_red_key
  , middleware_api_input_green_key
  , middleware_api_input_yellow_key
  , middleware_api_input_blue_key
  , middleware_api_input_a_key
  , middleware_api_input_b_key
  , middleware_api_input_c_key
  , middleware_api_input_d_key
  , middleware_api_input_e_key
  , middleware_api_input_f_key
  , middleware_api_input_g_key
  , middleware_api_input_h_key
  , middleware_api_input_cursor_left_key
  , middleware_api_input_cursor_up_key
  , middleware_api_input_cursor_right_key
  , middleware_api_input_cursor_down_key
  , middleware_api_input_enter_key
  , middleware_api_input_info_key
  , middleware_api_input_invalid_key
};

MIDDLEWARE_API_MIDDLEWARE_DECL void middleware_api_input_remote_control_key
 (enum middleware_api_input_keys key);

#ifdef __cplusplus
}
#endif

#endif
