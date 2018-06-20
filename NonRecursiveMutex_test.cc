#include <iostream>
#include <mutex>
#include <vector>
using namespace std;
MutexLock mutex;
std::vector<Foo> foos;

void post(const Foo& f){
	MutexLockGuard lock(mutex);
	foos.push_back(f);	
}

void traverse(){
	MutexLockGuard lock(mutex);
	for(std::vector<Foo>::const_iterator it = foos.begin(); it != foos.end();++it){
		it->doit();
	}
}

//xiugai
void post(const Foo& f){
	MutexLockGuard lock(mutex);
	postWithLockHold(f);
}

void postWithLockHold(const Foo& f){
	foos.push_back(f);
}

