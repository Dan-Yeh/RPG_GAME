#ifndef BOT_H
#define BOT_H

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

class Bot {
public:
#ifdef TEST
//For gprof to test perfomance
    std::string behavior_f1 = "Dan show fight rest fight rest fight fight 2 show fight save q";
    std::string behavior_f2 = "Dan show fight rest fight rest fight show fight save q";
    std::string behavior_m1 = "Fan show fight rest fight rest fight fight 3 show fight save q";
    std::string behavior_m2 = "Fan show fight rest fight rest fight fight show fight save q";
    std::string behavior_t1 = "Ian show fight rest fight rest fight fight 1 show fight save q";
    std::string behavior_t2 = "Ian show fight rest fight rest fight fight show fight save q";
    std::vector<std::string> behaviors { behavior_f1, behavior_f2, behavior_m1, behavior_m2, behavior_t1, behavior_t2 };
#else
    std::string behavior_f1 = "Dan show fight rest fight rest fight fight 2 show fight save q";
#endif
public:
    Bot();
};

#endif
