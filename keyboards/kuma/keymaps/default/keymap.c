#include QMK_KEYBOARD_H
#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define SCTL_ESC MT(MOD_LCTL, S(KC_ESC))
#define FN_SPC LT(FN, KC_SPC)
#define ___X___ KC_NO

enum layer_names {
	BASE,
	FN,
	SFT,
	SFTFN,
	//NP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// Base programmer dvorak layer
	[BASE] = LAYOUT(
		// Left hand
		KC_ESC , KC_DLR , KC_AMPR, KC_LBRC, KC_LCBR, KC_RCBR, KC_LPRN,
		    KC_TAB      , KC_SCLN, KC_COMM, KC_DOT , KC_P   , KC_Y   ,
	          CTL_ESC   , KC_A   , KC_O   , KC_E   , KC_U   , KC_I   ,
			     MO(SFT), KC_QUOT, KC_Q   , KC_J   , KC_K   , KC_X   ,
		                  MO(FN) ,    KC_LALT,    FN_SPC ,    KC_LGUI,
		KC_DEL ,
		// Right hand
		KC_BSPC,
		KC_EQL , KC_ASTR, KC_RPRN, KC_PLUS, KC_RBRC, KC_EXLM, KC_HASH,
		KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_SLSH, KC_AT  ,
		KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_MINS, KC_BSLS,
		KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   ,     MO(SFT)     ,
		KC_ENT ,   KC_SPC ,   KC_RALT
	),
	
	// Function-layer
	[FN] = LAYOUT(
		// Left hand
		___X___, ___X___, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,
		    ___X___     , ___X___, ___X___, ___X___, ___X___, ___X___,
		      _______   , ___X___, ___X___, ___X___, ___X___, ___X___,
		        _______ , ___X___, ___X___, ___X___, ___X___, ___X___,
		                  _______,    _______,    _______,    _______,
		_______,
		// Right hand
		_______,
		KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
		KC_PGUP, KC_HOME, KC_UP  , KC_END,  ___X___, ___X___, ___X___,
		KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, ___X___, ___X___, ___X___,
		___X___, ___X___, ___X___, ___X___, ___X___,     _______     ,
		MS_BTN1,   MS_BTN3,   MS_BTN2
	),
	
	// Shift layer (to get numbers to work correctly)
	[SFT] = LAYOUT(
		// Left hand
		S(KC_ESC), KC_TILD, KC_1      , KC_2      , KC_3     , KC_4   , KC_5   ,
		    S(KC_TAB)     , S(KC_SCLN), S(KC_COMM), S(KC_DOT), S(KC_P), S(KC_Y),
		      SCTL_ESC    , S(KC_A)   , S(KC_O)   , S(KC_E)  , S(KC_U), S(KC_I),
			     _______  , S(KC_QUOT), S(KC_Q)   , S(KC_J)  , S(KC_K), S(KC_X),
		                    _______   , S(KC_LALT),  S(KC_SPC),    S(KC_LGUI)  ,
		_______,
		// Right hand
		_______,
		KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_PERC, KC_GRV ,
		S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L), KC_QUES, KC_CIRC,
		S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S), KC_UNDS, KC_PIPE,
		S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z),     _______     ,
		S(KC_ENT),  S(KC_SPC),   _______
	),

	// Shift+fn layer (needed to press, for example, shift+F6)
	[SFTFN] = LAYOUT(
		// Left hand
		S(KC_ESC), KC_TILD, S(KC_F1), S(KC_F2)  , S(KC_F3), S(KC_F4), S(KC_F5),
		    S(KC_TAB)     , ___X___ , ___X___   , ___X___ , ___X___ , ___X___ ,
		      SCTL_ESC    , ___X___ , ___X___   , ___X___ , ___X___ , ___X___ ,
			     _______  , ___X___ , ___X___   , ___X___ , ___X___ , ___X___ ,
		                    _______ , S(KC_LALT),  S(KC_SPC),   S(KC_LGUI)    ,
		_______,
		// Right hand
		_______,
		S(KC_F6)  , S(KC_F7)  , S(KC_F8)  , S(KC_F9)  , S(KC_F10), S(KC_F11), S(KC_F12),
		S(KC_PGUP), S(KC_HOME), S(KC_UP)  , S(KC_END) , ___X___  , ___X___  , ___X___  ,
		S(KC_PGDN), S(KC_LEFT), S(KC_DOWN), S(KC_RGHT), ___X___  , ___X___  , ___X___  ,
		___X___   , ___X___   , ___X___   , ___X___   , ___X___  ,     _______         ,
		_______   ,   _______   ,   _______

	),
	
	// Numpad layer
	//[NP] = LAYOUT(
	//	// Left hand
	//	_______, _______, _______, _______, _______, _______, _______,
	//	    _______     , _______, _______, _______, _______, _______,
	//	      _______   , _______, _______, _______, _______, _______,
	//	        _______ , _______, _______, _______, _______, _______,
	//	                  _______,    _______,    _______,    _______,
	//	_______,
	//	// Right hand
	//	_______   ,
	//	_______   , KC_7   , KC_8   , KC_9   , _______, _______, _______,
	//	S(KC_PGUP), KC_4   , KC_5   , KC_6   , _______, _______, _______,
	//	S(KC_PGDN), KC_1   , KC_2   , KC_3   , _______, _______, _______,
	//	_______   , KC_0   , KC_0   , KC_ENT , _______,     _______     ,
	//	_______   ,   _______,   _______
	//),

	// In case I need more layers
	//[NAME] = LAYOUT(
	//	// Left hand
	//	_______, _______, _______, _______, _______, _______, _______,
	//	    _______     , _______, _______, _______, _______, _______,
	//	      _______   , _______, _______, _______, _______, _______,
	//	        _______ , _______, _______, _______, _______, _______,
	//	                  _______,    _______,    _______,    _______,
	//	_______,
	//	// Right hand
	//	_______,
	//	_______, _______, _______, _______, _______, _______, _______,
	//	_______, _______, _______, _______, _______, _______, _______,
	//	_______, _______, _______, _______, _______, _______, _______,
	//	_______, _______, _______, _______, _______,     _______     ,
	//	_______,   _______,   _______
	//),
};

// Arcane magic: Turn on the shift+fn-layer when shift and fn are both active.
layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, FN, SFT, SFTFN);
}
