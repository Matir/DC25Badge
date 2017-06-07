EESchema Schematic File Version 2
LIBS:protospin-rescue
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
LIBS:protospin-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L +5V #PWR01
U 1 1 592CED55
P 5200 2000
F 0 "#PWR01" H 5200 1850 50  0001 C CNN
F 1 "+5V" H 5200 2140 50  0000 C CNN
F 2 "" H 5200 2000 50  0000 C CNN
F 3 "" H 5200 2000 50  0000 C CNN
	1    5200 2000
	1    0    0    -1  
$EndComp
$Comp
L MIC5305-RESCUE-protospin U1
U 1 1 592CED5B
P 1700 1600
F 0 "U1" H 1950 2050 60  0000 C CNN
F 1 "MIC5305" H 1650 2450 60  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-5" H 1700 1600 60  0001 C CNN
F 3 "" H 1700 1600 60  0001 C CNN
	1    1700 1600
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P1
U 1 1 592CED62
P 800 2500
F 0 "P1" H 800 2650 50  0000 C CNN
F 1 "BATT" V 900 2500 50  0000 C CNN
F 2 "Connectors_JST:JST_PH_S2B-PH-SM4-TB_02x2.00mm_Angled" H 800 2500 50  0001 C CNN
F 3 "" H 800 2500 50  0000 C CNN
	1    800  2500
	-1   0    0    -1  
$EndComp
$Comp
L C_Small C4
U 1 1 592CED69
P 2200 1100
F 0 "C4" H 2210 1170 50  0000 L CNN
F 1 "0.1u" H 2210 1020 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2200 1100 50  0001 C CNN
F 3 "" H 2200 1100 50  0000 C CNN
	1    2200 1100
	1    0    0    -1  
$EndComp
$Comp
L C_Small C1
U 1 1 592CED70
P 1250 1200
F 0 "C1" H 1260 1270 50  0000 L CNN
F 1 "1u" H 1260 1120 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1250 1200 50  0001 C CNN
F 3 "" H 1250 1200 50  0000 C CNN
	1    1250 1200
	1    0    0    -1  
$EndComp
$Comp
L C_Small C6
U 1 1 592CED77
P 2450 1100
F 0 "C6" H 2460 1170 50  0000 L CNN
F 1 "1u" H 2460 1020 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2450 1100 50  0001 C CNN
F 3 "" H 2450 1100 50  0000 C CNN
	1    2450 1100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 592CED7E
P 1000 2650
F 0 "#PWR02" H 1000 2400 50  0001 C CNN
F 1 "GND" H 1000 2500 50  0000 C CNN
F 2 "" H 1000 2650 50  0000 C CNN
F 3 "" H 1000 2650 50  0000 C CNN
	1    1000 2650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 592CED84
P 1700 1400
F 0 "#PWR03" H 1700 1150 50  0001 C CNN
F 1 "GND" H 1700 1250 50  0000 C CNN
F 2 "" H 1700 1400 50  0000 C CNN
F 3 "" H 1700 1400 50  0000 C CNN
	1    1700 1400
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR04
U 1 1 592CED8A
P 2450 900
F 0 "#PWR04" H 2450 750 50  0001 C CNN
F 1 "+3V3" H 2450 1040 50  0000 C CNN
F 2 "" H 2450 900 50  0000 C CNN
F 3 "" H 2450 900 50  0000 C CNN
	1    2450 900 
	1    0    0    -1  
$EndComp
Text Notes 1050 2500 0    120  ~ 0
Power Regulators
$Comp
L ATSAMD21E18A-AU U2
U 1 1 592CED91
P 3500 6600
F 0 "U2" H 3350 7400 120 0000 C CNN
F 1 "ATSAMD21E18A-AU" V 3050 8450 120 0000 C CNN
F 2 "Housings_QFP:TQFP-32_7x7mm_Pitch0.8mm" H 3500 6600 120 0001 C CNN
F 3 "" H 3500 6600 120 0001 C CNN
	1    3500 6600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 592CED98
P 2250 5700
F 0 "#PWR05" H 2250 5450 50  0001 C CNN
F 1 "GND" H 2250 5550 50  0000 C CNN
F 2 "" H 2250 5700 50  0000 C CNN
F 3 "" H 2250 5700 50  0000 C CNN
	1    2250 5700
	1    0    0    -1  
