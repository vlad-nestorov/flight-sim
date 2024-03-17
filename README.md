# flight-sim
Make X-Plane 11 feel like a Cessna 172 I used to fly out of Brampton Flight Centre

See the blog entry for an overview: https://www.nestorov.net/blog/diy-flight-sim

## Parts

| Purpose | Part | Quantity  |
| ---- | ---- | ---- |
| Throttle and Mixture | [652-PTF01-152A-103B2](http://www.mouser.com/ProductDetail/bourns/ptf01-152a-103b2/?qs=VLbEAbY6DC%252bRFWZf7YL3ug%3d%3d&countrycode=CA&currencycode=CAD)<br />Bourns Slide Potentiometers | 2 |
| Computer Interface | [782-A000052](http://www.mouser.com/ProductDetail/arduino/a000052/?qs=JYLCs0CWXI0EuuE9AXNMFg%3d%3d&countrycode=CA&currencycode=CAD)<br />Arduino Development Boards & Kits - AVR | 1 |
| Toggle switches | [108-1MS1T1B1M1QE-EVX](http://www.mouser.com/ProductDetail/mountain-switch/1ms1t1b1m1qe-s/?qs=e8V%2fxjLdzRQvU50WuBvd1A%3d%3d&countrycode=CA&currencycode=CAD)  <br />Mountain Switch Toggle Switches | 7 |
| Master and Avionics Master | [691-TTGCTA201TWB](http://www.mouser.com/ProductDetail/carling-technologies/ttgc-ta201-tw-b/?qs=cBJjPLt5IahBZb8psSzcEA%3d%3d&countrycode=CA&currencycode=CAD)  <br />  Carling Rocker Switches  | 2 |
| Starter | [5164-1505-F](http://www.mouser.com/ProductDetail/davies-molding/1505-f/?qs=AaRlLUpeMszzpPZXN7jbMw%3d%3d&countrycode=CA&currencycode=CAD) <br />Davies Knobs & Dials  | 1 |
| Flaps | [633-M2018TYW01-HA](http://www.mouser.com/ProductDetail/nkk-switches/m2018tyw01-ha/?qs=t8w9rvwJwK%252bbpNRA6nphwg%3d%3d&countrycode=CA&currencycode=CAD)  <br />NKK Rocker Switches  | 1 |
| Starter | [105-SR2511F-25NS](http://www.mouser.com/ProductDetail/alpha-taiwan/sr2511f-0205-19r0b-e9-n-w-159/?qs=8%252br4Hz5Xir%2ffB87l0ASYIw%3d%3d&countrycode=CA&currencycode=CAD)   <br />Taiwan Alpha Rotary Switches  | 1 |
| Throttle control | [A-820 CONTROL 36" BLACK KNOB](https://www.aircraftspruce.ca/catalog/appages/a820.php) | 1 |
| Mixture control | [A-790 CONTROL 48" RED KNOB](https://www.aircraftspruce.com/catalog/appages/a7902.php) | 1 |


## Cockpit dimensions

You can import the airplane model from the following files using the [AC3D plugin](https://developer.x-plane.com/tools/ac3d-plugin/):

Each .obj model uses a cartesian system with the units in meters. Each part is offset from the center, so that when all the parts are imported, they fit together. (Don't make the mistake of moving parts around to make them fit....)

```
..\X-Plane 11\Aircraft\Laminar Research\Cessna 172SP\objects\cockpit_1.obj
..\X-Plane 11\Aircraft\Laminar Research\Cessna 172SP\objects\cockpit_2.obj
..\X-Plane 11\Aircraft\Laminar Research\Cessna 172SP\objects\cockpit_panel.obj
```


| Item | X | Y | Z |
| ---- | ---- | ---- | ---- |
| Orign (0, 0, 0) | Yoke Center | Floor below Yoke | Dashboard |
| Bottom of yoke rod | 0 | 0.649 | 0 |
| Left of Ignition | -0.236 |  | 0 |
| Right of flaps | 0.469 |  |  |
| Back of rudder | ? | ? | -0.313 |
| bottom of panel |  | 0.436 |  |

Width from magneto switch left to flaps right = 0.706
Seat height 0.383
Yoke Center height

## Frame Dimensions

Bottom of yoke rod to top of frame = 0.036
Frame height = 0.649 - 0.036 = 0.613
Leg height = 0.613 - 1 * 0.038 = 0.575

Panel width = 0.706
Inner leg width = 0.706 + 0.06 = 0.766


Top frame = Inner Leg + 2 * leg width  = 0.766 + 2 * 0.038 = 0.846

Ground frame stick out = (0.089 - 0.038) / 2

Bottom frame = Top Frame + (0.089 - 0.038) / 2 * 2 = 0.897



| Part | Count | Length |  |
| ---- | ---- | ---- | ---- |
| Leg | 2 | 0.575 |  |
| Top cross | 1 | 0.846 |  |
| Bottom cross | 1 | 0.897 |  |
| ground | 2 | 0.96 |  |

### Rudder position
back of Saitek rudder to back 2x4 = 0.070
back of rudder = -0.313
front of back 2x4 = 0.383
back of frame = 0.383 + 0.089 = 0.472

### Yoke position
Left of frame to center of yoke = 0.236 + 0.030 + 0.038 = 0.304
0.280
0.14
0.164


# Viewpoint
X 0.998
Y 0.505


Headset calibration point
0.125 + 2 * 0.036
0.197



## Dashboard measurements
Reference point | Top of dashboard, below center of yoke.

Part | x | y
--- | --- | ---
Toggle switch | 0.011 | -0.110
Toggle switch | -0.0121 | -0.110
Toggle switch | -0.0361 | -0.110
Toggle switch | -0.0611 | -0.110
Toggle switch | -0.0841 | -0.110
Toggle switch | -0.1071 | -0.110
Toggle switch | -0.1301 | -0.110
Ignition | -0.220 |  -0.096
Master center | -0.166 |  -0.088
Avionics  | 0.042 |  -0.088
Throttle | 0.253 |  -0.078
Mixture | 0.320 |  -0.078
Flaps | 0.442 |  -0.080
