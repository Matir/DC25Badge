#!/bin/zsh

# Copyright 2017 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cd $(dirname $0)

if ! test -d asf ; then
  TEMPD=`mktemp -d`
  wget -O $TEMPD/asf.zip https://www.microchip.com/asfwindows
  unzip -q -d $TEMPD $TEMPD/asf.zip -x xdk-asf\*/{avr32,mega,xmega}/\*
  mv --no-target-directory --no-clobber $TEMPD/xdk-asf* asf/
fi
