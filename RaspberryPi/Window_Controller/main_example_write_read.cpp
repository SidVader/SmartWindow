#include "write_read.h"


int main (void) {																	// example: presents the writing and reading in and out of a database
   MYSQL  *mysql = mysql_init(NULL);												// initialize MYSQL-Handle
   bool b_wert = false;
   double d_wert = 0;
   bool erf = false;
   bool succeeded_bool = false;														// bool for errorinformation for the try of getting a bool
   bool *succ_bool = &succeeded_bool;
   bool succeeded_double = false;													// bool for errorinformation for the try of getting a double
   bool *succ_double = &succeeded_double;

   erf = write_in_db(mysql, "SmartWindow", "AutoModus", "false");					// parameter: 1.MYSQL-handle, 2.db name, 3.tabularname, 4.value to write
// erf = write_in_db(mysql, "SmartWindow", "Temp_IN", "35.4452");

   b_wert = get_latest_value_bool(mysql, "SmartWindow", "AutoModus", succ_bool);	// parameter: 1.MYSQL-handle, 2.db name, 3.tabularname, 4.pointer points to information
   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   		// whether writing was successful

// d_wert = get_latest_value_double(mysql, "SmartWindow", "AutoModus", succ_double);
   d_wert = get_latest_value_double(mysql, "SmartWindow", "Temp_IN", succ_double);

   printf("successfully written: %s",(erf)? "true\n" : "false\n");
   printf("value as double: %f\n",d_wert);
   printf("value as bool: %s",(b_wert) ? "true\n" : "false\n");
   printf("bool successfull read: %s",(succeeded_bool) ? "true\n" : "false\n");
   printf("double successfull read: %s",(succeeded_double) ? "true\n" : "false\n");

   return 0;
}



