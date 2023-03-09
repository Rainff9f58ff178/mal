//
// Created by rain on 23-3-1.
//

#include<regex>
#include <string>
#include <iostream>
#include <filesystem>
using namespace std;
int main(){
//    string path="/src/img.jpeg";
//    std::regex regex1("src");
//    auto begin =std::sregex_iterator(path.begin(),path.end(),regex1);
//    std::sregex_iterator i = begin;
//    auto word_end = std::sregex_iterator ();
//    if(begin!=word_end){
//        std::smatch match=*i;
//        std::string match_str = match.str();
//        if(match_str.size()>0){
//            cout<<match_str<<endl;
//        }
//    }
//check if  end in .JBC

//    string path="/img.jpeg";
//    auto file_name =  std::find(path.rbegin(),path.rend(),'/');
//    auto back_name =std::find(path.rbegin(),path.rend(),'.');
//
//    cout<<(std::string(path.data(),&(*(file_name)))=="")<<endl;
    for (const auto & entry : std::filesystem::directory_iterator(".")){
        std::string file_path (std::move(entry.path().string()),1,entry.path().string().size()-1);
        cout<<file_path<<endl;
    }
    return 0;

}
