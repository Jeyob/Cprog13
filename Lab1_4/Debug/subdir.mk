################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Problematic.cpp \
../kth_cprog_vektor.cpp \
../test_template_vec.cpp 

OBJS += \
./Problematic.o \
./kth_cprog_vektor.o \
./test_template_vec.o 

CPP_DEPS += \
./Problematic.d \
./kth_cprog_vektor.d \
./test_template_vec.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


