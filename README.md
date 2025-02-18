# LightroomController

Works With:
This code is written for a Teensy 4.1 and Arduino IDE.

Functionality:
There are 23 buttons in the code that either send a MIDI note directly, or assign a CC value to the encoder output. It is intended to be used with MIDI2LR by "rsjaffe" to csend commands to Lightroom, speeding up your workflow. Here is a list of the functions I assigned, but feel free to modify the code as needed.

Button/Pin    Mode 1 MIDI	    Mode 1 Function		Mode 2 MIDI	    Mode 2 Function
1		          Note 32	        Next Photo		    Note 32	        Next Photo
2		          CC 33	          Exposure		      Note 55	        Set Color - Purple
3		          CC 34	          Highlights	    	Note 56	        Set Color - Yellow
4		          CC 35	          Shadows		        Note 57	        Pick
5		          CC 36	          Whites		        Note 58	        Unpick
6		          CC 37	          Blacks		        Note 59	        Rotate Clockwise
7		          Note 38	        White Picker	  	Note 60	        Tone Control - Auto
8		          CC 39	          Temp		          CC 61	
9		          CC 40	          Tint		          CC 62	
10		        CC 41	          Texture	        	CC 63	
11		        CC 42	          Clarity		        CC 64	
12		        CC 43	          Vibrance		      CC 65	
13		        CC 44	          Saturation		    Note 66	        Rotate CCW
14		        Note 45	        Prev Photo		    Note 45	        Prev Photo
15		        Note 46	        Undo		          Note 46	        Undo
16		        CC 47	          Angle		          CC 47	          Angle
17		        CC 48	          Crop - Top		    CC 48	          Crop - Top
18		        CC 49	          Crop - Left	    	CC 49	          Crop - Left
19		        CC 50	          Crop - Right	  	CC 50	          Crop - Right
20		        CC 51	          Crop - Bottom		  CC 51	          Crop - Bottom
21		        Note 52	        Preset 1		      CC 72	          Sharpening
22		        Note 53	        Preset 2		      CC 73	          Lum. Noise Reduction
23		        Note 54	        Preset 3	      	CC 74	          Col. Noise Reduction
