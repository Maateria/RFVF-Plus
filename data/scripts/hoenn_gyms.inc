@ Emerald's common gym and Pokémon League scripts, for Hoenn's (data/event_scripts.s and data/scripts/set_gym_trainers.inc there)

Common_EventScript_PlayGymBadgeFanfare::
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	return

Common_EventScript_ShowBagIsFull::
	msgbox Text_TooBadBagFull, MSGBOX_DEFAULT
	release
	end

Common_EventScript_BagIsFull::
	msgbox Text_TooBadBagFull, MSGBOX_DEFAULT
	return

Common_EventScript_SetGymTrainers::
	switch VAR_0x8008
	case 1, RustboroCity_Gym_SetGymTrainers
	case 2, DewfordTown_Gym_SetGymTrainers
	case 3, MauvilleCity_Gym_SetGymTrainers
	case 4, LavaridgeTown_Gym_SetGymTrainers
	case 5, PetalburgCity_Gym_SetGymTrainers
	case 6, FortreeCity_Gym_SetGymTrainers
	case 7, MossdeepCity_Gym_SetGymTrainers
	case 8, SootopolisCity_Gym_SetGymTrainers
	end

RustboroCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_JOSH
	settrainerflag TRAINER_TOMMY
	settrainerflag TRAINER_MARC
	return

DewfordTown_Gym_SetGymTrainers::
	settrainerflag TRAINER_TAKAO
	settrainerflag TRAINER_JOCELYN
	settrainerflag TRAINER_LAURA
	settrainerflag TRAINER_BRENDEN
	settrainerflag TRAINER_CRISTIAN
	settrainerflag TRAINER_LILITH
	return

MauvilleCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_KIRK
	settrainerflag TRAINER_SHAWN
	settrainerflag TRAINER_BEN
	settrainerflag TRAINER_VIVIAN
	settrainerflag TRAINER_ANGELO
	return

LavaridgeTown_Gym_SetGymTrainers::
	settrainerflag TRAINER_COLE
	settrainerflag TRAINER_AXLE
	settrainerflag TRAINER_KEEGAN
	settrainerflag TRAINER_GERALD
	settrainerflag TRAINER_DANIELLE
	settrainerflag TRAINER_JACE
	settrainerflag TRAINER_JEFF
	settrainerflag TRAINER_ELI
	return

PetalburgCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_RANDALL
	settrainerflag TRAINER_PARKER
	settrainerflag TRAINER_GEORGE
	settrainerflag TRAINER_BERKE
	settrainerflag TRAINER_MARY
	settrainerflag TRAINER_ALEXIA
	settrainerflag TRAINER_JODY
	return

FortreeCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_JARED
	settrainerflag TRAINER_FLINT
	settrainerflag TRAINER_ASHLEY
	settrainerflag TRAINER_EDWARDO
	settrainerflag TRAINER_HUMBERTO
	settrainerflag TRAINER_DARIUS
	return

MossdeepCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_PRESTON
	settrainerflag TRAINER_VIRGIL
	settrainerflag TRAINER_BLAKE
	settrainerflag TRAINER_HANNAH
	settrainerflag TRAINER_SAMANTHA
	settrainerflag TRAINER_MAURA
	settrainerflag TRAINER_SYLVIA
	settrainerflag TRAINER_NATE
	settrainerflag TRAINER_KATHLEEN
	settrainerflag TRAINER_CLIFFORD
	settrainerflag TRAINER_MACEY
	settrainerflag TRAINER_NICHOLAS
	return

SootopolisCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_ANDREA
	settrainerflag TRAINER_CRISSY
	settrainerflag TRAINER_BRIANNA
	settrainerflag TRAINER_CONNIE
	settrainerflag TRAINER_BRIDGET
	settrainerflag TRAINER_OLIVIA
	settrainerflag TRAINER_TIFFANY
	settrainerflag TRAINER_BETHANY
	settrainerflag TRAINER_ANNIKA
	settrainerflag TRAINER_DAPHNE
	return

