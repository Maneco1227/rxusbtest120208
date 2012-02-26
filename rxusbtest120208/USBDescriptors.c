//
// USB Descriptors.
//

/* Standard Device Descriptor */
unsigned short usb_gpcdc_DeviceDescriptorLength = 18;
unsigned char  usb_gpcdc_DeviceDescriptor[] =
{
	/*Size of this descriptor*/
	18,
	/*Device Descriptor*/
	0x01,
	/*USB Version 2.0*/
	0x00,0x02,
	/*Class Code - CDC*/
	0x02,
	/*Subclass Code*/
	0x00,
	/*Protocol Code*/
	0x00,
	/*Max Packet Size for endpoint 0*/
	0x40,
	/*Vendor ID*/
	0x5B, 0x04,
	/*Product ID*/
	0x14, 0x20,
	/*Device Release Number*/
	0x00, 0x01,
	/*Manufacturer String Descriptor*/
	1,
	/*Product String Descriptor*/
	2,
	/*Serial Number String Descriptor*/
	3,
	/*Number of Configurations supported*/
	0x01
};


// Configuration Descriptor.
unsigned short usb_gpcdc_ConfigrationDescriptorLength = 67;
unsigned char  usb_gpcdc_ConfigrationDescriptor[] =
{
	/*Size of this descriptor (Just the configuration part)*/
	0x09,
	/*Configuration Descriptor*/
	0x02,
	/*Combined length of all descriptors (little endian)*/
	67, 0x00,
	/*Number of interfaces*/
	0x02,
	/*This Interface Value*/
	0x01,
	/*No String Descriptor for this configuration*/
	0x00,
	/*bmAttributes - Self Powered(USB bus powered), No Remote Wakeup*/
	0xC0,
	/*bmAttributes - Not USB Bus powered, No Remote Wakeup*/		
	/*0x80,*/		
	/*bMaxPower (2mA units) 100mA (A unit load is defined as 100mA)*/
	50,

/* Communication Class Interface Descriptor */
	/*Size of this descriptor*/
	0x09,
	/*INTERFACE Descriptor*/
	0x04,
	/*Index of Interface*/
	0x00,
	/*bAlternateSetting*/
	0x00,
	/*Number of Endpoints*/
	0x01,
	/*Class code = Communication*/
	0x02,
	/*Subclass = Abstract Control Model*/
	0x20,
	/*No Protocol*/
	0x00,
	/*No String Descriptor for this interface*/
	0x00,

/*Header Functional Descriptor*/
	/*bFunctionalLength*/
	0x05,
	/*bDescriptorType = CS_INTERFACE*/
	0x24,
	/*bDescriptor Subtype = Header*/
	0x00,
	/*bcdCDC 1.1*/
	0x10,0x01,

/* ACM Functional Descriptor */
	/*bFunctionalLength*/
	0x04,
	/*bDescriptorType = CS_INTERFACE*/
	0x24,
	/*bDescriptor Subtype = Abstract Control Management*/
	0x02,
	/*bmCapabilities GET_LINE_CODING etc supported*/
	0x02,

/* Union Functional Descriptor */
	/*bFunctionalLength*/
	0x05,
	/*bDescriptorType = CS_INTERFACE*/
	0x24,
	/*bDescriptor Subtype = Union*/
	0x06,
	/*bMasterInterface = Communication Class Interface*/
	0x00,
	/*bSlaveInterface = Data Class Interface*/
	0x01,

/* Call Management Functional Descriptor */
	/*bFunctionalLength*/
	0x05,
	/*bDescriptorType = CS_INTERFACE*/
	0x24,
	/*bDescriptor Subtype = Call Management*/
	0x01,
	/*bmCapabilities*/
	0x00,
	/*bDataInterface: Data Class Interface = 1*/
	0x01,
	
/* Interrupt Endpoint */
	/*Size of this descriptor*/
	0x07,
	/*ENDPOINT Descriptor*/
	0x05,
	/*bEndpointAddress - IN endpoint, endpoint number = 3*/
	0x83,
	/*Endpoint Type is Interrupt*/
	0x03,
	/*Max Packet Size*/
	0x08,0x00,
	/*Polling Interval in mS*/
	0xFF,

/* DATA Class Interface Descriptor */
	/*Size of this descriptor*/
	0x09,
	/*INTERFACE Descriptor*/
	0x04,
	/*Index of Interface*/
	0x01,
	/*bAlternateSetting*/
	0x00,
	/*Number of Endpoints*/
	0x02,
	/*Class code = Data Interface*/
	0x0A,
	/*Subclass = Abstract Control Model*/
	0x00,
	/*No Protocol*/
	0x00,
	/*No String Descriptor for this interface*/
	0x00,

/*Endpoint Bulk OUT */
	/*Size of this descriptor*/
	0x07,
	/*ENDPOINT Descriptor*/
	0x05,
	/*bEndpointAddress - OUT endpoint, endpoint number = 1*/
	0x01,
	/*Endpoint Type is BULK*/
	0x02,
	/*Max Packet Size*/
	64,0x00,
	/*Polling Interval in mS - IGNORED FOR BULK*/
	0x00,

/* Endpoint Bulk IN */
	/*Size of this descriptor*/
	0x07,
	/*ENDPOINT Descriptor*/
	0x05,
	/*bEndpointAddress - IN endpoint, endpoint number = 2*/
	0x82,
	/*Endpoint Type is BULK*/
	0x02,
	/*Max Packet Size*/
	64,0x00,
	/*Polling Interval in mS - IGNORED FOR BULK*/
	0x00
};