$EndComp
$Comp
L C_Small C2
U 1 1 592CED9E
P 1450 5600
F 0 "C2" H 1460 5670 50  0000 L CNN
F 1 "0.1u" H 1460 5520 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1450 5600 50  0001 C CNN
F 3 "" H 1450 5600 50  0000 C CNN
	1    1450 5600
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR06
U 1 1 592CEDA5
P 1450 4950
F 0 "#PWR06" H 1450 4800 50  0001 C CNN
F 1 "+3V3" H 1450 5090 50  0000 C CNN
F 2 "" H 1450 4950 50  0000 C CNN
F 3 "" H 1450 4950 50  0000 C CNN
	1    1450 4950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 592CEDAB
P 1450 5850
F 0 "#PWR07" H 1450 5600 50  0001 C CNN
F 1 "GND" H 1450 5700 50  0000 C CNN
F 2 "" H 1450 5850 50  0000 C CNN
F 3 "" H 1450 5850 50  0000 C CNN
	1    1450 5850
	1    0    0    -1  
$EndComp
$Comp
L C_Small C10
U 1 1 592CEDB1
P 4000 5600
F 0 "C10" H 4010 5670 50  0000 L CNN
F 1 "0.1u" H 4010 5520 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4000 5600 50  0001 C CNN
F 3 "" H 4000 5600 50  0000 C CNN
	1    4000 5600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 592CEDB8
P 3800 5800
F 0 "#PWR08" H 3800 5550 50  0001 C CNN
F 1 "GND" H 3800 5650 50  0000 C CNN
F 2 "" H 3800 5800 50  0000 C CNN
F 3 "" H 3800 5800 50  0000 C CNN
	1    3800 5800
	1    0    0    -1  
$EndComp
$Comp
L C_Small C11
U 1 1 592CEDBE
P 4250 5600
F 0 "C11" H 4260 5670 50  0000 L CNN
F 1 "0.1u" H 4260 5520 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4250 5600 50  0001 C CNN
F 3 "" H 4250 5600 50  0000 C CNN
	1    4250 5600
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR09
U 1 1 592CEDC5
P 4250 5150
F 0 "#PWR09" H 4250 5000 50  0001 C CNN
F 1 "+3V3" H 4250 5290 50  0000 C CNN
F 2 "" H 4250 5150 50  0000 C CNN
F 3 "" H 4250 5150 50  0000 C CNN
	1    4250 5150
	1    0    0    -1  
$EndComp
Text GLabel 3300 1900 0    60   Input ~ 0
5V_EN
Text GLabel 3700 5300 2    60   Input ~ 0
~RESET
Text GLabel 1800 6650 2    60   Output ~ 0
~RESET
$Comp
L +3V3 #PWR010
U 1 1 592CEDCE
P 1700 6200
F 0 "#PWR010" H 1700 6050 50  0001 C CNN
F 1 "+3V3" H 1700 6340 50  0000 C CNN
F 2 "" H 1700 6200 50  0000 C CNN
F 3 "" H 1700 6200 50  0000 C CNN
	1    1700 6200
	1    0    0    -1  
$EndComp
$Comp
L R_Small R2
U 1 1 592CEDD4
P 1700 6350
F 0 "R2" H 1730 6370 50  0000 L CNN
F 1 "10k" H 1730 6310 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 1700 6350 50  0001 C CNN
F 3 "" H 1700 6350 50  0000 C CNN
	1    1700 6350
	1    0    0    -1  
$EndComp
$Comp
L C_Small C12
U 1 1 592CEDDB
P 4500 5600
F 0 "C12" H 4510 5670 50  0000 L CNN
F 1 "10u" H 4510 5520 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4500 5600 50  0001 C CNN
F 3 "" H 4500 5600 50  0000 C CNN
	1    4500 5600
	1    0    0    -1  
$EndComp
$Comp
L C_Small C3
U 1 1 592CEDE2
P 1700 6850
F 0 "C3" H 1710 6920 50  0000 L CNN
F 1 "0.1u" H 1710 6770 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1700 6850 50  0001 C CNN
F 3 "" H 1700 6850 50  0000 C CNN
	1    1700 6850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 592CEDE9
P 1700 7050
F 0 "#PWR011" H 1700 6800 50  0001 C CNN
F 1 "GND" H 1700 6900 50  0000 C CNN
F 2 "" H 1700 7050 50  0000 C CNN
F 3 "" H 1700 7050 50  0000 C CNN
	1    1700 7050
	1    0    0    -1  
$EndComp
$Comp
L R_Small R1
U 1 1 592CEDEF
P 1450 6650
F 0 "R1" H 1480 6670 50  0000 L CNN
F 1 "330" H 1480 6610 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 1450 6650 50  0001 C CNN
F 3 "" H 1450 6650 50  0000 C CNN
	1    1450 6650
	0    1    1    0   
