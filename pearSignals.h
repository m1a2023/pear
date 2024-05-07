#ifndef PEARSIGNALS_H
#define PEARSIGNALS_H


//      OVERDEFINING SIGNAL
#define     pearSignal     int8_t

//      OVERDEFINING INDEXER
#define     indexer     uint16_t

//      SIGNALS TO LISTWIDGET
enum SignalsListWidget
{
    DEFAULT_LISTWIDGET_OUTPUT           = 0x00000000,
    ONLYFOLDERS_LISTWIDGET_OUTPUT   	= 0x00000001,
    ONLYFILES_LISTWIDGET_OUTPUT     	= 0x00000002
};


<<<<<<< Updated upstream
//		SIGNALS FOR BOOL
#define 	Bool	uint8_t

enum SignalsBool
{
    FALSE 	= 0,
    TRUE	= 1
=======
//		SIGNALS TO Bool

enum
{
    FALSE,
    TRUE
>>>>>>> Stashed changes
};


#endif // PEARSIGNALS_H
