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

#pragma once

#include <beam/logger.hpp>
#include <beam/severity_type.hpp>
#include <beam/arg.hpp>

namespace beam
{

template<int Severity>
static void glog(const char* event)
{
  if(logger::is_severity_logged(Severity))
  {
    logger::log1(Severity, "", event);
  }
}

template<int Severity, typename T1>
static void glog(const char* event,
                 const char* name1, const arg<T1>& argument1)
{
  if(logger::is_severity_logged(Severity))
  {
    logger::log1(Severity, "", event,
                 name1, beam::to_string(argument1));
  }
}

template<int Severity, typename T1, typename T2>
static void glog(const char* event,
                 const char* name1, const arg<T1>& argument1,
                 const char* name2, const arg<T2>& argument2)
{
  if(logger::is_severity_logged(Severity))
  {
    logger::log1(Severity, "", event,
                 name1, beam::to_string(argument1),
                 name2, beam::to_string(argument2));
  }
}

template<int Severity, typename T1, typename T2, typename T3>
static void glog(const char* event,
                 const char* name1, const arg<T1>& argument1,
                 const char* name2, const arg<T2>& argument2,
                 const char* name3, const arg<T3>& argument3)
{
  if(logger::is_severity_logged(Severity))
  {
    logger::log1(Severity, "", event,
                 name1, beam::to_string(argument1),
                 name2, beam::to_string(argument2),
                 name3, beam::to_string(argument3));
  }
}

template<int Severity, typename T1, typename T2, typename T3, typename T4>
static void glog(const char* event,
                 const char* name1, const arg<T1>& argument1,
                 const char* name2, const arg<T2>& argument2,
                 const char* name3, const arg<T3>& argument3,
                 const char* name4, const arg<T4>& argument4)
{
  if(logger::is_severity_logged(Severity))
  {
    logger::log1(Severity, "", event,
                 name1, beam::to_string(argument1),
                 name2, beam::to_string(argument2),
                 name3, beam::to_string(argument3),
                 name4, beam::to_string(argument4));
  }
}

}
