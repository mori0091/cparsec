# -*- mode: makefile ; coding: utf-8-unix -*-

TARGET = $(LIB_DIR)/libcparsec.a

CFLAGS   += --std=c11 -Wno-pedantic-ms-format -D_GNU_SOURCE
CXXFLAGS += --std=c++11 -D_GNU_SOURCE
