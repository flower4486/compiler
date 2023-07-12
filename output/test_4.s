          .text                         
          .data                         
          .globl main                   
          .align 2                      

          .text                         
main:                                   # function entry
          sw    ra, -4(sp)              
          sw    fp, -8(sp)              
          mv    fp, sp                  
          addi  sp, sp, -8              
__LL0:                                  
                                  # ü
          li    t0, 1                   
                                  # ü
          li    t0, 2                   
                                  # ü
          mv    t1, t0                  
                                  # ü
          li    t0, 3                   
                                  # ü
          mv    t0, t0                  
                                  # T6 <- (T2 + T1)
          add   t0, t1, t0              
          mv    a0, t0                  
          mv    sp, fp                  
          lw    ra, -4(fp)              
          lw    fp, -8(fp)              
          ret                           
