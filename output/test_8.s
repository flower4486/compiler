          .text                         
          .data                         
          .global                       a
a:
          .word                         10
          .globl main                   
          .align 2                      

          .text                         
main:                                   # function entry
          sw    ra, -4(sp)              
          sw    fp, -8(sp)              
          mv    fp, sp                  
          addi  sp, sp, -8              
__LL0:                                  
                                  # T1 <- LOAD_SYMBOL a
          la    t0, a                   
                                  # T2 <- LOAD T1, 0
          lw    t0, 0(t0)               
          mv    a0, t0                  
          mv    sp, fp                  
          lw    ra, -4(fp)              
          lw    fp, -8(fp)              
          ret                           
