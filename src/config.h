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
# define NUM_PIXELS 5
# define LED_PIN 27
#elif defined(XBOARD_TEST)
# ifndef __SAMD21E18A__
#  error "XBOARD_TEST is a SAMD21E18A"
# endif
# define NUM_PIXELS 2
# define LED_PIN 27
#elif defined(XBOARD_XXV)
# ifndef __SAMD21E18A__
#  error "XBOARD_XXV is a SAMD21E18A"
# endif
# define NUM_PIXELS 48
# define LED_PIN 18
#else
# error "No known XBOARD defined."
#endif // Boards

#endif //_CONFIG_H_
