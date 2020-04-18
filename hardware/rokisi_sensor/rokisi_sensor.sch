EESchema Schematic File Version 4
LIBS:rokisi_sensor-cache
EELAYER 26 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title "robotore sensor circuits"
Date ""
Rev "0.1"
Comp "https://garberas.com/"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L gp2s700hcp:GP2S700HCP U2
U 1 1 5E8A8769
P 1900 2000
F 0 "U2" H 2150 2637 60  0000 C CNN
F 1 "GP2S700HCP" H 2150 2531 60  0000 C CNN
F 2 "mylib:GP2S700HCP" H 1900 2000 60  0001 C CNN
F 3 "" H 1900 2000 60  0001 C CNN
	1    1900 2000
	-1   0    0    1   
$EndComp
$Comp
L Device:R R6
U 1 1 5E8A888A
P 2400 2775
F 0 "R6" H 2470 2821 50  0000 L CNN
F 1 "1k" H 2470 2730 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2330 2775 50  0001 C CNN
F 3 "~" H 2400 2775 50  0001 C CNN
	1    2400 2775
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5E8A8968
P 2400 3200
F 0 "#PWR0101" H 2400 2950 50  0001 C CNN
F 1 "GND" H 2405 3027 50  0000 C CNN
F 2 "" H 2400 3200 50  0001 C CNN
F 3 "" H 2400 3200 50  0001 C CNN
	1    2400 3200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5E8A8A1F
P 675 2200
F 0 "#PWR0102" H 675 1950 50  0001 C CNN
F 1 "GND" H 680 2027 50  0000 C CNN
F 2 "" H 675 2200 50  0001 C CNN
F 3 "" H 675 2200 50  0001 C CNN
	1    675  2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 2100 675  2100
Wire Wire Line
	675  2100 675  2200
$Comp
L power:+3V3 #PWR0103
U 1 1 5E8A8A5F
P 1000 2325
F 0 "#PWR0103" H 1000 2175 50  0001 C CNN
F 1 "+3V3" H 1015 2498 50  0000 C CNN
F 2 "" H 1000 2325 50  0001 C CNN
F 3 "" H 1000 2325 50  0001 C CNN
	1    1000 2325
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 2325 1000 2375
Wire Wire Line
	1000 2375 1200 2375
$Comp
L Device:R R2
U 1 1 5E8A8A9A
P 2250 1850
F 0 "R2" H 2320 1896 50  0000 L CNN
F 1 "330" H 2320 1805 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2180 1850 50  0001 C CNN
F 3 "~" H 2250 1850 50  0001 C CNN
	1    2250 1850
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0104
U 1 1 5E8A8AD6
P 2250 1600
F 0 "#PWR0104" H 2250 1450 50  0001 C CNN
F 1 "+3V3" H 2265 1773 50  0000 C CNN
F 2 "" H 2250 1600 50  0001 C CNN
F 3 "" H 2250 1600 50  0001 C CNN
	1    2250 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 1600 2250 1700
Wire Wire Line
	2250 2000 2250 2100
Wire Wire Line
	2250 2100 2100 2100
Wire Wire Line
	2100 2375 2400 2375
Wire Wire Line
	2400 2375 2400 2625
Text GLabel 2700 2375 2    50   Output ~ 0
AD0
Wire Wire Line
	2700 2375 2400 2375
Connection ~ 2400 2375
Wire Wire Line
	2400 2925 2400 3200
$Comp
L gp2s700hcp:GP2S700HCP U5
U 1 1 5E8A9101
P 2025 4350
F 0 "U5" H 2275 4987 60  0000 C CNN
F 1 "GP2S700HCP" H 2275 4881 60  0000 C CNN
F 2 "mylib:GP2S700HCP" H 2025 4350 60  0001 C CNN
F 3 "" H 2025 4350 60  0001 C CNN
	1    2025 4350
	-1   0    0    1   
$EndComp
$Comp
L Device:R R14
U 1 1 5E8A9108
P 2525 5125
F 0 "R14" H 2595 5171 50  0000 L CNN
F 1 "1k" H 2595 5080 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2455 5125 50  0001 C CNN
F 3 "~" H 2525 5125 50  0001 C CNN
	1    2525 5125
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5E8A910F
P 2525 5550
F 0 "#PWR0105" H 2525 5300 50  0001 C CNN
F 1 "GND" H 2530 5377 50  0000 C CNN
F 2 "" H 2525 5550 50  0001 C CNN
F 3 "" H 2525 5550 50  0001 C CNN
	1    2525 5550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5E8A9115
P 800 4550
F 0 "#PWR0106" H 800 4300 50  0001 C CNN
F 1 "GND" H 805 4377 50  0000 C CNN
F 2 "" H 800 4550 50  0001 C CNN
F 3 "" H 800 4550 50  0001 C CNN
	1    800  4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1325 4450 800  4450
Wire Wire Line
	800  4450 800  4550
$Comp
L power:+3V3 #PWR0107
U 1 1 5E8A911D
P 1125 4675
F 0 "#PWR0107" H 1125 4525 50  0001 C CNN
F 1 "+3V3" H 1140 4848 50  0000 C CNN
F 2 "" H 1125 4675 50  0001 C CNN
F 3 "" H 1125 4675 50  0001 C CNN
	1    1125 4675
	1    0    0    -1  
$EndComp
Wire Wire Line
	1125 4675 1125 4725
Wire Wire Line
	1125 4725 1325 4725
$Comp
L Device:R R10
U 1 1 5E8A9125
P 2375 4200
F 0 "R10" H 2445 4246 50  0000 L CNN
F 1 "330" H 2445 4155 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2305 4200 50  0001 C CNN
F 3 "~" H 2375 4200 50  0001 C CNN
	1    2375 4200
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0108
U 1 1 5E8A912C
P 2375 3950
F 0 "#PWR0108" H 2375 3800 50  0001 C CNN
F 1 "+3V3" H 2390 4123 50  0000 C CNN
F 2 "" H 2375 3950 50  0001 C CNN
F 3 "" H 2375 3950 50  0001 C CNN
	1    2375 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2375 3950 2375 4050
