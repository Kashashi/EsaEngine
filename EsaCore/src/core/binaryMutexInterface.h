#ifndef __BINARYMUTEXINTERFACE_H__
#define __BINARYMUTEXINTERFACE_H__

#include <string>
#include <memory>
#include "loggerInterface.h"

namespace Kashashi{
class binaryMutexInterface{
public:
	binaryMutexInterface(shared_ptr<loggerInterface> logger);
	virtual ~binaryMutexInterface() = default;
	virtual bool initialize(const std::string& executeName) = 0;
};
}


#endif//__BINARYMUTEXINTERFACE_H__