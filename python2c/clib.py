import ctypes

def main():
    lib = ctypes.cdll.LoadLibrary("./libclib.so")

    lib.getValue.argtypes = None
    lib.getValue.restype = ctypes.c_int
    print(lib.getValue())

    lib.multiplyAndAdd.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.c_int]
    lib.multiplyAndAdd.restype = ctypes.c_int
    print("5 * 10 + 15 = {0}".format(lib.multiplyAndAdd(5,10,15)))

    lib.sayHello.argtypes = [ctypes.c_char_p]
    lib.sayHello.restype = None
    lib.sayHello(ctypes.c_char_p("World".encode("utf-8")))

if __name__ == "__main__":
    main()
