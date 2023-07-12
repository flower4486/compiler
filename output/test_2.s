          .text                         
          .data                         
          .global                       b
b:
          .word                         5
          .global                       a
a:
          .word                         3
          .globl main                   
          .align 2                      

          .text                         
main:                                   # function entry
          sw    ra, -4(sp)              
          sw    fp, -8(sp)              
          mv    fp, sp                  
          addi  sp, sp, -8              
__LL0:                                  
                                  # T2 <- LOAD_SYMBOL a
          la    t0, a                   
                                  # T3 <- LOAD T2, 0
          lw    t0, 0(t0)               
                                  # T4 <- LOAD_SYMBOL b
          la    t1, b                   
                                  # T5 <- LOAD T4, 0
          lw    t1, 0(t1)               
                                  # T6 <- (T3 + T5)
          add   t0, t0, t1              
          mv    a0, t0                  
          mv    sp, fp                  
          lw    ra, -4(fp)              
          lw    fp, -8(fp)              
          ret                           
