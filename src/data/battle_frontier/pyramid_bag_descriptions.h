// RFVF+: French Emerald's descriptions of the Pyramid's items, written for the Pyramid bag's narrow window
// (work/hoenn_scripts/pyramid_bag_desc.py)
static const u8 sPyramidBag_sBrightPowderDesc[] = _("Objet tenu qui\néblouit et baisse\nla précision.");
static const u8 sPyramidBag_sCalciumDesc[] = _("Monte l'ATQ. SPE.\nd'un POKéMON.");
static const u8 sPyramidBag_sCarbosDesc[] = _("Monte la VITESSE\nd'un POKéMON.");
static const u8 sPyramidBag_sCheriBerryDesc[] = _("Objet tenu qui\nsoigne la paralysie\npendant un combat.");
static const u8 sPyramidBag_sChestoBerryDesc[] = _("Objet tenu qui\nréveille les {PKMN}\ndormant au combat.");
static const u8 sPyramidBag_sChoiceBandDesc[] = _("Monte la puissance\nd'une attaque. Dés-\nactive les autres.");
static const u8 sPyramidBag_sDireHitDesc[] = _("Monte le taux de\ncritiques pendant\nun combat.");
static const u8 sPyramidBag_sEtherDesc[] = _("Restaure 10 PP\nd'une attaque\nsélectionnée.");
static const u8 sPyramidBag_sFluffyTailDesc[] = _("Pour s'enfuir d'un\ncombat contre un\nPOKéMON sauvage.");
static const u8 sPyramidBag_sFocusBandDesc[] = _("Objet tenu pouvant\nparfois empêcher\nd'être mis K.O.");
static const u8 sPyramidBag_sFullRestoreDesc[] = _("Restaure tous les\nPV et le statut\nd'un POKéMON.");
static const u8 sPyramidBag_sGuardSpecDesc[] = _("Empêche la perte\nde points de stats\npendant un combat.");
static const u8 sPyramidBag_sHPUpDesc[] = _("Monte les PV d'un\nPOKéMON.");
static const u8 sPyramidBag_sHyperPotionDesc[] = _("Restaure les PV\nd'un POKéMON\nde 200 points.");
static const u8 sPyramidBag_sIronDesc[] = _("Monte la DEFENSE\nd'un POKéMON.");
static const u8 sPyramidBag_sKingsRockDesc[] = _("Objet tenu pouvant\napeurer l'ennemi\ns'il est touché.");
static const u8 sPyramidBag_sLeftoversDesc[] = _("Objet tenu permet-\ntant de restaurer\nles PV au combat.");
static const u8 sPyramidBag_sLeppaBerryDesc[] = _("Objet tenu qui\nrestaure 10 PP\npendant un combat.");
static const u8 sPyramidBag_sLumBerryDesc[] = _("Objet tenu qui\nrestaure le statut\npendant un combat.");
static const u8 sPyramidBag_sMaxElixirDesc[] = _("Restaure tous les\nPP de toutes les\nattaques.");
static const u8 sPyramidBag_sMaxReviveDesc[] = _("Réanime un POKéMON\nK.O. et restaure\ntous ses PV.");
static const u8 sPyramidBag_sMentalHerbDesc[] = _("Objet tenu qui\nannule l'attirance\nd'un POKéMON.");
static const u8 sPyramidBag_sPechaBerryDesc[] = _("Objet tenu qui soi-\ngne du poison\npendant un combat.");
static const u8 sPyramidBag_sProteinDesc[] = _("Monte l'ATTAQUE\nd'un POKéMON.");
static const u8 sPyramidBag_sQuickClawDesc[] = _("Objet tenu qui\npermet parfois de\nfrapper le premier.");
static const u8 sPyramidBag_sRawstBerryDesc[] = _("Objet tenu qui\nsoigne une brûlure\npendant un combat.");
static const u8 sPyramidBag_sReviveDesc[] = _("Réanime un POKéMON\nK.O. et restaure la\nmoitié de ses PV.");
static const u8 sPyramidBag_sSacredAshDesc[] = _("Réanime tous les\nPOKéMON K.O. et\nrestaure leurs PV.");
static const u8 sPyramidBag_sScopeLensDesc[] = _("Objet tenu pour\nmonter le taux de\ncritiques.");
static const u8 sPyramidBag_sShellBellDesc[] = _("Objet tenu qui res-\ntaure les PV en\nfrappant l'ennemi.");
static const u8 sPyramidBag_sWhiteHerbDesc[] = _("Objet tenu qui\nrestaure les stats\nbaissées.");
static const u8 sPyramidBag_sXAccuracyDesc[] = _("Monte la précision\ndes attaques\npendant un combat.");
static const u8 sPyramidBag_sXAttackDesc[] = _("Monte l'ATTAQUE\npendant un combat.");
static const u8 sPyramidBag_sXDefendDesc[] = _("Monte la DEFENSE\npendant un combat.");
static const u8 sPyramidBag_sXSpecialDesc[] = _("Monte l'ATQ. SPE.\npendant un combat.");
static const u8 sPyramidBag_sXSpeedDesc[] = _("Monte la VITESSE\npendant un combat.");
static const u8 sPyramidBag_sZincDesc[] = _("Monte la DEF. SPE.\nd'un POKéMON.");

