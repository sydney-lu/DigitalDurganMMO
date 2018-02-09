// Copyright Digital Durgan studios. All rights reserved.

#include "Targetable.h"


bool ITargetable::OnTargeted_Implementation()
{
	m_isTargeted = true;
	return true;
}

bool ITargetable::OnUntargeted_Implementation()
{
	m_isTargeted = false; 
	return true;
}

bool ITargetable::IsTargeted_Implementation()
{
	return m_isTargeted;
}