Wire Wire Line
	2375 4350 2375 4450
Wire Wire Line
	2375 4450 2225 4450
Wire Wire Line
	2225 4725 2525 4725
Wire Wire Line
	2525 4725 2525 4975
Text GLabel 2825 4725 2    50   Output ~ 0
AD1
Wire Wire Line
	2825 4725 2525 4725
Connection ~ 2525 4725
Wire Wire Line
	2525 5275 2525 5550
$Comp
L gp2s700hcp:GP2S700HCP U8
U 1 1 5E8A9804
P 2000 6750
F 0 "U8" H 2250 7387 60  0000 C CNN
F 1 "GP2S700HCP" H 2250 7281 60  0000 C CNN
F 2 "mylib:GP2S700HCP" H 2000 6750 60  0001 C CNN
F 3 "" H 2000 6750 60  0001 C CNN
	1    2000 6750
	-1   0    0    1   
$EndComp
$Comp
L Device:R R21
U 1 1 5E8A980B
P 2500 7525
F 0 "R21" H 2570 7571 50  0000 L CNN
F 1 "1k" H 2570 7480 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2430 7525 50  0001 C CNN
F 3 "~" H 2500 7525 50  0001 C CNN
	1    2500 7525
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5E8A9812
P 2500 7950
F 0 "#PWR0109" H 2500 7700 50  0001 C CNN
F 1 "GND" H 2505 7777 50  0000 C CNN
F 2 "" H 2500 7950 50  0001 C CNN
F 3 "" H 2500 7950 50  0001 C CNN
	1    2500 7950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 5E8A9818
P 775 6950
F 0 "#PWR0110" H 775 6700 50  0001 C CNN
F 1 "GND" H 780 6777 50  0000 C CNN
F 2 "" H 775 6950 50  0001 C CNN
F 3 "" H 775 6950 50  0001 C CNN
	1    775  6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 6850 775  6850
Wire Wire Line
	775  6850 775  6950
$Comp
L power:+3V3 #PWR0111
U 1 1 5E8A9820
P 1100 7075
F 0 "#PWR0111" H 1100 6925 50  0001 C CNN
F 1 "+3V3" H 1115 7248 50  0000 C CNN
F 2 "" H 1100 7075 50  0001 C CNN
F 3 "" H 1100 7075 50  0001 C CNN
	1    1100 7075
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 7075 1100 7125
Wire Wire Line
	1100 7125 1300 7125
$Comp
L Device:R R17
U 1 1 5E8A9828
P 2350 6600
F 0 "R17" H 2420 6646 50  0000 L CNN
F 1 "330" H 2420 6555 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2280 6600 50  0001 C CNN
F 3 "~" H 2350 6600 50  0001 C CNN
	1    2350 6600
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0112
U 1 1 5E8A982F
P 2350 6350
F 0 "#PWR0112" H 2350 6200 50  0001 C CNN
F 1 "+3V3" H 2365 6523 50  0000 C CNN
F 2 "" H 2350 6350 50  0001 C CNN
F 3 "" H 2350 6350 50  0001 C CNN
	1    2350 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 6350 2350 6450
Wire Wire Line
	2350 6750 2350 6850
Wire Wire Line
	2350 6850 2200 6850
Wire Wire Line
	2200 7125 2500 7125
Wire Wire Line
	2500 7125 2500 7375
Text GLabel 2800 7125 2    50   Output ~ 0
AD2
Wire Wire Line
	2800 7125 2500 7125
Connection ~ 2500 7125
Wire Wire Line
	2500 7675 2500 7950
$Comp
L gp2s700hcp:GP2S700HCP U13
U 1 1 5E8A983E
P 2125 9100
F 0 "U13" H 2375 9737 60  0000 C CNN
F 1 "GP2S700HCP" H 2375 9631 60  0000 C CNN
F 2 "mylib:GP2S700HCP" H 2125 9100 60  0001 C CNN
F 3 "" H 2125 9100 60  0001 C CNN
	1    2125 9100
	-1   0    0    1   
$EndComp
$Comp
L Device:R R28
U 1 1 5E8A9845
P 2625 9875
F 0 "R28" H 2695 9921 50  0000 L CNN
F 1 "1k" H 2695 9830 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2555 9875 50  0001 C CNN
F 3 "~" H 2625 9875 50  0001 C CNN
	1    2625 9875
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 5E8A984C
P 2625 10300
F 0 "#PWR0113" H 2625 10050 50  0001 C CNN
F 1 "GND" H 2630 10127 50  0000 C CNN
F 2 "" H 2625 10300 50  0001 C CNN
F 3 "" H 2625 10300 50  0001 C CNN
	1    2625 10300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 5E8A9852
P 900 9300
F 0 "#PWR0114" H 900 9050 50  0001 C CNN
F 1 "GND" H 905 9127 50  0000 C CNN
F 2 "" H 900 9300 50  0001 C CNN
F 3 "" H 900 9300 50  0001 C CNN
	1    900  9300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1425 9200 900  9200
Wire Wire Line
	900  9200 900  9300
$Comp
L power:+3V3 #PWR0115
U 1 1 5E8A985A
P 1225 9425
F 0 "#PWR0115" H 1225 9275 50  0001 C CNN
F 1 "+3V3" H 1240 9598 50  0000 C CNN
F 2 "" H 1225 9425 50  0001 C CNN
F 3 "" H 1225 9425 50  0001 C CNN
	1    1225 9425
	1    0    0    -1  
$EndComp
Wire Wire Line
	1225 9425 1225 9475
Wire Wire Line
	1225 9475 1425 9475
