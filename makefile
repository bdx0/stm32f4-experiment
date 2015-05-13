### makefile ---
## Author: dbd
## Version: 0.0.1
## 

### Commentary:
##

### Code:

SHELL := bash

.PHONY: tools.sh
tools.sh:
	chmod +x $@
	@echo $@ done !!

tool: tools.sh
	./tools.sh
	@echo $@ done !!

export PATH:=$(PATH):$(shell pwd)/tool/arm-compiler/bin:$(shell pwd)/tool/stlink
.PHONY: check-tool
check-tool:
	echo $(PATH)
	arm-none-eabi-gcc --version
	@echo $@ done !!

.PHONY: libs.sh
libs.sh:
	chmod +x $@
	@echo $@ done !!

lib: libs.sh
	./libs.sh
	@echo $@ done !!
	
all: tool lib
	@echo  $@ done !!
	
shell:
	xterm
	@echo $@ done !!
