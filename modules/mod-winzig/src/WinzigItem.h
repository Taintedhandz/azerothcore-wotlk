#ifndef _WINZIG_ITEM_H_
#define _WINZIG_ITEM_H_

#include <random>
#include <vector>
#include "ScriptMgr.h"

#define STACKABLE_COUNT 5

enum Rarity {
    RARITY_NONE,
    RARITY_ONE_STAR,    // Poor
    RARITY_TWO_STAR,    // Common
    RARITY_THREE_STAR,  // Uncommon
    RARITY_FOUR_STAR,   // Rare
    RARITY_FIVE_STAR,   // Epic
    RARITY_SIX_STAR,    // Legendary
    RARITY_SEVEN_STAR,  // Artifact
    RARITY_EIGHT_STAR   // Heirloom
};

enum Banner {
    BANNER_NONE,
    BANNER_FEATURED,
    BANNER_PROMOTIONAL
};

class WinzigItem : public ItemScript
{
public:
    WinzigItem() : ItemScript("WinzigItem"), gen(rd()), dis(0.0, 1.0) {}

    bool OnUse(Player *player, Item *item, SpellCastTargets const &/*targets*/) override;

private:
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;

    float roll();
    int randomId(std::vector<int> ids);
    void openLootBox(Player *player, Item *item, enum Rarity rarity);
    bool sendRewardToPlayer(Player *player, uint32 itemId, enum Rarity rarity, enum Banner banner);
};

#endif // _WINZIG_ITEM_H_