#include <locale>
#include <codecvt>
#include <string>
#include <algorithm>

namespace emdev {
    std::wstring towstring(std::string str) {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        return converter.from_bytes(str);
    }

    std::string tostring(std::wstring str) {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        return converter.to_bytes(str);
    }

    std::wstring towupper(std::wstring str) {
        std::transform(str.begin(), str.end(), str.begin(), std::towupper);
        return str;
    }

    std::string toupper(std::string str) {
        std::wstring wstr = towstring(str);
        wstr = towupper(wstr);
        return tostring(wstr);
    }
}