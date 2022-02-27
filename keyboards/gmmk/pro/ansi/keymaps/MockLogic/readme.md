# MockLogic's GMMK Pro Layout

Mostly a QMK Learning project, this keymap includes a lot of featuers. It is intended to be run with RGB compatible keycaps as key highlighting is used in various places.

* Lots of RGB inidcators including a function layer where toggles are blue when the feature is activated and orange when the feature is deactivated
* Dynamic Macro recording (1 slot)
* N-Key Rollover disable/enable toggle for compatibility
* CapsWord feature based on [Pascal Getreuer's work](https://getreuer.info/posts/keyboards/caps-word/index.html).
* Autocorrection with over 400 common errors. also based on [Pascal Getreuer's work](https://getreuer.info/posts/keyboards/autocorrection/index.html).
* An RGB configuration mode with lots of controls.
* A Gaming Mode that disables potentially game disrupting keys like Windows, Capslock, and several other optional features. Has WASD highlighting through RGB.
* [Space Cadet Shift](https://docs.qmk.fm/#/feature_space_cadet).
* A mosue mode where it's possible to use the arrow keys along with Right Control and End, to emulate a mouse.
* Mouse Jiggler feature to keep a computer away based on [DIYCharles's Project](https://github.com/DIYCharles/MouseJiggler).
* The Encoder Knob is enabled. Most of the time it controls the volume.

## Keyboard Layout
The base layout of the keyboard is nearly default. I have chose to put my Delete key between F12 and the Knob, and a Home key directly under the Knob, with the usual Page Up, Page Down, and End keys under that.

## Function Controls
The F1 through F11 keys are the default media controls, highlighted in green.

Delete becomes Insert

The Grave (`~) key is the Macro recording key. Press it once to start recording and once again to stop the recording. Note you will need to hold down the function key to stop it again. 1 plays back the recording.

The 9 and 0 keys activate Space Cadet Shift, but only for the Shift Keys.

Back Space clears the keyboard memory.

Back slash resets the keyboard, as usual.

Capslock toggles CapsWord feature.

J activates the mouse jiggler feature.

C toggles the auto correction feature.

N Toggles the N-Key Rollover function. This setting is retained in memory.

Right Control turns on the Leader key.

## Leader Key options

Activate the Leader key and it should glow blue. Type a command to activate that feature. All commands are lower case.

* rgb - Brings up the RGB control page.
* game - Puts the keyboard in a gaming mode.
* white - sets the backlight to a pale warm white.
* color - set the backlight to a scrolling rainbow.

## RGB Control Mode

Most keys are disabled in this mode.

The F1-F12, and Delete, keys each set the keyboard to a particular color.

Q and W alter the hue (color), as does the encoder knob.

A and S alter the saturation (white vs color).

Z and X alter the vibrancey (how bright).

Up and Down arrows move through different effects.

Left and Right arrows control effect speed.

Pushing the knob down toggles the RGB matrix on/off.