$Comp
L Device:R R25
U 1 1 5E8A9862
P 2475 8950
F 0 "R25" H 2545 8996 50  0000 L CNN
F 1 "330" H 2545 8905 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2405 8950 50  0001 C CNN
F 3 "~" H 2475 8950 50  0001 C CNN
	1    2475 8950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0116
U 1 1 5E8A9869
P 2475 8700
F 0 "#PWR0116" H 2475 8550 50  0001 C CNN
F 1 "+3V3" H 2490 8873 50  0000 C CNN
F 2 "" H 2475 8700 50  0001 C CNN
F 3 "" H 2475 8700 50  0001 C CNN
	1    2475 8700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2475 8700 2475 8800
Wire Wire Line
	2475 9100 2475 9200
Wire Wire Line
	2475 9200 2325 9200
Wire Wire Line
	2325 9475 2625 9475
Wire Wire Line
	2625 9475 2625 9725
Text GLabel 2925 9475 2    50   Output ~ 0
AD3
Wire Wire Line
	2925 9475 2625 9475
Connection ~ 2625 9475
Wire Wire Line
	2625 10025 2625 10300
$Comp
L gp2s700hcp:GP2S700HCP U1
U 1 1 5E8AA503
P 4725 1950
F 0 "U1" H 4975 2587 60  0000 C CNN
F 1 "GP2S700HCP" H 4975 2481 60  0000 C CNN
F 2 "mylib:GP2S700HCP" H 4725 1950 60  0001 C CNN
F 3 "" H 4725 1950 60  0001 C CNN
	1    4725 1950
	-1   0    0    1   
$EndComp
$Comp
L Device:R R5
U 1 1 5E8AA50A
P 5225 2725
F 0 "R5" H 5295 2771 50  0000 L CNN
F 1 "1k" H 5295 2680 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5155 2725 50  0001 C CNN
F 3 "~" H 5225 2725 50  0001 C CNN
	1    5225 2725
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 5E8AA511
P 5225 3150
F 0 "#PWR0117" H 5225 2900 50  0001 C CNN
F 1 "GND" H 5230 2977 50  0000 C CNN
F 2 "" H 5225 3150 50  0001 C CNN
F 3 "" H 5225 3150 50  0001 C CNN
	1    5225 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0118
U 1 1 5E8AA517
P 3500 2150
F 0 "#PWR0118" H 3500 1900 50  0001 C CNN
F 1 "GND" H 3505 1977 50  0000 C CNN
F 2 "" H 3500 2150 50  0001 C CNN
F 3 "" H 3500 2150 50  0001 C CNN
	1    3500 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4025 2050 3500 2050
Wire Wire Line
	3500 2050 3500 2150
$Comp
L power:+3V3 #PWR0119
U 1 1 5E8AA51F
P 3825 2275
F 0 "#PWR0119" H 3825 2125 50  0001 C CNN
F 1 "+3V3" H 3840 2448 50  0000 C CNN
F 2 "" H 3825 2275 50  0001 C CNN
F 3 "" H 3825 2275 50  0001 C CNN
	1    3825 2275
	1    0    0    -1  
$EndComp
Wire Wire Line
	3825 2275 3825 2325
Wire Wire Line
	3825 2325 4025 2325
$Comp
L Device:R R1
U 1 1 5E8AA527
P 5075 1800
F 0 "R1" H 5145 1846 50  0000 L CNN
F 1 "330" H 5145 1755 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5005 1800 50  0001 C CNN
F 3 "~" H 5075 1800 50  0001 C CNN
	1    5075 1800
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0120
U 1 1 5E8AA52E
P 5075 1550
F 0 "#PWR0120" H 5075 1400 50  0001 C CNN
F 1 "+3V3" H 5090 1723 50  0000 C CNN
F 2 "" H 5075 1550 50  0001 C CNN
F 3 "" H 5075 1550 50  0001 C CNN
	1    5075 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5075 1550 5075 1650
Wire Wire Line
	5075 1950 5075 2050
Wire Wire Line
	5075 2050 4925 2050
Wire Wire Line
	4925 2325 5225 2325
Wire Wire Line
	5225 2325 5225 2575
Text GLabel 5525 2325 2    50   Output ~ 0
AD4
Wire Wire Line
	5525 2325 5225 2325
Connection ~ 5225 2325
Wire Wire Line
	5225 2875 5225 3150
$Comp
L gp2s700hcp:GP2S700HCP U4
U 1 1 5E8AA53D
P 4850 4300
F 0 "U4" H 5100 4937 60  0000 C CNN
F 1 "GP2S700HCP" H 5100 4831 60  0000 C CNN
F 2 "mylib:GP2S700HCP" H 4850 4300 60  0001 C CNN
F 3 "" H 4850 4300 60  0001 C CNN
	1    4850 4300
	-1   0    0    1   
$EndComp
$Comp
L Device:R R13
U 1 1 5E8AA544
P 5350 5075
F 0 "R13" H 5420 5121 50  0000 L CNN
F 1 "1k" H 5420 5030 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5280 5075 50  0001 C CNN
F 3 "~" H 5350 5075 50  0001 C CNN
	1    5350 5075
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0121
U 1 1 5E8AA54B
P 5350 5500
F 0 "#PWR0121" H 5350 5250 50  0001 C CNN
F 1 "GND" H 5355 5327 50  0000 C CNN
F 2 "" H 5350 5500 50  0001 C CNN
F 3 "" H 5350 5500 50  0001 C CNN
	1    5350 5500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0122
U 1 1 5E8AA551
P 3625 4500
F 0 "#PWR0122" H 3625 4250 50  0001 C CNN
F 1 "GND" H 3630 4327 50  0000 C CNN
F 2 "" H 3625 4500 50  0001 C CNN
F 3 "" H 3625 4500 50  0001 C CNN
	1    3625 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 4400 3625 4400
