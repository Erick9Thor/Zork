#include "../include/Exit.h"

Direction Exit::GetDirection() const
{
    return direction;
}

Room* Exit::GetSource() const
{
    return source;
}

Room* Exit::GetDestination() const
{
    return destination;
}

bool Exit::IsLocked() const
{
    return locked;
}

void Exit::SetLocked(bool locked)
{
    this->locked = locked;
}
