SkyPillar_Top_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_RESUME (SkyPillar_Top_OnResume), ON_TRANSITION (SkyPillar_Top_OnTransition), ON_WARP_INTO_MAP_TABLE (SkyPillar_Top_OnWarp)
@ hoenn_import: silent until scripted; Emerald source: pokeemerald/data/maps/SkyPillar_Top/scripts.inc
SkyPillar_Top_EventScript_Rayquaza::            @ NPC #1 (14,6)
	end
@ hoenn_import: left out: trigger (14,9) VAR_SKY_PILLAR_RAYQUAZA_CRY_DONE==0 -> SkyPillar_Top_EventScript_AwakenRayquaza
