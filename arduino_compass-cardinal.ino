/* 
Arduino function to convert compass heading to cardinal directions for
output on e.g. a display. Honneywell lists 1° to 2° for HMC5883L
compass heading accuracy. Other chips are similar in accuracy. Thus
this script disregards decimals. 

Usage: uncomment the desired cardinalDivision to select the amount of
winds, including the four cardinal directions, the eight principals,
the eight half winds an the sixteen quarter winds. For use with >32
quarter-points replace values where specified in code.

Use getCardinalDirection() to translate your input angle to the
corresponding cardinal direction based on the selected division. The
function returns the matching string from cardinalPoint[].
*/

// uncomment desired cardinal division
 byte cardinalDivision = 4;		
// byte cardinalDivision = 8;	
// byte cardinalDivision = 16;	
// byte cardinalDivision = 32;

// labels for all 32 compass points. For use with >32 quarter-points
// extend the array accordingly. Replace the abbreviations with full
// names or traditional wind point names if needed.
 const char* cardinalPoint[]={
	"N",
	"NbE",
	"NNE",
	"NEbN",
	"NE",
	"NEbE",
	"ENE",
	"EbN",
	"E",
	"EbS",
	"ESE",
	"SEbE",
	"SE",
	"SEbS",
	"SSE",
	"SbE",
	"S",
	"SbW",
	"SSW",
	"SWbS",
	"SW",
	"SWbW",
	"WSW",
	"WbS",
	"W",
	"WbN",
	"WNW",
	"NWbW",
	"NW",
	"NWbN",
	"NNW",
	"NbW"
};

// Number of cardinal points in cardinalPoint[].
	const byte cardinalPointLength = 32;


void setup()  
{

}


void loop() {

// read compass and store output in var angle
	float angle = 330.7;	
	// get cardinal directon from compass angle
	getCardinalDirection(angle);

}


const char* getCardinalDirection(word inputAngle) {

// optinal: check if cardinalDivision is set. If not set use the four
// cardinal directions.
	if (cardinalDivision = NULL){
		const	byte cardinalDivision = 4;
	}

// Calculate range for min and max azimuth of a compass point,
// depending on selected cardinal division. Only range/2 is needed.
	float cardinalAzimuthRange = 180 / (float) cardinalDivision;
	float y = ( inputAngle + cardinalAzimuthRange ) / ( cardinalAzimuthRange * 2 );

// decimals in y are not needed as we want to use y to directly access
// the string array
	word x = (word) y;

// we start at 0° and end at 360°; North thus has a range starting
// before 360° and ending after 0°. Instead of adding North again at
// the end of the array, we treat a value bigger than cardinalDivison
// as 0, thus North.
	if( x >= cardinalDivision ){
		x = 0; 
	}

	x = ( x * cardinalPointLength / cardinalDivision );

	return cardinalPoint[x];
}