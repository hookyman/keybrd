Tutorial 2 - single-layer keyboard
=======================================
The easiest way to learn the keyboard library is to read some simple sketches.
[keybrd_2_single-layer.ino](keybrd_2_single-layer/keybrd_2_single-layer.ino) is a simple sketch with annotations that explain how a keybrd sketch works.
The sketch will run on the basic breadboard keyboard described in [tutorial_1_breadboard_keyboard.md](tutorial_1_breadboard_keyboard.md)

After reading the sketch you will be able to modify it to suite your own single-layer keyboard design.

![basic breadboard keyboard](keybrd_1_breadboard/basic_breadboard_keyboard_front.JPG "basic breadboard keyboard")

Exercises
---------
1) Read the four class definitions #included in the sketch.
Classes are defined in the [keybrd library](../src/).

2) Add a fifth key to the breadboard keyboard and sketch.
Not all rows have to have the same number of keys.
The scanner should have enough readPins to cover all the keys of the longest row.

| Layout |**0**|**1**|**2**|
|:------:|:---:|:---:|:---:|
|  **0** |  1  |  2  |  3  |
|  **1** |  a  |  b  |     |

Please take the [keybrd tutorials usability survey](../CONTRIBUTING.md#keybrd-tutorials-usability-survey)

<br>
<a rel="license" href="https://creativecommons.org/licenses/by/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://licensebuttons.net/l/by/4.0/88x31.png" /></a><br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">keybrd tutorial</span> by <a xmlns:cc="https://creativecommons.org/ns" href="https://github.com/wolfv6/keybrd" property="cc:attributionName" rel="cc:attributionURL">Wolfram Volpi</a> is licensed under a <a rel="license" href="https://creativecommons.org/licenses/by/4.0/">Creative Commons Attribution 4.0 International License</a>.<br />Permissions beyond the scope of this license may be available at <a xmlns:cc="https://creativecommons.org/ns" href="https://github.com/wolfv6/keybrd/issues/new" rel="cc:morePermissions">https://github.com/wolfv6/keybrd/issues/new</a>.
