#include "Utilities/Singleton.inl"
#include "Core/EngineTypes.h"
#include "ode/ode.h"

#ifndef CXC_PHYSICALWORLD_H
#define CXC_PHYSICALWORLD_H

namespace cxc
{

	class World;

	class CXC_ENGINECORE_API PhysicalWorld final : public Singleton<PhysicalWorld>
	{
		friend class Singleton<PhysicalWorld>;
		friend class World;

	public:
		PhysicalWorld();
		~PhysicalWorld();

	public:

		glm::vec3 GetGravity() const { return Gravity; }
		dWorldID GetWorldID() { return PhysicalWorldID; }
		dSpaceID GetTopSpaceID() { return TopLevelSpace; }
		dJointGroupID GetJointGroupID() { return ContactJoints; }
		void SetGravity(const glm::vec3& NewGravity) { Gravity = NewGravity; }

		void SuspendPhysics() noexcept { bPhysicsPaused = true; };
		void ResumePhysics() noexcept { bPhysicsPaused = false; };

	public:

		void InitializePhysicalWorld();
		void DestroyPhysicalWorld();

	public:

		void PhysicsTick(float Seconds);

		static void nearCallback(void *data, dGeomID o1, dGeomID o2) noexcept;

	private:

		void ActiveGravity();

		// World ID
		dWorldID PhysicalWorldID;

		// Top level space
		dSpaceID TopLevelSpace;

		// Joint group
		dJointGroupID ContactJoints;

		// Whether the ODE is initialized
		bool bODEInitialized;

		// Whether the physics engine is paused
		bool bPhysicsPaused;

		// Gravity vector
		glm::vec3 Gravity;

	};
}

#endif // CXC_PHYSICALWORLD_H