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

#ifndef MIDDLEWARE_API_PROPOSAL_LIFETIME_H
#define MIDDLEWARE_API_PROPOSAL_LIFETIME_H

#include <stddef.h>

#include <middleware-api/declaration.h>

#ifdef __cplusplus
extern "C" {
#endif

MIDDLEWARE_API_MIDDLEWARE_DECL void middleware_api_lifetime_start
 (unsigned int service_id
  , const char* pat_section, size_t pat_size
  , const char* pmt_section, size_t pmt_size);
MIDDLEWARE_API_MIDDLEWARE_DECL void middleware_api_lifetime_stop();

#ifdef __cplusplus
}
#endif

#endif
