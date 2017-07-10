#!/usr/bin/python
#
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

import sys


def main(argv):
    pass


if __name__ == '__main__':
    main(sys.argv)
import math
import sys

gamma = 2.5;

template = '''
#include <compiler.h>
#include "pattern.h"

const uint16_t consts_num_steps = %(nsteps)d;
const uint16_t consts_resolution = %(resolution)d;
const uint8_t sin_table[] = {%(sin_table)s};
const uint8_t gamma_table[] = {%(gamma_table)s};
const uint8_t gamma_min_idx = %(gamma_min_idx)d;
const struct_rgb colorwheel[] = {%(colorwheel)s};
'''

nleds = int(sys.argv[1])
resolution = int(sys.argv[2])
outfile = sys.argv[3]

nsteps = nleds * resolution

# Use 0x7f to be centered around, rather than centered around 0.
# Offset by pi/2 to start at 0
sin_vals = []
for i in xrange(nsteps):
    point = i * 2 * math.pi / nsteps - (math.pi / 2)
    y = math.sin(point)
    int_y = int(y * 0x7f + 0x7f)
    sin_vals.append(int_y)

# Gamma adjustment table per Adafruit
gamma_vals = [int(math.pow(i/256.0, gamma) * 256.0 + 0.5) for i in xrange(256)]

# Use HSV->RGB with S,V=1 for colorwheel in same nsteps as sin_table.
colorwheel = []
for i in xrange(nsteps):
    H_degrees = float(i)/nsteps*360.0
    H_prime = H_degrees/60.0
    X = 1 - abs(H_prime % 2 - 1)
    if H_prime <= 1:
        colorwheel.append((1.0, X, 0))
    elif H_prime <= 2:
        colorwheel.append((X, 1.0, 0))
    elif H_prime <= 3:
        colorwheel.append((0, 1.0, X))
    elif H_prime <= 4:
        colorwheel.append((0, X, 1.0))
    elif H_prime <= 5:
        colorwheel.append((X, 0, 1.0))
    else:
        colorwheel.append((1.0, 0, X))
colorwheel = ['{%s}' % ','.join(('%d' % int(x * 0xFF)) for x in y) for y in colorwheel]

# Render them
templ = {}
templ['sin_table'] = ', '.join('%d' % x for x in sin_vals)
templ['resolution'] = resolution
templ['nsteps'] = nsteps
templ['gamma_table'] = ', '.join('%d' % x for x in gamma_vals)
templ['gamma_min_idx'] = gamma_vals.index([x for x in gamma_vals if x>0][0])
templ['colorwheel'] = ', '.join(colorwheel)

with open(outfile, 'w') as fp:
    fp.write(template % templ)
