//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// WindowsDevicesSpi.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_DEVICES_SPI_EXPORT
#define OBJCUWP_WINDOWS_DEVICES_SPI_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Devices_Spi.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDSSpiConnectionSettings, WDSSpiBusInfo, WDSSpiDevice, WDSSpiController;
@protocol WDSISpiConnectionSettingsFactory, WDSISpiConnectionSettings, WDSISpiBusInfo, WDSISpiDeviceStatics, WDSISpiController, WDSISpiControllerStatics, WDSISpiDevice;

// Windows.Devices.Spi.SpiMode
enum _WDSSpiMode {
    WDSSpiModeMode0 = 0,
    WDSSpiModeMode1 = 1,
    WDSSpiModeMode2 = 2,
    WDSSpiModeMode3 = 3,
};
typedef unsigned WDSSpiMode;

// Windows.Devices.Spi.SpiSharingMode
enum _WDSSpiSharingMode {
    WDSSpiSharingModeExclusive = 0,
    WDSSpiSharingModeShared = 1,
};
typedef unsigned WDSSpiSharingMode;

#include "WindowsDevicesSpiProvider.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Spi.ISpiDeviceStatics
#ifndef __WDSISpiDeviceStatics_DEFINED__
#define __WDSISpiDeviceStatics_DEFINED__

@protocol WDSISpiDeviceStatics
- (NSString *)getDeviceSelector;
- (NSString *)getDeviceSelectorFromFriendlyName:(NSString *)friendlyName;
- (WDSSpiBusInfo*)getBusInfo:(NSString *)busId;
- (void)fromIdAsync:(NSString *)busId settings:(WDSSpiConnectionSettings*)settings success:(void (^)(WDSSpiDevice*))success failure:(void (^)(NSError*))failure;
@end

OBJCUWP_WINDOWS_DEVICES_SPI_EXPORT
@interface WDSISpiDeviceStatics : RTObject <WDSISpiDeviceStatics>
@end

#endif // __WDSISpiDeviceStatics_DEFINED__

// Windows.Devices.Spi.SpiConnectionSettings
#ifndef __WDSSpiConnectionSettings_DEFINED__
#define __WDSSpiConnectionSettings_DEFINED__

OBJCUWP_WINDOWS_DEVICES_SPI_EXPORT
@interface WDSSpiConnectionSettings : RTObject
+ (WDSSpiConnectionSettings*)make:(int)chipSelectLine ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property WDSSpiSharingMode sharingMode;
@property WDSSpiMode mode;
@property int dataBitLength;
@property int clockFrequency;
@property int chipSelectLine;
@end

#endif // __WDSSpiConnectionSettings_DEFINED__

// Windows.Devices.Spi.SpiBusInfo
#ifndef __WDSSpiBusInfo_DEFINED__
#define __WDSSpiBusInfo_DEFINED__

OBJCUWP_WINDOWS_DEVICES_SPI_EXPORT
@interface WDSSpiBusInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) int chipSelectLineCount;
@property (readonly) int maxClockFrequency;
@property (readonly) int minClockFrequency;
@property (readonly) NSArray* /* int */ supportedDataBitLengths;
@end

#endif // __WDSSpiBusInfo_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWP_WINDOWS_DEVICES_SPI_EXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.Spi.SpiDevice
#ifndef __WDSSpiDevice_DEFINED__
#define __WDSSpiDevice_DEFINED__

OBJCUWP_WINDOWS_DEVICES_SPI_EXPORT
@interface WDSSpiDevice : RTObject <WFIClosable>
+ (NSString *)getDeviceSelector;
+ (NSString *)getDeviceSelectorFromFriendlyName:(NSString *)friendlyName;
+ (WDSSpiBusInfo*)getBusInfo:(NSString *)busId;
+ (void)fromIdAsync:(NSString *)busId settings:(WDSSpiConnectionSettings*)settings success:(void (^)(WDSSpiDevice*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WDSSpiConnectionSettings* connectionSettings;
@property (readonly) NSString * deviceId;
- (void)write:(NSArray* /* uint8_t */)buffer;
- (void)read:(NSArray* /* uint8_t */*)buffer;
- (void)transferSequential:(NSArray* /* uint8_t */)writeBuffer readBuffer:(NSArray* /* uint8_t */*)readBuffer;
- (void)transferFullDuplex:(NSArray* /* uint8_t */)writeBuffer readBuffer:(NSArray* /* uint8_t */*)readBuffer;
- (void)close;
@end

#endif // __WDSSpiDevice_DEFINED__

// Windows.Devices.Spi.SpiController
#ifndef __WDSSpiController_DEFINED__
#define __WDSSpiController_DEFINED__

OBJCUWP_WINDOWS_DEVICES_SPI_EXPORT
@interface WDSSpiController : RTObject
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDSSpiController*))success failure:(void (^)(NSError*))failure;
+ (void)getControllersAsync:(RTObject<WDSPISpiProvider>*)provider success:(void (^)(NSArray* /* WDSSpiController* */))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (WDSSpiDevice*)getDevice:(WDSSpiConnectionSettings*)settings;
@end

#endif // __WDSSpiController_DEFINED__

