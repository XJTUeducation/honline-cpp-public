#pragma once
#include "tracker/Types.h"
#include <vector>
#include <QString>
#include <fstream>
#include <stdio.h>
#include "tracker/Data/DataStream.h"

///--- This is only valid when we record a stream
class SolutionStream{
public:
	std::vector<Eigen::Matrix<Scalar, Eigen::Dynamic, 1>> frames;
	std::vector<Eigen::Matrix<Scalar, num_joints * 3, 1>> joint_locations;
    bool _valid = false;
    
public:
    bool isValid(int fid = 0){
        return _valid; // || ( (fid <= _valid_id) && (fid >= 0) );
    }
  
    void reserve(int size){
        //frames.reserve(size);
    }

    void resize(int num_frames){
        frames.resize(num_frames);
    }    

	void set(int frame_id, size_t num_parameters, const std::vector<Scalar>& theta) {
		Eigen::Map<const Eigen::Matrix<Scalar, num_thetas, 1>> theta_map(theta.data());
		frames[frame_id] = Eigen::Matrix<Scalar, Eigen::Dynamic, 1>::Zero(num_parameters, 1);
		frames[frame_id].segment(0, num_thetas) = theta_map;
	}

	void set(int frame_id, size_t num_parameters, const std::vector<Scalar>& theta, const std::vector<Scalar>& beta) {
		Eigen::Map<const Eigen::Matrix<Scalar, num_thetas, 1>> theta_map(theta.data());
		frames[frame_id] = Eigen::Matrix<Scalar, Eigen::Dynamic, 1>::Zero(num_parameters, 1);
		frames[frame_id].segment(0, num_thetas) = theta_map;
		for (size_t i = 0; i < beta.size(); i++) {
			frames[frame_id][num_thetas + i] = beta[i];
		}
		
    }

};