Wire Wire Line
	3625 4400 3625 4500
$Comp
L power:+3V3 #PWR0123
U 1 1 5E8AA559
P 3950 4625
F 0 "#PWR0123" H 3950 4475 50  0001 C CNN
F 1 "+3V3" H 3965 4798 50  0000 C CNN
F 2 "" H 3950 4625 50  0001 C CNN
F 3 "" H 3950 4625 50  0001 C CNN
	1    3950 4625
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 4625 3950 4675
Wire Wire Line
	3950 4675 4150 4675
$Comp
L Device:R R9
U 1 1 5E8AA561
P 5200 4150
F 0 "R9" H 5270 4196 50  0000 L CNN
F 1 "330" H 5270 4105 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5130 4150 50  0001 C CNN
F 3 "~" H 5200 4150 50  0001 C CNN
	1    5200 4150
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0124
U 1 1 5E8AA568
P 5200 3900
F 0 "#PWR0124" H 5200 3750 50  0001 C CNN
F 1 "+3V3" H 5215 4073 50  0000 C CNN
F 2 "" H 5200 3900 50  0001 C CNN
F 3 "" H 5200 3900 50  0001 C CNN
	1    5200 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 3900 5200 4000
Wire Wire Line
	5200 4300 5200 4400
Wire Wire Line
	5200 4400 5050 4400
Wire Wire Line
	5050 4675 5350 4675
Wire Wire Line
	5350 4675 5350 4925
Text GLabel 5650 4675 2    50   Output ~ 0
AD5
Wire Wire Line
	5650 4675 5350 4675
Connection ~ 5350 4675
Wire Wire Line
	5350 5225 5350 5500
$Comp
L gp2s700hcp:GP2S700HCP U7
U 1 1 5E8AA577
P 4825 6700
F 0 "U7" H 5075 7337 60  0000 C CNN
F 1 "GP2S700HCP" H 5075 7231 60  0000 C CNN
F 2 "mylib:GP2S700HCP" H 4825 6700 60  0001 C CNN
F 3 "" H 4825 6700 60  0001 C CNN
	1    4825 6700
	-1   0    0    1   
$EndComp
$Comp
L Device:R R20
U 1 1 5E8AA57E
P 5325 7475
F 0 "R20" H 5395 7521 50  0000 L CNN
F 1 "1k" H 5395 7430 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5255 7475 50  0001 C CNN
F 3 "~" H 5325 7475 50  0001 C CNN
	1    5325 7475
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0125
U 1 1 5E8AA585
P 5325 7900
F 0 "#PWR0125" H 5325 7650 50  0001 C CNN
F 1 "GND" H 5330 7727 50  0000 C CNN
F 2 "" H 5325 7900 50  0001 C CNN
F 3 "" H 5325 7900 50  0001 C CNN
	1    5325 7900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0126
U 1 1 5E8AA58B
P 3600 6900
F 0 "#PWR0126" H 3600 6650 50  0001 C CNN
F 1 "GND" H 3605 6727 50  0000 C CNN
F 2 "" H 3600 6900 50  0001 C CNN
F 3 "" H 3600 6900 50  0001 C CNN
	1    3600 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4125 6800 3600 6800
Wire Wire Line
	3600 6800 3600 6900
$Comp
L power:+3V3 #PWR0127
U 1 1 5E8AA593
P 3925 7025
F 0 "#PWR0127" H 3925 6875 50  0001 C CNN
F 1 "+3V3" H 3940 7198 50  0000 C CNN
F 2 "" H 3925 7025 50  0001 C CNN
F 3 "" H 3925 7025 50  0001 C CNN
	1    3925 7025
	1    0    0    -1  
$EndComp
Wire Wire Line
	3925 7025 3925 7075
Wire Wire Line
	3925 7075 4125 7075
$Comp
L Device:R R16
U 1 1 5E8AA59B
P 5175 6550
F 0 "R16" H 5245 6596 50  0000 L CNN
F 1 "330" H 5245 6505 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5105 6550 50  0001 C CNN
F 3 "~" H 5175 6550 50  0001 C CNN
	1    5175 6550
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0128
U 1 1 5E8AA5A2
P 5175 6300
F 0 "#PWR0128" H 5175 6150 50  0001 C CNN
F 1 "+3V3" H 5190 6473 50  0000 C CNN
F 2 "" H 5175 6300 50  0001 C CNN
F 3 "" H 5175 6300 50  0001 C CNN
	1    5175 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5175 6300 5175 6400
Wire Wire Line
	5175 6700 5175 6800
Wire Wire Line
	5175 6800 5025 6800
Wire Wire Line
	5025 7075 5325 7075
Wire Wire Line
	5325 7075 5325 7325
Text GLabel 5625 7075 2    50   Output ~ 0
AD6
Wire Wire Line
	5625 7075 5325 7075
Connection ~ 5325 7075
Wire Wire Line
	5325 7625 5325 7900
$Comp
L gp2s700hcp:GP2S700HCP U11
U 1 1 5E8AA5B1
P 4950 9050
F 0 "U11" H 5200 9687 60  0000 C CNN
F 1 "GP2S700HCP" H 5200 9581 60  0000 C CNN
F 2 "mylib:GP2S700HCP" H 4950 9050 60  0001 C CNN
F 3 "" H 4950 9050 60  0001 C CNN
	1    4950 9050
	-1   0    0    1   
$EndComp
$Comp
L Device:R R27
U 1 1 5E8AA5B8
P 5450 9825
F 0 "R27" H 5520 9871 50  0000 L CNN
F 1 "1k" H 5520 9780 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5380 9825 50  0001 C CNN
F 3 "~" H 5450 9825 50  0001 C CNN
	1    5450 9825
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0129
U 1 1 5E8AA5BF
P 5450 10250
F 0 "#PWR0129" H 5450 10000 50  0001 C CNN
F 1 "GND" H 5455 10077 50  0000 C CNN
F 2 "" H 5450 10250 50  0001 C CNN
F 3 "" H 5450 10250 50  0001 C CNN
	1    5450 10250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0130
