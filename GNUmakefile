# -*- mode: makefile ; coding: utf-8-unix -*-
.PHONY: all build clean show test test.build

-include Project.mk

DEFAULT_TEST_TARGET = $(TEST_LIB_DIR)/lib$(notdir $(abspath .)).a
DEFAULT_CFLAGS = -MMD -MD -pedantic-errors -Wpedantic -Wall -Wextra -Winit-self -Wno-missing-field-initializers

INC_DIR ?= include
SRC_DIR ?= src
TEST_DIR = test

DST_BASE_DIR = build
DST_DIR = $(DST_BASE_DIR)/default
OBJ_DIR = $(DST_DIR)/obj
BIN_DIR = $(DST_DIR)/bin
LIB_DIR = $(DST_DIR)/lib

SRCS ?= $(if $(wildcard $(SRC_DIR)),$(shell find $(SRC_DIR) -type f -name '*.c' -o -name '*.cpp'))
OBJS ?= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,\
	$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,\
	$(SRCS)))
DEPS ?= $(patsubst %.o,%.d,$(OBJS))

CFLAGS   += $(DEFAULT_CFLAGS)
CXXFLAGS += $(DEFAULT_CFLAGS)

INCLUDES  = $(foreach d,$(wildcard $(INC_DIR) $(SRC_DIR)),-I$(d))
CPPFLAGS += $(INCLUDES)

ifneq ($(SRCS),)
DEFAULT_TARGET      = $(BIN_DIR)/$(notdir $(CURDIR))
TARGET  ?= $(DEFAULT_TARGET)
endif

TARGET_LIB ?= $(filter %.a,$(TARGET))
TARGET_BIN ?= $(filter-out %.a,$(TARGET))

TEST_OBJ_DIR = $(DST_DIR)/test/obj
TEST_BIN_DIR = $(DST_DIR)/test/bin
TEST_LIB_DIR = $(DST_DIR)/test/lib
TEST_RUNNER ?= $(TEST_BIN_DIR)/unit
ifneq ($(SRCS),)
TEST_TARGET ?= $(or $(TARGET_LIB),$(DEFAULT_TEST_TARGET))
endif

CC  = gcc
CXX = g++
AR  = ar

# ----

all: build test

# ifneq ($(SRCS),)
# all: build test
# else
# all: test
# endif

# ----
_PROVIDE_MK = _provide.mk
ifneq ($(REQUIRE),)
PROJECT_DEPENDS = $(foreach i,$(REQUIRE),$(addprefix $(i)/,$(_PROVIDE_MK)))
-include $(PROJECT_DEPENDS)
endif

build:: $(TARGET)

clean::
	@rm -f $(OBJS) $(TARGET) $(DEPS) $(_PROVIDE_MK)
	@rm -rf $(DST_BASE_DIR)

show:
	$(info INC_DIR      = $(INC_DIR))
	$(info SRC_DIR      = $(SRC_DIR))
	$(info TEST_DIR     = $(TEST_DIR))
	$(info DST_DIR      = $(DST_DIR))
	$(info OBJ_DIR      = $(OBJ_DIR))
	$(info BIN_DIR      = $(BIN_DIR))
	$(info LIB_DIR      = $(LIB_DIR))
	$(info TARGET       = $(TARGET))
	$(info TARGET_BIN   = $(TARGET_BIN))
	$(info TARGET_LIB   = $(TARGET_LIB))
	$(info TEST_OBJ_DIR = $(TEST_OBJ_DIR))
	$(info TEST_BIN_DIR = $(TEST_BIN_DIR))
	$(info TEST_LIB_DIR = $(TEST_LIB_DIR))
	$(info TEST_TARGET  = $(TEST_TARGET))
	$(info TEST_RUNNER  = $(TEST_RUNNER))
	$(info INCLUDES     = $(INCLUDES))
	$(info LIBS         = $(LIBS))
	$(info LDFLAGS      = $(LDFLAGS))
	$(info LDLIBS       = $(LDLIBS))
	$(info REQUIRE      = $(REQUIRE))
	@echo

test:: $(TEST_RUNNER)
	$(info [TEST]  Run     : $<	[$(notdir $(CURDIR))])
	@$<

$(TARGET_BIN): $(OBJS) $(LIBS)
	$(info [CXXLD] Build   : $@	[$(notdir $(CURDIR))])
	@mkdir -p $(dir $@)
	@$(CXX) -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(TARGET_LIB) $(DEFAULT_TEST_TARGET): $(OBJS)
	$(info [AR]    Build   : $@	[$(notdir $(CURDIR))])
	@mkdir -p $(dir $@)
	@$(AR) cr $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(info [C]     Compile : $@ ($<))
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(info [CXX]   Compile : $@ ($<))
	@mkdir -p $(dir $@)
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -c -o $@ $<

$(TEST_RUNNER): test.build
test.build: $(TEST_TARGET)
	@$(MAKE) LIBS="$(TEST_TARGET) $(LIBS)" \
		 DST_DIR="$(DST_DIR)/test" \
		 INC_DIR="$(INC_DIR) thirdparty/catch2" \
		 SRC_DIR="$(TEST_DIR)" \
		 TARGET="$(TEST_RUNNER)" \
		 REQUIRE="" \
		 -s --no-print-directory \
		 build

debug:
	@$(MAKE) DST_DIR="$(DST_BASE_DIR)/debug" \
		 DEFAULT_CFLAGS="$(DEFAULT_CFLAGS) -g -DDEBUG" \
		 -s --no-print-directory

release:
	@$(MAKE) DST_DIR="$(DST_BASE_DIR)/release" \
		 DEFAULT_CFLAGS="$(DEFAULT_CFLAGS) -O2" \
		 -s --no-print-directory

-include $(DEPS)

# ----
%/$(_PROVIDE_MK):
	@$(MAKE) --no-print-directory -sC $(dir $@) $(notdir $@)

$(_PROVIDE_MK):
	@$(file > $@,$(foreach d,$(wildcard $(INC_DIR)),INCLUDES+=-I$(abspath $(d))))
	@$(file >>$@,INCLUDES+=$(filter-out $(foreach d,$(wildcard $(INC_DIR) $(SRC_DIR)),-I$(d)),$(INCLUDES)))
ifneq ($(TARGET_LIB),)
	@$(file >>$@,LIBS+=$(addprefix $(CURDIR)/,$$(LIB_DIR)/$(notdir $(TARGET_LIB))))
	@$(file >>$@,LIBS+=$(LIBS))
	@$(file >>$@,LDLIBS+=$(LDLIBS))
	@$(file >>$@,LDFLAGS+=$(LDFLAGS))
endif
	@$(file >>$@,build clean test::)
	@$(file >>$@,	@$$(MAKE) -C $(CURDIR) $$@)
