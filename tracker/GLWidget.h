#pragma once
#include <QGLWidget>
#include <QOpenGLWidget>
#include "tracker/ForwardDeclarations.h"
#include "tracker/OpenGL/KinectDataRenderer/KinectDataRenderer.h"
#include "tracker/OpenGL/ConvolutionRenderer/ConvolutionRenderer.h"

//class GLWidget : public QOpenGLWidget {
class GLWidget : public QGLWidget {
public:
	Worker * worker;
	DataStream * const datastream;
	SolutionStream * const solutions;

	Camera * const camera;
	KinectDataRenderer kinect_renderer;
	ConvolutionRenderer convolution_renderer;

	bool playback;
	bool real_color;
	bool display_sensor_data = true;
	bool display_hand_model = true;
	bool display_model_outline = false;
	bool display_data_outline = false;
	bool display_data_correspondences = false;
	bool display_silhouette_correspondences = false;
	bool display_ground_truth_marker_positions = false; 
	bool display_ground_truth_reinit_constraints = false;
	bool display_model_marker_positions = false;
	bool display_fingertips = false;

	bool apply_estimated_shape = false;

	std::string data_path;
	std::string sequence_path;

public:

	GLWidget(Worker* worker, DataStream * datastream, SolutionStream * solutions, bool playback, bool real_color, std::string data_path, std::string sequence_path);

	~GLWidget();

	void initializeGL();

	void paintGL();

private:
	Eigen::Vector3f camera_center = Eigen::Vector3f(0, 0, 0);
	Eigen::Vector3f image_center = Eigen::Vector3f(0, 0, 375);
	Eigen::Vector3f camera_up = Eigen::Vector3f(0, 1, 0);
	Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

	bool mouse_button_pressed = true;
	Eigen::Vector2f cursor_position = Eigen::Vector2f(640, 480);
	Eigen::Vector2f euler_angles = Eigen::Vector2f(-6.411, -1.8);
	Eigen::Vector2f initial_euler_angles = Eigen::Vector2f(-6.411, -1.8);
	float cursor_sensitivity = 0.003f;
	float wheel_sensitivity = 0.03f;

	void process_mouse_movement(GLfloat cursor_x, GLfloat cursor_y);

	void process_mouse_button_pressed(GLfloat cursor_x, GLfloat cursor_y);

	void process_mouse_button_released();

	void process_mouse_wheel(int delta);
	
	void mouseMoveEvent(QMouseEvent *event);

	void mousePressEvent(QMouseEvent *event);

	void wheelEvent(QWheelEvent * event);

	void keyPressEvent(QKeyEvent *event);

	std::vector<std::pair<Vector3, Vector3>> GLWidget::prepare_data_correspondences_for_degub_renderer();

	std::vector<std::pair<Vector3, Vector3>> GLWidget::prepare_silhouette_correspondences_for_degub_renderer();
};