@ Emerald's Elite Four rooms (data/scripts/elite_four.inc there)
PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	playse SE_DOOR
	setmetatile 6, 1, METATILE_HoennEliteFour_OpenDoor_Frame, FALSE
	setmetatile 6, 2, METATILE_HoennEliteFour_OpenDoor_Opening, FALSE
	setmetatile 0, 2, METATILE_HoennEliteFour_RightSpotlightOff, TRUE
	setmetatile 1, 2, METATILE_HoennEliteFour_LeftSpotlightOff, TRUE
	setmetatile 2, 2, METATILE_HoennEliteFour_RightSpotlightOff, TRUE
	setmetatile 3, 2, METATILE_HoennEliteFour_LeftSpotlightOff, TRUE
	setmetatile 4, 2, METATILE_HoennEliteFour_RightSpotlightOff, TRUE
	setmetatile 8, 2, METATILE_HoennEliteFour_LeftSpotlightOff, TRUE
	setmetatile 9, 2, METATILE_HoennEliteFour_RightSpotlightOff, TRUE
	setmetatile 10, 2, METATILE_HoennEliteFour_LeftSpotlightOff, TRUE
	setmetatile 11, 2, METATILE_HoennEliteFour_RightSpotlightOff, TRUE
	setmetatile 12, 2, METATILE_HoennEliteFour_LeftSpotlightOff, TRUE
	special DrawWholeMapView
	return

PokemonLeague_EliteFour_EventScript_WalkInCloseDoor::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp6
	waitmovement 0
	playse SE_TRUCK_DOOR
	setmetatile 5, 12, METATILE_HoennEliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 6, 12, METATILE_HoennEliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 7, 12, METATILE_HoennEliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 5, 13, METATILE_HoennEliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 6, 13, METATILE_HoennEliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 7, 13, METATILE_HoennEliteFour_EntryDoor_ClosedBottom, TRUE
	special DrawWholeMapView
	return

@ Essentially unused, only necessary when re-entering an Elite Four room after defeating the member, which isnt normally possible
PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom::
	setmetatile 6, 1, METATILE_HoennEliteFour_OpenDoor_Frame, FALSE
	setmetatile 6, 2, METATILE_HoennEliteFour_OpenDoor_Opening, FALSE
	setmetatile 5, 12, METATILE_HoennEliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 6, 12, METATILE_HoennEliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 7, 12, METATILE_HoennEliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 5, 13, METATILE_HoennEliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 6, 13, METATILE_HoennEliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 7, 13, METATILE_HoennEliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 0, 2, METATILE_HoennEliteFour_RightSpotlightOff, TRUE
	setmetatile 1, 2, METATILE_HoennEliteFour_LeftSpotlightOff, TRUE
	setmetatile 2, 2, METATILE_HoennEliteFour_RightSpotlightOff, TRUE
	setmetatile 3, 2, METATILE_HoennEliteFour_LeftSpotlightOff, TRUE
	setmetatile 4, 2, METATILE_HoennEliteFour_RightSpotlightOff, TRUE
	setmetatile 8, 2, METATILE_HoennEliteFour_LeftSpotlightOff, TRUE
	setmetatile 9, 2, METATILE_HoennEliteFour_RightSpotlightOff, TRUE
	setmetatile 10, 2, METATILE_HoennEliteFour_LeftSpotlightOff, TRUE
	setmetatile 11, 2, METATILE_HoennEliteFour_RightSpotlightOff, TRUE
	setmetatile 12, 2, METATILE_HoennEliteFour_LeftSpotlightOff, TRUE
	return

PokemonLeague_EliteFour_EventScript_CloseDoor::
	setmetatile 5, 12, METATILE_HoennEliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 6, 12, METATILE_HoennEliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 7, 12, METATILE_HoennEliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 5, 13, METATILE_HoennEliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 6, 13, METATILE_HoennEliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 7, 13, METATILE_HoennEliteFour_EntryDoor_ClosedBottom, TRUE
	return

Common_Movement_WalkUp6::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_HallOfFame_EventScript_ResetEliteFour::
	clearflag FLAG_DEFEATED_ELITE_4_SIDNEY
	clearflag FLAG_DEFEATED_ELITE_4_PHOEBE
	clearflag FLAG_DEFEATED_ELITE_4_GLACIA
	clearflag FLAG_DEFEATED_ELITE_4_DRAKE
	setvar VAR_ELITE_4_STATE, 0
	return

Common_EventScript_NopReturn::
	return

Common_EventScript_RemoveStaticPokemon::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end
