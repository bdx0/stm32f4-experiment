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
	
shell:
	cd lib/stm32_discovery_arm_gcc/blinky && xterm
	@echo $@ done !!
	
.PHONY: git-create
git-create:
	git init
	git config --global user.name "Duong Bao Duy"
	git config --global user.email "baoduy.duong0206@gmail.com"
	case "$(shell git remote)" in \
		"origin" ) git remote remove origin; \
	esac 
	git remote add origin https://github.com/duongbaoduy/stm32f4-experiment.git
	@echo Done $@ : $^ !!

.PHONY: build
build:
	@echo Done $@ !!

.PHONY: clean
clean:
	@echo Done $@ !!

.PHONY: all
all:  tool lib #shell
	@echo Your script path: $(LOCAL_PATH)
	@echo Select target for make
	@echo Done $@ !!!

.PHONY: git-pub
git-pub:
	git push -u origin --all
	@echo Done $@ !!