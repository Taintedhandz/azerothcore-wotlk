#include "Config.h"
#include "Group.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "DataMap.h"
#include "Chat.h"
#include "Hardcore.h"

class HardcoreAllMapScript : public AllMapScript
{
public:
    HardcoreAllMapScript() : AllMapScript("HardcoreAllMapScript") {}

    void OnPlayerEnterAll(Map* map, Player* player)
    {
        if (!sConfigMgr->GetOption<bool>("Hardcore.Enable", false))
            return;

        if (player->IsGameMaster())
            return;

        if (map->IsDungeon())
        {
            HardcoreMapInfo* mapInfo = map->CustomData.GetDefault<HardcoreMapInfo>("HardcoreMapInfo");

            if (!mapInfo->hardcore)
            {
                ChatHandler(player->GetSession()).SendSysMessage("Hardcore disabled.");
                return;
            }

            if (!player->HasAura(SPELL_AURA_HARDCORE))
            {
                disqualify(player, mapInfo);
                return;
            }

            uint32 mapId = map->GetId();

            if (mapId == RAGEFIRE_CHASM_MAP_ID && player->getLevel() > 18)
                disqualify(player, mapInfo);
            else if ((mapId == DEADMINES_MAP_ID || mapId == WAILING_CAVERNS_MAP_ID) && player->getLevel() > 20)
                disqualify(player, mapInfo);
            else if (mapId == SHADOWFANG_KEEP_MAP_ID && player->getLevel() > 21)
                disqualify(player, mapInfo);
            else if (mapId == BLACKFATHOM_DEEPS_MAP_ID && player->getLevel() > 24)
                disqualify(player, mapInfo);
            else if (mapId == STORMWIND_STOCKADES_MAP_ID && player->getLevel() > 25)
                disqualify(player, mapInfo);
            else if (mapId == RAZORFEN_KRAUL_MAP_ID && player->getLevel() > 27)
                disqualify(player, mapInfo);
            else if (mapId == GNOMEREGAN_MAP_ID && player->getLevel() > 28)
                disqualify(player, mapInfo);
            else if (mapId == RAZORFEN_DOWNS_MAP_ID && player->getLevel() > 37)
                disqualify(player, mapInfo);
            else if ((mapId == SCARLET_MONASTERY_MAP_ID || mapId == ULDAMAN_MAP_ID) && player->getLevel() > 40)
                disqualify(player, mapInfo);
            else if (mapId == MARAUDON_MAP_ID && player->getLevel() > 48)
                disqualify(player, mapInfo);
            else if (mapId == ZULFARRAK_MAP_ID && player->getLevel() > 46)
                disqualify(player, mapInfo);
            else if (mapId == SUNKEN_TEMPLE_MAP_ID && player->getLevel() > 50)
                disqualify(player, mapInfo);
            else if (mapId == BLACKROCK_DEPTHS_MAP_ID && player->getLevel() > 56)
                disqualify(player, mapInfo);
            else if (isSixtyDungeon(mapId) && player->getLevel() > 60)
                disqualify(player, mapInfo);

            if (!mapInfo->hardcore)
                return;

            ChatHandler(player->GetSession()).SendSysMessage("Hardcore enabled.");
        }
    }

private:
    bool isSixtyDungeon(uint32 mapId)
    {
        return mapId == DIRE_MAUL_MAP_ID
            || mapId == LOWER_BLACKROCK_SPIRE_MAP_ID
            || mapId == SCHOLOMANCE_MAP_ID
            || mapId == STRATHOLME_MAP_ID;
    }

    void disqualify(Player* player, HardcoreMapInfo* mapInfo)
    {
        if (!mapInfo->hardcore)
            return;

        mapInfo->hardcore = false;

        Group* group = player->GetGroup();

        if (group)
        {
            GroupReference const* member = group->GetFirstMember();

            while (member != NULL)
            {
                ChatHandler(member->GetSource()->GetSession()).SendSysMessage("Hardcore disabled.");
                member = member->next();
            }

            return;
        }

        ChatHandler(player->GetSession()).SendSysMessage("Hardcore disabled.");
    }
};

void AddHardcoreAllMapScripts()
{
    new HardcoreAllMapScript();
}