unsigned char usb_gpcdc_StringDescriptor0[] =
{	
	0x04, 0x03, 0x09, 0x04
};

unsigned char usb_gpcdc_StringDescriptor1[] =
{
	/* Length of this descriptor*/
	16,
	/* Descriptor Type = STRING */
	0x03,
	/* Descriptor Text (unicode) */
	'R', 0x00, 'E', 0x00, 'N', 0x00, 'E', 0x00,
	'S', 0x00, 'A', 0x00, 'S', 0x00
};

unsigned char usb_gpcdc_StringDescriptor2[] =
{
	/* Length of this descriptor*/
	44,
	/* Descriptor Type = STRING */
	0x03,
	/* Descriptor Text (unicode) */
	'C', 0x00, 'D', 0x00, 'C', 0x00, ' ', 0x00,
	'U', 0x00, 'S', 0x00, 'B', 0x00, ' ', 0x00,
	'D', 0x00, 'e', 0x00, 'm', 0x00, 'o', 0x00,
	'n', 0x00, 's', 0x00, 't', 0x00, 'r', 0x00,
	'a', 0x00, 't', 0x00, 'i', 0x00, 'o', 0x00,
	'n', 0x00
};

unsigned char usb_gpcdc_StringDescriptor3[] =
{	
	/* Length of this descriptor*/
	8,
	/* Descriptor Type = STRING */
	0x03,
	/* Descriptor Text (unicode) */
	'1', 0x00, '.', 0x00, '1', 0x00
};

unsigned char usb_gpcdc_StringDescriptor4[] =
{	/* iConfiguration */
	22,		/*	0:bLength */
	0x03,	/*	1:bDescriptorType */
	'F', 0x00,	/*	2:wLANGID[0] */
	'u', 0x00,
	'l', 0x00,
	'l', 0x00,
	'-', 0x00,
	'S', 0x00,
	'p', 0x00,
	'e', 0x00,
	'e', 0x00,
	'd', 0x00
};

unsigned char usb_gpcdc_StringDescriptor5[] =
{	/* iInterface */
	32,		/*	0:bLength */
	0x03,	/*	1:bDescriptorType */
	'R', 0x00,
	'X', 0x00,
	'6', 0x00,
	'2', 0x00,
	' ', 0x00,
	'U', 0x00,
	'S', 0x00,
	'B', 0x00,
	' ', 0x00,
	'S', 0x00,
	'a', 0x00,
	'm', 0x00,
	'p', 0x00,
	'l', 0x00,
	'e', 0x00,
};

unsigned char usb_gpcdc_StringDescriptor6[] =
{	/* iSerialNumber */
	18,		/*	0:bLength */
	0x03,	/*	1:bDescriptorType */
	'0', 0x00,
	'0', 0x00,
	'0', 0x00,
	'0', 0x00,
	'0', 0x00,
	'0', 0x00,
	'0', 0x00,
	'1', 0x00,
};

unsigned char usb_gpcdc_StringDescriptor7[] =
{	/* iSerialNumber */
	18,		/*	0:bLength */
	0x03,	/*	1:bDescriptorType */
	'0', 0x00,
	'0', 0x00,
	'0', 0x00,
	'0', 0x00,
	'0', 0x00,
	'0', 0x00,
	'0', 0x00,
	'1', 0x00,
};

