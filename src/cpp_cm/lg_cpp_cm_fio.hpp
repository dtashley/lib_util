//--------------------------------------------------------------------------------------------------
//Header file for C++ formatted I/O functions.
//--------------------------------------------------------------------------------------------------
//This file is part of LibGen, https://github.com/dtashley/LibGen, and is provided
//under The Unlicense, reproduced below.
//--------------------------------------------------------------------------------------------------
//This is free and unencumbered software released into the public domain.
//
//Anyone is free to copy, modify, publish, use, compile, sell, or
//distribute this software, either in source code form or as a compiled
//binary, for any purpose, commercial or non - commercial, and by any
//means.
//
//In jurisdictions that recognize copyright laws, the author or authors
//of this software dedicate any and all copyright interest in the
//software to the public domain.We make this dedication for the benefit
//of the public at large and to the detriment of our heirs and
//successors.We intend this dedication to be an overt act of
//relinquishment in perpetuity of all present and future rights to this
//software under copyright law.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//OTHER DEALINGS IN THE SOFTWARE.
//
//For more information, please refer to <https://unlicense.org>
//--------------------------------------------------------------------------------------------------
#ifndef LG_CPP_CM_FIO_CPP_H_INCLUDED
   #define LG_CPP_CM_FIO_CPP_H_INCLUDED

   #include <iostream>

   #include "time.h"

   extern void LgCppCcm_FioRepcharStream(std::ostream& in_output_stream, const char in_c, const size_t in_n);
   extern void LgCppCcm_FioRepchar(const char in_c, size_t in_n);
   extern void LgCppCcm_FioHlineStream(std::ostream& in_output_stream, const size_t in_line_len = 78);
   extern void LgCppCcm_FioHline(const size_t in_line_len = 78);
   extern void LgCppCcm_FioBannerheadingStream(std::ostream& in_output_stream,
                                               const char* const in_s,
                                               const size_t in_line_len = 78,
                                               const size_t in_n_extra_lines = 1);
   extern void LgCppCcm_FioBannerheading(const char* const in_s, const size_t in_line_len = 78, const size_t in_n_extra_lines = 1);
   extern void LgCppCcm_TimeStream(std::ostream& in_output_stream, time_t * const in_ltime = nullptr, const bool in_acquire_time = false);
   extern void LgCppCcm_Time(time_t* const in_ltime = nullptr, const bool in_acquire_time = false);
#endif

//End of lg_cpp_cm_fio_cpp.h.
