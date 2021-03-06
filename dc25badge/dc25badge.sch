EESchema Schematic File Version 2
LIBS:dc25badge-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:dc25badge
LIBS:switches
LIBS:dc25badge-cache
EELAYER 25 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 2
Title "DC25 Badge XXV"
Date "2017-06-24"
Rev "2"
Comp "@Matir"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L +5V #PWR01
U 1 1 592A4C04
P 5150 1950
F 0 "#PWR01" H 5150 1800 50  0001 C CNN
F 1 "+5V" H 5150 2090 50  0000 C CNN
F 2 "" H 5150 1950 50  0000 C CNN
F 3 "" H 5150 1950 50  0000 C CNN
	1    5150 1950
	1    0    0    -1  
$EndComp
$Comp
L MIC5305 U1
U 1 1 592A519E
P 1650 1550
F 0 "U1" H 1900 2000 60  0000 C CNN
F 1 "MIC5305" H 1600 2400 60  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-5" H 1650 1550 60  0001 C CNN
F 3 "" H 1650 1550 60  0001 C CNN
	1    1650 1550
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P1
U 1 1 592A5337
P 750 2450
F 0 "P1" H 750 2600 50  0000 C CNN
F 1 "BATT" V 850 2450 50  0000 C CNN
F 2 "Connectors_JST:JST_PH_S2B-PH-SM4-TB_02x2.00mm_Angled" H 750 2450 50  0001 C CNN
F 3 "" H 750 2450 50  0000 C CNN
	1    750  2450
	-1   0    0    -1  
$EndComp
$Comp
L C_Small C2
U 1 1 592A53A0
P 2150 1150
F 0 "C2" H 2160 1220 50  0000 L CNN
F 1 "0.1u" H 2160 1070 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2150 1150 50  0001 C CNN
F 3 "" H 2150 1150 50  0000 C CNN
	1    2150 1150
	1    0    0    -1  
$EndComp
$Comp
L C_Small C1
U 1 1 592A53D1
P 1200 1150
F 0 "C1" H 1210 1220 50  0000 L CNN
F 1 "1u" H 1210 1070 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 1200 1150 50  0001 C CNN
F 3 "" H 1200 1150 50  0000 C CNN
	1    1200 1150
	1    0    0    -1  
$EndComp
$Comp
L C_Small C3
U 1 1 592A543D
P 2400 1150
F 0 "C3" H 2410 1220 50  0000 L CNN
F 1 "1u" H 2410 1070 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2400 1150 50  0001 C CNN
F 3 "" H 2400 1150 50  0000 C CNN
	1    2400 1150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 592A5659
P 1600 2550
F 0 "#PWR02" H 1600 2300 50  0001 C CNN
F 1 "GND" H 1600 2400 50  0000 C CNN
F 2 "" H 1600 2550 50  0000 C CNN
F 3 "" H 1600 2550 50  0000 C CNN
	1    1600 2550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 592A568F
P 1650 1350
F 0 "#PWR03" H 1650 1100 50  0001 C CNN
F 1 "GND" H 1650 1200 50  0000 C CNN
F 2 "" H 1650 1350 50  0000 C CNN
F 3 "" H 1650 1350 50  0000 C CNN
	1    1650 1350
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR04
U 1 1 592A5759
P 2400 850
F 0 "#PWR04" H 2400 700 50  0001 C CNN
F 1 "+3V3" H 2400 990 50  0000 C CNN
F 2 "" H 2400 850 50  0000 C CNN
F 3 "" H 2400 850 50  0000 C CNN
	1    2400 850 
	1    0    0    -1  
$EndComp
Text Notes 1200 2050 0    120  ~ 0
Power Regulators
$Comp
L ATSAMD21E18A-AU U3
U 1 1 592A784B
P 3450 6550
F 0 "U3" H 3300 7350 120 0000 C CNN
F 1 "ATSAMD21E18A-AU" V 3000 8400 120 0000 C CNN
F 2 "Housings_QFP:TQFP-32_7x7mm_Pitch0.8mm" H 3450 6550 120 0001 C CNN
F 3 "" H 3450 6550 120 0001 C CNN
	1    3450 6550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 592A794C
P 2200 5650
F 0 "#PWR05" H 2200 5400 50  0001 C CNN
F 1 "GND" H 2200 5500 50  0000 C CNN
F 2 "" H 2200 5650 50  0000 C CNN
F 3 "" H 2200 5650 50  0000 C CNN
	1    2200 5650
	1    0    0    -1  