U 1 1 5E8AA5C5
P 3725 9250
F 0 "#PWR0130" H 3725 9000 50  0001 C CNN
F 1 "GND" H 3730 9077 50  0000 C CNN
F 2 "" H 3725 9250 50  0001 C CNN
F 3 "" H 3725 9250 50  0001 C CNN
	1    3725 9250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 9150 3725 9150
Wire Wire Line
	3725 9150 3725 9250
$Comp
L power:+3V3 #PWR0131
U 1 1 5E8AA5CD
P 4050 9375
F 0 "#PWR0131" H 4050 9225 50  0001 C CNN
F 1 "+3V3" H 4065 9548 50  0000 C CNN
F 2 "" H 4050 9375 50  0001 C CNN
F 3 "" H 4050 9375 50  0001 C CNN
	1    4050 9375
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 9375 4050 9425
Wire Wire Line
	4050 9425 4250 9425
$Comp
L Device:R R23
U 1 1 5E8AA5D5
P 5300 8900
F 0 "R23" H 5370 8946 50  0000 L CNN
F 1 "330" H 5370 8855 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5230 8900 50  0001 C CNN
F 3 "~" H 5300 8900 50  0001 C CNN
	1    5300 8900
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0132
U 1 1 5E8AA5DC
P 5300 8650
F 0 "#PWR0132" H 5300 8500 50  0001 C CNN
F 1 "+3V3" H 5315 8823 50  0000 C CNN
F 2 "" H 5300 8650 50  0001 C CNN
F 3 "" H 5300 8650 50  0001 C CNN
	1    5300 8650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 8650 5300 8750
Wire Wire Line
	5300 9050 5300 9150
Wire Wire Line
	5300 9150 5150 9150
Wire Wire Line
	5150 9425 5450 9425
Wire Wire Line
	5450 9425 5450 9675
Text GLabel 5750 9425 2    50   Output ~ 0
AD7
Wire Wire Line
	5750 9425 5450 9425
Connection ~ 5450 9425
Wire Wire Line
	5450 9975 5450 10250
$Comp
L gp2s700hcp:GP2S700HCP U3
U 1 1 5E8AC173
P 7675 2025
F 0 "U3" H 7925 2662 60  0000 C CNN
F 1 "GP2S700HCP" H 7925 2556 60  0000 C CNN
F 2 "mylib:GP2S700HCP" H 7675 2025 60  0001 C CNN
F 3 "" H 7675 2025 60  0001 C CNN
	1    7675 2025
	-1   0    0    1   
$EndComp
$Comp
L Device:R R7
U 1 1 5E8AC17A
P 8175 2800
F 0 "R7" H 8245 2846 50  0000 L CNN
F 1 "1k" H 8245 2755 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8105 2800 50  0001 C CNN
F 3 "~" H 8175 2800 50  0001 C CNN
	1    8175 2800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0133
U 1 1 5E8AC181
P 8175 3225
F 0 "#PWR0133" H 8175 2975 50  0001 C CNN
F 1 "GND" H 8180 3052 50  0000 C CNN
F 2 "" H 8175 3225 50  0001 C CNN
F 3 "" H 8175 3225 50  0001 C CNN
	1    8175 3225
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0134
U 1 1 5E8AC187
P 6450 2225
F 0 "#PWR0134" H 6450 1975 50  0001 C CNN
F 1 "GND" H 6455 2052 50  0000 C CNN
F 2 "" H 6450 2225 50  0001 C CNN
F 3 "" H 6450 2225 50  0001 C CNN
	1    6450 2225
	1    0    0    -1  
$EndComp
Wire Wire Line
	6975 2125 6450 2125
Wire Wire Line
	6450 2125 6450 2225
$Comp
L power:+3V3 #PWR0135
U 1 1 5E8AC18F
P 6775 2350
F 0 "#PWR0135" H 6775 2200 50  0001 C CNN
F 1 "+3V3" H 6790 2523 50  0000 C CNN
F 2 "" H 6775 2350 50  0001 C CNN
F 3 "" H 6775 2350 50  0001 C CNN
	1    6775 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6775 2350 6775 2400
Wire Wire Line
	6775 2400 6975 2400
$Comp
L Device:R R4
U 1 1 5E8AC197
P 8025 1875
F 0 "R4" H 8095 1921 50  0000 L CNN
F 1 "330" H 8095 1830 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7955 1875 50  0001 C CNN
F 3 "~" H 8025 1875 50  0001 C CNN
	1    8025 1875
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0136
U 1 1 5E8AC19E
P 8025 1625
F 0 "#PWR0136" H 8025 1475 50  0001 C CNN
F 1 "+3V3" H 8040 1798 50  0000 C CNN
F 2 "" H 8025 1625 50  0001 C CNN
F 3 "" H 8025 1625 50  0001 C CNN
	1    8025 1625
	1    0    0    -1  
$EndComp
Wire Wire Line
	8025 1625 8025 1725
Wire Wire Line
	8025 2025 8025 2125
Wire Wire Line
	8025 2125 7875 2125
Wire Wire Line
	7875 2400 8175 2400
Wire Wire Line
	8175 2400 8175 2650
Text GLabel 8475 2400 2    50   Output ~ 0
AD8
Wire Wire Line
	8475 2400 8175 2400
Connection ~ 8175 2400
Wire Wire Line
	8175 2950 8175 3225
$Comp
L gp2s700hcp:GP2S700HCP U6
U 1 1 5E8AC1AD
P 7800 4375
F 0 "U6" H 8050 5012 60  0000 C CNN
F 1 "GP2S700HCP" H 8050 4906 60  0000 C CNN
F 2 "mylib:GP2S700HCP" H 7800 4375 60  0001 C CNN
F 3 "" H 7800 4375 60  0001 C CNN
	1    7800 4375
	-1   0    0    1   
