#include "DebugRenderer.h"

void DebugRenderer::add_points(const std::vector<Vector3> &points, Vector3 color){
	add( new PointRenderer(points, color, data_path) ); 
}

void DebugRenderer::add_points(const std::vector<Vector3> &points, const std::vector<Vector3> &colors) {
	add(new PointRenderer(points, colors, data_path));
}

void DebugRenderer::add_segments(const std::vector<pair<Vector3, Vector3> > &segments, const std::vector<Vector3> &colors) {
	add(new SegmentRenderer(segments, colors, data_path));
}

void DebugRenderer::add_segments(const std::vector<pair<Vector3, Vector3> > &segments, Vector3 color) {
	add(new SegmentRenderer(segments, color, data_path));
}

void DebugRenderer::add_arcs(const std::vector<pair<Vector3, Vector3> > &endpoints, std::vector<Vector3> centers, std::vector<float> radii, Vector3 color) {
	add(new ArcRenderer(endpoints, centers, radii, color, data_path));
}
