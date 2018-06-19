################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Adns3080.c" \
"../Sources/Events.c" \
"../Sources/FP3.c" \
"../Sources/MPU6050.c" \
"../Sources/Move_ssl.c" \
"../Sources/PID.c" \
"../Sources/Spi.c" \
"../Sources/Uart.c" \
"../Sources/bsp.c" \
"../Sources/kalman.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/Adns3080.c \
../Sources/Events.c \
../Sources/FP3.c \
../Sources/MPU6050.c \
../Sources/Move_ssl.c \
../Sources/PID.c \
../Sources/Spi.c \
../Sources/Uart.c \
../Sources/bsp.c \
../Sources/kalman.c \
../Sources/main.c \

OBJS += \
./Sources/Adns3080_c.obj \
./Sources/Events_c.obj \
./Sources/FP3_c.obj \
./Sources/MPU6050_c.obj \
./Sources/Move_ssl_c.obj \
./Sources/PID_c.obj \
./Sources/Spi_c.obj \
./Sources/Uart_c.obj \
./Sources/bsp_c.obj \
./Sources/kalman_c.obj \
./Sources/main_c.obj \

OBJS_QUOTED += \
"./Sources/Adns3080_c.obj" \
"./Sources/Events_c.obj" \
"./Sources/FP3_c.obj" \
"./Sources/MPU6050_c.obj" \
"./Sources/Move_ssl_c.obj" \
"./Sources/PID_c.obj" \
"./Sources/Spi_c.obj" \
"./Sources/Uart_c.obj" \
"./Sources/bsp_c.obj" \
"./Sources/kalman_c.obj" \
"./Sources/main_c.obj" \

C_DEPS += \
./Sources/Adns3080_c.d \
./Sources/Events_c.d \
./Sources/FP3_c.d \
./Sources/MPU6050_c.d \
./Sources/Move_ssl_c.d \
./Sources/PID_c.d \
./Sources/Spi_c.d \
./Sources/Uart_c.d \
./Sources/bsp_c.d \
./Sources/kalman_c.d \
./Sources/main_c.d \

C_DEPS_QUOTED += \
"./Sources/Adns3080_c.d" \
"./Sources/Events_c.d" \
"./Sources/FP3_c.d" \
"./Sources/MPU6050_c.d" \
"./Sources/Move_ssl_c.d" \
"./Sources/PID_c.d" \
"./Sources/Spi_c.d" \
"./Sources/Uart_c.d" \
"./Sources/bsp_c.d" \
"./Sources/kalman_c.d" \
"./Sources/main_c.d" \

OBJS_OS_FORMAT += \
./Sources/Adns3080_c.obj \
./Sources/Events_c.obj \
./Sources/FP3_c.obj \
./Sources/MPU6050_c.obj \
./Sources/Move_ssl_c.obj \
./Sources/PID_c.obj \
./Sources/Spi_c.obj \
./Sources/Uart_c.obj \
./Sources/bsp_c.obj \
./Sources/kalman_c.obj \
./Sources/main_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Adns3080_c.obj: ../Sources/Adns3080.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Adns3080.args" -ObjN="Sources/Adns3080_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/Events_c.obj: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Events.args" -ObjN="Sources/Events_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/FP3_c.obj: ../Sources/FP3.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/FP3.args" -ObjN="Sources/FP3_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/MPU6050_c.obj: ../Sources/MPU6050.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/MPU6050.args" -ObjN="Sources/MPU6050_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/Move_ssl_c.obj: ../Sources/Move_ssl.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Move_ssl.args" -ObjN="Sources/Move_ssl_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/PID_c.obj: ../Sources/PID.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/PID.args" -ObjN="Sources/PID_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/Spi_c.obj: ../Sources/Spi.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Spi.args" -ObjN="Sources/Spi_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/Uart_c.obj: ../Sources/Uart.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Uart.args" -ObjN="Sources/Uart_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/bsp_c.obj: ../Sources/bsp.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/bsp.args" -ObjN="Sources/bsp_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/kalman_c.obj: ../Sources/kalman.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/kalman.args" -ObjN="Sources/kalman_c.obj" "$<" -Lm="Sources/kalman_c.d" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/kalman_c.d: ../Sources/kalman.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