$EndComp
$Comp
L Device:R R15
U 1 1 5E8AC1B4
P 8300 5150
F 0 "R15" H 8370 5196 50  0000 L CNN
F 1 "1k" H 8370 5105 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8230 5150 50  0001 C CNN
F 3 "~" H 8300 5150 50  0001 C CNN
	1    8300 5150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0137
U 1 1 5E8AC1BB
P 8300 5575
F 0 "#PWR0137" H 8300 5325 50  0001 C CNN
F 1 "GND" H 8305 5402 50  0000 C CNN
F 2 "" H 8300 5575 50  0001 C CNN
F 3 "" H 8300 5575 50  0001 C CNN
	1    8300 5575
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0138
U 1 1 5E8AC1C1
P 6575 4575
F 0 "#PWR0138" H 6575 4325 50  0001 C CNN
F 1 "GND" H 6580 4402 50  0000 C CNN
F 2 "" H 6575 4575 50  0001 C CNN
F 3 "" H 6575 4575 50  0001 C CNN
	1    6575 4575
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 4475 6575 4475
Wire Wire Line
	6575 4475 6575 4575
$Comp
L power:+3V3 #PWR0139
U 1 1 5E8AC1C9
P 6900 4700
F 0 "#PWR0139" H 6900 4550 50  0001 C CNN
F 1 "+3V3" H 6915 4873 50  0000 C CNN
F 2 "" H 6900 4700 50  0001 C CNN
F 3 "" H 6900 4700 50  0001 C CNN
	1    6900 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 4700 6900 4750
Wire Wire Line
	6900 4750 7100 4750
$Comp
L Device:R R11
U 1 1 5E8AC1D1
P 8150 4225
F 0 "R11" H 8220 4271 50  0000 L CNN
F 1 "330" H 8220 4180 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8080 4225 50  0001 C CNN
F 3 "~" H 8150 4225 50  0001 C CNN
	1    8150 4225
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0140
U 1 1 5E8AC1D8
P 8150 3975
F 0 "#PWR0140" H 8150 3825 50  0001 C CNN
F 1 "+3V3" H 8165 4148 50  0000 C CNN
F 2 "" H 8150 3975 50  0001 C CNN
F 3 "" H 8150 3975 50  0001 C CNN
	1    8150 3975
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 3975 8150 4075
Wire Wire Line
	8150 4375 8150 4475
Wire Wire Line
	8150 4475 8000 4475
Wire Wire Line
	8000 4750 8300 4750
Wire Wire Line
	8300 4750 8300 5000
Text GLabel 8600 4750 2    50   Output ~ 0
AD9
Wire Wire Line
	8600 4750 8300 4750
Connection ~ 8300 4750
Wire Wire Line
	8300 5300 8300 5575
$Comp
L gp2s700hcp:GP2S700HCP U9
U 1 1 5E8AC1E7
P 7775 6775
F 0 "U9" H 8025 7412 60  0000 C CNN
F 1 "GP2S700HCP" H 8025 7306 60  0000 C CNN
F 2 "mylib:GP2S700HCP" H 7775 6775 60  0001 C CNN
F 3 "" H 7775 6775 60  0001 C CNN
	1    7775 6775
	-1   0    0    1   
$EndComp
$Comp
L Device:R R18
U 1 1 5E8AC20B
P 8125 6625
F 0 "R18" H 8195 6671 50  0000 L CNN
F 1 "330" H 8195 6580 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8055 6625 50  0001 C CNN
F 3 "~" H 8125 6625 50  0001 C CNN
	1    8125 6625
	1    0    0    -1  
$EndComp
Wire Wire Line
	8125 6375 8125 6475
Wire Wire Line
	8125 6775 8125 6875
Wire Wire Line
	8125 6875 7975 6875
$Comp
L Connector:Conn_01x13_Female J1
U 1 1 5E8B3A92
P 11600 2225
F 0 "J1" H 11627 2251 50  0000 L CNN
F 1 "Conn_01x13_Female" H 11627 2160 50  0000 L CNN
F 2 "mylib:FFC-SMD_13P-P0.50_X05B20U13T" H 11600 2225 50  0001 C CNN
F 3 "~" H 11600 2225 50  0001 C CNN
	1    11600 2225
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J2
U 1 1 5E8B3C64
P 11600 3750
F 0 "J2" H 11627 3726 50  0000 L CNN
F 1 "Conn_01x04_Female" H 11627 3635 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.00mm" H 11600 3750 50  0001 C CNN
F 3 "~" H 11600 3750 50  0001 C CNN
	1    11600 3750
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0141
U 1 1 5E8B7701
P 11125 2975
F 0 "#PWR0141" H 11125 2825 50  0001 C CNN
F 1 "+3V3" H 11140 3148 50  0000 C CNN
F 2 "" H 11125 2975 50  0001 C CNN
F 3 "" H 11125 2975 50  0001 C CNN
	1    11125 2975
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0142
U 1 1 5E8D99B6
P 10800 2850
F 0 "#PWR0142" H 10800 2600 50  0001 C CNN
F 1 "GND" H 10805 2677 50  0000 C CNN
F 2 "" H 10800 2850 50  0001 C CNN
F 3 "" H 10800 2850 50  0001 C CNN
	1    10800 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	11400 2625 10800 2625
Wire Wire Line
	11400 2725 10800 2725