$EndComp
$Comp
L SW_Push SW1
U 1 1 592CEDF6
P 1050 6650
F 0 "SW1" H 1100 6750 50  0000 L CNN
F 1 "RESET" H 1050 6590 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_EVQP0" H 1050 6850 50  0001 C CNN
F 3 "" H 1050 6850 50  0000 C CNN
	1    1050 6650
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X05 P3
U 1 1 592CEDFD
P 3050 6850
F 0 "P3" H 3050 7150 50  0000 C CNN
F 1 "CONN_CORTEX" H 3050 6550 50  0000 C CNN
F 2 "Pin_Headers2:Pin_Header_Straight_2x05_Pitch1.27mm_SMD" H 3050 5650 50  0001 C CNN
F 3 "" H 3050 5650 50  0000 C CNN
	1    3050 6850
	1    0    0    -1  
$EndComp
Text GLabel 3500 7050 2    60   Output ~ 0
~RESET
NoConn ~ 2800 7050
NoConn ~ 2800 6950
NoConn ~ 3300 6950
NoConn ~ 3300 6850
$Comp
L GND #PWR012
U 1 1 592CEE09
P 2600 7000
F 0 "#PWR012" H 2600 6750 50  0001 C CNN
F 1 "GND" H 2600 6850 50  0000 C CNN
F 2 "" H 2600 7000 50  0000 C CNN
F 3 "" H 2600 7000 50  0000 C CNN
	1    2600 7000
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR013
U 1 1 592CEE0F
P 2600 6550
F 0 "#PWR013" H 2600 6400 50  0001 C CNN
F 1 "+3V3" H 2600 6690 50  0000 C CNN
F 2 "" H 2600 6550 50  0000 C CNN
F 3 "" H 2600 6550 50  0000 C CNN
	1    2600 6550
	1    0    0    -1  
$EndComp
Text GLabel 3500 6650 2    60   BiDi ~ 0
SWDIO
Text GLabel 3500 6850 2    60   Output ~ 0
SWCLK
Text GLabel 3800 4000 2    60   BiDi ~ 0
SWDIO
Text GLabel 3800 4100 2    60   Input ~ 0
SWCLK
Text GLabel 3800 4500 2    60   BiDi ~ 0
USBD-
Text GLabel 3800 4400 2    60   BiDi ~ 0
USBD+
$Comp
L USB_OTG P2
U 1 1 592CEE1B
P 1000 4000
F 0 "P2" H 1325 3875 50  0000 C CNN
F 1 "USB_OTG" H 1000 4200 50  0000 C CNN
F 2 "Badge_Parts:Amphenol_10118192" V 950 3900 50  0001 C CNN
F 3 "" V 950 3900 50  0000 C CNN
	1    1000 4000
	0    -1   1    0   
$EndComp
$Comp
L GND #PWR014
U 1 1 592CEE22
P 1300 4300
F 0 "#PWR014" H 1300 4050 50  0001 C CNN
F 1 "GND" H 1300 4150 50  0000 C CNN
F 2 "" H 1300 4300 50  0000 C CNN
F 3 "" H 1300 4300 50  0000 C CNN
	1    1300 4300
	1    0    0    -1  
$EndComp
NoConn ~ 1300 4100
NoConn ~ 1300 3800
Text GLabel 1300 3900 2    60   BiDi ~ 0
USBD-
Text GLabel 1300 4000 2    60   BiDi ~ 0
USBD+
$Comp
L 74AHCT125 U4
U 3 1 592CEE2C
P 6800 4650
F 0 "U4" H 6800 4750 50  0000 L BNN
F 1 "74AHCT125" H 6850 4500 50  0000 L TNN
F 2 "SMD_Packages:SOIC-14_N" H 6800 4650 50  0001 C CNN
F 3 "" H 6800 4650 50  0000 C CNN
	3    6800 4650
	1    0    0    -1  
$EndComp
$Comp
L 74AHCT125 U4
U 4 1 592CEE33
P 6800 5150
F 0 "U4" H 6800 5250 50  0000 L BNN
F 1 "74AHCT125" H 6850 5000 50  0000 L TNN
F 2 "SMD_Packages:SOIC-14_N" H 6800 5150 50  0001 C CNN
F 3 "" H 6800 5150 50  0000 C CNN
	4    6800 5150
	1    0    0    -1  
