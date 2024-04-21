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
    ONLYFILES_LISTWIDGET_OUTPUT     	= 0x00000002,

};


#endif // PEARSIGNALS_H
