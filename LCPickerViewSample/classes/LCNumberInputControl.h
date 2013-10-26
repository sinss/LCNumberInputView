//
//  LCNumberInputControl.h
//  InsurancePig
//
//  Created by leo.chang on 13/10/22.
//  Copyright (c) 2013年 Good-idea Consunting Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

#define kNumberControlWidth 320
#define kNumberControlHeight 300
#define kAnimationDuration 0.4
#define kNumberInputTitleBarColor [UIColor colorWithRed:0.251 green:0.502 blue:0.000 alpha:1.000]

enum
{
    numberInputTypeInteger = 0,
    numberInputTypeFloat = 1,
};

@class LCNumberInputControl;
@protocol LCNumberInputDelegate <NSObject>

- (void)numberControl:(LCNumberInputControl*)view didInputWithNumber:(NSNumber*)number;
- (void)numberControl:(LCNumberInputControl *)view didCancelWithNumber:(NSNumber *)number;

@end

@interface LCNumberInputControl : UIView

@property (weak) id <LCNumberInputDelegate> delegate;
@property (nonatomic, strong) IBOutlet UINavigationBar *titleBar;
@property (nonatomic, strong) IBOutlet UITextField *numberField;
@property (nonatomic, strong) IBOutlet UIButton *arrowButton;
@property (nonatomic, strong) NSMutableString *currentInput;
@property (nonatomic, strong) NSNumber *inputResult;
@property (nonatomic, assign) NSInteger inputType;  //number or float
@property (nonatomic, assign) NSInteger tag;

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *placeHolder;

- (IBAction)numberButtonPress:(UIButton*)sender;
- (IBAction)dotButtonPress:(UIButton*)sender;
- (IBAction)clearButtonPress:(UIButton*)sender;
- (IBAction)cancelButtonPress:(UIButton*)sender;
- (IBAction)confirmButonPress:(UIButton*)sender;

- (void)showWithOffset:(CGPoint)offset;
- (void)dismissWithOffset:(CGPoint)offset;

- (IBAction)downButtonPress:(id)sender;

@end
