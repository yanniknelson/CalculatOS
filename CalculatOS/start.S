
.section ".text.boot"

.global _start

_start:
    mrs     x1, mpidr_el1                 // read cpu id from mpidr_el
    and     x1, x1, #3                    // select last two bits (0-3)
    cbz     x1, 2f                        // if x1 (CPU id) is zero, branch to label 2 otherwise vv (2f means label 2, look forward)
1:  wfe                                   // wait for an event
    b       1b                            // jump to label 1 (wait for event). This is an infinte do nothing loop

2:  ldr     x1, =_start                   // set top of stack just before our code (stack grows to a lower address per AAPCS64)
    mov     sp, x1                        // can't load it directly into the stack pointer, load it into x1 then move x1 into the stack pointer

    // clear bss
    ldr     x1, =__bss_start
    ldr     w2, =__bss_size

3:  cbz     w2, 4f                        // if we've zeroed out all of the bss, jup to label 4 (enter kernel)
    str     xzr, [x1], #8                 // store zero at the address pointed to by x1 and then add 8 to x1 to point to the next byte
    sub     w2, w2, #1                    // subtract 1 (byte) from the size count
    cbnz    w2, 3b                        // if the bss has not been filled with 0s then jump to label 3 otherwise continue onwards (2b means label 3, look backwards)

4:  bl      main                          // jump to C code, should not return
    b       1b                            // jump to label 1 (wait for event). Takes it to the infinite do nothing loop