Text GLabel 11400 3650 0    50   UnSpc ~ 0
LEFT_VCC
Text GLabel 11400 3750 0    50   UnSpc ~ 0
LEFT_GND
Text GLabel 8125 6375 0    50   UnSpc ~ 0
LEFT_VCC
Text GLabel 7075 7150 0    50   UnSpc ~ 0
LEFT_VCC
Text GLabel 7075 6875 0    50   UnSpc ~ 0
LEFT_GND
$Comp
L gp2s700hcp:GP2S700HCP U10
U 1 1 5E92C6A7
P 7775 7775
F 0 "U10" H 8025 7588 60  0000 C CNN
F 1 "GP2S700HCP" H 8025 7694 60  0000 C CNN
F 2 "mylib:GP2S700HCP" H 7775 7775 60  0001 C CNN
F 3 "" H 7775 7775 60  0001 C CNN
	1    7775 7775
	-1   0    0    1   
$EndComp
Text GLabel 7075 8150 0    50   UnSpc ~ 0
LEFT_VCC
Text GLabel 7075 7875 0    50   UnSpc ~ 0
LEFT_GND
$Comp
L Device:R R22
U 1 1 5E92F779
P 8275 7625
F 0 "R22" H 8345 7671 50  0000 L CNN
F 1 "330" H 8345 7580 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8205 7625 50  0001 C CNN
F 3 "~" H 8275 7625 50  0001 C CNN
	1    8275 7625
	1    0    0    -1  
$EndComp
Wire Wire Line
	8275 7375 8275 7475
Text GLabel 8275 7375 0    50   UnSpc ~ 0
LEFT_VCC
Wire Wire Line
	7975 7875 8275 7875
Wire Wire Line
	8275 7875 8275 7775
Wire Wire Line
	7975 8150 8650 8150
Wire Wire Line
	8650 8150 8650 7150
Wire Wire Line
	8650 7150 7975 7150
Wire Wire Line
	8650 7150 8900 7150
Connection ~ 8650 7150
$Comp
L Device:R R19
U 1 1 5E93BB3D
P 8900 7450
F 0 "R19" H 8970 7496 50  0000 L CNN
F 1 "1k" H 8970 7405 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8830 7450 50  0001 C CNN
F 3 "~" H 8900 7450 50  0001 C CNN
	1    8900 7450
	1    0    0    -1  
$EndComp
Text GLabel 8900 7775 3    50   UnSpc ~ 0
LEFT_GND
Wire Wire Line
	8900 7150 8900 7300
Wire Wire Line
	8900 7600 8900 7775
Text GLabel 9125 7150 2    50   Output ~ 0
left_analog
Wire Wire Line
	8900 7150 9125 7150
Connection ~ 8900 7150
$Comp
L gp2s700hcp:GP2S700HCP U12
U 1 1 5E958DE9
P 7825 9050
F 0 "U12" H 8075 9687 60  0000 C CNN
F 1 "GP2S700HCP" H 8075 9581 60  0000 C CNN
F 2 "mylib:GP2S700HCP" H 7825 9050 60  0001 C CNN
F 3 "" H 7825 9050 60  0001 C CNN
	1    7825 9050
	-1   0    0    1   
$EndComp
$Comp
L Device:R R24
U 1 1 5E958DF0
P 8175 8900
F 0 "R24" H 8245 8946 50  0000 L CNN
F 1 "330" H 8245 8855 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8105 8900 50  0001 C CNN
F 3 "~" H 8175 8900 50  0001 C CNN
	1    8175 8900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8175 8650 8175 8750
Wire Wire Line
	8175 9050 8175 9150
Wire Wire Line
	8175 9150 8025 9150
Text GLabel 8175 8650 0    50   UnSpc ~ 0
RIGHT_VCC
Text GLabel 7125 9425 0    50   UnSpc ~ 0
RIGHT_VCC
Text GLabel 7125 9150 0    50   UnSpc ~ 0
RIGHT_GND
$Comp
L gp2s700hcp:GP2S700HCP U14
U 1 1 5E958DFD
P 7825 10050
F 0 "U14" H 8075 9863 60  0000 C CNN
F 1 "GP2S700HCP" H 8075 9969 60  0000 C CNN
F 2 "mylib:GP2S700HCP" H 7825 10050 60  0001 C CNN
F 3 "" H 7825 10050 60  0001 C CNN
	1    7825 10050
	-1   0    0    1   
$EndComp
Text GLabel 7125 10425 0    50   UnSpc ~ 0
RIGHT_VCC
Text GLabel 7125 10150 0    50   UnSpc ~ 0
RIGHT_GND
$Comp
L Device:R R29
U 1 1 5E958E06
P 8325 9900
F 0 "R29" H 8395 9946 50  0000 L CNN
F 1 "330" H 8395 9855 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8255 9900 50  0001 C CNN
F 3 "~" H 8325 9900 50  0001 C CNN
	1    8325 9900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8325 9650 8325 9750
Text GLabel 8325 9650 0    50   UnSpc ~ 0
RIGHT_VCC
Wire Wire Line
	8025 10150 8325 10150
Wire Wire Line
	8325 10150 8325 10050
Wire Wire Line
	8025 10425 8700 10425
Wire Wire Line
	8700 10425 8700 9425
Wire Wire Line
	8700 9425 8025 9425
Wire Wire Line
	8700 9425 8950 9425
Connection ~ 8700 9425
$Comp
L Device:R R26
U 1 1 5E958E16
P 8950 9725
F 0 "R26" H 9020 9771 50  0000 L CNN
F 1 "1k" H 9020 9680 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8880 9725 50  0001 C CNN
F 3 "~" H 8950 9725 50  0001 C CNN
	1    8950 9725
	1    0    0    -1  
$EndComp
Text GLabel 8950 10050 3    50   UnSpc ~ 0
RIGHT_GND
Wire Wire Line
	8950 9425 8950 9575
Wire Wire Line
	8950 9875 8950 10050
Text GLabel 9175 9425 2    50   Output ~ 0
right_analog
Wire Wire Line
	8950 9425 9175 9425
