package main

/*
#cgo CFLAGS: -I. 
#cgo LDFLAGS: -L. -lluahost -llua

#include <stdlib.h>
#include <stdio.h>
#include "lua-host.h"
*/
import "C"
import "fmt"
import "os"
import "bufio"


func lua(text string) {
  C.call_lua(C.CString(text))
}

func main() {
  reader := bufio.NewReader(os.Stdin)

  for true {
    fmt.Print(": ")
    text, _ := reader.ReadString('\n')
    go lua(text)
  }
}
