//
//  iHealthHS6.h
//  iHealthHS6
//
//  Created by daiqingquan on 15/11/25.
//  Copyright © 2015年 daiqingquan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "User.h"

/*HS6 error instruction*/
/*
 error code:
 
 7:User verify error;
 
 101,102,103,104:networkerror
 
 */

typedef void (^DisposeHS6SuccessBlock)(NSDictionary* deviceInfo);

typedef void (^DisposeHS6FailBlock)(NSString* failmsg);

typedef void (^DisposeHS6EndBlock)(NSDictionary* deviceDic);

typedef void (^DisposeHS6ErrorBlock)(NSNumber* error);

//Binding QR Device
typedef void(^BinedQRDeviceBlock)(NSArray *resultArray);
//Binding QR Device
typedef void(^BinedQRDeviceErrorBlock)(NSString *errorCode);

//unbind Device
typedef void(^DisBinedQRDeviceBlock)(NSArray *resultArray);
//unbind QR Device
typedef void(^DisBinedQRDeviceErrorBlock)(NSString *errorCode);

typedef void (^BlockHS6UserAuthentication)(UserAuthenResult result);

@interface iHealthHS6 : NSObject{

    DisposeHS6SuccessBlock _disposeHS6SuccessBlock;
    
    DisposeHS6FailBlock _disposeHS6FailBlock;
    
    DisposeHS6EndBlock _disposeHS6EndBlock;
    
    DisposeHS6ErrorBlock _disposeHS6ErrorBlock;
    
    BlockHS6UserAuthentication _blockHS6UserAuthentication;
    
    
    BinedQRDeviceBlock _blockBinedQRDevice;
    BinedQRDeviceErrorBlock _blockBinedQRDeviceError;
    
    DisBinedQRDeviceBlock _blockDisBinedQRDevice;
    DisBinedQRDeviceErrorBlock _blockDisBinedQRDeviceError;

}

+(iHealthHS6 *)shareIHHS6Controller;


/*Binding QR Device*/
//When using the SDK for the first time, measuring method needs to be called to finish user verification.
/*
 Import parameter:
 tempUser: Properties included: clientID，clientSecret，userID，height.
 deviceID: device Mac
 clientID & clientSecret: the only identification for users of the SDK, requires registration from iHealth administrator, please email: lvjincan@jiuan.com for more information.
 Return parameters:
 BlockHS6UserAuthentication: The return parameters of ’‘userid’, ‘height’, ’clientID’, and ‘clientSecret’ after verification
 
 The interpretation for the verification:
 UserAuthen_RegisterSuccess: New-user registration succeeded.
 UserAuthen_LoginSuccess: User login succeeded.
 UserAuthen_CombinedSuccess: The user is an iHealth user as well, measurement via SDK has been activated, and the data from the measurement belongs to the user.
 UserAuthen_TrySuccess: Testing without internet connection succeeded.
 UserAuthen_InvalidateUserInfo: Userid/clientID/clientSecret verification failed.
 UserAuthen_SDKInvalidateRight: SDK has not been authorized.
 UserAuthen_UserInvalidateRight: User has not been authorized.
 UserAuthen_InternetError: Internet error, verification failed.
 The measurement via SDK will be operated in the case of 1-4, and will be terminated if any of 5-8 occurs. The interface needs to be re-called after analyzing the return parameters.
 Notice: when a new user registers via SDK, an ‘iHealth disclaimer’ will pop up automatically, and will require the user to agree in order to continue. SDK applications require an Internet connection; there is 10-day trial period if the SDK cannot connect to the internet, the SDK is fully functional during tryout period, but will be terminated without a working internet connection after 10 days.
 
 binedResult: Action = 1;(1:bind sucess 2：full user bind faild 3,:ts error bind faild 4 other),MAC
 
 Position = 1;（user in weight number）
 
 Status = 1;（1:binding 2：unbind）
 
 TS (time);

 binedError: error code
 Error code definition：
 refer to “error” : HS6 error instruction.
 */

-(void)cloudCommandUserBinedQRDeviceWithUser:(User *)tempUser  deviceID:(NSString *)tempDeviceID BlockHS6UserAuthentication:(BlockHS6UserAuthentication)BlockHS6UserAuthentication binedResult:(BinedQRDeviceBlock)result binedError:(BinedQRDeviceErrorBlock)error;

/*unBind QR Device*/
/*
 Import parameter:
 tempUser: Properties included: clientID，clientSecret，userID，height.
 deviceID: device Mac
 clientID & clientSecret: the only identification for users of the SDK, requires registration from iHealth administrator, please email: lvjincan@jiuan.com for more information.
 Return parameters:
 
 disBinedResult: Action = 1;(1:bind sucess 2：full user bind faild 3,:ts error bind faild 4 other),MAC
 
 Status = 1;（1:binding 2：unbind）
 
 disBinedError: error code
 Error code definition：
 refer to “error” : HS6 error instruction.
 */


-(void)cloudCommandUserDisBinedQRDeviceForUser:(User *)tempUser withDeviceID:(NSString *)tempDeviceID disBinedResult:(DisBinedQRDeviceBlock)result disBinedError:(DisBinedQRDeviceErrorBlock)error;

/*set HS6 wifi*/
/*
 Import parameter:
 password: wifi password.
 Return parameters:
 
 disposeHS6SuccessBlock: bind sucess
 
 disposeHS6FailBlock:user bind faild
 
 disposeHS6EndBlock: end set
 
 disposeHS6ErrorBlock: error code
 Error code definition：
 refer to “error” : HS6 error instruction.
 */

-(void)commandSetHS6WithPassWord:(NSString*)password disposeHS6SuccessBlock:(DisposeHS6SuccessBlock)disposeHS6SuccessBlock disposeHS6FailBlock:(DisposeHS6FailBlock)disposeHS6FailBlock  disposeHS6EndBlock:(DisposeHS6EndBlock)disposeHS6EndBlock disposeHS6ErrorBlock:(DisposeHS6ErrorBlock)disposeHS6ErrorBlock;



@end
