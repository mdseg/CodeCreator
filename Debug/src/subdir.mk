################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Campo.c \
../src/CodeCreator.c \
../src/Entidad.c \
../src/utn.c 

OBJS += \
./src/Campo.o \
./src/CodeCreator.o \
./src/Entidad.o \
./src/utn.o 

C_DEPS += \
./src/Campo.d \
./src/CodeCreator.d \
./src/Entidad.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


