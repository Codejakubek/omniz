/**
* OmniZShooters Source Code.
* Copyright © 2021 Dawid Jakubowski (Codedemens)
* 
* 
* Authors:
* Programmer, Graphic Designer, Voice Actor:
*     - Dawid (Codedemens) Jakubowski
*/

#include <OZ_CoreData.h>

////////////////////////////////////////
OZ_DECLARE_CLASS_CPP(OZ_OtherCoreData)
OZ_DECLARE_CLASS_CPP(OZ_DefaultOtherCoreData)
OZ_OtherCoreData::OZ_OtherCoreData(OZ_CoreData& data) : data(data) {

}
OZ_DefaultOtherCoreData::OZ_DefaultOtherCoreData(OZ_CoreData& data) : OZ_OtherCoreData(data) {

}
bool OZ_DefaultOtherCoreData::IsValid() const {
    return true;
}
////////////////////////////////////////
OZ_DECLARE_CLASS_CPP(OZ_CoreData)
OZ_CoreData::OZ_CoreData(OZ_Core& ref) : ref(ref) {

}
OZ_CoreData::~OZ_CoreData() {

}

////////////////////////////////////////