//
//  Created by Yordan on 3/20/15.
//
//

#ifndef __SGE_H__
#define __SGE_H__

// The definitions below are exported
#pragma GCC visibility push(default)

// Header tree:
//
// app/Application
// - events/EventManager
//   - events/Event
//     - utils/HasID
// - logic/BaseLogic
//   - actors/ActorManage
//     - actors/Actor
//       - actors/ActorComponent
//       - utils/HasID
//   - utils/FiniteStateMachine
// - views/BaseView
//   - events/Event
//     - utils/HasID
//
// events/CommonEvents
// - actors/Actor
// - events/Event
//
// actors/TransformComponent
// - actors/ActorComponent
//
// utils/Utils

#include "app/Application.h"
#include "events/CommonEvents.h"
#include "actors/TransformComponent.h"
#include "utils/Utils.h"

#pragma GCC visibility pop
#endif // __SGE_H__
