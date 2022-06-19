//
// Created by rain on 2022/6/16.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_TYPE_H
#define LINUXNETWORKPROGRAMCHENSHUO_TYPE_H


//only use for up_cast;
template<typename To,typename From>
inline To implicit_cast(const From&  f){
    return f;
}
//only use for down_cast;
template<typename To,typename From>
inline To down_cast(const From& f){

    bool never= false;
    if(never){
        return implicit_cast<To>(f);
    }
    //never use implicit_cast to down_cast (fail)

#if !defined(NDEBUG) && !defined(GOOGLE_PROTOBUF_NO_RTTI)
    assert(f == nullptr || dynamic_cast<To>(f) != nullptr);  // RTTI: debug mode only!
#endif
    return static_cast<To>(f);
}
#endif //LINUXNETWORKPROGRAMCHENSHUO_TYPE_H
