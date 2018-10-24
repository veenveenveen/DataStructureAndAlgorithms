//
//  Model.m
//  DataStructureAndAlgorithms
//
//  Created by 黄启明 on 2018/10/17.
//  Copyright © 2018 Himin. All rights reserved.
//

#import "Model.h"

@interface Model() {
    int _age;
}

@end

@implementation Model

+ (Model *)modelWithDict:(NSDictionary *)dict {
    Model *model = [[Model alloc] init];
    [model setValuesForKeysWithDictionary:dict];
    return model;
}

- (void)setValue:(id)value forUndefinedKey:(NSString *)key {
    // do nothing
}

- (void)setNilValueForKey:(NSString *)key {
    NSLog(@"%@value为空",key);
}

//+ (BOOL)accessInstanceVariablesDirectly {
//    return NO;
//}


- (CGRect)rect {
    return _rect;
}

@end
