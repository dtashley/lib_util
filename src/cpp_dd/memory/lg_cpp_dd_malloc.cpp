//--------------------------------------------------------------------------------------------------
//C++ data-driven functions, wrapper around malloc() family of functions, with the ability
//to throw an exception if out of memory.
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
#define MODULE_LG_CPP_DD_MALLOC

#include <exception>

#include <malloc.h>

#include "lg_cpp_dd_malloc.hpp"

/*!
 * Allocates a block of memory of <i>in_size</i> bytes, and returns a pointer to the allocated
 * block.
 *
 * \param[in]  in_size           The number of bytes to allocate.  If this parameter is 0,
 *                               the function will allocate no memory and return <i>nullptr</i>.
 * \returns                      Pointer to allocated block of memory.  Because this is a
 *                               wrapper for <i>malloc()</i>, the pointer is aligned to the
 *                               most stringent alignment requirements of the platform.
 *                               <i>nullptr</i> will be returned if <i>in_size</i> is 0.
 * \reentrancyandthreadsafety    This function is re-entrant and thread safe.
 * \errorsandexceptions          The function will throw an exception of <i>malloc()</i>
 *                               is unable to allocate the memory.
 */
void *LgCppCm_MallocMalloc(size_t in_size)
{
   void* rv = nullptr;

   if (!in_size)
   {
      //Block of size 0 requested.  Nullptr return.
      rv = nullptr;
   }
   else
   {
      //Attempt to get block.
      rv = malloc(in_size);

      if (!rv)
      {
         //Nullptr return with a non-zero size request.  With malloc(), this
         //can only mean out of memory.  Throw exception.  We never make it to
         //the return statement.
         throw std::bad_alloc{};
      }
   }

   return(rv);
}


/*!
 * Allocates a block of memory of correctly sized to hold <i>in_num</i> elements, each
 * of size <i>in_size</i> bytes, and returns a pointer to the allocated block.
 *
 * \param[in]  in_num            The number of elements for which memory should be allocated.
 *                               See notes about the value of 0 in the description of the
 *                               <i>in_size</i> parameter below.
 * \param[in]  in_size           The size, in bytes, of each element.  If either <i>in_num</i>
 *                               or <i>in_size</i> are 0, then a block of size 0 is being
 *                               requested.  This function will return <i>nullptr</i> in this
 *                               case.
 * \returns                      Pointer to allocated block of memory.  Because this is a
 *                               wrapper for <i>calloc()</i>, the pointer is aligned to the
 *                               most stringent alignment requirements of the platform.
 *                               <i>nullptr</i> will be returned if <i>in_num</i> or
 *                               <i>in_size</i> is 0.
 * \reentrancyandthreadsafety    This function is re-entrant and thread safe.
 * \errorsandexceptions          The function will throw an exception if <i>calloc()</i>
 *                               is unable to allocate the memory.
 */
void* LgCppCm_MallocCalloc(size_t in_num, size_t in_size)
{
   void* rv = nullptr;

   if ((!in_num) || (!in_size))
   {
      //A request for a block of 0 bytes is being made.  Return nullptr.
      rv = nullptr;
   }
   else
   {
      //Request a block.
      rv = calloc(in_num, in_size);

      if (!rv)
      {
         //Nullptr return with a non-zero block request.  With calloc(), this
         //can only mean out of memory.  Throw exception.  We never make it to
         //the return statement.
         throw std::bad_alloc{};
      }
   }

   return rv;
}


/*!
 * Allocates a block of memory of correctly sized to hold <i>in_num</i> elements, each
 * of size <i>in_size</i> bytes, and returns a pointer to the allocated block.
 *
 * \param[in]  in_num            The number of elements for which memory should be allocated.
 *                               See notes about the value of 0 in the description of the
 *                               <i>in_size</i> parameter below.
 * \param[in]  in_size           The size, in bytes, of each element.  If either <i>in_num</i>
 *                               or <i>in_size</i> are 0, then a block of size 0 is being
 *                               requested.  This function will return <i>nullptr</i> in this
 *                               case.
 * \returns                      Pointer to allocated block of memory.  Because this is a
 *                               wrapper for <i>calloc()</i>, the pointer is aligned to the
 *                               most stringent alignment requirements of the platform.
 *                               <i>nullptr</i> will be returned if <i>in_num</i> or
 *                               <i>in_size</i> is 0.
 * \reentrancyandthreadsafety    This function is re-entrant and thread safe.
 * \errorsandexceptions          The function will throw an exception if <i>calloc()</i>
 *                               is unable to allocate the memory.
 */
