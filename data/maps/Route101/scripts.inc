Route101_MapScripts::
	.byte 0
@ hoenn_import: Emerald map scripts not ported: ON_TRANSITION (Route101_OnTransition), ON_FRAME_TABLE (Route101_OnFrame)
Route101_EventScript_Youngster::
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end

Route101_EventScript_Boy::
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end
@ hoenn_import: left out: trigger (10,19) VAR_ROUTE101_STATE==1 -> Route101_EventScript_StartBirchRescue; trigger (11,19) VAR_ROUTE101_STATE==1 -> Route101_EventScript_StartBirchRescue; trigger (10,18) VAR_ROUTE101_STATE==2 -> Route101_EventScript_PreventExitSouth; trigger (11,18) VAR_ROUTE101_STATE==2 -> Route101_EventScript_PreventExitSouth; trigger (6,16) VAR_ROUTE101_STATE==2 -> Route101_EventScript_PreventExitWest; trigger (6,15) VAR_ROUTE101_STATE==2 -> Route101_EventScript_PreventExitWest; trigger (6,17) VAR_ROUTE101_STATE==2 -> Route101_EventScript_PreventExitWest; trigger (6,18) VAR_ROUTE101_STATE==2 -> Route101_EventScript_PreventExitWest; trigger (7,13) VAR_ROUTE101_STATE==2 -> Route101_EventScript_PreventExitNorth
