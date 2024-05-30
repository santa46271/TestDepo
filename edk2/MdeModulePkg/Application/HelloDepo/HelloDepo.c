#include<Uefi.h>
#include <Library/PcdLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiApplicationEntryPoint.h>

EFI_STATUS
EFIAPI
Hello_Depo (IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable) {
  CHAR16 numStr[3] ={'0'};
  for (UINT32 i =1; i <= 20; ++i) {
    if (i<=9) {
      numStr[0] = i + '0';
      numStr[1] = '\0';
    }
    else {
      numStr[0] = i/10 + '0';
      numStr[1] = i%10 + '0';
      numStr[2] = '\0';
    }
    SystemTable->ConOut->OutputString(SystemTable->ConOut, numStr);
    SystemTable->ConOut->OutputString(SystemTable->ConOut, L": Hello, Depo!\r\n");
  }
  return EFI_SUCCESS;
}