$EndComp
Text GLabel 7250 4650 2    60   Output ~ 0
SPI_CLK
Text GLabel 7250 5150 2    60   Output ~ 0
SPI_MOSI
NoConn ~ 3700 4800
$Comp
L R_Small R4
U 1 1 592CEE52
P 7900 5100
F 0 "R4" H 7930 5120 50  0000 L CNN
F 1 "10k" H 7930 5060 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 7900 5100 50  0001 C CNN
F 3 "" H 7900 5100 50  0000 C CNN
	1    7900 5100
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR015
U 1 1 592CEE59
P 7900 4900
F 0 "#PWR015" H 7900 4750 50  0001 C CNN
F 1 "+3V3" H 7900 5040 50  0000 C CNN
F 2 "" H 7900 4900 50  0000 C CNN
F 3 "" H 7900 4900 50  0000 C CNN
	1    7900 4900
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG016
U 1 1 592CEE5F
P 5350 900
F 0 "#FLG016" H 5350 995 50  0001 C CNN
F 1 "PWR_FLAG" H 5350 1080 50  0000 C CNN
F 2 "" H 5350 900 50  0000 C CNN
F 3 "" H 5350 900 50  0000 C CNN
	1    5350 900 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR017
U 1 1 592CEE65
P 5350 1050
F 0 "#PWR017" H 5350 800 50  0001 C CNN
F 1 "GND" H 5350 900 50  0000 C CNN
F 2 "" H 5350 1050 50  0000 C CNN
F 3 "" H 5350 1050 50  0000 C CNN
	1    5350 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 1300 2450 1200
Wire Wire Line
	1700 1300 2450 1300
Wire Wire Line
	2200 1200 2200 1300
Connection ~ 2200 1300
Wire Wire Line
	1250 900  1250 1100
Connection ~ 1250 1000
Wire Wire Line
	1250 1300 1250 1400
Wire Wire Line
	1250 1400 1700 1400
Wire Wire Line
	1700 1400 1700 1300
Wire Wire Line
	2450 1000 2450 900 
Connection ~ 2450 900 
Wire Wire Line
	1000 900  1000 2450
Wire Wire Line
	1000 900  1250 900 
Connection ~ 1250 900 
Connection ~ 1000 1800
Wire Notes Line
	6250 2850 6250 550 
Wire Wire Line
	3700 5500 3800 5500
Wire Wire Line
	3800 5500 3800 5800
Wire Wire Line
	2350 5500 2250 5500
Wire Wire Line
	2250 5500 2250 5700
Wire Wire Line
	2350 5400 1450 5400
Wire Wire Line
	1450 4950 1450 5500
Connection ~ 1450 5400
Wire Wire Line
	1450 5850 1450 5700
Wire Wire Line
	3700 5400 4000 5400
Wire Wire Line
	4000 5400 4000 5500
Wire Wire Line
	3800 5800 4500 5800
Wire Wire Line
	4000 5800 4000 5700
Wire Wire Line
	3700 5200 4500 5200
Wire Wire Line
	4250 5150 4250 5500
Wire Wire Line
	4250 5800 4250 5700
Connection ~ 4000 5800
Connection ~ 4250 5200
Wire Wire Line
	4500 5200 4500 5500
Wire Wire Line
	4500 5800 4500 5700
Connection ~ 4250 5800
Wire Wire Line
	1700 6200 1700 6250
Wire Wire Line
	1700 6450 1700 6750
Wire Wire Line
	1550 6650 1800 6650
Connection ~ 1700 6650
Wire Wire Line
	1700 6950 1700 7050
Wire Wire Line
	1250 6650 1350 6650
Wire Wire Line
	850  6650 850  7000
Wire Wire Line
	850  7000 1700 7000
Connection ~ 1700 7000
Wire Wire Line
	3300 7050 3500 7050
Wire Wire Line
	2800 6850 2600 6850
Wire Wire Line
	2600 6750 2600 7000
Wire Wire Line
	2800 6750 2600 6750
Connection ~ 2600 6850
Wire Wire Line
	2600 6550 2600 6650
Wire Wire Line
	2600 6650 2800 6650
Wire Wire Line
	3500 6850 3450 6850
Wire Wire Line
	3450 6850 3450 6750
Wire Wire Line
	3450 6750 3300 6750
Wire Wire Line
	3300 6650 3500 6650
Wire Wire Line
	1300 4300 1300 4200
Wire Wire Line
	6150 5450 7900 5450
Wire Wire Line
	7900 5450 7900 5200
Connection ~ 6800 5450
Wire Wire Line
	7900 4900 7900 5000
Wire Wire Line
	5350 900  5350 1050