$EndComp
$Comp
L C_Small C7
U 1 1 592A7CB2
P 1400 5550
F 0 "C7" H 1410 5620 50  0000 L CNN
F 1 "0.1u" H 1410 5470 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 1400 5550 50  0001 C CNN
F 3 "" H 1400 5550 50  0000 C CNN
	1    1400 5550
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR06
U 1 1 592A7D9A
P 1400 4900
F 0 "#PWR06" H 1400 4750 50  0001 C CNN
F 1 "+3V3" H 1400 5040 50  0000 C CNN
F 2 "" H 1400 4900 50  0000 C CNN
F 3 "" H 1400 4900 50  0000 C CNN
	1    1400 4900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 592A7E37
P 1400 5800
F 0 "#PWR07" H 1400 5550 50  0001 C CNN
F 1 "GND" H 1400 5650 50  0000 C CNN
F 2 "" H 1400 5800 50  0000 C CNN
F 3 "" H 1400 5800 50  0000 C CNN
	1    1400 5800
	1    0    0    -1  
$EndComp
$Comp
L C_Small C9
U 1 1 592A80B4
P 3950 5550
F 0 "C9" H 3960 5620 50  0000 L CNN
F 1 "0.1u" H 3960 5470 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3950 5550 50  0001 C CNN
F 3 "" H 3950 5550 50  0000 C CNN
	1    3950 5550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 592A8194
P 3750 5750
F 0 "#PWR08" H 3750 5500 50  0001 C CNN
F 1 "GND" H 3750 5600 50  0000 C CNN
F 2 "" H 3750 5750 50  0000 C CNN
F 3 "" H 3750 5750 50  0000 C CNN
	1    3750 5750
	1    0    0    -1  
$EndComp
$Comp
L C_Small C10
U 1 1 592A8296
P 4200 5550
F 0 "C10" H 4210 5620 50  0000 L CNN
F 1 "0.1u" H 4210 5470 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 4200 5550 50  0001 C CNN
F 3 "" H 4200 5550 50  0000 C CNN
	1    4200 5550
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR09
U 1 1 592A8397
P 4200 5100
F 0 "#PWR09" H 4200 4950 50  0001 C CNN
F 1 "+3V3" H 4200 5240 50  0000 C CNN
F 2 "" H 4200 5100 50  0000 C CNN
F 3 "" H 4200 5100 50  0000 C CNN
	1    4200 5100
	1    0    0    -1  
$EndComp
Text GLabel 3650 5250 2    60   Input ~ 0
~RESET
Text GLabel 1750 6600 2    60   Output ~ 0
~RESET
$Comp
L +3V3 #PWR010
U 1 1 592A8A6B
P 1650 6150
F 0 "#PWR010" H 1650 6000 50  0001 C CNN
F 1 "+3V3" H 1650 6290 50  0000 C CNN
F 2 "" H 1650 6150 50  0000 C CNN
F 3 "" H 1650 6150 50  0000 C CNN
	1    1650 6150
	1    0    0    -1  
$EndComp
$Comp
L R_Small R6
U 1 1 592A8AA5
P 1650 6300
F 0 "R6" H 1680 6320 50  0000 L CNN
F 1 "10k" H 1680 6260 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 1650 6300 50  0001 C CNN
F 3 "" H 1650 6300 50  0000 C CNN
	1    1650 6300
	1    0    0    -1  
$EndComp
$Comp
L C_Small C11
U 1 1 592A8B58
P 4450 5550
F 0 "C11" H 4460 5620 50  0000 L CNN
F 1 "10u" H 4460 5470 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 4450 5550 50  0001 C CNN
F 3 "" H 4450 5550 50  0000 C CNN
	1    4450 5550
	1    0    0    -1  
$EndComp
$Comp
L C_Small C8
U 1 1 592A90F9
P 1650 6800
F 0 "C8" H 1660 6870 50  0000 L CNN
F 1 "0.1u" H 1660 6720 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 1650 6800 50  0001 C CNN
F 3 "" H 1650 6800 50  0000 C CNN
	1    1650 6800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 592A9161
P 1650 7000
F 0 "#PWR011" H 1650 6750 50  0001 C CNN
F 1 "GND" H 1650 6850 50  0000 C CNN
F 2 "" H 1650 7000 50  0000 C CNN
F 3 "" H 1650 7000 50  0000 C CNN
	1    1650 7000
	1    0    0    -1  
$EndComp
$Comp
L R_Small R5
U 1 1 592A9281
P 1400 6600
F 0 "R5" H 1430 6620 50  0000 L CNN
F 1 "330" H 1430 6560 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 1400 6600 50  0001 C CNN
F 3 "" H 1400 6600 50  0000 C CNN
	1    1400 6600
	0    1    1    0   
