ENTRY(mini_crt_entry)

SECTIONS
{
  . = 0x08048000;

  .text : {
    *(.text)
  }

  .rodata : {
    *(.rodata)
  }

  .data : {
    *(.data)
  }

  .bss : {
    __bss_start = .;
    *(.bss)
    *(COMMON)
    __bss_end = .;
  }
}