Connection ~ 5350 950 
$Comp
L 74AHCT125 U4
U 1 1 592CEEAC
P 4750 6450
F 0 "U4" H 4750 6550 50  0000 L BNN
F 1 "74AHCT125" H 4800 6300 50  0000 L TNN
F 2 "SMD_Packages:SOIC-14_N" H 4750 6450 50  0001 C CNN
F 3 "" H 4750 6450 50  0000 C CNN
	1    4750 6450
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG018
U 1 1 592CEEB3
P 2200 900
F 0 "#FLG018" H 2200 995 50  0001 C CNN
F 1 "PWR_FLAG" H 2200 1080 50  0000 C CNN
F 2 "" H 2200 900 50  0000 C CNN
F 3 "" H 2200 900 50  0000 C CNN
	1    2200 900 
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG019
U 1 1 592CEEB9
P 1200 1800
F 0 "#FLG019" H 1200 1895 50  0001 C CNN
F 1 "PWR_FLAG" H 1200 1980 50  0000 C CNN
F 2 "" H 1200 1800 50  0000 C CNN
F 3 "" H 1200 1800 50  0000 C CNN
	1    1200 1800
	1    0    0    -1  
$EndComp
Text Label 1500 1800 2    60   ~ 0
VBAT
$Comp
L 74AHCT125 U4
U 2 1 592CEEC0
P 4750 7150
F 0 "U4" H 4750 7250 50  0000 L BNN
F 1 "74AHCT125" H 4800 7000 50  0000 L TNN
F 2 "SMD_Packages:SOIC-14_N" H 4750 7150 50  0001 C CNN
F 3 "" H 4750 7150 50  0000 C CNN
	2    4750 7150
	1    0    0    1   
$EndComp
Wire Wire Line
	4750 6750 4750 6850
$Comp
L +5V #PWR020
U 1 1 592CEEC8
P 5300 6800
F 0 "#PWR020" H 5300 6650 50  0001 C CNN
F 1 "+5V" H 5300 6940 50  0000 C CNN
F 2 "" H 5300 6800 50  0000 C CNN
F 3 "" H 5300 6800 50  0000 C CNN
	1    5300 6800
	1    0    0    -1  
$EndComp
NoConn ~ 5200 6450
NoConn ~ 5200 7150
Wire Wire Line
	4750 6800 5300 6800
Connection ~ 4750 6800
Wire Wire Line
	4300 6450 4300 7250
$Comp
L GND #PWR021
U 1 1 592CEED3
P 4300 7250
F 0 "#PWR021" H 4300 7000 50  0001 C CNN
F 1 "GND" H 4300 7100 50  0000 C CNN
F 2 "" H 4300 7250 50  0000 C CNN
F 3 "" H 4300 7250 50  0000 C CNN
	1    4300 7250
	1    0    0    -1  
$EndComp
Connection ~ 4300 7150
$Comp
L PWR_FLAG #FLG022
U 1 1 592CEEDA
P 1650 5400
F 0 "#FLG022" H 1650 5495 50  0001 C CNN
F 1 "PWR_FLAG" H 1650 5580 50  0000 C CNN
F 2 "" H 1650 5400 50  0000 C CNN
F 3 "" H 1650 5400 50  0000 C CNN
	1    1650 5400
	1    0    0    -1  
$EndComp
Text GLabel 2250 4800 0    60   Output ~ 0
TXD
Text GLabel 2250 4900 0    60   Input ~ 0
RXD
Wire Wire Line
	2250 4800 2350 4800
Wire Wire Line
	2350 4900 2250 4900
NoConn ~ 3700 4600
Text GLabel 3800 4300 2    60   Output ~ 0
5V_EN
$Comp
L Crystal_Small Y1
U 1 1 592CEEF1
P 2400 3300
F 0 "Y1" H 2400 3400 50  0000 C CNN
F 1 "32.768k" H 2400 3200 50  0000 C CNN
F 2 "Crystals:Crystal_SMD_G8" H 2400 3300 50  0001 C CNN
F 3 "" H 2400 3300 50  0000 C CNN
	1    2400 3300
	-1   0    0    1   
$EndComp
$Comp
L C_Small C7
U 1 1 592CEEF8
P 2600 3450
F 0 "C7" H 2610 3520 50  0000 L CNN
F 1 "22pF" H 2610 3370 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2600 3450 50  0001 C CNN
F 3 "" H 2600 3450 50  0000 C CNN
	1    2600 3450
	1    0    0    -1  
$EndComp
$Comp
L C_Small C5
U 1 1 592CEEFF
P 2200 3450
F 0 "C5" H 2210 3520 50  0000 L CNN
F 1 "22pF" H 2210 3370 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2200 3450 50  0001 C CNN
F 3 "" H 2200 3450 50  0000 C CNN
	1    2200 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 3350 2600 3300
Wire Wire Line
	2500 3300 2750 3300
Wire Wire Line
	2050 3300 2300 3300
Wire Wire Line
	2200 3300 2200 3350
