## Matir's DEF CON 25 Badge ##

This is an unofficial badge I made for DEF CON 25.  It's a blinding party-style
badge with 48 individually addressable RGB LEDs.  Off an adequate battery (a
medium LiPo) you can run all lights at max brightness, but that is *bright*.

![Finished Badge](https://raw.githubusercontent.com/Matir/DC25Badge/master/img/finished_badge.jpg)

This is intended as a one-time release for others to learn from and/or remix the
firmware.  I don't plan to take pull requests since it will be over and I'll be
on to another project by the release.  :)

### PCB ###

The PCB was designed using Kicad.  Source files are in the `dc25badge/`
directory.

![PCB Rendering](https://raw.githubusercontent.com/Matir/DC25Badge/master/img/xxv_top.png)

### Compiling Firmware ###

To build the firmware, you'll need 3 things: this git repository, the Atmel
Software Framework (ASF), and an ARM compiler.  On Debian & Ubuntu, you'll want
to install the packages `gcc-arm-none-eabi` and `binutils-arm-none-eabi`.

`setup.sh` in the `src/` directory will get you the latest build of the ASF (at
least, it worked when this was prepared).  Running `make` will build the
firmware image.

To choose which patterns are available by pushing the mode button, edit the
array in `pattern.c`.

### Uploading Firmware ###

To upload a firmware image, you'll need to get into the bootloader.  To do this,
"double tap" the reset button, and the reset LED will stay solid green.  (If it
doesn't, you're not in the bootloader.)

You can then use `bossa` or just run `make upload` from the `src/` directory to
upload the current firmware build.

This is not an official Google product.
