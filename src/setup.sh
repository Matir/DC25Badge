#!/bin/zsh

cd $(dirname $0)

if ! test -d asf ; then
  TEMPD=`mktemp -d`
  wget -O $TEMPD/asf.zip https://www.microchip.com/asfwindows
  unzip -q -d $TEMPD $TEMPD/asf.zip -x xdk-asf\*/{avr32,mega,xmega}/\*
  mv --no-target-directory --no-clobber $TEMPD/xdk-asf* asf/
fi
