cmake_minimum_required ( VERSION 3.1.0 )
project ( RTWeekend LANGUAGES CXX )
set (CMAKE_CXX_STANDARD 23)
add_executable(inOneWeekend 
	main.cpp
	HitRecord.cpp
	HittableList.cpp
	Sphere.cpp
	Vec3.cpp)