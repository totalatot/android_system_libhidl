/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// All static variables go here, to control initialization and
// destruction order in the library.

#include <android/hidl/base/1.0/IBase.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <hwbinder/IBinder.h>
#include <utils/threads.h>

namespace android {
namespace hardware {

// For ServiceManagement.cpp
extern Mutex gDefaultServiceManagerLock;
extern sp<android::hidl::manager::V1_0::IServiceManager> gDefaultServiceManager;

// For HidlBinderSupport
// value function receives reinterpret_cast<void *>(static_cast<IFoo *>(foo)),
// returns sp<IBinder>
extern std::map<std::string, std::function<sp<IBinder>(void *)>>
        gBnConstructorMap;

// For HidlPassthroughSupport
// value function receives reinterpret_cast<void *>(static_cast<IFoo *>(foo)),
// returns sp<IBase>
extern std::map<std::string, std::function<sp<::android::hidl::base::V1_0::IBase>(void *)>>
        gBsConstructorMap;

}   // namespace hardware
}   // namespace android