Text GLabel 2750 3300 2    60   Output ~ 0
XIN32
Text GLabel 2050 3300 0    60   Input ~ 0
XOUT32
Connection ~ 2600 3300
Connection ~ 2200 3300
$Comp
L GND #PWR023
U 1 1 592CEF0E
P 2400 3650
F 0 "#PWR023" H 2400 3400 50  0001 C CNN
F 1 "GND" H 2400 3500 50  0000 C CNN
F 2 "" H 2400 3650 50  0000 C CNN
F 3 "" H 2400 3650 50  0000 C CNN
	1    2400 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 3550 2200 3650
Wire Wire Line
	2200 3650 2600 3650
Wire Wire Line
	2600 3650 2600 3550
Connection ~ 2400 3650
NoConn ~ 2350 5200
NoConn ~ 2350 5300
Text GLabel 2250 4000 0    60   Input ~ 0
XIN32
Text GLabel 2250 4100 0    60   Output ~ 0
XOUT32
Wire Wire Line
	2350 4000 2250 4000
Wire Wire Line
	2250 4100 2350 4100
Connection ~ 1650 5400
Connection ~ 1200 1800
Text Notes 3900 3250 0    120  ~ 0
Control
NoConn ~ 2350 4200
NoConn ~ 2350 4300
NoConn ~ 2350 5000
NoConn ~ 2350 5100
Text GLabel 2250 4500 0    60   Input ~ 0
SOFT_PWR
Text GLabel 2250 4600 0    60   Input ~ 0
MODE
Wire Notes Line
	550  2850 7050 2850
Text GLabel 9150 3950 0    60   Output ~ 0
MODE
Text GLabel 9150 4050 0    60   Output ~ 0
SOFT_PWR
Text GLabel 3800 5100 2    60   Output ~ 0
MOSI3
Text GLabel 3800 5000 2    60   Output ~ 0
SCLK3
Text GLabel 3800 4900 2    60   Output ~ 0
SPI_EN
Wire Wire Line
	3800 4900 3700 4900
Wire Wire Line
	3800 5000 3700 5000
Wire Wire Line
	3800 5100 3700 5100
Text GLabel 6150 4650 0    60   Input ~ 0
SCLK3
Text GLabel 6150 5150 0    60   Input ~ 0
MOSI3
Wire Wire Line
	6350 5150 6150 5150
Wire Wire Line
	6350 4650 6150 4650
Text GLabel 6150 5450 0    60   Input ~ 0
SPI_EN
Wire Wire Line
	6800 4950 6350 4950
Wire Wire Line
	6350 4950 6350 5450
Connection ~ 6350 5450
Text GLabel 2250 4700 0    60   Input ~ 0
BRIGHT
Wire Wire Line
	3800 4000 3700 4000
Wire Wire Line
	3700 4100 3800 4100
Wire Wire Line
	3800 4400 3700 4400
Wire Wire Line
	3700 4500 3800 4500
Text GLabel 9150 3850 0    60   Output ~ 0
BRIGHT
Wire Wire Line
	1000 2650 1000 2550
$Comp
L TPS61232 U3
U 1 1 592CEF63
P 4200 2450
F 0 "U3" H 4400 2450 60  0000 C CNN
F 1 "TPS61232" H 4200 3250 60  0000 C CNN
F 2 "Badge_Parts:PSON-10P" H 4200 2450 60  0001 C CNN
F 3 "" H 4200 2450 60  0001 C CNN
	1    4200 2450
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR024
U 1 1 592CEF6A
P 4200 2650
F 0 "#PWR024" H 4200 2400 50  0001 C CNN
F 1 "GND" H 4200 2500 50  0000 C CNN
F 2 "" H 4200 2650 50  0000 C CNN
F 3 "" H 4200 2650 50  0000 C CNN
	1    4200 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 2600 4200 2650
$Comp
L C_Small C9
U 1 1 592CEF71
P 3650 2350
F 0 "C9" H 3660 2420 50  0000 L CNN
F 1 "0.1u" H 3660 2270 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3650 2350 50  0001 C CNN
F 3 "" H 3650 2350 50  0000 C CNN
	1    3650 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 1800 3750 1800
Connection ~ 4200 2600
Wire Wire Line
	2900 2600 5450 2600
Wire Wire Line
	3650 2600 3650 2450
Wire Wire Line
	3650 2250 3650 2200
Wire Wire Line
	3650 2200 3750 2200
$Comp
L L_Core_Ferrite L1
U 1 1 592CEF7E
P 4200 1450
F 0 "L1" V 4150 1450 50  0000 C CNN
F 1 "L_Core_Ferrite" V 4310 1450 50  0000 C CNN
F 2 "Badge_Parts:Inductor_6.5x6" H 4200 1450 50  0001 C CNN
F 3 "" H 4200 1450 50  0000 C CNN
	1    4200 1450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4650 1900 4750 1900
