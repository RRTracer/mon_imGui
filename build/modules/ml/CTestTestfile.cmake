# CMake generated Testfile for 
# Source directory: /home/879enwt/REPO_git/mon_imGui/opencv-4.x/modules/ml
# Build directory: /home/879enwt/REPO_git/mon_imGui/build/modules/ml
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_ml "/home/879enwt/REPO_git/mon_imGui/build/bin/opencv_test_ml" "--gtest_output=xml:opencv_test_ml.xml")
set_tests_properties(opencv_test_ml PROPERTIES  LABELS "Main;opencv_ml;Accuracy" WORKING_DIRECTORY "/home/879enwt/REPO_git/mon_imGui/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/home/879enwt/REPO_git/mon_imGui/opencv-4.x/cmake/OpenCVUtils.cmake;1799;add_test;/home/879enwt/REPO_git/mon_imGui/opencv-4.x/cmake/OpenCVModule.cmake;1365;ocv_add_test_from_target;/home/879enwt/REPO_git/mon_imGui/opencv-4.x/cmake/OpenCVModule.cmake;1123;ocv_add_accuracy_tests;/home/879enwt/REPO_git/mon_imGui/opencv-4.x/modules/ml/CMakeLists.txt;2;ocv_define_module;/home/879enwt/REPO_git/mon_imGui/opencv-4.x/modules/ml/CMakeLists.txt;0;")
