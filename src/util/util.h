#pragma once

#ifndef NDEBUG

#include <iostream>

#define LOG(msg) std::cout<<__FILE__<<":"<<__LINE__<<"::"<<msg<<std::endl
#else
#define LOG(msg)
#endif // !NDEBUG


namespace util {

}
