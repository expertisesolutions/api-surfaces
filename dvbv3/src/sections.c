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

#include <middleware-api/sections.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#include <linux/dvb/frontend.h>

typedef struct middleware_api_sections_filter middleware_api_sections_filter;

static int frontend_fd;
static const int frequency = 623142857;

void middleware_api_sections_tune()
{
  const char* frontend_device_path = "/dev/dvb/adapter0/frontend0";
  frontend_fd = open(frontend_device_path, O_RDWR);
  if(frontend_fd <= 0)
  {
    fprintf(stderr, "=== Couldn't open device %s, error %d and errno %d\n"
            , frontend_device_path, frontend_fd, errno);
    fflush(stderr);
    abort();
  }

  struct dvb_frontend_parameters p;
  memset(&p, 0, sizeof(p));
  p.frequency = frequency;
  p.inversion = INVERSION_AUTO;
  p.u.ofdm.bandwidth = BANDWIDTH_6_MHZ;
  p.u.ofdm.code_rate_HP = p.u.ofdm.code_rate_LP = FEC_AUTO;
  p.u.ofdm.constellation = QAM_AUTO;
  p.u.ofdm.transmission_mode = TRANSMISSION_MODE_AUTO;
  p.u.ofdm.guard_interval = GUARD_INTERVAL_AUTO;
  p.u.ofdm.hierarchy_information = HIERARCHY_AUTO;

  int r;
  do
  {
    r = ioctl(frontend_fd, FE_SET_FRONTEND, &p);
  } while(r == -1 && errno == EINTR);
  if(r == -1)
  {
    fprintf(stderr, "Failed tuning to frequency %d with error %d and errno %d\n"
            , frequency, r, errno);
    fflush(stderr);
    abort();
  }

  printf("Succesfully tuned to frequency %d\n", frequency);
}

middleware_api_sections_filter* middleware_api_sections_create_filter_for_pid
(uint16_t pid, middleware_api_sections_filter_callback_type callback, void* state)
{
  return 0;
}

void middleware_api_sections_remove_filter(middleware_api_sections_filter* p)
{
}

