#!/usr/bin/python3

max = 0

import os, glob
for filename in glob.glob('*.bas'):
   with open(os.path.join(os.getcwd(), filename), 'r') as f: # open in readonly mode
        fo = open(filename[:-3] + "c", "w")
        fo.write('#include <avr/pgmspace.h>\n')
        fo.write('#include "programs.h"\n')
        fo.write('const PROGMEM line program_%s[] = {\n' % filename[:-4])
        for line in f:
            i = line.find(' ')
            num = line[:i]
            out = line[i+1:-1]
            #out = out.replace('\n', '\\n')
            out = out.replace('\\', '\\\\')
            out = out.replace('"', '\\"')
            L = len(out)
            if L > max:
                max = L
            fo.write('{%s, "%s"},\n' % (num, out))
        fo.write('{},\n};\n')

print(f"Maximum length = {max}")
