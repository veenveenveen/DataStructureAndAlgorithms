//
//  Model.h
//  DataStructureAndAlgorithms
//
//  Created by 黄启明 on 2018/10/17.
//  Copyright © 2018 Himin. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Model : NSObject {
    CGRect _rect;
}

//@property(nonatomic, assign) int age;
@property(nonatomic, copy) NSString *name;
@property(nonatomic, copy) NSArray *skills;

- (CGRect)rect;

+ (Model *)modelWithDict:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
