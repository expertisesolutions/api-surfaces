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

#ifndef MIDDLEWARE_API_PROPOSAL_SECTIONS_H
#define MIDDLEWARE_API_PROPOSAL_SECTIONS_H

#define MIDDLEWARE_API_PROPOSAL_SECTIONS

#include <stdint.h>
#include <stdlib.h>

#include <middleware-api/declaration.h>

#ifdef __cplusplus
extern "C" {
#endif

struct middleware_api_sections_filter;
typedef struct middleware_api_sections_filter* middleware_api_sections_filter_t;

typedef void(*middleware_api_sections_filter_callback_t)
  (const char* buffer, size_t size, middleware_api_sections_filter_t filter, void* state);

MIDDLEWARE_API_MANUFACTURER_DECL middleware_api_sections_filter_t
 middleware_api_sections_create_filter_for_pid
 (uint16_t pid, middleware_api_sections_filter_callback_t callback, void* state);

MIDDLEWARE_API_MANUFACTURER_DECL middleware_api_sections_filter_t
 middleware_api_sections_create_pes_filter_for_pid
 (uint16_t pid, middleware_api_sections_filter_callback_t callback, void* state);

MIDDLEWARE_API_MANUFACTURER_DECL middleware_api_sections_filter_t
 middleware_api_sections_create_filter_for_pid_and_table_id 
 (uint16_t pid, uint8_t table_id, middleware_api_sections_filter_callback_t callback
  , void* state);

MIDDLEWARE_API_MANUFACTURER_DECL middleware_api_sections_filter_t
 middleware_api_sections_create_filter_for_pid_and_table_id_and_table_id_extension
 (uint16_t pid, uint8_t table_id, uint16_t table_id_extension
  , middleware_api_sections_filter_callback_t callback
  , void* state);

MIDDLEWARE_API_MANUFACTURER_DECL void middleware_api_sections_remove_filter
 (middleware_api_sections_filter_t p);

#ifdef __cplusplus
}
#endif

#endif
