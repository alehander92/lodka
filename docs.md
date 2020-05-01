

### based on `osdev`: https://wiki.osdev.org/GCC_Cross-Compiler#Binutils

buiding binutils

```
export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

../configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install

 
# The $PREFIX/bin dir _must_ be in the PATH. We did that above.
which -- $TARGET-as || echo $TARGET-as is not in the PATH

cd ~/gcc-9.3.0
mkdir build-gcc
cd build-gcc
../configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc
```