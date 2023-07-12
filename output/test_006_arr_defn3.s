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
                                  # T0 = ALLOC 32
          addi  sp, sp, -32             
          mv    t0, sp                  
                                  # ı
          li    t1, 0                   
                                  # STORE T1 -> T0, 0
          sw    t1, 0(t0)               
                                  # T2 = ALLOC 32
          addi  sp, sp, -32             
          mv    t1, sp                  
                                  # ı
          li    t2, 1                   
                                  # STORE T3 -> T2, 0
          sw    t2, 0(t1)               
                                  # ı
          li    t2, 2                   
                                  # STORE T4 -> T2, 4
          sw    t2, 4(t1)               
                                  # ı
          li    t2, 3                   
                                  # STORE T5 -> T2, 8
          sw    t2, 8(t1)               
                                  # ı
          li    t2, 4                   
                                  # STORE T6 -> T2, 12
          sw    t2, 12(t1)              
                                  # ı
          li    t2, 5                   
                                  # STORE T7 -> T2, 16
          sw    t2, 16(t1)              
                                  # ı
          li    t2, 6                   
                                  # STORE T8 -> T2, 20
          sw    t2, 20(t1)              
                                  # ı
          li    t2, 7                   
                                  # STORE T9 -> T2, 24
          sw    t2, 24(t1)              
                                  # ı
          li    t2, 8                   
                                  # STORE T10 -> T2, 28
          sw    t2, 28(t1)              
                                  # T11 = ALLOC 32
          addi  sp, sp, -32             
          mv    t1, sp                  
                                  # ı
          li    t2, 7                   
                                  # STORE T12 -> T11, 0
          sw    t2, 0(t1)               
                                  # ı
          li    t2, 8                   
                                  # STORE T13 -> T11, 4
          sw    t2, 4(t1)               
                                  # ı
          li    t2, 5                   
                                  # STORE T14 -> T11, 8
          sw    t2, 8(t1)               
                                  # ı
          li    t2, 6                   
                                  # STORE T15 -> T11, 12
          sw    t2, 12(t1)              
                                  # ı
          li    t2, 3                   
                                  # STORE T16 -> T11, 16
          sw    t2, 16(t1)              
                                  # ı
          li    t2, 4                   
                                  # STORE T17 -> T11, 20
          sw    t2, 20(t1)              
                                  # ı
          li    t2, 1                   
                                  # STORE T18 -> T11, 24
          sw    t2, 24(t1)              
                                  # ı
          li    t2, 2                   
                                  # STORE T19 -> T11, 28
          sw    t2, 28(t1)              
                                  # T20 = ALLOC 32
          addi  sp, sp, -32             
          mv    t1, sp                  
                                  # ı
          li    t2, 1                   
                                  # STORE T21 -> T20, 0
          sw    t2, 0(t1)               
                                  # ı
          li    t2, 2                   
                                  # STORE T22 -> T20, 4
          sw    t2, 4(t1)               
                                  # ı
          li    t2, 7                   
                                  # STORE T23 -> T20, 8
          sw    t2, 8(t1)               
                                  # ı
          li    t2, 8                   
                                  # STORE T24 -> T20, 12
          sw    t2, 12(t1)              
                                  # ı
          li    t2, 5                   
                                  # STORE T25 -> T20, 16
          sw    t2, 16(t1)              
                                  # ı
          li    t2, 3                   
                                  # STORE T26 -> T20, 20
          sw    t2, 20(t1)              
                                  # T27 = ALLOC 32
          addi  sp, sp, -32             
          mv    t1, sp                  
                                  # ı
          li    t2, 7                   
                                  # STORE T28 -> T27, 0
          sw    t2, 0(t1)               
                                  # ı
          li    t2, 8                   
                                  # STORE T29 -> T27, 4
          sw    t2, 4(t1)               
                                  # ı
          li    t2, 5                   
                                  # STORE T30 -> T27, 8
          sw    t2, 8(t1)               
                                  # ı
          li    t2, 6                   
                                  # STORE T31 -> T27, 12
          sw    t2, 12(t1)              
                                  # ı
          li    t2, 3                   
                                  # STORE T32 -> T27, 16
          sw    t2, 16(t1)              
                                  # ı
          li    t2, 4                   
                                  # STORE T33 -> T27, 20
          sw    t2, 20(t1)              
                                  # ı
          li    t2, 0                   
                                  # STORE T34 -> T27, 24
          sw    t2, 24(t1)              
                                  # ı
          li    t2, 0                   
                                  # STORE T35 -> T27, 28
          sw    t2, 28(t1)              
                                  # ı
          li    t2, 3                   
                                  # ı
          li    t3, 1                   
                                  # ı
          li    t4, 2                   
                                  # T39 <- (T36 * T38)
          mul   t2, t2, t4              
                                  # T40 <- (T39 + T37)
          add   t2, t2, t3              
                                  # ı
          li    t3, 4                   
                                  # T42 <- (T40 * T41)
          mul   t2, t2, t3              
                                  # T43 <- (T27 + T42)
          add   t2, t1, t2              
                                  # T44 <- LOAD T43, 0
          lw    t2, 0(t2)               
                                  # ı
          li    t3, 0                   
                                  # ı
          li    t4, 0                   
                                  # ı
          li    t5, 2                   
                                  # T48 <- (T45 * T47)
          mul   t3, t3, t5              
                                  # T49 <- (T48 + T46)
          add   t3, t3, t4              
                                  # ı
          li    t4, 4                   
                                  # T51 <- (T49 * T50)
          mul   t3, t3, t4              
                                  # T52 <- (T27 + T51)
          add   t3, t1, t3              
                                  # T53 <- LOAD T52, 0
          lw    t3, 0(t3)               
                                  # T54 <- (T44 + T53)
          add   t2, t2, t3              
                                  # ı
          li    t3, 0                   
                                  # ı
          li    t4, 1                   
                                  # ı
          li    t5, 2                   
                                  # T58 <- (T55 * T57)
          mul   t3, t3, t5              
                                  # T59 <- (T58 + T56)
          add   t3, t3, t4              
                                  # ı
          li    t4, 4                   
                                  # T61 <- (T59 * T60)
          mul   t3, t3, t4              
                                  # T62 <- (T27 + T61)
          add   t1, t1, t3              
                                  # T63 <- LOAD T62, 0
          lw    t1, 0(t1)               
                                  # T64 <- (T54 + T63)
          add   t1, t2, t1              
                                  # ı
          li    t2, 2                   
                                  # ı
          li    t3, 0                   
                                  # ı
          li    t4, 2                   
                                  # T68 <- (T65 * T67)
          mul   t2, t2, t4              
                                  # T69 <- (T68 + T66)
          add   t2, t2, t3              
                                  # ı
          li    t3, 4                   
                                  # T71 <- (T69 * T70)
          mul   t2, t2, t3              
                                  # T72 <- (T0 + T71)
          add   t0, t0, t2              
                                  # T73 <- LOAD T72, 0
          lw    t0, 0(t0)               
                                  # T74 <- (T64 + T73)
          add   t0, t1, t0              
          mv    a0, t0                  
          mv    sp, fp                  
          lw    ra, -4(fp)              
          lw    fp, -8(fp)              
          ret                           
