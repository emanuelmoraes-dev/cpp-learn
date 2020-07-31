#ifndef STRUTIL_H_INCLUDED
#define STRUTIL_H_INCLUDED

#include <string>

namespace emdev {
    std::wstring towstring(std::string str);
    std::string tostring(std::wstring str);
    std::wstring towupper(std::wstring str);
    std::string toupper(std::string str);
}

#endif // STRUTIL_H_INCLUDED