Connection ~ 8950 9425
Text GLabel 11400 3850 0    50   Output ~ 0
left_analog
Text GLabel 11400 3950 0    50   Input ~ 0
left_led
Text GLabel 12800 3575 0    50   UnSpc ~ 0
LEFT_VCC
$Comp
L Device:R R8
U 1 1 5E96E512
P 13150 3575
F 0 "R8" V 12943 3575 50  0000 C CNN
F 1 "1k" V 13034 3575 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 13080 3575 50  0001 C CNN
F 3 "~" H 13150 3575 50  0001 C CNN
	1    13150 3575
	0    1    1    0   
$EndComp
$Comp
L Device:LED D2
U 1 1 5E96E66E
P 13625 3575
F 0 "D2" H 13617 3320 50  0000 C CNN
F 1 "LED" H 13617 3411 50  0000 C CNN
F 2 "LEDs:LED_0603_HandSoldering" H 13625 3575 50  0001 C CNN
F 3 "~" H 13625 3575 50  0001 C CNN
	1    13625 3575
	-1   0    0    1   
$EndComp
Text GLabel 14000 3575 2    50   Output ~ 0
left_led
Wire Wire Line
	13775 3575 14000 3575
Wire Wire Line
	12800 3575 13000 3575
Wire Wire Line
	13300 3575 13475 3575
$Comp
L Connector:Conn_01x04_Female J3
U 1 1 5E97F376
P 11575 4400
F 0 "J3" H 11602 4376 50  0000 L CNN
F 1 "Conn_01x04_Female" H 11602 4285 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.00mm" H 11575 4400 50  0001 C CNN
F 3 "~" H 11575 4400 50  0001 C CNN
	1    11575 4400
	1    0    0    -1  
$EndComp
Text GLabel 11375 4300 0    50   UnSpc ~ 0
RIGHT_VCC
Text GLabel 11375 4400 0    50   UnSpc ~ 0
RIGHT_GND
Text GLabel 11375 4500 0    50   Output ~ 0
right_analog
Text GLabel 11375 4600 0    50   Input ~ 0
right_led
Text GLabel 12775 4225 0    50   UnSpc ~ 0
RIGHT_VCC
$Comp
L Device:R R12
U 1 1 5E97F382
P 13125 4225
F 0 "R12" V 12918 4225 50  0000 C CNN
F 1 "1k" V 13009 4225 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 13055 4225 50  0001 C CNN
F 3 "~" H 13125 4225 50  0001 C CNN
	1    13125 4225
	0    1    1    0   
$EndComp
$Comp
L Device:LED D3
U 1 1 5E97F389
P 13600 4225
F 0 "D3" H 13592 3970 50  0000 C CNN
F 1 "LED" H 13592 4061 50  0000 C CNN
F 2 "LEDs:LED_0603_HandSoldering" H 13600 4225 50  0001 C CNN
F 3 "~" H 13600 4225 50  0001 C CNN
	1    13600 4225
	-1   0    0    1   
$EndComp
Text GLabel 13975 4225 2    50   Output ~ 0
right_led
Wire Wire Line
	13750 4225 13975 4225
Wire Wire Line
	12775 4225 12975 4225
Wire Wire Line
	13275 4225 13450 4225
Text GLabel 11400 1625 0    50   Output ~ 0
AD9
Text GLabel 11400 1725 0    50   Output ~ 0
AD8
Text GLabel 11400 1825 0    50   Output ~ 0
AD7
Text GLabel 11400 2525 0    50   Output ~ 0
AD0
Text GLabel 11400 2425 0    50   Output ~ 0
AD1
Text GLabel 11400 2325 0    50   Output ~ 0
AD2
Text GLabel 11400 2225 0    50   Output ~ 0
AD3
Text GLabel 11400 2125 0    50   Output ~ 0
AD4
Text GLabel 11400 2025 0    50   Output ~ 0
AD5
Text GLabel 11400 1925 0    50   Output ~ 0
AD6
$Comp
L power:+3V3 #PWR0143
U 1 1 5E9A9DEE
P 12700 1450
F 0 "#PWR0143" H 12700 1300 50  0001 C CNN
F 1 "+3V3" H 12715 1623 50  0000 C CNN
F 2 "" H 12700 1450 50  0001 C CNN
F 3 "" H 12700 1450 50  0001 C CNN
	1    12700 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5E9A9E75
P 12700 1850
F 0 "R3" H 12770 1896 50  0000 L CNN
F 1 "1k" H 12770 1805 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 12630 1850 50  0001 C CNN
F 3 "~" H 12700 1850 50  0001 C CNN
	1    12700 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 5E9A9F24
P 12700 2325
F 0 "D1" V 12738 2208 50  0000 R CNN
F 1 "LED" V 12647 2208 50  0000 R CNN
F 2 "LEDs:LED_0603_HandSoldering" H 12700 2325 50  0001 C CNN
F 3 "~" H 12700 2325 50  0001 C CNN
	1    12700 2325
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0144
U 1 1 5E9AA141
P 12700 2625
F 0 "#PWR0144" H 12700 2375 50  0001 C CNN
F 1 "GND" H 12705 2452 50  0000 C CNN
F 2 "" H 12700 2625 50  0001 C CNN
F 3 "" H 12700 2625 50  0001 C CNN
	1    12700 2625
	1    0    0    -1  
$EndComp
Wire Wire Line
	12700 1450 12700 1700
Wire Wire Line
	12700 2000 12700 2175
Wire Wire Line
	12700 2475 12700 2625
Wire Wire Line
	10800 2625 10800 2725
Connection ~ 10800 2725
Wire Wire Line
	10800 2725 10800 2850
Wire Wire Line
	11400 2825 11300 2825
Wire Wire Line
	11300 2825 11300 3050
Wire Wire Line
	11300 3050 11125 3050
Wire Wire Line
	11125 3050 11125 2975
$EndSCHEMATC