$EndComp
$Comp
L SW_Push SW1
U 1 1 592A92F9
P 1000 6600
F 0 "SW1" H 1050 6700 50  0000 L CNN
F 1 "RESET" H 1000 6540 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_EVQP0" H 1000 6800 50  0001 C CNN
F 3 "" H 1000 6800 50  0000 C CNN
	1    1000 6600
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X05 P3
U 1 1 592A95D2
P 3000 6800
F 0 "P3" H 3000 7100 50  0000 C CNN
F 1 "CORTEX" H 3000 6500 50  0000 C CNN
F 2 "Pin_Headers2:Pin_Header_Straight_2x05_Pitch1.27mm_SMD" H 3000 5600 50  0001 C CNN
F 3 "" H 3000 5600 50  0000 C CNN
	1    3000 6800
	1    0    0    -1  
$EndComp
Text GLabel 3450 7000 2    60   Output ~ 0
~RESET
NoConn ~ 2750 7000
NoConn ~ 2750 6900
NoConn ~ 3250 6900
NoConn ~ 3250 6800
$Comp
L GND #PWR012
U 1 1 592A986B
P 2550 6950
F 0 "#PWR012" H 2550 6700 50  0001 C CNN
F 1 "GND" H 2550 6800 50  0000 C CNN
F 2 "" H 2550 6950 50  0000 C CNN
F 3 "" H 2550 6950 50  0000 C CNN
	1    2550 6950
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR013
U 1 1 592A99A6
P 2550 6500
F 0 "#PWR013" H 2550 6350 50  0001 C CNN
F 1 "+3V3" H 2550 6640 50  0000 C CNN
F 2 "" H 2550 6500 50  0000 C CNN
F 3 "" H 2550 6500 50  0000 C CNN
	1    2550 6500
	1    0    0    -1  
$EndComp
Text GLabel 3450 6600 2    60   Output ~ 0
SWDIO
Text GLabel 3450 6800 2    60   Output ~ 0
SWCLK
Text GLabel 3750 3950 2    60   Input ~ 0
SWDIO
Text GLabel 3750 4050 2    60   Input ~ 0
SWCLK
Text GLabel 3750 4450 2    60   BiDi ~ 0
USBD-
Text GLabel 3750 4350 2    60   BiDi ~ 0
USBD+
$Comp
L USB_OTG-RESCUE-dc25badge P2
U 1 1 592AA55B
P 950 3950
F 0 "P2" H 1275 3825 50  0000 C CNN
F 1 "USB_OTG" H 950 4150 50  0000 C CNN
F 2 "Badge_Parts:Amphenol_10118192" V 900 3850 50  0001 C CNN
F 3 "" V 900 3850 50  0000 C CNN
	1    950  3950
	0    -1   1    0   
$EndComp
$Comp
L GND #PWR014
U 1 1 592AA720
P 1250 4250
F 0 "#PWR014" H 1250 4000 50  0001 C CNN
F 1 "GND" H 1250 4100 50  0000 C CNN
F 2 "" H 1250 4250 50  0000 C CNN
F 3 "" H 1250 4250 50  0000 C CNN
	1    1250 4250
	1    0    0    -1  
$EndComp
NoConn ~ 1250 4050
NoConn ~ 1250 3750
Text GLabel 1250 3850 2    60   BiDi ~ 0
USBD-
Text GLabel 1250 3950 2    60   BiDi ~ 0
USBD+
$Comp
L 74AHCT125 U4
U 2 1 592AAF69
P 6750 4600
F 0 "U4" H 6750 4700 50  0000 L BNN
F 1 "74AHCT125" H 6800 4450 50  0000 L TNN
F 2 "SMD_Packages:SOIC-14_N" H 6750 4600 50  0001 C CNN
F 3 "" H 6750 4600 50  0000 C CNN
	2    6750 4600
	1    0    0    -1  
$EndComp
$Comp
L TEST_1P W2
U 1 1 592AB569
P 2700 850
F 0 "W2" H 2700 1120 50  0000 C CNN
F 1 "3v3" H 2700 1050 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Big" H 2900 850 50  0001 C CNN
F 3 "" H 2900 850 50  0000 C CNN
	1    2700 850 
	1    0    0    -1  
$EndComp
$Comp
L TEST_1P W3
U 1 1 592AB697
P 5400 1950
F 0 "W3" H 5400 2220 50  0000 C CNN
F 1 "5v" H 5400 2150 50  0000 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Big" H 5600 1950 50  0001 C CNN
F 3 "" H 5600 1950 50  0000 C CNN
	1    5400 1950
	1    0    0    -1  
$EndComp
Text GLabel 7700 4600 2    60   Output ~ 0
SPI_CLK
Text GLabel 7700 5300 2    60   Output ~ 0
SPI_MOSI
Wire Wire Line
	2400 1350 2400 1250
