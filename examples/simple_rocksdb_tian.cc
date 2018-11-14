#include <string>
#include <iostream>
#include "rocksdb/db.h"
#include "rocksdb/options.h" 
using namespace rocksdb; 
std::string kDBPath = "/tmp/rocksdb_simple_example"; 
int main() {
	DB* db;
	Options options;
	// create the DB if it's not already present
	options.create_if_missing = true;
	// open DB
	Status s = DB::Open(options, kDBPath, &db);
	assert(s.ok());
	// Put key-value
	s = db->Put(WriteOptions(), "key1", "example value");
	assert(s.ok());
	std::string value;
	// get value
	s = db->Get(ReadOptions(), "key1", &value);
	assert(s.ok());
	std::cout<<"Get key1 from rocksdb database,value is :("<<value<<")"<<std::endl;
	delete db;
	return 0;
}
