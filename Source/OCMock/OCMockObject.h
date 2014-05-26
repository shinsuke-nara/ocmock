//---------------------------------------------------------------------------------------
//  $Id$
//  Copyright (c) 2004-2008 by Mulle Kybernetik. See License file for details.
//---------------------------------------------------------------------------------------

#import <Foundation/Foundation.h>

@class OCMLocation;
@class OCMockRecorder;
@class OCMInvocationMatcher;


@interface OCMockObject : NSProxy
{
	BOOL			isNice;
	BOOL			expectationOrderMatters;
	NSMutableArray	*recorders;
	NSMutableArray	*expectations;
	NSMutableArray	*rejections;
	NSMutableArray	*exceptions;
    NSMutableArray  *invocations;
}

+ (id)mockForClass:(Class)aClass;
+ (id)mockForProtocol:(Protocol *)aProtocol;
+ (id)partialMockForObject:(NSObject *)anObject;

+ (id)niceMockForClass:(Class)aClass;
+ (id)niceMockForProtocol:(Protocol *)aProtocol;

+ (id)strictMockForClass:(Class)aClass;
+ (id)strictPartialMockForObject:(NSObject *)anObject;

+ (id)observerMock;

- (id)init;

- (void)setExpectationOrderMatters:(BOOL)flag;

- (id)stub;
- (id)expect;
- (id)reject;

- (id)verify;
- (id)verifyAtLocation:(OCMLocation *)location;

- (void)verifyWithDelay:(NSTimeInterval)delay;

- (void)stopMocking;

// internal use only

- (void)prepareForMockingMethod:(SEL)aSelector;
- (void)prepareForMockingClassMethod:(SEL)aSelector;

- (BOOL)handleInvocation:(NSInvocation *)anInvocation;
- (void)handleUnRecordedInvocation:(NSInvocation *)anInvocation;
- (BOOL)handleSelector:(SEL)sel;

- (void)verifyInvocation:(OCMInvocationMatcher *)matcher;
- (void)verifyInvocation:(OCMInvocationMatcher *)matcher atLocation:(OCMLocation *)location;

@property (nonatomic, readwrite) BOOL isStrict;

@end

