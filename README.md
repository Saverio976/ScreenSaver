# MYSCREENSAVER

## 11 screensaver

- 1
three circles that bounce and leave a trail behind them
![circles](assets/screens/screen_1.png)

- 2
random little lines fall from top to bottom
![snow](assets/screens/screen_2.png)

- 3
draws randomly crossed circles
![spawn](assets/screens/screen_3.png)

- 4
do you remember the 'dvd' image that bounces on the screen ? the same one but with a .bmp image.
the challenge was to retrieve pixels from a .bmp with only possibility to read the file as a "text" file

- 5
windows like bubulles bounce
![bubulle](assets/screens/screen_5.png)

- 6
a simple background color that fade
![fade](assets/screens/screen_6.png)

- 7
divize the screen into multiple square at each time
![square](assets/screens/screen_7.png)

- 8
the langton ant, an ant tha moove right or left depends on the situation
![langton](assets/screens/screen_8.png)

- 9
a conway game of life screen
![conway](assets/screens/screen_9.png)

- 10
the barnsley fern 'fractal'
![barnsley](assets/screens/screen_10.png)

- 11
a square that repeat itself on its border
![squares](assets/screens/screen_11.png)

## Config:

- change the background color [all screens]

go to include/myscreensaver.h

change `sfBlack` to your color (defaults : sfMagenta, sfBlue, sfRed, sfWhite,
sfBlue, sfYellow) : `#define BG_COLOR sfBlack`

if you want to make a custom color : `https://rgb.to/`

- change the image to display [screen 4]

convert your file in bmp (
https://online-converting.com/image/convert2bmp/#
 dont forgot to change the color setting by `32 (True color RGBA)` and let the
`with rows direction` by default.)

go to the include/nico.h and change `"assets/nico.bmp"` by your picture (
`#define IMAGE_DVD "your_path_picture.bmp"`)

- change the size one cell of the langton screen [screen 8]

go to include/langton.h

change the value of macro NUMBER_COL_CASE and NUMBER_LINE_CASE

- change the color of the cells of the langton screen [screen 8]

go to include/langton.h

change the value of macro COLOR_TABLE_1 and COLOR_TABLE_2

- change the size of one cell of the game of life screen [screen 9]

go to include/gameoflife.h

change the value of macro NUMBER_COL_CASE and NUMBER_LINE_CASE

- change the color of the cells of the game of life screen [screen 9]

go to include/gameoflife.h

change the value of macro DEFT_COLOR_1 and DEFT_COLOR_2

## Compil:

`make`
or
`make re`
to re make the executable

if there is some compilation error and you dont modify anything, fill an
issue, else, you have modifed a part that do this error.

if you modified a macro (to change the default behavious) make sur you changed
them to same type (`10` is not the same as `"10"`). If you have any question
feeel free to discuss it on github discussion.

## Run:

`./my_screensaver -h` to get the usage message
