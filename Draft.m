//
//  Draft.m
//  Phileas_Gestion
//
//  Created by Romain on 11/05/2015.
//  Copyright (c) 2015 Florent&Romain. All rights reserved.
//

#import "Draft.h"

@implementation Draft

+(RKObjectMapping*)mapping   {
    
    RKObjectMapping *mapping = [RKObjectMapping mappingForClass:[Draft class]];
    
    [mapping addAttributeMappingsFromDictionary:@{
                                                  @"def_id": @"def_id",
                                                  @"amount": @"amount",
                                                  @"date": @"date",
                                                  @"km": @"km",
                                                  @"receipt1": @"receipt",
                                                  @"details.3": @"com",
                                                  @"details.4": @"from",
                                                  @"details.5": @"to"
                                                  }];
    
    
    return mapping;
    
}

@end