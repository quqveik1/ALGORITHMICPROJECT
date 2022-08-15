
#include "TXLib.h"

//#pragma GCC diagnostic ignored "-Wformat-security"

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   
//!
//! @param   index  
//! @param   size_or_array
//! @param   size_if_pointer
//!
//! @return  
//!
//! @usage @code
//!
//!
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY

#define $a(index, size_or_array, size_if_pointer)

#else

#define $a(index, size_or_array)  txAssertIndex (index, size_or_array,\
                                                      #index, #size_or_array,\
                                                      __FILE__, __LINE__, __TX_FUNCTION__)
#endif

//-----------------------------------------------------------------------------------------------------------------

template <typename indexT, typename sizeT>
indexT txAssertIndex (indexT index, sizeT size,
                      const char* indexName, const char* sizeName,
                      const char* file, int line, const char* func)
    {
    if (!(0 <= index && index < (indexT) size))
        {
        std::stringstream str;

        str << "\a" "Index [" << indexName << " = " << index << "] is out of range for an array of size [";
        if (isalpha (sizeName[0])) str << sizeName << " = ";
        str << size << "].";

        _txError (file, line, func, 0, str.str().c_str());
        }
        
    return index;
    }

template <typename indexT, typename sizeT, typename elemT>
indexT txAssertIndex (indexT index, const elemT*, indexT firstIndex, sizeT size,
                      const char* indexName, const char* arrayName, const char* firstIndexAndSizeName,
                      const char* file, int line, const char* func)
    {
    if (!(firstIndex <= index && index < (indexT) size))
        {
        std::stringstream str;

        bool expr  = !!strpbrk (arrayName, "+-*/%<>=!~&|^?");
        bool space = !!strchr  (arrayName, ' ');

        str << "\a" "Index [" << indexName << " = " << index << "] is out of range for " 
            << (expr? "(" : "") << arrayName << (expr? ")" : "") << (space? " " : "") << "[";
        if (isalpha (firstIndexAndSizeName[0])) str << firstIndexAndSizeName << " = ";
        str << firstIndex << ".." << size-1 << "].";

        _txError (file, line, func, 0, str.str().c_str());
        }
        
    return index;
    }

template <typename indexT, typename elemT, size_t size>
indexT txAssertIndex (indexT index, const elemT (&) [size],
                      const char* indexName, const char* arrayName, const char*,
                      const char* file, int line, const char* func)
    {
    if (!(0 <= index && index < (indexT) size))
        {
        std::stringstream str;

        str << "\a" "Index [" << indexName << " = " << index << "] is out of range for " << arrayName << "["
            << size << "].";

        _txError (file, line, func, 0, str.str().c_str());
        }
        
    return index;
    }

//-----------------------------------------------------------------------------------------------------------------
 /*
int main()
    {
    const int size = 5;
    int arr[size] = {};

    for (int i = 0; i <  size;   i++) arr [$a (i, size)] = i;

    for (int i = 0; i <  size;   i++) arr [$a (i, arr)]  = i;

    for (int i = 0; i <  size;   i++) arr [$a (i-1, arr+1, -1, size)]   = i;

    for (int i = 0; i <= size-1; i++) arr [$a (i,   arr+1,  0, size-1)] = i;

    return arr[0];
    }
      */
    