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
                                  # �
          li    t0, 1                   
                                  # �
          li    t0, 2                   
                                  # �
          mv    t1, t0                  
                                  # �
          li    t0, 3                   
                                  # �
          mv    t0, t0                  
                                  # T6 <- (T2 + T1)
          add   t0, t1, t0              
          mv    a0, t0                  
          mv    sp, fp                  
          lw    ra, -4(fp)              
          lw    fp, -8(fp)              
          ret                           
