# arduino compass

A small library to convert a compass module output to cardinal points.

## Usage

Call `getCardinalDirection(angle)` where `angle` is your compass heading. Honneywell lists 1° to 2° for HMC5883L
compass heading accuracy. Other chips are similar in accuracy. Thus
 decimals are omitted by this script, declaring the angle parameter as `word`. The function will then output the abbreviation of the matching cardinal point as a `char`. 

## Configuration

### Setting number of cardinal points
Decide on the number of cardinal points your project calls for. Refer to [Points of the compass](http://en.wikipedia.org/wiki/Points_of_the_compass) to get a sense of what might be suitable for your needs. 

The number of cardinal points is set in `byte cardinalDivision`. The current implementation allows `4`, `8`, `16` or `32` cardinal points. Uncomment the corresponding line for `cardinalDivision` or supply the argument yourself. If `cardinalDivision` is not set a default of `4` is used.  

### Adding cardinal points

Additional points can be added to the compass rose requiring two steps:

1. Adjust `cardinalPoint[]` accordingly by adding the additional abbreviations
2. Change `byte cardinalPointLength` to the number of cardinal points set in `cardinalPoint[]`. 

Points are listed in a clockwise fashion starting at 0° on a compass rose.

Bear in mind that heading can change quickly and compass modules ouput might scatter. Using too many points can render the output useless: your cardinal point might change too often due to subtle changes in heading. 

### Changing cardinal point output

If you'd like to output the full compass point names instead of abbreviations change `cardinalPoint[]` accordingly. I opted for abbreviations as they use less memory and are easier / faster to read on a display. 
