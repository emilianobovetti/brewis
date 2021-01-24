#include "Global.h"

LiquidCrystalImproved lcd(LCD_RS_PIN, LCD_ENABLE_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

char globalBuffer[GLOBAL_STRING_BUFFER_SIZE];

const char *heatingSystem  = "heating system";
const char *sendDataSystem = "send data system";

const char *started  = "started";
const char *stopped  = "stopped";
const char *enabled  = "enabled";
const char *disabled = "disabled";

const char *on  = "on";
const char *off = "off";

const char *error = "ERR";
const char *ack   = "ACK";

const char *unknown = "unknown";

const char* space  = " ";
