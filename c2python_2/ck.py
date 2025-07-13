
import sys
import subprocess

print(sys.argv)
#ret = subprocess.call('dir', shell = True)
ret = subprocess.call('pwd', shell = True)
print(f'goodbyte {ret}')

