GraniteCave_1F_MapScripts::
	.byte 0
GraniteCave_1F_EventScript_ItemEscapeRope::     @ item ball, works (FLAG_ITEM_GRANITE_CAVE_1F_ESCAPE_ROPE)
	finditem ITEM_ESCAPE_ROPE
	end
GraniteCave_1F_EventScript_Hiker::
	msgbox GraniteCave_1F_Text_AlreadyKnowFlash, MSGBOX_NPC
	end

