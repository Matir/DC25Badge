#ifndef _CONF_USB_H_
#define _CONF_USB_H_

#include <compiler.h>

#define USB_DEVICE_VENDOR_ID              0x03EB
#define USB_DEVICE_PRODUCT_ID             0x1337
#define USB_DEVICE_MAJOR_VERSION          1
#define USB_DEVICE_MINOR_VERSION          0
#define USB_DEVICE_POWER                  100
#define USB_DEVICE_ATTR                   USB_CONFIG_ATTR_SELF_POWERED
#define USB_DEVICE_MANUFACTURE_NAME       "Matir"
#define USB_DEVICE_PRODUCT_NAME           "XXV"

#define  UDC_VBUS_EVENT(b_vbus_high)
#define  UDC_SOF_EVENT()
#define  UDC_SUSPEND_EVENT()
#define  UDC_RESUME_EVENT()

#define  UDI_CDC_ENABLE_EXT(port)          stdio_usb_enable()
#define  UDI_CDC_DISABLE_EXT(port)         stdio_usb_disable()
#define  UDI_CDC_RX_NOTIFY(port)
#define  UDI_CDC_TX_EMPTY_NOTIFY(port)
#define  UDI_CDC_SET_CODING_EXT(port,cfg)
#define  UDI_CDC_SET_DTR_EXT(port,set)
#define  UDI_CDC_SET_RTS_EXT(port,set)

#define  UDI_CDC_DEFAULT_RATE             115200
#define  UDI_CDC_DEFAULT_STOPBITS         CDC_STOP_BITS_1
#define  UDI_CDC_DEFAULT_PARITY           CDC_PAR_NONE
#define  UDI_CDC_DEFAULT_DATABITS         8

#include <udi_cdc_conf.h>
#include <stdio_usb.h>

#endif // _CONF_USB_H_
