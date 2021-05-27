#ifndef HASH_OPT
#define HASH_OPT


#include "leveldb/slice.h"


namespace Hash_opt
{
  unsigned hash_Value_Calc(const leveldb::Slice& key);
  bool sliceCmp(const leveldb::Slice & a,const leveldb::Slice & b);
  class Hash_table
  {
    public:
    std::pair<leveldb::Slice * , std::string * >  * _ht;

  };
}

#endif 
