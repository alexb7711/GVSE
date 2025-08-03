BUILD_D = build
.ONESHELL:
all:
	@cmake -S . -B $(BUILD_D)
	@cd build
	@make -j8
	@cd ..

clean:
	@rm -rf $(BUILD_D)
