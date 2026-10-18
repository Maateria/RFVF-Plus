@ johto_import: generated from PokemonHnS data/maps/SafariZoneGate_SafariZoneEntrance_hns; scripted maps get their own file later
.equ LOCALID_SAFARIZONEGATE_BAOBA, 1

SafariZoneGate_SafariZoneEntrance_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/SafariZoneGate_SafariZoneEntrance_hns/scripts.inc)
SafariZoneGate_SafariZoneEntrance_EventScript_Baoba:: @ GENTLEMAN_HNS #1 (5,10)
SafariZoneGate_SafariZoneEntrance_EventScript_WelcomeAttendant:: @ MYSTERY_EVENT_DELIVERYMAN_HNS #2 (15,3)
SafariZoneGate_SafariZoneEntrance_EventScript_InfoAttendant:: @ MYSTERY_EVENT_DELIVERYMAN_HNS #3 (12,2)
SafariZoneGate_SafariZoneEntrance_EventScript_Boy:: @ LITTLE_BOY_HNS #4 (2,5)
SafariZoneGate_SafariZoneEntrance_EventScript_Blender3Girl:: @ GIRL_1_HNS #5 (14,7)
SafariZoneGate_SafariZoneEntrance_EventScript_Blender3Boy:: @ BOY_2_HNS #6 (13,6)
SafariZoneGate_SafariZoneEntrance_EventScript_Blender3PokefanF:: @ WOMAN_2_HNS #7 (12,7)
SafariZoneGate_SafariZoneEntrance_EventScript_Blender2Man:: @ COOLTRAINER_M_HNS #8 (16,11)
SafariZoneGate_SafariZoneEntrance_EventScript_Blender2Twin:: @ TWIN_HNS #9 (18,11)
SafariZoneGate_SafariZoneEntrance_EventScript_BlendMaster:: @ OLD_MAN_2_HNS #10 (16,7)
SafariZoneGate_SafariZoneEntrance_EventScript_BerryBlender3:: @ sign (13,7)
SafariZoneGate_SafariZoneEntrance_EventScript_BerryBlender2:: @ sign (17,11)
SafariZoneGate_SafariZoneEntrance_EventScript_BerryBlender1:: @ sign (17,7)
SafariZoneGate_SafariZoneEntrance_EventScript_Chart1:: @ sign (6,1)
SafariZoneGate_SafariZoneEntrance_EventScript_Chart2:: @ sign (7,1)
	end
