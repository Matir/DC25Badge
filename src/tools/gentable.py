import math
import sys

gamma = 2.8;

template = '''
#include <compiler.h>
#include "pattern.h"

const uint16_t consts_num_steps = %(nsteps)d;
const uint16_t consts_resolution = %(resolution)d;
const uint8_t sin_table[] = {%(sin_table)s};
const uint8_t gamma_table[] = {%(gamma_table)s};
'''

nleds = int(sys.argv[1])
resolution = int(sys.argv[2])
outfile = sys.argv[3]

nsteps = nleds * resolution

# Use 0x7f to be centered around, rather than centered around 0.
sin_vals = [math.sin(i * 2 * math.pi / nsteps) * 0x7f + 0x7f for i in xrange(nsteps)]

gamma_vals = [int(math.pow(i/256.0, gamma) * 256.0 + 0.5) for i in xrange(256)]

templ = {}
templ['sin_table'] = ', '.join('%d' % x for x in sin_vals)
templ['resolution'] = resolution
templ['nsteps'] = nsteps
templ['gamma_table'] = ', '.join('%d' % x for x in gamma_vals)

with open(outfile, 'w') as fp:
    fp.write(template % templ)
