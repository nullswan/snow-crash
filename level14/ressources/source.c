
undefined4 main(void)

{
  bool bVar1;
  long lVar2;
  undefined4 uVar3;
  int iVar4;
  __uid_t _Var5;
  uint uVar6;
  int in_GS_OFFSET;
  char *pcVar7;
  FILE *pFVar8;
  int iVar9;
  char local_114 [256];
  int local_14;
  
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  bVar1 = false;
  iVar9 = 1;
  pFVar8 = (FILE *)0x0;
  lVar2 = ptrace(PTRACE_TRACEME,0,1,0);
  if (lVar2 < 0) {
    pcVar7 = "You should not reverse this";
    puts("You should not reverse this");
    uVar3 = 1;
  }
  else {
    pcVar7 = getenv("LD_PRELOAD");
    if (pcVar7 == (char *)0x0) {
      iVar9 = open("/etc/ld.so.preload",0);
      if (iVar9 < 1) {
        iVar4 = syscall_open("/proc/self/maps",0);
        if (iVar4 == -1) {
          iVar9 = 0x46;
          pFVar8 = (FILE *)0x1;
          pcVar7 = "/proc/self/maps is unaccessible, probably a LD_PRELOAD attempt exit..\n";
          fwrite("/proc/self/maps is unaccessible, probably a LD_PRELOAD attempt exit..\n",1,0x46,
                 stderr);
          uVar3 = 1;
        }
        else {
          do {
            do {
              while( true ) {
                pFVar8 = (FILE *)0x100;
                pcVar7 = local_114;
                iVar9 = iVar4;
                uVar6 = syscall_gets((int)pcVar7,0x100);
                if (uVar6 == 0) goto LAB_08048ead;
                iVar9 = isLib(local_114,(int)&DAT_08049063);
                if (iVar9 == 0) break;
                bVar1 = true;
              }
            } while (!bVar1);
            iVar9 = isLib(local_114,(int)&DAT_08049068);
            if (iVar9 != 0) {
              iVar9 = 0x20;
              fwrite("Check flag.Here is your token : ",1,0x20,stdout);
              _Var5 = getuid();
              pFVar8 = stdout;
              if (_Var5 == 0xbbe) {
                pcVar7 = ft_des("H8B8h_20B4J43><8>\\ED<;j@3");
                fputs(pcVar7,pFVar8);
              }
              else if (_Var5 < 0xbbf) {
                if (_Var5 == 0xbba) {
                  pcVar7 = ft_des("<>B16\\AD<C6,G_<1>^7ci>l4B");
                  fputs(pcVar7,pFVar8);
                }
                else if (_Var5 < 0xbbb) {
                  if (_Var5 == 3000) {
                    pcVar7 = ft_des("I`fA>_88eEd:=`85h0D8HE>,D");
                    fputs(pcVar7,pFVar8);
                  }
                  else if (_Var5 < 0xbb9) {
                    if (_Var5 == 0) {
                      iVar9 = 0x21;
                      fwrite("You are root are you that dumb ?\n",1,0x21,stdout);
                    }
                    else {
LAB_08048e06:
                      iVar9 = 0x38;
                      fwrite("\nNope there is no token here for you sorry. Try again :)",1,0x38,
                             stdout);
                    }
                  }
                  else {
                    pcVar7 = ft_des("7`4Ci4=^d=J,?>i;6,7d416,7");
                    fputs(pcVar7,pFVar8);
                  }
                }
                else if (_Var5 == 0xbbc) {
                  pcVar7 = ft_des("?4d@:,C>8C60G>8:h:Gb4?l,A");
                  fputs(pcVar7,pFVar8);
                }
                else if (_Var5 < 0xbbd) {
                  pcVar7 = ft_des("B8b:6,3fj7:,;bh>D@>8i:6@D");
                  fputs(pcVar7,pFVar8);
                }
                else {
                  pcVar7 = ft_des("G8H.6,=4k5J0<cd/D@>>B:>:4");
                  fputs(pcVar7,pFVar8);
                }
              }
              else if (_Var5 == 0xbc2) {
                pcVar7 = ft_des("74H9D^3ed7k05445J0E4e;Da4");
                fputs(pcVar7,pFVar8);
              }
              else if (_Var5 < 0xbc3) {
                if (_Var5 == 0xbc0) {
                  pcVar7 = ft_des("bci`mC{)jxkn<\"uD~6%g7FK`7");
                  fputs(pcVar7,pFVar8);
                }
                else if (_Var5 < 0xbc1) {
                  pcVar7 = ft_des("78H:J4<4<9i_I4k0J^5>B1j`9");
                  fputs(pcVar7,pFVar8);
                }
                else {
                  pcVar7 = ft_des("Dc6m~;}f8Cj#xFkel;#&ycfbK");
                  fputs(pcVar7,pFVar8);
                }
              }
              else if (_Var5 == 0xbc4) {
                pcVar7 = ft_des("8_Dw\"4#?+3i]q&;p6 gtw88EC");
                fputs(pcVar7,pFVar8);
              }
              else if (_Var5 < 0xbc4) {
                pcVar7 = ft_des("70hCi,E44Df[A4B/J@3f<=:`D");
                fputs(pcVar7,pFVar8);
              }
              else if (_Var5 == 0xbc5) {
                pcVar7 = ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I");
                fputs(pcVar7,pFVar8);
              }
              else {
                if (_Var5 != 0xbc6) goto LAB_08048e06;
                pcVar7 = ft_des("g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|");
                fputs(pcVar7,pFVar8);
              }
              pcVar7 = (char *)0xa;
              pFVar8 = stdout;
              fputc(10,stdout);
              goto LAB_08048ead;
            }
            pcVar7 = afterSubstr(local_114,(int)"00000000 00:00 0");
          } while (pcVar7 != (char *)0x0);
          iVar9 = 0x30;
          pFVar8 = (FILE *)0x1;
          pcVar7 = "LD_PRELOAD detected through memory maps exit ..\n";
          fwrite("LD_PRELOAD detected through memory maps exit ..\n",1,0x30,stderr);
LAB_08048ead:
          uVar3 = 0;
        }
      }
      else {
        iVar9 = 0x25;
        pFVar8 = (FILE *)0x1;
        pcVar7 = "Injection Linked lib detected exit..\n";
        fwrite("Injection Linked lib detected exit..\n",1,0x25,stderr);
        uVar3 = 1;
      }
    }
    else {
      iVar9 = 0x25;
      pFVar8 = (FILE *)0x1;
      pcVar7 = "Injection Linked lib detected exit..\n";
      fwrite("Injection Linked lib detected exit..\n",1,0x25,stderr);
      uVar3 = 1;
    }
  }
  if (local_14 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pcVar7,pFVar8,iVar9);
}
