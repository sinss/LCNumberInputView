//
//  ViewController.m
//  LCPickerViewSample
//
//  Created by Leo Chang on 10/21/13.
//  Copyright (c) 2013 MountainStar Inc. All rights reserved.
//

#import "ViewController.h"
#import "LCNumberInputControl.h"

@interface ViewController () <LCNumberInputDelegate>

@property (nonatomic, strong) UIView *maskView;
@property (nonatomic, strong) NSNumber *pickValue;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)show:(id)sender
{
    LCNumberInputControl *inputView = [[[NSBundle mainBundle] loadNibNamed:@"LCNumberInputControl" owner:self options:nil] objectAtIndex:0];
    [inputView setFrame:CGRectMake(0, self.view.frame.size.height, kNumberControlWidth, kNumberControlHeight)];
    [inputView setDelegate:self];
    [inputView setTag:0];
    [inputView setInputType:numberInputTypeInteger];
    //current pick value
    [inputView setInputResult:[NSNumber numberWithInteger:[_resultLabel.text integerValue]]];
    [inputView.titleBar.topItem setTitle:[NSString stringWithFormat:@"Please input a number"]];
    [inputView.numberField setPlaceholder:[NSString stringWithFormat:@"Input you number"]];
    [self.view addSubview:inputView];
    
    /*
     if your parent controller has a tableview , then your need tableview contentoffset
     
     eg. self.tableView.contentoffset
     */
    [inputView showWithOffset:CGPointMake(0, 0) inView:self.view];
}

- (IBAction)showFloat:(id)sender
{
    LCNumberInputControl *inputView = [[[NSBundle mainBundle] loadNibNamed:@"LCNumberInputControl" owner:self options:nil] objectAtIndex:0];
    [inputView setFrame:CGRectMake(0, self.view.frame.size.height, kNumberControlWidth, kNumberControlHeight)];
    [inputView setDelegate:self];
    [inputView setTag:1];
    [inputView setInputType:numberInputTypeFloat];
    //current pick value
    [inputView setInputResult:[NSNumber numberWithInteger:[_resultLabel.text integerValue]]];
    [inputView.titleBar.topItem setTitle:[NSString stringWithFormat:@"Please input a number"]];
    [inputView.numberField setPlaceholder:[NSString stringWithFormat:@"Input you number"]];
    [self.view addSubview:inputView];
    
    /*
     if your parent controller has a tableview , then your need tableview contentoffset
     
     eg. self.tableView.contentoffset
     */
    [inputView showWithOffset:CGPointMake(0, 0) inView:self.view];
}

- (void)dismissPickerControl:(LCNumberInputControl*)view
{
    /*
     if your parent controller has a tableview , then your need tableview contentoffset
     
     eg. self.tableView.contentoffset
     */
    [view dismissWithOffset:CGPointMake(0, 0)];
}

#pragma mark - LCTableViewPickerDelegate


- (void)numberControl:(LCNumberInputControl *)view didInputWithNumber:(NSNumber *)number
{
    self.pickValue = number;
    if (view.tag == 0)
    {
        [_resultLabel setText:[NSString stringWithFormat:@"%li", (long)number.integerValue]];
    }
    else if (view.tag == 1)
    {
        [_resultLabel setText:[NSString stringWithFormat:@"%f", number.doubleValue]];
    }
    
    [self dismissPickerControl:view];
}

- (void)numberControl:(LCNumberInputControl *)view didCancelWithNumber:(NSNumber *)number
{
    [self dismissPickerControl:view];
}
@end
