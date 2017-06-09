#ifndef _CONFIG_H_
#define _CONFIG_H_

#if defined(__SAMD21G18A__)
# include <samd21g18a.h>
#elif defined(__SAMD21E18A__)
# include <samd21e18a.h>
#else
# error "Unknown MCU."
#endif

#define PATTERN_TC TC3
#define DEBOUNCE_TC TC4

#if defined(XBOARD_SPARKFUN)
# ifndef __SAMD21G18A__
#  error "XBOARD_SPARKFUN is a SAMD21G18A"
# endif
# define NUM_PIXELS           5
# define LED_PIN              27
# define PATTERN_BUTTON_PIN   PIN_PA15A_EIC_EXTINT15
# define PATTERN_BUTTON_MUX   MUX_PA15A_EIC_EXTINT15
# define BRIGHT_BUTTON_PIN    PIN_PA14A_EIC_EXTINT14
# define BRIGHT_BUTTON_MUX    MUX_PA14A_EIC_EXTINT14

#elif defined(XBOARD_TEST)
# ifndef __SAMD21E18A__
#  error "XBOARD_TEST is a SAMD21E18A"
# endif
# define NUM_PIXELS           2
# define LED_PIN              27
# define PATTERN_BUTTON_PIN   PIN_PA06A_EIC_EXTINT6
# define PATTERN_BUTTON_MUX   MUX_PA06A_EIC_EXTINT6
# define BRIGHT_BUTTON_PIN    PIN_PA07A_EIC_EXTINT7
# define BRIGHT_BUTTON_MUX    MUX_PA07A_EIC_EXTINT7

#elif defined(XBOARD_XXV)
# ifndef __SAMD21E18A__
#  error "XBOARD_XXV is a SAMD21E18A"
# endif
# define NUM_PIXELS           48
# define LED_PIN              18
# define PATTERN_BUTTON_PIN   PIN_PA06A_EIC_EXTINT6
# define PATTERN_BUTTON_MUX   MUX_PA06A_EIC_EXTINT6
# define BRIGHT_BUTTON_PIN    PIN_PA07A_EIC_EXTINT7
# define BRIGHT_BUTTON_MUX    MUX_PA07A_EIC_EXTINT7

#else
# error "No known XBOARD defined."
#endif // Boards

#endif //_CONFIG_H_
