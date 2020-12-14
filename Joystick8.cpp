/*
  Joystick2.cpp

  Copyright (c) 2015, Matthew Heironimus

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Modified by Robert Volarić
*/

#include "Joystick8.h"

#if defined(_USING_HID)

#define JOYSTICK_REPORT_ID  0x03
#define JOYSTICK2_REPORT_ID  0x04
#define JOYSTICK3_REPORT_ID  0x05
#define JOYSTICK4_REPORT_ID  0x06
#define JOYSTICK5_REPORT_ID  0x07
#define JOYSTICK6_REPORT_ID  0x08
#define JOYSTICK7_REPORT_ID  0x09
#define JOYSTICK8_REPORT_ID  0x0a
#define JOYSTICK_STATE_SIZE 5

bool _dataArray = true;

static const uint8_t _hidReportDescriptor[] PROGMEM = {
  
    // Joystick #1
    0x05, 0x01,               // USAGE_PAGE (Generic Desktop)
    0x09, 0x04,               // USAGE (Joystick)
    0xa1, 0x01,               // COLLECTION (Application)
    0x85, JOYSTICK_REPORT_ID, // REPORT_ID (3)

    
	
	

		// X, Y, and Z Axis
				0x05, 0x01,               //   USAGE_PAGE (Generic Desktop)
				0x15, 0x00,			      //   LOGICAL_MINIMUM (0)
				0x26, 0xff, 0x00,	      //   LOGICAL_MAXIMUM (255)
				0x75, 0x08,			      //   REPORT_SIZE (8)
				0x09, 0x01,			      //   USAGE (Pointer)
				0xA1, 0x00,			      //   COLLECTION (Physical)
				0x09, 0x30,		          //     USAGE (x)
				0x09, 0x31,		          //     USAGE (y)
				0x09, 0x32,		          //     USAGE (z)
				0x09, 0x33,		          //     USAGE (rx)
				0x09, 0x34,		          //     USAGE (ry)
				0x95, 0x05,		          //     REPORT_COUNT (5)
				0x81, 0x02,		          //     INPUT (Data,Var,Abs)
		    0xc0,                      //   END_COLLECTION
		    0xc0,                       // END_COLLECTION
			
			// Joystick #2
			    0x05, 0x01,               // USAGE_PAGE (Generic Desktop)
			    0x09, 0x04,               // USAGE (Joystick)
			    0xa1, 0x01,               // COLLECTION (Application)
			    0x85, JOYSTICK2_REPORT_ID, // REPORT_ID (4)

			    
				
				

					// X, Y, and Z Axis
							0x05, 0x01,               //   USAGE_PAGE (Generic Desktop)
							0x15, 0x00,			      //   LOGICAL_MINIMUM (0)
							0x26, 0xff, 0x00,	      //   LOGICAL_MAXIMUM (255)
							0x75, 0x08,			      //   REPORT_SIZE (8)
							0x09, 0x01,			      //   USAGE (Pointer)
							0xA1, 0x00,			      //   COLLECTION (Physical)
							0x09, 0x30,		          //     USAGE (x)
							0x09, 0x31,		          //     USAGE (y)
							0x09, 0x32,		          //     USAGE (z)
							0x09, 0x33,		          //     USAGE (rx)
							0x09, 0x34,		          //     USAGE (ry)
							0x95, 0x05,		          //     REPORT_COUNT (5)
							0x81, 0x02,		          //     INPUT (Data,Var,Abs)
					    0xc0,                      //   END_COLLECTION
					    0xc0,                       // END_COLLECTION
						
						// Joystick #3
									    0x05, 0x01,               // USAGE_PAGE (Generic Desktop)
									    0x09, 0x04,               // USAGE (Joystick)
									    0xa1, 0x01,               // COLLECTION (Application)
									    0x85, JOYSTICK3_REPORT_ID, // REPORT_ID (5)

									    
										
										

											// X, Y, and Z Axis
													0x05, 0x01,               //   USAGE_PAGE (Generic Desktop)
													0x15, 0x00,			      //   LOGICAL_MINIMUM (0)
													0x26, 0xff, 0x00,	      //   LOGICAL_MAXIMUM (255)
													0x75, 0x08,			      //   REPORT_SIZE (8)
													0x09, 0x01,			      //   USAGE (Pointer)
													0xA1, 0x00,			      //   COLLECTION (Physical)
													0x09, 0x30,		          //     USAGE (x)
													0x09, 0x31,		          //     USAGE (y)
													0x09, 0x32,		          //     USAGE (z)
													0x09, 0x33,		          //     USAGE (rx)
													0x09, 0x34,		          //     USAGE (ry)
													0x95, 0x05,		          //     REPORT_COUNT (5)
													0x81, 0x02,		          //     INPUT (Data,Var,Abs)
											    0xc0,                      //   END_COLLECTION
											    0xc0,                       // END_COLLECTION
												
												// Joystick #4
																					    0x05, 0x01,               // USAGE_PAGE (Generic Desktop)
																					    0x09, 0x04,               // USAGE (Joystick)
																					    0xa1, 0x01,               // COLLECTION (Application)
																					    0x85, JOYSTICK4_REPORT_ID, // REPORT_ID (5)

																					    
																						
																						

																							// X, Y, and Z Axis
																									0x05, 0x01,               //   USAGE_PAGE (Generic Desktop)
																									0x15, 0x00,			      //   LOGICAL_MINIMUM (0)
																									0x26, 0xff, 0x00,	      //   LOGICAL_MAXIMUM (255)
																									0x75, 0x08,			      //   REPORT_SIZE (8)
																									0x09, 0x01,			      //   USAGE (Pointer)
																									0xA1, 0x00,			      //   COLLECTION (Physical)
																									0x09, 0x30,		          //     USAGE (x)
																									0x09, 0x31,		          //     USAGE (y)
																									0x09, 0x32,		          //     USAGE (z)
																									0x09, 0x33,		          //     USAGE (rx)
																									0x09, 0x34,		          //     USAGE (ry)
																									0x95, 0x05,		          //     REPORT_COUNT (5)
																									0x81, 0x02,		          //     INPUT (Data,Var,Abs)
																							    0xc0,                      //   END_COLLECTION
																							    0xc0,                       // END_COLLECTION
																								
																								
				// Joystick #5
				0x05, 0x01,               // USAGE_PAGE (Generic Desktop)
				0x09, 0x04,               // USAGE (Joystick)
				0xa1, 0x01,               // COLLECTION (Application)
				0x85, JOYSTICK5_REPORT_ID, // REPORT_ID (5)

																																	    
																																		
																																		

				// X, Y, and Z Axis
				0x05, 0x01,               //   USAGE_PAGE (Generic Desktop)
				0x15, 0x00,			      //   LOGICAL_MINIMUM (0)
			    0x26, 0xff, 0x00,	      //   LOGICAL_MAXIMUM (255)
			    0x75, 0x08,			      //   REPORT_SIZE (8)
				0x09, 0x01,			      //   USAGE (Pointer)
				0xA1, 0x00,			      //   COLLECTION (Physical)
				0x09, 0x30,		          //     USAGE (x)
				0x09, 0x31,		          //     USAGE (y)
				0x09, 0x32,		          //     USAGE (z)
				0x09, 0x33,		          //     USAGE (rx)
				0x09, 0x34,		          //     USAGE (ry)
				0x95, 0x05,		          //     REPORT_COUNT (5)
				0x81, 0x02,		          //     INPUT (Data,Var,Abs)
				0xc0,                      //   END_COLLECTION
				0xc0,                      // END_COLLECTION
				
				// Joystick #6
								0x05, 0x01,               // USAGE_PAGE (Generic Desktop)
								0x09, 0x04,               // USAGE (Joystick)
								0xa1, 0x01,               // COLLECTION (Application)
								0x85, JOYSTICK6_REPORT_ID, // REPORT_ID (6)

																																					    
																																						
																																						

								// X, Y, and Z Axis
								0x05, 0x01,               //   USAGE_PAGE (Generic Desktop)
								0x15, 0x00,			      //   LOGICAL_MINIMUM (0)
							    0x26, 0xff, 0x00,	      //   LOGICAL_MAXIMUM (255)
							    0x75, 0x08,			      //   REPORT_SIZE (8)
								0x09, 0x01,			      //   USAGE (Pointer)
								0xA1, 0x00,			      //   COLLECTION (Physical)
								0x09, 0x30,		          //     USAGE (x)
								0x09, 0x31,		          //     USAGE (y)
								0x09, 0x32,		          //     USAGE (z)
								0x09, 0x33,		          //     USAGE (rx)
								0x09, 0x34,		          //     USAGE (ry)
								0x95, 0x05,		          //     REPORT_COUNT (5)
								0x81, 0x02,		          //     INPUT (Data,Var,Abs)
								0xc0,                      //   END_COLLECTION
								0xc0,                      // END_COLLECTION
								
								// Joystick #7
												0x05, 0x01,               // USAGE_PAGE (Generic Desktop)
												0x09, 0x04,               // USAGE (Joystick)
												0xa1, 0x01,               // COLLECTION (Application)
												0x85, JOYSTICK7_REPORT_ID, // REPORT_ID (5)

																																									    
																																										
																																										

												// X, Y, and Z Axis
												0x05, 0x01,               //   USAGE_PAGE (Generic Desktop)
												0x15, 0x00,			      //   LOGICAL_MINIMUM (0)
											    0x26, 0xff, 0x00,	      //   LOGICAL_MAXIMUM (255)
											    0x75, 0x08,			      //   REPORT_SIZE (8)
												0x09, 0x01,			      //   USAGE (Pointer)
												0xA1, 0x00,			      //   COLLECTION (Physical)
												0x09, 0x30,		          //     USAGE (x)
												0x09, 0x31,		          //     USAGE (y)
												0x09, 0x32,		          //     USAGE (z)
												0x09, 0x33,		          //     USAGE (rx)
												0x09, 0x34,		          //     USAGE (ry)
												0x95, 0x05,		          //     REPORT_COUNT (5)
												0x81, 0x02,		          //     INPUT (Data,Var,Abs)
												0xc0,                      //   END_COLLECTION
												0xc0,                      // END_COLLECTION
												
												// Joystick #7
																								0x05, 0x01,               // USAGE_PAGE (Generic Desktop)
																								0x09, 0x04,               // USAGE (Joystick)
																								0xa1, 0x01,               // COLLECTION (Application)
																								0x85, JOYSTICK8_REPORT_ID, // REPORT_ID (8)

																																																					    
																																																						
																																																						

																								// X, Y, and Z Axis
																								0x05, 0x01,               //   USAGE_PAGE (Generic Desktop)
																								0x15, 0x00,			      //   LOGICAL_MINIMUM (0)
																							    0x26, 0xff, 0x00,	      //   LOGICAL_MAXIMUM (255)
																							    0x75, 0x08,			      //   REPORT_SIZE (8)
																								0x09, 0x01,			      //   USAGE (Pointer)
																								0xA1, 0x00,			      //   COLLECTION (Physical)
																								0x09, 0x30,		          //     USAGE (x)
																								0x09, 0x31,		          //     USAGE (y)
																								0x09, 0x32,		          //     USAGE (z)
																								0x09, 0x33,		          //     USAGE (rx)
																								0x09, 0x34,		          //     USAGE (ry)
																								0x95, 0x05,		          //     REPORT_COUNT (5)
																								0x81, 0x02,		          //     INPUT (Data,Var,Abs)
																								0xc0,                      //   END_COLLECTION
																								0xc0                     // END_COLLECTION
				
				
				
				
				
				
																								
																																				

    
};

