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

#ifndef MIDDLEWARE_API_PROPOSAL_GRAPHICS_H
#define MIDDLEWARE_API_PROPOSAL_GRAPHICS_H

#define MIDDLEWARE_API_PROPOSAL_GRAPHICS_SURFACES

#include <stddef.h>
#include <stdint.h>

#include <middleware-api/declaration.h>

#ifdef __cplusplus
extern "C" {
#endif

struct middleware_api_graphics_surface;
typedef struct middleware_api_graphics_surface* middleware_api_graphics_surface_t;
typedef void(*middleware_api_graphics_primary_surface_draw_callback_t)(middleware_api_graphics_surface_t, void*);

enum middleware_api_graphics_image_format
{
  middleware_api_graphics_image_format_jpeg
  , middleware_api_graphics_image_format_png
  , middleware_api_graphics_image_format_gif
};

MIDDLEWARE_API_MANUFACTURER_DECL void middleware_api_graphics_on_primary_surface_draw
 (middleware_api_graphics_primary_surface_draw_callback_t callback, void* ud);

MIDDLEWARE_API_MANUFACTURER_DECL middleware_api_graphics_surface_t
 middleware_api_graphics_create_surface
 (unsigned int width, unsigned int height);

MIDDLEWARE_API_MANUFACTURER_DECL void middleware_api_graphics_release_surface
 (middleware_api_graphics_surface_t p);

MIDDLEWARE_API_MANUFACTURER_DECL void middleware_api_graphics_stretch_bitblit
(middleware_api_graphics_surface_t destination, middleware_api_graphics_surface_t source
 , unsigned int dx, unsigned int dy, unsigned int dw, unsigned int dh
 , unsigned int sx, unsigned int sy, unsigned int sw, unsigned int sh);

MIDDLEWARE_API_MANUFACTURER_DECL void middleware_api_graphics_clear_surface
 (middleware_api_graphics_surface_t p, uint32_t color);

MIDDLEWARE_API_MANUFACTURER_DECL middleware_api_graphics_surface_t
 middleware_api_graphics_load_image
 (const char* buffer, size_t size
  , enum middleware_api_graphics_image_format format);

MIDDLEWARE_API_MANUFACTURER_DECL size_t middleware_api_graphics_width
 (middleware_api_graphics_surface_t p);

MIDDLEWARE_API_MANUFACTURER_DECL size_t middleware_api_graphics_height
 (middleware_api_graphics_surface_t p);

MIDDLEWARE_API_MANUFACTURER_DECL size_t middleware_api_graphics_primary_surface_width();

MIDDLEWARE_API_MANUFACTURER_DECL size_t middleware_api_graphics_primary_surface_height();

#ifdef __cplusplus
}
#endif

#endif