Wire Wire Line
	1200 1350 2400 1350
Wire Wire Line
	1200 850  1200 1050
Connection ~ 1200 950 
Wire Wire Line
	1200 1250 1200 1350
Wire Wire Line
	1650 1350 1650 1250
Wire Wire Line
	2400 850  2400 1050
Wire Wire Line
	2150 850  2700 850 
Connection ~ 2400 850 
Wire Wire Line
	950  850  950  2400
Wire Wire Line
	700  850  1200 850 
Connection ~ 1200 850 
Connection ~ 950  1750
Wire Notes Line
	6200 2800 6200 500 
Wire Wire Line
	3650 5450 3750 5450
Wire Wire Line
	3750 5450 3750 5750
Wire Wire Line
	2300 5450 2200 5450
Wire Wire Line
	2200 5450 2200 5650
Wire Wire Line
	2300 5350 1400 5350
Wire Wire Line
	1400 4900 1400 5450
Connection ~ 1400 5350
Wire Wire Line
	1400 5800 1400 5650
Wire Wire Line
	3650 5350 3950 5350
Wire Wire Line
	3950 5350 3950 5450
Wire Wire Line
	3750 5750 4450 5750
Wire Wire Line
	3950 5750 3950 5650
Wire Wire Line
	3650 5150 4450 5150
Wire Wire Line
	4200 5100 4200 5450
Wire Wire Line
	4200 5750 4200 5650
Connection ~ 3950 5750
Connection ~ 4200 5150
Wire Wire Line
	4450 5150 4450 5450
Wire Wire Line
	4450 5750 4450 5650
Connection ~ 4200 5750
Wire Wire Line
	1650 6150 1650 6200
Wire Wire Line
	1650 6400 1650 6700
Wire Wire Line
	1500 6600 1750 6600
Connection ~ 1650 6600
Wire Wire Line
	1650 6900 1650 7000
Wire Wire Line
	1200 6600 1300 6600
Wire Wire Line
	800  6600 800  6950
Wire Wire Line
	800  6950 1650 6950
Connection ~ 1650 6950
Wire Wire Line
	3250 7000 3450 7000
Wire Wire Line
	2750 6800 2550 6800
Wire Wire Line
	2550 6700 2550 6950
Wire Wire Line
	2750 6700 2550 6700
Connection ~ 2550 6800
Wire Wire Line
	2550 6500 2550 6600
Wire Wire Line
	2550 6600 2750 6600
Wire Wire Line
	3450 6800 3400 6800
Wire Wire Line
	3400 6800 3400 6700
Wire Wire Line
	3400 6700 3250 6700
Wire Wire Line
	3250 6600 3450 6600
Wire Wire Line
	1250 4250 1250 4150
$Comp
L 74AHCT125 U4
U 3 1 592AD3D9
P 4700 6400
F 0 "U4" H 4700 6500 50  0000 L BNN
F 1 "74AHCT125" H 4750 6250 50  0000 L TNN
F 2 "SMD_Packages:SOIC-14_N" H 4700 6400 50  0001 C CNN
F 3 "" H 4700 6400 50  0000 C CNN
	3    4700 6400
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG015
U 1 1 592AD95C
P 1150 1750
F 0 "#FLG015" H 1150 1845 50  0001 C CNN
F 1 "PWR_FLAG" H 1150 1930 50  0000 C CNN
F 2 "" H 1150 1750 50  0000 C CNN
F 3 "" H 1150 1750 50  0000 C CNN
	1    1150 1750
	1    0    0    -1  
$EndComp
Text Label 1450 1750 2    60   ~ 0
VBAT
$Comp
L 74AHCT125 U4
U 4 1 592AE1D6
P 4700 7100
F 0 "U4" H 4700 7200 50  0000 L BNN
F 1 "74AHCT125" H 4750 6950 50  0000 L TNN
F 2 "SMD_Packages:SOIC-14_N" H 4700 7100 50  0001 C CNN
F 3 "" H 4700 7100 50  0000 C CNN
	4    4700 7100
	1    0    0    1   
$EndComp
Wire Wire Line
	4700 6700 4700 6800
$Comp
L +5V #PWR016
U 1 1 592AE3BE
P 5250 6750
F 0 "#PWR016" H 5250 6600 50  0001 C CNN
F 1 "+5V" H 5250 6890 50  0000 C CNN
F 2 "" H 5250 6750 50  0000 C CNN
F 3 "" H 5250 6750 50  0000 C CNN
	1    5250 6750
	1    0    0    -1  
$EndComp
NoConn ~ 5150 6400
NoConn ~ 5150 7100
Wire Wire Line
	4700 6750 5250 6750
