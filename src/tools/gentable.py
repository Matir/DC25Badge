import math
import sys

template = '''
#include <compiler.h>
const uint8_t sin_table[] = {%s};
'''

nsteps = int(sys.argv[1])
outfile = sys.argv[2]

vals = [math.sin(i * 2 * math.pi / nsteps) * 0x7f + 0x7f for i in xrange(nsteps)]

with open(outfile, 'w') as fp:
    fp.write(template % ', '.join('%d' % x for x in vals))
