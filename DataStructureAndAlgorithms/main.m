//
//  main.m
//  DataStructureAndAlgorithms
//
//  Created by 黄启明 on 2018/10/17.
//  Copyright © 2018 Himin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Model.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
//        NSNumber *t = @20;
//        NSKeyValueObservingOptionNew
        
        NSDictionary *dict = @{@"age": @20,
                               @"name": @"Himin",
                               @"skills": @[@"c", @"oc", @"swift"]};
//        Model *model = [Model modelWithDict:dict];
        Model *model = [Model new];
        
        [model setValuesForKeysWithDictionary:dict];
        
        [model setValue:nil forKey:@"age"];
        
        [model setValue:[NSValue valueWithRect:CGRectMake(23, 0, 10, 10)] forKey:@"rect"];
        
        NSLog(@"%f",[[model valueForKey:@"rect"] rectValue].origin.x);
        
        NSLog(@"age = %@",[model valueForKey:@"age"]);
        
        NSLog(@"rectX = %f",model.rect.origin.x);
        
        NSLog(@"name = %@,\nskills = %@",model.name,model.skills);
        
    }
    return 0;
}