Connection ~ 4700 6750
Wire Wire Line
	4250 6400 4250 7200
$Comp
L GND #PWR017
U 1 1 592AE5B3
P 4250 7200
F 0 "#PWR017" H 4250 6950 50  0001 C CNN
F 1 "GND" H 4250 7050 50  0000 C CNN
F 2 "" H 4250 7200 50  0000 C CNN
F 3 "" H 4250 7200 50  0000 C CNN
	1    4250 7200
	1    0    0    -1  
$EndComp
Connection ~ 4250 7100
Text GLabel 2200 4750 0    60   Output ~ 0
TXD
Text GLabel 2200 4850 0    60   Input ~ 0
RXD
Wire Wire Line
	2200 4750 2300 4750
Wire Wire Line
	2300 4850 2200 4850
NoConn ~ 3650 4550
Text GLabel 1150 3300 2    60   Input ~ 0
TXD
Text GLabel 1150 3400 2    60   Output ~ 0
RXD
Wire Wire Line
	1150 3400 1050 3400
Wire Wire Line
	1050 3300 1150 3300
$Comp
L Crystal_Small Y1
U 1 1 592B07B2
P 2350 3250
F 0 "Y1" H 2350 3350 50  0000 C CNN
F 1 "32.768k" H 2350 3150 50  0000 C CNN
F 2 "Crystals:Crystal_SMD_G8" H 2350 3250 50  0001 C CNN
F 3 "" H 2350 3250 50  0000 C CNN
	1    2350 3250
	-1   0    0    1   
$EndComp
$Comp
L C_Small C13
U 1 1 592B0AEE
P 2550 3400
F 0 "C13" H 2560 3470 50  0000 L CNN
F 1 "22pF" H 2560 3320 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2550 3400 50  0001 C CNN
F 3 "" H 2550 3400 50  0000 C CNN
	1    2550 3400
	1    0    0    -1  
$EndComp
$Comp
L C_Small C12
U 1 1 592B0B76
P 2150 3400
F 0 "C12" H 2160 3470 50  0000 L CNN
F 1 "22pF" H 2160 3320 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2150 3400 50  0001 C CNN
F 3 "" H 2150 3400 50  0000 C CNN
	1    2150 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 3300 2550 3250
Wire Wire Line
	2450 3250 2700 3250
Wire Wire Line
	2000 3250 2250 3250
Wire Wire Line
	2150 3250 2150 3300
Text GLabel 2700 3250 2    60   Output ~ 0
XIN32
Text GLabel 2000 3250 0    60   Input ~ 0
XOUT32
Connection ~ 2550 3250
Connection ~ 2150 3250
$Comp
L GND #PWR018
U 1 1 592B1083
P 2350 3600
F 0 "#PWR018" H 2350 3350 50  0001 C CNN
F 1 "GND" H 2350 3450 50  0000 C CNN
F 2 "" H 2350 3600 50  0000 C CNN
F 3 "" H 2350 3600 50  0000 C CNN
	1    2350 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 3500 2150 3600
Wire Wire Line
	2150 3600 2550 3600
Wire Wire Line
	2550 3600 2550 3500
Connection ~ 2350 3600
NoConn ~ 2300 5150
NoConn ~ 2300 5250
Text GLabel 2200 3950 0    60   Input ~ 0
XIN32
Text GLabel 2200 4050 0    60   Output ~ 0
XOUT32
Wire Wire Line
	2300 3950 2200 3950
Wire Wire Line
	2200 4050 2300 4050
Connection ~ 1150 1750
Text Notes 3850 3200 0    120  ~ 0
Control
$Sheet
S 8050 1800 800  550 
U 592B4AC3
F0 "LEDs" 120
F1 "LEDs.sch" 120
$EndSheet
NoConn ~ 2300 4150
NoConn ~ 2300 4250
NoConn ~ 2300 4950
NoConn ~ 2300 5050
Text GLabel 2200 4550 0    60   Input ~ 0
MODE
$Comp
L SW_Push SW3
U 1 1 592B9DF2
P 6000 3550
F 0 "SW3" H 6050 3650 50  0000 L CNN
F 1 "MODE" H 6000 3490 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_EVQP0" H 6000 3750 50  0001 C CNN
F 3 "" H 6000 3750 50  0000 C CNN
	1    6000 3550
	1    0    0    -1  
$EndComp
Wire Notes Line
	500  2800 7000 2800
Text GLabel 5700 3550 0    60   Output ~ 0
MODE
Wire Wire Line
	5700 3550 5800 3550
$Comp
L GND #PWR019
U 1 1 592BA362
P 6300 3900
F 0 "#PWR019" H 6300 3650 50  0001 C CNN
F 1 "GND" H 6300 3750 50  0000 C CNN
F 2 "" H 6300 3900 50  0000 C CNN
F 3 "" H 6300 3900 50  0000 C CNN
	1    6300 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3550 6300 3550