Wire Wire Line
	4750 1900 4750 1450
Wire Wire Line
	4750 1450 4350 1450
Wire Wire Line
	4650 1800 4750 1800
Connection ~ 4750 1800
Wire Wire Line
	4050 1450 3650 1450
Wire Wire Line
	3650 1450 3650 1800
Connection ~ 3650 1800
$Comp
L R_Small R3
U 1 1 592CEF8D
P 3350 2350
F 0 "R3" H 3380 2370 50  0000 L CNN
F 1 "10k" H 3380 2310 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 3350 2350 50  0001 C CNN
F 3 "" H 3350 2350 50  0000 C CNN
	1    3350 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 2250 3350 1900
Connection ~ 3350 1900
Wire Wire Line
	3350 2450 3350 2600
Connection ~ 3650 2600
NoConn ~ 3750 2000
$Comp
L +5V #PWR025
U 1 1 592CEF99
P 3550 2100
F 0 "#PWR025" H 3550 1950 50  0001 C CNN
F 1 "+5V" H 3550 2240 50  0000 C CNN
F 2 "" H 3550 2100 50  0000 C CNN
F 3 "" H 3550 2100 50  0000 C CNN
	1    3550 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 2100 3550 2100
NoConn ~ 4650 2200
$Comp
L C_Small C8
U 1 1 592CEFA1
P 2900 2350
F 0 "C8" H 2910 2420 50  0000 L CNN
F 1 "22u" H 2910 2270 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2900 2350 50  0001 C CNN
F 3 "" H 2900 2350 50  0000 C CNN
	1    2900 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 2250 2900 1800
Connection ~ 2900 1800
Wire Wire Line
	3300 1900 3750 1900
Wire Wire Line
	2900 2450 2900 2600
Connection ~ 3350 2600
$Comp
L C_Small C13
U 1 1 592CEFAD
P 4950 2350
F 0 "C13" H 4960 2420 50  0000 L CNN
F 1 "22u" H 4960 2270 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4950 2350 50  0001 C CNN
F 3 "" H 4950 2350 50  0000 C CNN
	1    4950 2350
	1    0    0    -1  
$EndComp
$Comp
L C_Small C14
U 1 1 592CEFB4
P 5200 2350
F 0 "C14" H 5210 2420 50  0000 L CNN
F 1 "22u" H 5210 2270 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5200 2350 50  0001 C CNN
F 3 "" H 5200 2350 50  0000 C CNN
	1    5200 2350
	1    0    0    -1  
$EndComp
$Comp
L C_Small C15
U 1 1 592CEFBB
P 5450 2350
F 0 "C15" H 5460 2420 50  0000 L CNN
F 1 "22u" H 5460 2270 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5450 2350 50  0001 C CNN
F 3 "" H 5450 2350 50  0000 C CNN
	1    5450 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 2600 5450 2450
Wire Wire Line
	5200 2450 5200 2600
Connection ~ 5200 2600
Wire Wire Line
	4950 2450 4950 2600
Connection ~ 4950 2600
Wire Wire Line
	4650 2000 5450 2000
Wire Wire Line
	5450 2000 5450 2250
Wire Wire Line
	4650 2100 4750 2100
Wire Wire Line
	4750 2100 4750 2000
Connection ~ 4750 2000
Wire Wire Line
	4950 2250 4950 2000
Connection ~ 4950 2000
Wire Wire Line
	5200 2250 5200 2000
Connection ~ 5200 2000
Connection ~ 5450 2000
NoConn ~ 3700 4200
NoConn ~ 3700 4700
Wire Wire Line
	2250 4500 2350 4500
Wire Wire Line
	2350 4600 2250 4600
Wire Wire Line
	2350 4700 2250 4700
$Comp
L GND #PWR026
U 1 1 592CEFD9
P 900 4450
F 0 "#PWR026" H 900 4200 50  0001 C CNN
F 1 "GND" H 900 4300 50  0000 C CNN
F 2 "" H 900 4450 50  0000 C CNN
F 3 "" H 900 4450 50  0000 C CNN
	1    900  4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  4450 900  4400
NoConn ~ 2350 4400
Wire Wire Line
	3800 4300 3700 4300
$Comp
L APA102 U5
U 1 1 592CFD9F
P 7900 4100
F 0 "U5" H 7900 4450 60  0000 C CNN
F 1 "APA102" H 7550 4450 60  0000 C CNN
F 2 "Badge_Parts:APA102" H 7900 4100 120 0001 C CNN
F 3 "" H 7900 4100 120 0001 C CNN
	1    7900 4100
	1    0    0    -1  
