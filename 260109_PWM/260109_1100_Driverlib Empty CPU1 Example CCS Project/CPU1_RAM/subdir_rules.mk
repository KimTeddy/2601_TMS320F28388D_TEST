################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-124535772: ../c2000.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs2031/ccs/utils/sysconfig_1.26.0/sysconfig_cli.bat" -s "C:/ti/C2000Ware_6_00_01_00/.metadata/sdk.json" -d "F2838x" -p "337bga" -r "F2838x_337bga" --script "C:/Users/Teddy/Documents/GitHub/2601_TMS320F28388D_TEST/260109_PWM/260109_1100_Driverlib Empty CPU1 Example CCS Project/c2000.syscfg" -o "syscfg" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-124535772 ../c2000.syscfg
syscfg/board.h: build-124535772
syscfg/board.cmd.genlibs: build-124535772
syscfg/board.opt: build-124535772
syscfg/board.json: build-124535772
syscfg/pinmux.csv: build-124535772
syscfg/epwm.dot: build-124535772
syscfg/c2000ware_libraries.cmd.genlibs: build-124535772
syscfg/c2000ware_libraries.opt: build-124535772
syscfg/c2000ware_libraries.c: build-124535772
syscfg/c2000ware_libraries.h: build-124535772
syscfg/clocktree.h: build-124535772
syscfg: build-124535772

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2031/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu64 --idiv_support=idiv0 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --include_path="C:/Users/Teddy/Documents/GitHub/2601_TMS320F28388D_TEST/260109_PWM/260109_1100_Driverlib Empty CPU1 Example CCS Project" --include_path="C:/ti/C2000Ware_6_00_01_00" --include_path="C:/Users/Teddy/Documents/GitHub/2601_TMS320F28388D_TEST/260109_PWM/260109_1100_Driverlib Empty CPU1 Example CCS Project/device" --include_path="C:/ti/C2000Ware_6_00_01_00/driverlib/f2838x/driverlib/" --include_path="C:/ti/ccs2031/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=RAM --define=DEBUG --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/Teddy/Documents/GitHub/2601_TMS320F28388D_TEST/260109_PWM/260109_1100_Driverlib Empty CPU1 Example CCS Project/CPU1_RAM/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2031/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu64 --idiv_support=idiv0 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --include_path="C:/Users/Teddy/Documents/GitHub/2601_TMS320F28388D_TEST/260109_PWM/260109_1100_Driverlib Empty CPU1 Example CCS Project" --include_path="C:/ti/C2000Ware_6_00_01_00" --include_path="C:/Users/Teddy/Documents/GitHub/2601_TMS320F28388D_TEST/260109_PWM/260109_1100_Driverlib Empty CPU1 Example CCS Project/device" --include_path="C:/ti/C2000Ware_6_00_01_00/driverlib/f2838x/driverlib/" --include_path="C:/ti/ccs2031/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=RAM --define=DEBUG --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/Teddy/Documents/GitHub/2601_TMS320F28388D_TEST/260109_PWM/260109_1100_Driverlib Empty CPU1 Example CCS Project/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


