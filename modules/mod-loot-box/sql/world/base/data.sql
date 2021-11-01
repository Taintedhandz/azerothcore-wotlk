-- Put only sql data in this file (insert, update, replace into, delete etc...).

DELETE FROM `item_template` WHERE `entry` = 5621798;
INSERT INTO `item_template` (`entry`, `name`, `displayid`, `Quality`, `stackable`, `spellid_1`, `spellcooldown_1`, `description`, `ScriptName`)
VALUES (5621798, 'Loot Box', 12331, 6, 250, 7931299, 1000, "I can't believe it's not gambling!", 'LootBoxItem');

UPDATE `item_template`
SET `name` = 'Macaroon', `displayid` = 51567, `maxcount` = 2147483647, `stackable` = 2147483647, `description` = 'Time is money, friend.'
WHERE entry = 37711;

UPDATE `item_template`
SET `bonding` = 0, `maxcount` = 0
WHERE `entry` IN (
    38577, 46779 ,19160 ,33223 ,32588, 45037, 49283, 38312, 44819, 38577, 38233,
    45047, 39286, 13583, 38312, 23709, 19054
);

DELETE FROM `creature_model_info` WHERE `DisplayID` = 7359065;
INSERT INTO `creature_model_info` (`DisplayID`, `CombatReach`, `Gender`)
VALUES (7359065, 1.5, 1);

DELETE FROM `creature_template` WHERE `entry` = 5126979;
INSERT INTO `creature_template` (
    `entry`, `modelid1`, `name`, `subname`, `gossip_menu_id`, `minlevel`,
    `maxlevel`, `faction`, `npcflag`, `DamageModifier`, `BaseAttackTime`,
    `RangeAttackTime`, `unit_class`, `unit_flags`, `unit_flags2`, `type`,
    `flags_extra`, `VerifiedBuild`
) VALUES (
    5126979, 11689, 'Winzig', 'Wobbling Goblin', 0, 60, 60, 35, 128, 1,
    2000, 2000, 4, 768, 2048, 7, 2, 12340
);
-- Replace Landro Longshot.
DELETE FROM `creature` WHERE `guid` = 565;
INSERT INTO `creature` (
    `guid`, `id`, `modelid`, `equipment_id`, `position_x`, `position_y`,
    `position_z`, `orientation`, `spawntimesecs`, `wander_distance`,
    `curhealth`
) VALUES (
    565, 5126979, 11689, 0, -14397.5, 426.08, 7.97355, 5.51524, 300, 0, 4979
);
-- Rename `subname` of the two guards.
UPDATE `creature_template` SET `subname` = 'Wobbling Goblin' WHERE `entry` = 21045;

-- Populate Winzig's stock.
DELETE FROM `npc_vendor` WHERE `entry` = 5126979;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `ExtendedCost`)
VALUES
    (5126979, 0, 5621798, 3870077), -- Loot Box
    (5126979, 1, 1710, 3870075), -- Greater Healing Potion
    (5126979, 2, 3827, 3870075), -- Mana Potion
    (5126979, 3, 5634, 3870075), -- Free Action Potion
    (5126979, 4, 3826, 3870075), -- Major Troll's Blood Elixir
    (5126979, 5, 3386, 3870075), -- Potion of Curing
    (5126979, 6, 6048, 3870075), -- Shadow Protection Potion
    (5126979, 7, 45621, 3870075), -- Elixir of Minor Accuracy
    (5126979, 8, 4498, 3870077), -- Brown Leather Satchel
    (5126979, 9, 4497, 3870078); -- Heavy Brown Bag
