//
//  Student.cpp
//  TestArrayArchived
//
//  Created by OwenTsang on 8/4/13.
//
//

#include "Student.h"

void Student::encodeWithCoder(CCUserDefault* encoder,const char* primerKey)
{
    assert(encoder != NULL && strcmp(primerKey, "")!= 0);
    
    encoder->setIntegerForKey(CODER_KEY_MAKE(primerKey, "ID") ,_id);
    encoder->setStringForKey(CODER_KEY_MAKE(primerKey, "NAME") ,_name);
}

OBCoding* Student::initWithCoder(CCUserDefault* decoder,const char* primerKey)
{
    assert(decoder != NULL && strcmp(primerKey, "")!= 0);
    
    _id = decoder->getIntegerForKey(CODER_KEY_MAKE(primerKey, "ID"),0);
    _name = decoder->getStringForKey(CODER_KEY_MAKE(primerKey, "NAME"),"");
    
    return this;
}