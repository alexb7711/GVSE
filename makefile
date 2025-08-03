BUILD_D = build
.ONESHELL:
all:
	[ ! -d "$(BUILD_D)" ] && cmake -S . -B $(BUILD_D)
	cd build
	make -j8
	cd ..

clean:
	rm -rf $(BUILD_D)
