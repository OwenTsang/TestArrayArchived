//
//  Student.h
//  TestArrayArchived
//
//  Created by OwenTsang on 8/4/13.
//
//

#ifndef __TestArrayArchived__Student__
#define __TestArrayArchived__Student__

#include "cocos2d.h"
#include "OBCording.h"


class Student :public OBCoding
{
public:
    virtual void encodeWithCoder(CCUserDefault* encoder,const char* primerKey = NULL);
    virtual OBCoding* initWithCoder(CCUserDefault* decoder,const char* primerKey = NULL);
    
    CC_SYNTHESIZE(int, _id, Id);
    CC_SYNTHESIZE(std::string, _name, Name);

};


#endif /* defined(__TestArrayArchived__Student__) */