#if 0
The realloc() function changes the size of the memory block pointed to by ptr
to size bytes.The contents will be unchanged in the range from the start of the
region up to the minimum of the old and new sizes.If the new size is larger than
the old size, the added memory will not be initialized.If ptr is NULL, then the
call is equivalent to malloc(size), for all values of size; if size is equal to
zero, and ptr is not NULL, then the call is equivalent to free(ptr).Unless ptr is
NULL, it must have been returned by an earlier call to malloc(), calloc() or
realloc().If the area pointed to was moved, a free(ptr) is done.

The realloc() function returns a pointer to the newly allocated memory, 
which is suitably aligned for any kind of variable and may be different from ptr,
or NULL if the request fails.If size was equal to 0, either NULL or a pointer
suitable to be passed to free() is returned.If realloc() fails the original
block is left untouched; it is not freed or moved.
#endif
void* LgCppCm_MallocRealloc(void* in_memblock, size_t in_size)
{
   void* rv = nullptr;

   if (!in_memblock)
   {
      if (!in_size)
      {
         //Request to reallocate a nullptr memory block to zero size.
         //Return nullptr again.
         rv = nullptr;
      }
      else
      {
         //in_memblock is nullptr, but in_size > 0.  This is
         //equivalent to a fresh allocation.
         //
         //Make a malloc request.  If out of memory, an exception will
         //be thrown.
         rv = LgCppCm_MallocMalloc(in_size);
      }
   }
   else
   {
      if (!in_size)
      {
         //in_memblock is not nullptr, but in_size is 0.  free the
         //pointer and return nullptr.
         free(in_memblock);
         rv = nullptr;
      }
      else
      {
         //The incoming pointer is not nullptr, and the incoming size is not 0.
         //Call the realloc function to reallocate, possibly moving.
         rv = realloc(in_memblock, in_size);

         //If the return pointer is nullptr, this can only mean out of memory.
         //Throw an exception.  Per the realloc() specification, the original
         //memory is still allocated.
         if (!rv)
         {
            throw std::bad_alloc{};
         }
      }
   }

   return rv;
}


/*!
 * Allocates a block of memory of correctly sized to hold <i>in_num</i> elements, each
 * of size <i>in_size</i> bytes, and returns a pointer to the allocated block.
 *
 * \param[in]  in_num            The number of elements for which memory should be allocated.
 *                               See notes about the value of 0 in the description of the
 *                               <i>in_size</i> parameter below.
 * \param[in]  in_size           The size, in bytes, of each element.  If either <i>in_num</i>
 *                               or <i>in_size</i> are 0, then a block of size 0 is being
 *                               requested.  This function will return <i>nullptr</i> in this
 *                               case.
 * \returns                      Pointer to allocated block of memory.  Because this is a
 *                               wrapper for <i>calloc()</i>, the pointer is aligned to the
 *                               most stringent alignment requirements of the platform.
 *                               <i>nullptr</i> will be returned if <i>in_num</i> or
 *                               <i>in_size</i> is 0.
 * \reentrancyandthreadsafety    This function is re-entrant and thread safe.
 * \errorsandexceptions          The function will throw an exception if <i>calloc()</i>
 *                               is unable to allocate the memory.
 */

void LgCppCm_MallocFree( void *in_memblock )
{
   if (!in_memblock)
   {
      //Pointer in is nullptr.  Do nothing.
   }
   else
   {
      //Free the block.
      free(in_memblock);
   }
}

//End of lg_cpp_dd_malloc.cpp.
