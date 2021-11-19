# MYSCREENSAVER

## Config:

- change the background color
go to include/myscreensaver.h
change `sfBlack` to your color (defaults : sfMagenta, sfBlue, sfRed, sfWhite,
sfBlue, sfYellow) : `#define BG_COLOR sfBlack`

- change the image to display
convert your file in bmp ( https://online-converting.com/image/convert2bmp/#
dont forgot to change the color setting by `32 (True color RGBA)` and let the
`with rows direction` by default. )
go to the include/nico.h and change `"assets/nico.bmp"` by your picture (
`#define IMAGE_DVD "your_path_picture.bmp"`)

## Compil:

`make`

## Run:

`./my_screensaver -h` to get the usage message