$EndComp
$Comp
L APA102 U6
U 1 1 592CFEB0
P 8900 4100
F 0 "U6" H 8900 4450 60  0000 C CNN
F 1 "APA102" H 8550 4450 60  0000 C CNN
F 2 "Badge_Parts:APA102" H 8900 4100 120 0001 C CNN
F 3 "" H 8900 4100 120 0001 C CNN
	1    8900 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 3400 8300 3400
Wire Wire Line
	8300 3500 8150 3500
Text GLabel 7250 3400 0    60   Input ~ 0
SPI_MOSI
Text GLabel 7250 3500 0    60   Input ~ 0
SPI_CLK
Wire Wire Line
	7300 3400 7250 3400
Wire Wire Line
	7300 3500 7250 3500
$Comp
L +5V #PWR027
U 1 1 592D0EE8
P 9100 2800
F 0 "#PWR027" H 9100 2650 50  0001 C CNN
F 1 "+5V" H 9100 2940 50  0000 C CNN
F 2 "" H 9100 2800 50  0000 C CNN
F 3 "" H 9100 2800 50  0000 C CNN
	1    9100 2800
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR028
U 1 1 592D0F46
P 9100 3000
F 0 "#PWR028" H 9100 2850 50  0001 C CNN
F 1 "+3V3" H 9100 3140 50  0000 C CNN
F 2 "" H 9100 3000 50  0000 C CNN
F 3 "" H 9100 3000 50  0000 C CNN
	1    9100 3000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR029
U 1 1 592D0FA4
P 9150 4700
F 0 "#PWR029" H 9150 4450 50  0001 C CNN
F 1 "GND" H 9150 4550 50  0000 C CNN
F 2 "" H 9150 4700 50  0000 C CNN
F 3 "" H 9150 4700 50  0000 C CNN
	1    9150 4700
	1    0    0    -1  
$EndComp
Text GLabel 9150 4250 0    60   BiDi ~ 0
SWDIO
Text GLabel 9150 4150 0    60   Output ~ 0
SWCLK
Text GLabel 9150 4350 0    60   Output ~ 0
~RESET
Text GLabel 9150 4450 0    60   Input ~ 0
TXD
Text GLabel 9150 4550 0    60   Input ~ 0
RXD
$Comp
L CONN_01X16 P4
U 1 1 592D1E73
P 9900 3950
F 0 "P4" H 9900 4800 50  0000 C CNN
F 1 "CONN_01X16" V 10000 3950 50  0000 C CNN
F 2 "Pin_Headers2:Pin_Header_Straight_1x16_Pitch2.54mm_SMD_Pin1Right" H 9900 3950 50  0001 C CNN
F 3 "" H 9900 3950 50  0000 C CNN
	1    9900 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 2800 9500 2800
Wire Wire Line
	9500 2800 9500 3200
Wire Wire Line
	9100 3000 9450 3000
Wire Wire Line
	9450 3000 9450 3300
Wire Wire Line
	9450 3300 9700 3300
Wire Wire Line
	9150 3400 9700 3400
Wire Wire Line
	9150 3500 9700 3500
Wire Wire Line
	9700 4700 9150 4700
Wire Wire Line
	9200 3600 9700 3600
Wire Wire Line
	9200 3600 9200 3850
Wire Wire Line
	9200 3850 9150 3850
Wire Wire Line
	9150 3950 9250 3950
Wire Wire Line
	9250 3950 9250 3700
Wire Wire Line
	9250 3700 9700 3700
Wire Wire Line
	9300 3800 9700 3800
Wire Wire Line
	9300 3800 9300 4050
Wire Wire Line
	9300 4050 9150 4050
Wire Wire Line
	9150 4150 9350 4150
Wire Wire Line
	9350 4150 9350 3900
Wire Wire Line
	9350 3900 9700 3900
Wire Wire Line
	9400 4000 9700 4000
Wire Wire Line
	9400 4000 9400 4250
Wire Wire Line
	9400 4250 9150 4250
Wire Wire Line
	9500 3200 9700 3200
Wire Wire Line
	9700 4100 9450 4100
Wire Wire Line
	9450 4100 9450 4350
Wire Wire Line
	9450 4350 9150 4350
Wire Wire Line
	9150 4450 9500 4450
Wire Wire Line
	9500 4450 9500 4200
Wire Wire Line
	9500 4200 9700 4200
Wire Wire Line
	9700 4300 9550 4300
Wire Wire Line
	9550 4300 9550 4550
Wire Wire Line
	9550 4550 9150 4550
Wire Wire Line
	9700 4400 9700 4700
Connection ~ 9700 4600
Connection ~ 9700 4500
Wire Wire Line
	2450 900  2200 900 
$EndSCHEMATC