static const struct {
    u16 itemId;
    const u8 *description;
} sPyramidBagDescriptions[] =
{
    {ITEM_BRIGHT_POWDER, sPyramidBag_sBrightPowderDesc},
    {ITEM_CALCIUM, sPyramidBag_sCalciumDesc},
    {ITEM_CARBOS, sPyramidBag_sCarbosDesc},
    {ITEM_CHERI_BERRY, sPyramidBag_sCheriBerryDesc},
    {ITEM_CHESTO_BERRY, sPyramidBag_sChestoBerryDesc},
    {ITEM_CHOICE_BAND, sPyramidBag_sChoiceBandDesc},
    {ITEM_DIRE_HIT, sPyramidBag_sDireHitDesc},
    {ITEM_ETHER, sPyramidBag_sEtherDesc},
    {ITEM_FLUFFY_TAIL, sPyramidBag_sFluffyTailDesc},
    {ITEM_FOCUS_BAND, sPyramidBag_sFocusBandDesc},
    {ITEM_FULL_RESTORE, sPyramidBag_sFullRestoreDesc},
    {ITEM_GUARD_SPEC, sPyramidBag_sGuardSpecDesc},
    {ITEM_HP_UP, sPyramidBag_sHPUpDesc},
    {ITEM_HYPER_POTION, sPyramidBag_sHyperPotionDesc},
    {ITEM_IRON, sPyramidBag_sIronDesc},
    {ITEM_KINGS_ROCK, sPyramidBag_sKingsRockDesc},
    {ITEM_LEFTOVERS, sPyramidBag_sLeftoversDesc},
    {ITEM_LEPPA_BERRY, sPyramidBag_sLeppaBerryDesc},
    {ITEM_LUM_BERRY, sPyramidBag_sLumBerryDesc},
    {ITEM_MAX_ELIXIR, sPyramidBag_sMaxElixirDesc},
    {ITEM_MAX_REVIVE, sPyramidBag_sMaxReviveDesc},
    {ITEM_MENTAL_HERB, sPyramidBag_sMentalHerbDesc},
    {ITEM_PECHA_BERRY, sPyramidBag_sPechaBerryDesc},
    {ITEM_PROTEIN, sPyramidBag_sProteinDesc},
    {ITEM_QUICK_CLAW, sPyramidBag_sQuickClawDesc},
    {ITEM_RAWST_BERRY, sPyramidBag_sRawstBerryDesc},
    {ITEM_REVIVE, sPyramidBag_sReviveDesc},
    {ITEM_SACRED_ASH, sPyramidBag_sSacredAshDesc},
    {ITEM_SCOPE_LENS, sPyramidBag_sScopeLensDesc},
    {ITEM_SHELL_BELL, sPyramidBag_sShellBellDesc},
    {ITEM_WHITE_HERB, sPyramidBag_sWhiteHerbDesc},
    {ITEM_X_ACCURACY, sPyramidBag_sXAccuracyDesc},
    {ITEM_X_ATTACK, sPyramidBag_sXAttackDesc},
    {ITEM_X_DEFEND, sPyramidBag_sXDefendDesc},
    {ITEM_X_SPECIAL, sPyramidBag_sXSpecialDesc},
    {ITEM_X_SPEED, sPyramidBag_sXSpeedDesc},
    {ITEM_ZINC, sPyramidBag_sZincDesc},
};
