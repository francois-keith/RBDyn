// This file is part of RBDyn.
//
// RBDyn is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// RBDyn is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with RBDyn.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

// include
// SpaceVecAlg
#include <SpaceVecAlg/SpaceVecAlg>

namespace rbd
{
class MultiBodyConfig;
/**
	 * Compute the ZMP in the world frame
	 * as in Kajita's book on humanoid robots chap. 3 p.38
	 * @param mbc Use gravity
	 * @param com CoM position in world frame
	 * @oaram comA CoM acceleration in world frame
	 * @param altitude Double representing the surface's altitude in world frame
	 */
Eigen::Vector3d computeCentroidalZMP(MultiBodyConfig& mbc, Eigen::Vector3d& com,
		Eigen::Vector3d& comA, double altitude);

}