Joystick_::Joystick_(uint8_t initJoystickId)
{
	// Setup HID report structure
		static bool usbSetup = false;
		
		if (!usbSetup)
		{
		    static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
		    HID().AppendDescriptor(&node);
	        usbSetup = true;
		}
	    
	    // Initalize State
			joystickId = initJoystickId;
	    	xAxis = 0;
			yAxis = 0;
	    	zAxis = 0;
	    	xAxisRotation = 0;
	    	yAxisRotation = 0;
	    	
	    	
	    	if(_dataArray){
	    		
	    		for(int i = 0; i < 5; i++){
	    			
	    			dataArray[i] = 0;
	    			_dataArray = false;
	    		}
	    	}
	    	
	    	
	    	
	    	
	}

	void Joystick_::begin(bool initAutoSendState)
	{
	    autoSendState = initAutoSendState;
	    sendState();
	}

	void Joystick_::end()
	{
	}

	
	void Joystick_::setXAxis(int8_t value)
	{
		dataArray [0] = value;
	}
	void Joystick_::setYAxis(int8_t value)
	{
		dataArray [1] = value;
	}
	

	void Joystick_::setZAxis(int8_t value)
	{
		dataArray [2] = value;
	}
	
	void Joystick_::setXAxisRotation(int8_t value)
	{
		dataArray [3] = value;
		
	}
	void Joystick_::setYAxisRotation(int8_t value)
	{
		dataArray [4] = value;
	}

	void Joystick_::sendState()
	{
	    int8_t data[JOYSTICK_STATE_SIZE];
	    

	    
	    data[0] = xAxis;
	    data[1] = yAxis;
	    data[2] = zAxis;
	    data[3] = xAxisRotation;
	    data[4] = yAxisRotation;

	    // HID().SendReport(Report number, array of values in same order as HID descriptor, length)
	    HID().SendReport(JOYSTICK_REPORT_ID + joystickId, dataArray, JOYSTICK_STATE_SIZE);
	}

	Joystick_ Joystick[8] =
	{
	    Joystick_(0),
	    Joystick_(1),
		Joystick_(2),
		Joystick_(3),
		Joystick_(4),
		Joystick_(5),
		Joystick_(6),
		Joystick_(7)
	   
	};

	#endif