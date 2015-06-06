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

#ifndef MIDDLEWARE_API_PROPOSAL_DSMCC_FS_H
#define MIDDLEWARE_API_PROPOSAL_DSMCC_FS_H

#include <middleware-api/declaration.h>

#ifdef __cplusplus
extern "C" {
#endif

struct middleware_api_dsmcc_fs_file;

MIDDLEWARE_API_MIDDLEWARE_DECL middleware_api_dsmcc_fs_file* middleware_api_dsmcc_fs_open
 (const char* name);

MIDDLEWARE_API_MIDDLEWARE_DECL size_t middleware_api_dsmcc_fs_size
 (middleware_api_dsmcc_fs_file* f);
MIDDLEWARE_API_MIDDLEWARE_DECL size_t middleware_api_dsmcc_fs_read
 (middleware_api_dsmcc_fs_file* f, size_t offset
  , char* buffer, size_t size);

#ifdef __cplusplus
}
#endif

#endif
