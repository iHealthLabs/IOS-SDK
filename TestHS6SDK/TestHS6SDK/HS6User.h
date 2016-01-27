//
//  User.h
//  HSDemoCode
//
//  Created by zhiwei jing on 14-7-23.
//  Copyright (c) 2014年 zhiwei jing. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum{
    HS6UserAuthen_RegisterSuccess = 1,//New-user registration succeeded
    HS6UserAuthen_LoginSuccess,// User login succeeded
    HS6UserAuthen_CombinedSuccess,// The user is iHealth user as well, measurement via SDK has been activated, and the data from the measurement belongs to the user
    HS6UserAuthen_TrySuccess,//Testing without Internet connection succeeded
    HS6UserAuthen_InvalidateUserInfo,//Userid/clientID/clientSecret verification failed
    HS6UserAuthen_SDKInvalidateRight,//SDK has not been authorized
    HS6UserAuthen_UserInvalidateRight,//User has not been authorized
    HS6UserAuthen_InternetError//Internet error, verification failed
}HS6UserAuthenResult;

//User
typedef enum{
    HS6LengthUnit_Mile = 0,
    HS6LengthUnit_Kilometer,
}HS6LengthUnit;

typedef enum{
    HS6UserSex_Female = 0,
    HS6UserSex_Male,
}HS6UserSex;

typedef enum{
    HS6HSUnit_Kg = 1, //kg
    HS6HSUnit_LB,     //lb
    HS6HSUnit_ST      //st
}HS6HSUnit;

typedef enum{
    HS6UserIsAthelete_No = 0, //No athelete
    HS6UserIsAthelete_Yes     //athelete
}HS6UserIsAthelete;



@interface HS6User : NSObject

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
@property HS6UserIsAthelete isAthlete;
@property HS6UserSex sex;
@property HS6LengthUnit lengthUnit;


@end
