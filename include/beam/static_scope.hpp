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

#include <beam/static_scope_impl.hpp>

namespace beam
{

extern const char default_name[];

template<int SeverityEnabled, const char * scope_name = default_name>
struct static_scope
{
  template<int Severity>
  void slog(const char* event)
  {
    static_scope_impl<Severity <= SeverityEnabled, Severity>::
      slog(event);
  }

  template<int Severity, typename T1>
  void slog(const char* event,
            const char* name1, const arg<T1>& argument1)
  {
    static_scope_impl<Severity <= SeverityEnabled, Severity>::
      slog(event,
           name1, argument1);
  }

  template<int Severity, typename T1, typename T2>
  void slog(const char* event,
            const char* name1, const arg<T1>& argument1,
            const char* name2, const arg<T2>& argument2)
  {
    static_scope_impl<Severity <= SeverityEnabled, Severity>::
      slog(event,
           name1, argument1,
           name2, argument2);
  }

  template<int Severity, typename T1, typename T2, typename T3>
  void slog(const char* event,
            const char* name1, const arg<T1>& argument1,
            const char* name2, const arg<T2>& argument2,
            const char* name3, const arg<T3>& argument3)
  {
    static_scope_impl<Severity <= SeverityEnabled, Severity>::
      slog(event,
           name1, argument1,
           name2, argument2,
           name3, argument3);
  }

};

}
