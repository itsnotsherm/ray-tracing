#include "Color.h"
#include "Ray.h"
#include "Vec3.h"

#include <iostream>

double hit_sphere(const Point3& center, double radius, const Ray& r) {
    Vec3 oc = center - r.origin(); // origin (of ray) to center
    Vec3 d = r.direction();
    
    // coefficients of quadratic formula
    auto a = dot(d, d);
    auto b = -2 * dot(d, oc);
    auto c = dot(oc, oc) - radius * radius;
    auto discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return -1.0;
    }
    else {
        return (-b - std::sqrt(discriminant)) / (2.0 * a); // assume smallest t
    }
}

// Currently implements a simple color gradient background
Color ray_color(const Ray& r) {
    // Hardcoded a sphere on z = -1 with radius 0.5
    const Point3 c = Point3(0, 0, -1);
    const double radius = 0.5;

    auto t = hit_sphere(c, radius, r);
    if (t > 0) {
        Vec3 N = unit_vector(r.at(t) - c); // surface normal vector at the point where ray hits sphere
        return 0.5 * Color(N.x() + 1, N.y() + 1, N.z() + 1);  // map each component from [-1, 1] to [0, 1]
    }


    Vec3 unit_direction = unit_vector(r.direction()); // normalizes ray direction for interpolation
    auto a = 0.5 * (unit_direction.y() + 1.0); // map Y of normalized vector from [-1, 1] to [0, 1]

    // blendedValue = (1 - a) * startValue + a * (endValue)
    // color(1, 1, 1) is white, color(0.5, 0.7, 1.0) is sky-blue
    return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
}

int main() {

    // Image
    auto aspect_ratio = 16.0 / 9.0; // width : height
    int image_width = 400;
    
    // Ensure image height is at least 1 after calculation
    int image_height = static_cast<double>(image_width) / aspect_ratio;
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera
    auto camera_center = Point3(0, 0, 0);
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);

    // Viewport span and distance between each pixel in direction of u and v
    auto viewport_u = Vec3(viewport_width, 0, 0);
    auto viewport_v = Vec3(0, -viewport_height, 0);
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // Q (upper left corner of viewport) = camera center - z-offset of camera - 0.5(viewport spans)
    auto viewport_upper_left = camera_center - Vec3(0, 0, focal_length) - 0.5 * (viewport_u + viewport_v);

    // Pixel(0,0) location is Q + 0.5(pixel-to-pixel distance), where pixel grid is inset from edges
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);


    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            Ray r{ camera_center, ray_direction };

            auto pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }
    std::clog << "\rDone.                 \n";
}