gcc `pkg-config --cflags gtk4` main_window.c player.c -o main `pkg-config --libs gtk4`
# https://stackoverflow.com/questions/26884574/questions-about-gcc-unrecognized-option-rdynamic
# Use `-export-dynamic` instead of `-rdynamic`