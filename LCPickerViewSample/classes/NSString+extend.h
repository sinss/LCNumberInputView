//
//  NSString+extend.h
//  InsurancePig
//
//  Created by Leo Chang on 6/20/14.
//  Copyright (c) 2014 Good-idea Consunting Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (extend)

- (NSDate*)toDate;
- (NSDate*)fromStringToFullDate;
- (NSDate*)fromFullStringToDate;
- (NSDate*)fromNSDateStringToDate;

- (BOOL)isPureInt;
- (BOOL)isPureFloat;

/* useful */
-(BOOL)isBlank;
-(BOOL)isValid;
- (NSString *)removeWhiteSpacesFromString;


- (NSUInteger)countNumberOfWords;
- (BOOL)containsString:(NSString *)subString;
- (BOOL)isBeginsWith:(NSString *)string;
- (BOOL)isEndssWith:(NSString *)string;

- (NSString *)replaceCharcter:(NSString *)olderChar withCharcter:(NSString *)newerChar;
- (NSString*)getSubstringFrom:(NSInteger)begin to:(NSInteger)end;
- (NSString *)addString:(NSString *)string;
- (NSString *)removeSubString:(NSString *)subString;

- (BOOL)containsOnlyLetters;
- (BOOL)containsOnlyNumbers;
- (BOOL)containsOnlyNumbersAndLetters;
- (BOOL)isInThisarray:(NSArray*)array;

+ (NSString *)getStringFromArray:(NSArray *)array;
- (NSArray *)getArray;

+ (NSString *)getMyApplicationVersion;
+ (NSString *)getMyApplicationName;

- (NSData *)convertToData;
+ (NSString *)getStringFromData:(NSData *)data;

- (BOOL)isValidEmail;
- (BOOL)isVAlidPhoneNumber;
- (BOOL)isValidUrl;

@end
