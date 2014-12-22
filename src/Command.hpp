#pragma once

////////////////////////////////////////////////////////////
/// \brief The Command class is the base class for all Input actions
////////////////////////////////////////////////////////////

class Command
{
public:
	Command();
	~Command(void);

	virtual void execute() = 0;
};

////////////////////////////////////////////////////////////
/// \class Command
/// \ingroup Input
///
/// The Command class is used for Actor interactions. 
/// It will be assigned to a button on a keyboard, Mouse, Control-Pad or even can be passed via script.
/// By passing Commands rather then raw input, the user can asign commands to whatever keys he wishes, this is invaluable for an RTS as players can asign buttons in relation to their playing style.
/// A list of Commands can be sequenced together, recorded, and even Undone if the need arises.
/// By using commands, controls can easily be handed over to AI, as the Input system does not care how the Commands are created, for example. A player sending a 'MoveCommand' and a Script sending the same command will not differ.
///
////////////////////////////////////////////////////////////