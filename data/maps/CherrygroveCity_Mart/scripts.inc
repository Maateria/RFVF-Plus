@ johto_import: generated from PokemonHnS data/maps/CherrygroveCity_Mart_hns; scripted maps get their own file later
CherrygroveCity_Mart_MapScripts::
	.byte 0

@ silent until scripted (PokemonHnS data/maps/CherrygroveCity_Mart_hns/scripts.inc)
CherrygroveCity_Mart_EventScript_Clerk::        @ MART_EMPLOYEE_HNS #1 (2,3)
CherrygroveCity_Mart_EventScript_Youngster::    @ YOUNGSTER_HNS #2 (3,5)
CherrygroveCity_Mart_EventScript_Bugcatcher::   @ BUG_CATCHER_HNS #3 (8,5)
	end
