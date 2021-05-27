#include <string>
#include "leveldb/db.h"
#include "db/dbformat.h"
#include "db/skiplist.h"
#include "util/arena.h"
#include "db/memtable.h"
#include "db/dbformat.h"
#include "leveldb/comparator.h"
#include "leveldb/env.h"
#include "leveldb/slice.h"
#include "leveldb/iterator.h"
#include "util/coding.h"
#include <pthread.h>

namespace Hash_opt
{
  unsigned hash_Value_Calc(const leveldb::Slice& key)
  {
    size_t sz = key.size();
    const char * p = key.data();
    unsigned ret = 1;
    for(int i=0;i<sz;++i)
    {
      ret = (ret*p[i]+1)%100000;
    }
    return ret;
  }
  bool sliceCmp(const leveldb::Slice & a,const leveldb::Slice & b){
    if(a.size()!=b.size()) return false;
    size_t sz = std::max(a.size(),b.size());
    for(int i =0;i<sz;++i)
    {
      if(a[i]!=b[i])
        return false;
    }
    return true;
  }
  class Hash_table
  {
    public:
    std::pair<leveldb::Slice * , leveldb::Slice * >  * _ht;

  };
}