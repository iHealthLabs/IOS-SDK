//
//  ViewController.h
//  TestHS6SDK
//
//  Created by daiqingquan on 16/1/13.
//  Copyright © 2016年 daiqingquan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "iHealthHS6.h"
@interface ViewController : UIViewController{
    HS6User *currentUser;
    NSString *HS6SerialNub;
    NSString *wifiPasswrod;
}

- (IBAction)unbind:(UIButton *)sender;

- (IBAction)setHS6:(UIButton *)sender;

- (IBAction)Binding:(UIButton *)sender;

@end

