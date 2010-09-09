# Mon Makefile à moi
OPENWRT_PATH=/opt/OpenWRT-Freerunner/openwrt
CXX=$(OPENWRT_PATH)/staging_dir/toolchain-arm_v4t_gcc-4.3.3+cs_uClibc-0.9.30.1_eabi/bin/arm-openwrt-linux-uclibcgnueabi-g++
CXXFLAGS =-O2 -pipe -march=armv4t -mtune=arm920t -funit-at-a-time -fhonour-copts -msoft-float
CXXFLAGS+=-I$(OPENWRT_PATH)/staging_dir/target-arm_v4t_uClibc-0.9.30.1_eabi/usr/include
CXXFLAGS+=-I$(OPENWRT_PATH)/staging_dir/target-arm_v4t_uClibc-0.9.30.1_eabi/include
CXXFLAGS+=-I$(OPENWRT_PATH)/staging_dir/toolchain-arm_v4t_gcc-4.3.3+cs_uClibc-0.9.30.1_eabi/usr/include
CXXFLAGS+=-I$(OPENWRT_PATH)/staging_dir/toolchain-arm_v4t_gcc-4.3.3+cs_uClibc-0.9.30.1_eabi/include
LDFLAGS =
LDFLAGS+=-L$(OPENWRT_PATH)/staging_dir/target-arm_v4t_uClibc-0.9.30.1_eabi/usr/lib
LDFLAGS+=-L$(OPENWRT_PATH)/staging_dir/target-arm_v4t_uClibc-0.9.30.1_eabi/lib
LDFLAGS+=-L$(OPENWRT_PATH)/staging_dir/toolchain-arm_v4t_gcc-4.3.3+cs_uClibc-0.9.30.1_eabi/usr/lib
LDFLAGS+=-L$(OPENWRT_PATH)/staging_dir/toolchain-arm_v4t_gcc-4.3.3+cs_uClibc-0.9.30.1_eabi/lib
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
MODULES=
EXECUTABLE=pdlv

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(MODULES) $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE)
	rm -f *.o a.out
