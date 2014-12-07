/*
 * IStateMachine.h
 *
 *  Created on: Nov 12, 2014
 *      Author: Dean
 */

#ifndef ENTITIES_ISTATEMACHINE_H_
#define ENTITIES_ISTATEMACHINE_H_

namespace enDJIN {

class IState
{
public:
    // Do something
    virtual IState Run(Entity *thatEntity);

};

class IStateMachine
{
public:
    // Accessor to look at the current state.
    virtual IState CurrentState(Entity *thatEntity);

    // List of all possible transitions we can make from this current state.
    virtual std::vector<std::string> PossibleTransitions();

    // Advance to a named state, returning true on success.
    virtual bool Advance(Entity *thatEntity);

    // Is this state a "completion" state. Are we there yet?
    virtual bool IsComplete();
};

} /* namespace enDJIN */

#endif /* ENTITIES_ISTATEMACHINE_H_ */
