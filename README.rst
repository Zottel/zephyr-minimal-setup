########################################
 Zephyr Minimal Setup Test (for Debian)
########################################

Since a full Zephyr setup can be a real beast, I tried to set up a minimal
development environment.  Here I use only the STM32 hal for the nucleo_h563zi
board.

Quick Start
===========

Set up System with::

  # Debian packages:
  sudo apt install gcc-arm-none-eabi ninja-build build-essential python3-pip

  # West
  pip3 install west

  # PyOCD
  pip3 install pyocd
  pyocd pack --update
  pyocd pack --install stm32h5
  pyocd pack --install stm32h563zitx


Set up Zephyr with::

  # Most settings are done in .west/config, just need fetch opts here.
  west update --fetch-opt=--filter=tree:0


Then compile with::

  export ZEPHYR_TOOLCHAIN_VARIANT=cross-compile
  export CROSS_COMPILE=/usr/bin/arm-none-eabi-

  # Not working: export SYSROOT_DIR=/usr/lib/arm-none-eabi/newlib/
  # It will probably use the corredt SYSROOT_DIR per default, but you may try:
  #west build hello_world -DSYSROOT_DIR=/usr/lib/arm-none-eabi/newlib/

  west build hello_world
  # Then, or instead:
  west build hello_world --target flash


Technical Details
=================

This repository contains the configuration for a west workspace in
.west/config and west.yml.  For now we use module already integrated in the
vanilla Zephyr manifest, so our west.yml includes Zephyr and allowlists
the modules we actually need.