Connection ~ 6300 3550
Text GLabel 3750 5050 2    60   Output ~ 0
MOSI3
Text GLabel 3750 4950 2    60   Output ~ 0
SCLK3
Wire Wire Line
	3750 5050 3650 5050
Text GLabel 6100 4600 0    60   Input ~ 0
SCLK3
Text GLabel 6100 5300 0    60   Input ~ 0
MOSI3
Wire Wire Line
	6300 5300 6100 5300
Wire Wire Line
	6300 4600 6100 4600
Text GLabel 2200 4650 0    60   Input ~ 0
BRIGHT
Wire Wire Line
	3750 3950 3650 3950
Wire Wire Line
	3650 4050 3750 4050
Wire Wire Line
	3750 4350 3650 4350
Wire Wire Line
	3650 4450 3750 4450
$Comp
L SW_Push SW4
U 1 1 592BCAF0
P 6000 3800
F 0 "SW4" H 6050 3900 50  0000 L CNN
F 1 "BRIGHT" H 6000 3740 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_EVQP0" H 6000 4000 50  0001 C CNN
F 3 "" H 6000 4000 50  0000 C CNN
	1    6000 3800
	1    0    0    -1  
$EndComp
Text GLabel 5700 3800 0    60   Output ~ 0
BRIGHT
Wire Wire Line
	5800 3800 5700 3800
Wire Wire Line
	6300 3800 6200 3800
Connection ~ 6300 3800
$Comp
L TPS61232 U2
U 1 1 592C521F
P 4150 2400
F 0 "U2" H 4350 2400 60  0000 C CNN
F 1 "TPS61232" H 4150 3200 60  0000 C CNN
F 2 "Badge_Parts:PSON-10P" H 4150 2400 60  0001 C CNN
F 3 "" H 4150 2400 60  0001 C CNN
	1    4150 2400
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR020
U 1 1 592C536E
P 4150 2600
F 0 "#PWR020" H 4150 2350 50  0001 C CNN
F 1 "GND" H 4150 2450 50  0000 C CNN
F 2 "" H 4150 2600 50  0000 C CNN
F 3 "" H 4150 2600 50  0000 C CNN
	1    4150 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 2550 4150 2600
$Comp
L C_Small C5
U 1 1 592C545C
P 3600 2300
F 0 "C5" H 3610 2370 50  0000 L CNN
F 1 "0.1u" H 3610 2220 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3600 2300 50  0001 C CNN
F 3 "" H 3600 2300 50  0000 C CNN
	1    3600 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  1750 3700 1750
Connection ~ 4150 2550
Wire Wire Line
	2850 2550 5900 2550
Wire Wire Line
	3600 2550 3600 2400
Wire Wire Line
	3600 2200 3600 2150
Wire Wire Line
	3600 2150 3700 2150
$Comp
L L_Core_Ferrite L1
U 1 1 592C5BDB
P 4150 1400
F 0 "L1" V 4100 1400 50  0000 C CNN
F 1 "1uH" V 4260 1400 50  0000 C CNN
F 2 "Badge_Parts:Inductor_6.5x6" H 4150 1400 50  0001 C CNN
F 3 "" H 4150 1400 50  0000 C CNN
	1    4150 1400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4700 1850 4600 1850
Wire Wire Line
	4700 1400 4700 1850
Wire Wire Line
	4700 1400 4300 1400
Wire Wire Line
	4600 1750 4700 1750
Connection ~ 4700 1750
Wire Wire Line
	4000 1400 3600 1400
Wire Wire Line
	3600 1400 3600 1850
Connection ~ 3600 1750
Connection ~ 3600 2550
NoConn ~ 3700 1950
$Comp
L +5V #PWR021
U 1 1 592C61C0
P 3500 2050
F 0 "#PWR021" H 3500 1900 50  0001 C CNN
F 1 "+5V" H 3500 2190 50  0000 C CNN
F 2 "" H 3500 2050 50  0000 C CNN
F 3 "" H 3500 2050 50  0000 C CNN
	1    3500 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 2050 3500 2050
NoConn ~ 4600 2150
$Comp
L C_Small C4
U 1 1 592C62F3
P 2850 2300
F 0 "C4" H 2860 2370 50  0000 L CNN
F 1 "22u" H 2860 2220 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2850 2300 50  0001 C CNN
F 3 "" H 2850 2300 50  0000 C CNN
	1    2850 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 2200 2850 1750
Connection ~ 2850 1750
Wire Wire Line
	2850 2400 2850 2550
