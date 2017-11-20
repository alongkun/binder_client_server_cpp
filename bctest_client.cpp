#define LOG_TAG "HelloService"

#include <fcntl.h>
#include <sys/prctl.h>
#include <sys/wait.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <cutils/properties.h>
#include <utils/Log.h>

#include "IHelloService.h"

using namespace android;

int main(int argc, char** argv)
{
	int ret;

	if(argc < 2)
	{
		ALOGI("argv < 2\n");
		return -1;
	}

	sp<ProcessState> proc(ProcessState::self());
	sp<IServiceManager> sm = defaultServiceManager();
	
	sp<IBinder> binder = sm->getService(String16("Hello"));

	if (binder == 0) 
	{
		ALOGI("can't get hello service\n");
		return -1;
	}

	sp<IHelloService> service = interface_cast<IHelloService>(binder);

	if(argc < 3)
	{
		service->sayhello();
		ALOGI("clinet call sayhello\n");
	}
	else
	{
		ret = service->sayhello_to(argv[2]);
		ALOGI("clinet call sayhello_to cnt : %d\n", ret);
	}
	
	return 0;
}


