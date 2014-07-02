//
//  NSNumber+extend.h
//  InsurancePig
//
//  Created by Leo Chang on 6/23/14.
//  Copyright (c) 2014 Good-idea Consunting Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSNumber (extend)

/* 顯示 */
- (NSString*)toDisplayNumberWithDigit:(NSInteger)digit;
- (NSString*)toDisplayPercentageWithDigit:(NSInteger)digit;

/*　四捨五入 */
- (NSNumber*)doRoundWithDigit:(NSUInteger)digit;
- (NSNumber*)doCeilWithDigit:(NSUInteger)digit;
- (NSNumber*)doFloorWithDigit:(NSUInteger)digit;

@end