$Comp
L C_Small C6
U 1 1 592C6FCA
P 4900 2300
F 0 "C6" H 4910 2370 50  0000 L CNN
F 1 "22u" H 4910 2220 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 4900 2300 50  0001 C CNN
F 3 "" H 4900 2300 50  0000 C CNN
	1    4900 2300
	1    0    0    -1  
$EndComp
$Comp
L C_Small C14
U 1 1 592C708E
P 5150 2300
F 0 "C14" H 5160 2370 50  0000 L CNN
F 1 "22u" H 5160 2220 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5150 2300 50  0001 C CNN
F 3 "" H 5150 2300 50  0000 C CNN
	1    5150 2300
	1    0    0    -1  
$EndComp
$Comp
L C_Small C27
U 1 1 592C7169
P 5400 2300
F 0 "C27" H 5410 2370 50  0000 L CNN
F 1 "22u" H 5410 2220 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5400 2300 50  0001 C CNN
F 3 "" H 5400 2300 50  0000 C CNN
	1    5400 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 2550 5400 2400
Wire Wire Line
	5150 2400 5150 2550
Connection ~ 5150 2550
Wire Wire Line
	4900 2400 4900 2550
Connection ~ 4900 2550
Wire Wire Line
	5400 1950 5400 2200
Wire Wire Line
	4600 2050 4700 2050
Wire Wire Line
	4700 2050 4700 1950
Connection ~ 4700 1950
Wire Wire Line
	4900 1950 4900 2200
Connection ~ 4900 1950
Wire Wire Line
	5150 1950 5150 2200
Connection ~ 5150 1950
Connection ~ 5400 1950
NoConn ~ 3650 4150
NoConn ~ 3650 4650
Wire Wire Line
	2300 4550 2200 4550
Wire Wire Line
	2300 4650 2200 4650
NoConn ~ 1050 3400
NoConn ~ 1050 3300
$Comp
L GND #PWR022
U 1 1 592CB85E
P 850 4400
F 0 "#PWR022" H 850 4150 50  0001 C CNN
F 1 "GND" H 850 4250 50  0000 C CNN
F 2 "" H 850 4400 50  0000 C CNN
F 3 "" H 850 4400 50  0000 C CNN
	1    850  4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  4400 850  4350
NoConn ~ 3650 4250
Wire Wire Line
	3750 4950 3650 4950
Wire Wire Line
	3600 1850 3700 1850
NoConn ~ 2300 4350
Wire Wire Line
	6300 3550 6300 3900
NoConn ~ 2300 4450
$Comp
L 74AHCT125 U4
U 1 1 592AB1CD
P 6750 5300
F 0 "U4" H 6750 5400 50  0000 L BNN
F 1 "74AHCT125" H 6800 5150 50  0000 L TNN
F 2 "SMD_Packages:SOIC-14_N" H 6750 5300 50  0001 C CNN
F 3 "" H 6750 5300 50  0000 C CNN
	1    6750 5300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR023
U 1 1 59345803
P 6750 4900
F 0 "#PWR023" H 6750 4650 50  0001 C CNN
F 1 "GND" H 6750 4750 50  0000 C CNN
F 2 "" H 6750 4900 50  0000 C CNN
F 3 "" H 6750 4900 50  0000 C CNN
	1    6750 4900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR024
U 1 1 5934585D
P 6750 5600
F 0 "#PWR024" H 6750 5350 50  0001 C CNN
F 1 "GND" H 6750 5450 50  0000 C CNN
F 2 "" H 6750 5600 50  0000 C CNN
F 3 "" H 6750 5600 50  0000 C CNN
	1    6750 5600
	1    0    0    -1  
$EndComp
NoConn ~ 3650 4750
Text GLabel 3750 4850 2    60   Output ~ 0
LED_GLOBAL
Wire Wire Line
	3750 4850 3650 4850
Text GLabel 6100 6150 0    60   Input ~ 0
LED_GLOBAL
$Comp
L R_Small R1
U 1 1 5934799E
P 6300 6150
F 0 "R1" H 6330 6170 50  0000 L CNN
F 1 "330" H 6330 6110 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 6300 6150 50  0001 C CNN
F 3 "" H 6300 6150 50  0000 C CNN
	1    6300 6150
	0    1    1    0   
$EndComp
$Comp
L LED_Small D1
U 1 1 59347A4B
P 6600 6150
F 0 "D1" H 6550 6275 50  0000 L CNN
F 1 "LED" H 6425 6050 50  0000 L CNN
F 2 "LEDs:LED_0805" V 6600 6150 50  0001 C CNN
F 3 "" V 6600 6150 50  0000 C CNN
	1    6600 6150
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR025
U 1 1 59347BAA
P 6850 6250
F 0 "#PWR025" H 6850 6000 50  0001 C CNN
F 1 "GND" H 6850 6100 50  0000 C CNN
F 2 "" H 6850 6250 50  0000 C CNN
F 3 "" H 6850 6250 50  0000 C CNN
	1    6850 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 6150 6200 6150
