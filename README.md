# Genesis OS
### A brief forray into OS dev

![gplv3-or-later.png]

Everything is essentially implemented ver-batim from [https://wiki.osdev.org]

Implemented:
 - Booting with Limine
 - Boilerplate (GDT, IDT, PIC, ISR)
 - Terminal printer
 - A bit of a libc
 - Basic file IO
 - Incomplete implementation of USTAR filesystem

Thanks to the cool people in the OSDev Discord server for putting up with my nonsense!

## Dependencies

 - [https://github.com/limine-bootloader/limine](Limine)
 - [https://github.com/stivale/stivale](Stivale \(Submodule\))
