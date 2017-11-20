LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	BnHelloService.cpp \
	BpHelloService.cpp \
	bctest_server.cpp 

LOCAL_SHARED_LIBRARIES := \
	libcutils \
	libutils \
	liblog \
	libbinder 

LOCAL_MODULE:= bctest_server
LOCAL_32_BIT_ONLY := true

include $(BUILD_EXECUTABLE)



include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	BnHelloService.cpp \
	BpHelloService.cpp \
	bctest_client.cpp 

LOCAL_SHARED_LIBRARIES := \
	libcutils \
	libutils \
	liblog \
	libbinder 

LOCAL_MODULE:= bctest_client
LOCAL_32_BIT_ONLY := true

include $(BUILD_EXECUTABLE)