Wire Wire Line
	6400 6150 6500 6150
Wire Wire Line
	6700 6150 6850 6150
Wire Wire Line
	6850 6150 6850 6250
$Comp
L Q_NMOS_GSD Q1
U 1 1 5939E8DA
P 1250 2400
F 0 "Q1" V 1200 2150 50  0000 L CNN
F 1 "DMN1019USN" V 1300 1750 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 1450 2500 50  0001 C CNN
F 3 "" H 1250 2400 50  0000 C CNN
	1    1250 2400
	0    -1   1    0   
$EndComp
Wire Wire Line
	950  2500 1050 2500
Wire Wire Line
	1600 2550 1600 2500
Wire Wire Line
	1600 2500 1450 2500
Wire Wire Line
	1250 2200 950  2200
Connection ~ 950  2200
Wire Wire Line
	2150 1250 2150 1350
Connection ~ 2150 1350
Wire Wire Line
	2150 1050 2150 950 
Connection ~ 1650 1350
$Comp
L C_Small C17
U 1 1 593A4319
P 5650 2300
F 0 "C17" H 5660 2370 50  0000 L CNN
F 1 "1u" H 5660 2220 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5650 2300 50  0001 C CNN
F 3 "" H 5650 2300 50  0000 C CNN
	1    5650 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 2550 5650 2400
Connection ~ 5400 2550
Wire Wire Line
	5650 1950 5650 2200
$Comp
L R_Small R2
U 1 1 593B7147
P 7450 4600
F 0 "R2" V 7550 4650 50  0000 L CNN
F 1 "330" V 7550 4450 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 7450 4600 50  0001 C CNN
F 3 "" H 7450 4600 50  0000 C CNN
	1    7450 4600
	0    -1   -1   0   
$EndComp
$Comp
L R_Small R3
U 1 1 593B71D5
P 7450 5300
F 0 "R3" V 7550 5350 50  0000 L CNN
F 1 "330" V 7550 5150 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" H 7450 5300 50  0001 C CNN
F 3 "" H 7450 5300 50  0000 C CNN
	1    7450 5300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7700 4600 7550 4600
Wire Wire Line
	7350 4600 7200 4600
Wire Wire Line
	7200 5300 7350 5300
Wire Wire Line
	7550 5300 7700 5300
$Comp
L C_Small C23
U 1 1 593C3098
P 5900 2300
F 0 "C23" H 5950 2350 50  0000 L CNN
F 1 "NP" H 5950 2200 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5900 2300 50  0001 C CNN
F 3 "" H 5900 2300 50  0000 C CNN
	1    5900 2300
	1    0    0    -1  
$EndComp
Connection ~ 5650 1950
Connection ~ 5650 2550
Wire Wire Line
	4600 1950 5900 1950
Wire Wire Line
	5900 1950 5900 2200
Wire Wire Line
	5900 2550 5900 2400
$Comp
L C_Small C28
U 1 1 593C40FA
P 700 1500
F 0 "C28" H 710 1570 50  0000 L CNN
F 1 "NP" H 710 1420 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 700 1500 50  0001 C CNN
F 3 "" H 700 1500 50  0000 C CNN
	1    700  1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	700  1400 700  850 
Connection ~ 950  850 
$Comp
L GND #PWR026
U 1 1 593C428E
P 700 1700
F 0 "#PWR026" H 700 1450 50  0001 C CNN
F 1 "GND" H 700 1550 50  0000 C CNN
F 2 "" H 700 1700 50  0000 C CNN
F 3 "" H 700 1700 50  0000 C CNN
	1    700  1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	700  1700 700  1600
Text Label 1050 2500 1    60   ~ 0
BNEG
$Comp
L Jumper_NO_Small JP1
U 1 1 594EF10E
P 1250 2650
F 0 "JP1" H 1250 2550 50  0000 C CNN
F 1 "Jumper_NO_Small" H 1260 2590 50  0001 C CNN
F 2 "Badge_Parts:JP_SOLDER" H 1250 2650 50  0001 C CNN
F 3 "" H 1250 2650 50  0000 C CNN
	1    1250 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 2650 950  2650
Wire Wire Line
	950  2650 950  2500
Wire Wire Line
	1350 2650 1500 2650
Wire Wire Line
	1500 2650 1500 2500
Connection ~ 1500 2500
Connection ~ 950  2500
$EndSCHEMATC
