# CMake generated Testfile for 
# Source directory: /home/879enwt/REPO_git/mon_imGui/opencv-4.x/modules/imgproc
# Build directory: /home/879enwt/REPO_git/mon_imGui/build/modules/imgproc
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_imgproc "/home/879enwt/REPO_git/mon_imGui/build/bin/opencv_test_imgproc" "--gtest_output=xml:opencv_test_imgproc.xml")
set_tests_properties(opencv_test_imgproc PROPERTIES  LABELS "Main;opencv_imgproc;Accuracy" WORKING_DIRECTORY "/home/879enwt/REPO_git/mon_imGui/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/home/879enwt/REPO_git/mon_imGui/opencv-4.x/cmake/OpenCVUtils.cmake;1799;add_test;/home/879enwt/REPO_git/mon_imGui/opencv-4.x/cmake/OpenCVModule.cmake;1365;ocv_add_test_from_target;/home/879enwt/REPO_git/mon_imGui/opencv-4.x/cmake/OpenCVModule.cmake;1123;ocv_add_accuracy_tests;/home/879enwt/REPO_git/mon_imGui/opencv-4.x/modules/imgproc/CMakeLists.txt;13;ocv_define_module;/home/879enwt/REPO_git/mon_imGui/opencv-4.x/modules/imgproc/CMakeLists.txt;0;")
add_test(opencv_perf_imgproc "/home/879enwt/REPO_git/mon_imGui/build/bin/opencv_perf_imgproc" "--gtest_output=xml:opencv_perf_imgproc.xml")
set_tests_properties(opencv_perf_imgproc PROPERTIES  LABELS "Main;opencv_imgproc;Performance" WORKING_DIRECTORY "/home/879enwt/REPO_git/mon_imGui/build/test-reports/performance" _BACKTRACE_TRIPLES "/home/879enwt/REPO_git/mon_imGui/opencv-4.x/cmake/OpenCVUtils.cmake;1799;add_test;/home/879enwt/REPO_git/mon_imGui/opencv-4.x/cmake/OpenCVModule.cmake;1264;ocv_add_test_from_target;/home/879enwt/REPO_git/mon_imGui/opencv-4.x/cmake/OpenCVModule.cmake;1124;ocv_add_perf_tests;/home/879enwt/REPO_git/mon_imGui/opencv-4.x/modules/imgproc/CMakeLists.txt;13;ocv_define_module;/home/879enwt/REPO_git/mon_imGui/opencv-4.x/modules/imgproc/CMakeLists.txt;0;")
add_test(opencv_sanity_imgproc "/home/879enwt/REPO_git/mon_imGui/build/bin/opencv_perf_imgproc" "--gtest_output=xml:opencv_perf_imgproc.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
set_tests_properties(opencv_sanity_imgproc PROPERTIES  LABELS "Main;opencv_imgproc;Sanity" WORKING_DIRECTORY "/home/879enwt/REPO_git/mon_imGui/build/test-reports/sanity" _BACKTRACE_TRIPLES "/home/879enwt/REPO_git/mon_imGui/opencv-4.x/cmake/OpenCVUtils.cmake;1799;add_test;/home/879enwt/REPO_git/mon_imGui/opencv-4.x/cmake/OpenCVModule.cmake;1265;ocv_add_test_from_target;/home/879enwt/REPO_git/mon_imGui/opencv-4.x/cmake/OpenCVModule.cmake;1124;ocv_add_perf_tests;/home/879enwt/REPO_git/mon_imGui/opencv-4.x/modules/imgproc/CMakeLists.txt;13;ocv_define_module;/home/879enwt/REPO_git/mon_imGui/opencv-4.x/modules/imgproc/CMakeLists.txt;0;")
