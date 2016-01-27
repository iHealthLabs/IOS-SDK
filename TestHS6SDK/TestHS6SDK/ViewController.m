//
//  ViewController.m
//  TestHS6SDK
//
//  Created by daiqingquan on 16/1/13.
//  Copyright © 2016年 daiqingquan. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Do any additional setup after loading the view, typically from a nib.
    
    currentUser = [[HS6User alloc] init];
    #warning ‘clientSecret’ and ‘clientID’ are the only identification for user of SDK, are required registration from iHealth administrator. lvjincan@ihealthlabs.com.cn
    
    currentUser.clientSecret=@"";
    currentUser.clientID=@"";
    
    #warning ‘userID’, the only identification for the user，by the form of email or cell phone #(cell-phone-# form is not supported temperately)
    currentUser.userID=@"";
    
    #warning ‘HS6SerialNub’, you can scan the QR of HS6
    HS6SerialNub = @"";
    
    #warning ‘wifiPasswrod’, the password of the Wifi connected
    wifiPasswrod = @"";
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)unbind:(UIButton *)sender{
    
    iHealthHS6*hs6=[iHealthHS6 shareIHHS6Controller];
    
    [hs6 cloudCommandUserDisBinedQRDeviceForUser:currentUser withDeviceID:HS6SerialNub disBinedResult:^(NSArray *resultArray) {
        
        NSLog(@"jiebangresultArray :%@",resultArray);
        
    } disBinedError:^(NSString *errorCode) {
        
        NSLog(@"jiebangerrorCode :%@",errorCode);
        
    }];
}


- (IBAction)Binding:(UIButton *)sender{
    
    iHealthHS6*hs6=[iHealthHS6 shareIHHS6Controller];
    
    [hs6 cloudCommandUserBinedQRDeviceWithUser:currentUser deviceID:HS6SerialNub BlockHS6UserAuthentication:^(HS6UserAuthenResult result) {
        
        NSLog(@"UserAuthenResult :%u",result);
        
    } binedResult:^(NSArray *resultArray) {
        
        NSLog(@"bangdingresultArray :%@",resultArray);
        
    } binedError:^(NSString *errorCode) {
        
        
        NSLog(@"bangdingerrorCode :%@",errorCode);
        
    }];
}

- (IBAction)setHS6:(UIButton *)sender{
    
    
    iHealthHS6*hs6=[iHealthHS6 shareIHHS6Controller];
    
    [hs6 commandSetHS6WithPassWord:wifiPasswrod disposeHS6SuccessBlock:^(NSDictionary *deviceInfo) {
        
        NSLog(@"deviceInfo :%@",deviceInfo);
        
    } disposeHS6FailBlock:^(NSString *failmsg) {
        
        NSLog(@"failmsg :%@",failmsg);
        
    } disposeHS6EndBlock:^(NSDictionary *deviceDic) {
        
        NSLog(@"deviceDic :%@",deviceDic);
        
    } disposeHS6ErrorBlock:^(NSNumber *error) {
        
        NSLog(@"seterror :%@",error);
        
    }];
    
}


@end
