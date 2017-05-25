/*

  Easy to Use example of rBASE64 Library

  This example shows the calling convention for the various functions.



  Created by Behrooz Sirouszad (boseji) on 22/02/2017.
  Copyright 2017 - Under creative commons license 3.0:
     

  @version API 1.0.0
  @author Behrooz Sirouszad@gmail.com

*/

#include <rBase64.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(rbase64.encode("Hello There, I am doing Good."));
  Serial.println(rbase64.decode("SGVsbG8gVGhlcmUsIEkgYW0gZG9pbmcgR29vZC4="));
  delay(2000);
}

