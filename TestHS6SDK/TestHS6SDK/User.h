//
//  User.h
//  HSDemoCode
//
//  Created by zhiwei jing on 14-7-23.
//  Copyright (c) 2014年 zhiwei jing. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum{
    UserAuthen_RegisterSuccess = 1,//New-user registration succeeded
    UserAuthen_LoginSuccess,// User login succeeded
    UserAuthen_CombinedSuccess,// The user is iHealth user as well, measurement via SDK has been activated, and the data from the measurement belongs to the user
    UserAuthen_TrySuccess,//Testing without Internet connection succeeded
    UserAuthen_InvalidateUserInfo,//Userid/clientID/clientSecret verification failed
    UserAuthen_SDKInvalidateRight,//SDK has not been authorized
    UserAuthen_UserInvalidateRight,//User has not been authorized
    UserAuthen_InternetError//Internet error, verification failed
}UserAuthenResult;

//User
typedef enum{
    LengthUnit_Mile = 0,
    LengthUnit_Kilometer,
}LengthUnit;

typedef enum{
    UserSex_Female = 0,
    UserSex_Male,
}UserSex;

typedef enum{
    HSUnit_Kg = 1, //kg
    HSUnit_LB,     //lb
    HSUnit_ST      //st
}HSUnit;

typedef enum{
    UserIsAthelete_No = 0, //No athelete
    UserIsAthelete_Yes     //athelete
}UserIsAthelete;



@interface User : NSObject

@property (nonatomic, strong) NSString * clientID;
@property (nonatomic, strong) NSString * clientSecret;
@property (nonatomic, strong) NSString * userID;

@property (nonatomic, strong) NSNumber * serialNub;
@property (nonatomic, strong) NSDate *birthday;
//unit:cm
@property (nonatomic, strong) NSNumber * height;
//kg
@property (strong, nonatomic)NSNumber *weight;
@property (strong, nonatomic)NSNumber *bmr;
@property UserIsAthelete isAthlete;
@property UserSex sex;
@property LengthUnit lengthUnit;


@end
