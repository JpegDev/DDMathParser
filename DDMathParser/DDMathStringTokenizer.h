//
//  DDMathParserTokenizer.h
//  DDMathParser
//
//  Created by Dave DeLong on 6/28/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DDMathStringToken;

@interface DDMathStringTokenizer : NSEnumerator {
    unichar *_characters;
    NSUInteger _length;
    NSUInteger _characterIndex;
    
    NSArray *_tokens;
    NSUInteger _tokenIndex;
    
}

+ (NSCharacterSet *)legalCharacters;

+ (id)tokenizerWithString:(NSString *)expressionString error:(NSError **)error;
- (id)initWithString:(NSString *)expressionString error:(NSError **)error;

- (NSArray *)tokens;

- (DDMathStringToken *)nextToken;
- (DDMathStringToken *)peekNextToken;

- (void)reset;

// methods overridable by subclasses
- (void)didParseToken:(DDMathStringToken *)token;

// methods that can be used by subclasses
- (void)appendToken:(DDMathStringToken *)token;

@end
