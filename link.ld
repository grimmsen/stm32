MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 128K
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    .text : {
        /* Set the initial address to 0 */
        . = 0;
        LONG(ORIGIN(RAM)+LENGTH(RAM));
        LONG(main | 1);
        . = 0x058;
        LONG(__extint_ext0_handler | 1);
        . = 0x0b0;
        LONG(0 | 1);
        /* The whole interrupt table is 332 bytes long. Advance to that position. */
        . = 332;
        /* And here comes the rest of the code */
        *(.text*)
    } > FLASH /* Put this in the flash memory region */
    .bss : {
      *(.bss*)
    } > RAM
}
