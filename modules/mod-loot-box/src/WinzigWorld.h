#ifndef _WINZIG_WORLD_H_
#define _WINZIG_WORLD_H_

#include <vector>
#include "ScriptMgr.h"

class WinzigWorld : public WorldScript
{
public:
    WinzigWorld() : WorldScript("WinzigWorld") {}

    void OnBeforeConfigLoad(bool /*reload*/) override
    {
        SetInitialWorldSettings();
    }

    void SetInitialWorldSettings();

    static bool Enabled;

    static int StackSize;

    static float FiveStarRate;
    static float FourStarRate;

    static int PromotionalGuarantee;
    static int FiveStarGuarantee;
    static int FeaturedGuarantee;
    static int FourStarGuarantee;

    static int Box;
    static int NPC;

    static std::vector<int> Promotions;
    static std::vector<int> Features;
    static std::vector<int> FiveStars;
    static std::vector<int> FourStars;
    static std::vector<int> ThreeStars;

    static int CustomCurrency;
    static int DailyReward;
    static int LevelReward;
    static int KillReward;
};

#endif // _WINZIG_WORLD_H_
