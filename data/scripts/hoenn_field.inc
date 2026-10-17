@ Emerald's scripts of Hoenn metatiles read on A (src/field_control_avatar.c GetInteractedMetatileScript), official
@ French texts

EventScript_Vase::
	msgbox Text_Vase, MSGBOX_SIGN
	end

@ Sootopolis's houses (closed while the weather crisis lasts) and the Sky Pillar (before Wallace opens it)
EventScript_ClosedDoor::
	msgbox Text_DoorIsClosed, MSGBOX_SIGN
	end

Text_Vase:
	.string "Ce vase semble avoir de la valeur!\p"
	.string "En regardant à l'intérieur, on\n"
	.string "s'aperçoit qu'il est vide.$"

Text_DoorIsClosed:
	.string "La porte est fermée.$"
