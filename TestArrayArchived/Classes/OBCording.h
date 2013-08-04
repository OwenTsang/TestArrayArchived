//
//  OBCording.h
//  Taffics
//
//  Created by OwenTsang on 5/8/13.
//
//

#ifndef __Taffics__OBCording__
#define __Taffics__OBCording__

#include "cocos2d.h"

using namespace cocos2d;

#define CODER_KEY_MAKE(primaryKey,subKey)\
    CCString::createWithFormat("%s_%s",primaryKey,subKey)->getCString()

class OBCoding: public CCObject
{
protected:
    OBCoding():CCObject(){}

public:
    virtual void encodeWithCoder(CCUserDefault* encoder,const char* primerKey = NULL) = 0;
    virtual OBCoding* initWithCoder(CCUserDefault* decoder,const char* primerKey = NULL) = 0;
};

#define OB_ARCHIVED_ARRAY(xmlWriter,arrayName,array) \
            {\
                if(!xmlWriter || !arrayName || !array)\
                return;\
                int count = array->count();\
                xmlWriter->setIntegerForKey(CCString::createWithFormat("%s_count",arrayName)->getCString(),count);\
                for(int i = 0; i < count ; ++i)\
                {\
                    OBCoding* coder = (OBCoding*)array->objectAtIndex(i);\
                    coder->encodeWithCoder(xmlWriter, CCString::createWithFormat("%s_%d",arrayName,i)->getCString());\
                }\
            }


#define OB_UNARCHIVED_ARRAY(unarchivedArray,xmlReader,arrayName,TYPE_NAME) \
            {\
                if(!xmlReader || !arrayName){\
                    unarchivedArray = NULL; \
                }\
                else{\
                    int count = 0; \
                    OBCoding* coder = NULL;\
                    count = xmlReader->getIntegerForKey(CCString::createWithFormat("%s_count",arrayName)->getCString(),count);\
                    if(count <= 0){\
                        unarchivedArray = NULL; \
                    }\
                    else{\
                        unarchivedArray = CCArray::createWithCapacity(count);\
                        for(int i = 0; i < count ; ++i)\
                        {\
                            coder = dynamic_cast<OBCoding*>(new TYPE_NAME());\
                            assert(coder);\
                            coder->initWithCoder(xmlReader,CCString::createWithFormat("%s_%d",arrayName,i)->getCString());\
                            unarchivedArray->addObject(coder);\
                            coder->release();\
                        }\
                    }\
                }\
            }

#endif /* defined(__Taffics__OBCording__) */
