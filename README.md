kadirgokhansezer ~/Desktop/vector_imp $% g++ -std=c++20 custom_vector_main.cpp; ./a.out
Average: 52
Execution time: 6165968 microseconds, which is 6.16597 seconds


kadirgokhansezer ~/Desktop/vector_imp $% g++ -std=c++20 std_vector_main.cpp; ./a.out   
Average: 52
Execution time: 14761148 microseconds, which is 14.7611 seconds



From which we can easly see that, the extra features that std gives us, add lots of latency to our executables.

