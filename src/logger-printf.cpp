/*
 * Copyright (c) 2012, Prevas A/S
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Prevas A/S nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/**
 *
 *
 * \author Morten Kjaergaard
 */

#include <beam/logger.hpp>
#include <stdio.h>
#include <boost/date_time/posix_time/time_formatters.hpp>

namespace bt = boost::posix_time;

namespace beam
{

logger logger::instance_;

void logger::log1(int severity,
		  const char * event,
		  const char * name1, const std::string& arg1,
		  const char * name2, const std::string& arg2,
		  const char * name3, const std::string& arg3,
		  const char * name4, const std::string& arg4)
{
  // Do this better
  printf("[%s %s] %s\n",
	 Severity::name(severity),
	 bt::to_simple_string(bt::microsec_clock::universal_time().time_of_day()).c_str(),
	 event);

  //                        [FATAL 14:20:20.878682]
  const char * my_format = "                      - %s: %s\n";

  if(name1[0] != 0)
  {
    printf(my_format, name1, arg1.c_str());
  }

  if(name2[0] != 0)
  {
    printf(my_format, name2, arg2.c_str());
  }

  if(name3[0] != 0)
  {
    printf(my_format, name3, arg3.c_str());
  }

  if(name4[0] != 0)
  {
    printf(my_format, name4, arg4.c_str());
  }

}

}
