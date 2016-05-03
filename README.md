# SDK
Update History:  
1. Update version 1.0.13, enable bit-code function.  
2. Update version 1.0.14, support BP3L BP7S KD926 KD550BT HS6.(2016.1.11)   
3. Update version 1.0.15, fix PO3 bug(2016.3.7)
4. Update version 1.0.16, add dataID for measure reault , add calories for sport and bmr.(2016.5.3)
    a. Add dataID for measure result(BP BG HS AM PO), etc: {"weight":60,"dataID":"xxxxxxx"}
    b. Add 'activityLevel' property for AM user, 'bmr' property is invalidate now. 
       activityLevel=1, Sedentary,spend most of day sitting.    
       activityLevel=2, Active,spend a good part of day doing some physical activity.
       activityLevel=3, Very Active,spend most of day doing heavy physical activity.
    c. Modify calories for AM, etc {Calories = 49,Step = 1213,TotalCalories = 656}
       Calories is for sport only.
       TotalCalories sum Calories and bmr.



### Support iHealth Device for iOS

iHealth Bp3  
iHealth Bp3l  
iHealth Bp5  
iHealth Bp7  
iHealth Bp7s  
iHealth Bp550BT  
iHealth KD926  
iHealth Abi  
iHealth Hs3  
iHealth Hs4  
iHealth Hs4s  
iHealth Hs5  
iHealth Hs6  
iHealth Am3  
iHealth Am3s  
iHealth Po3  
iHealth BG1(AG-680)  
iHealth BG5 


## iHealth Device Connection 

iHealth Device SDK communicate with iHealth Device by Dock, Bluetooth, BluetoothLe, Wifi or Audio.  
**Dock:** iHealth Bp3  
**Bluetooth:** iHealth Bp5, iHealth Bp7,  iHealth Abi, iHealth Hs3,  iHealth BG5  
**BluetoothLe:** iHealth Bp3l, iHealth Bp550BT, iHealth KD926, iHealth Am3, iHealth Am3s, iHealth Po3, iHealth Bp7s, iHealth Hs4, iHealth Hs4s,  
**Audio:** iHealth BG1(AG-680)  
**Wifi:** iHealth Hs5, iHealth Hs6



### Document for development
[Click this link](https://github.com/iHealthLabs/IOS-SDK/tree/master/%20Document)


