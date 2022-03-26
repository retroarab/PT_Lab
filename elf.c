#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void readelf(FILE* fp,char par[])
{
    int bit_op=0;
    char magic[4];
    char arch[2];
    int bit_64=0;
    fread(&magic,4,1,fp);
    if(strchr(par,'h'))
    {
        if((magic[0]==0x7f) && (magic[1]==0x45) && (magic[2]==0x4c) && (magic[3]==0x46))
        {
            printf("Valid ELF file \n");
        }
        else
        {
            printf("Not a valid ELF file\n");
            return;
        }
        fread(&arch,2,1,fp);
        if(arch[0]==1)
        {
            printf("This is a 32-BIT ELF file \n");
        }
        else if(arch[0]==2)
        {
            printf("This is a 64-bit ELF file \n");
            bit_64=1;
        }
        if(arch[1]==1)
        {
            printf("Intel little edian \n");
        }
        else if(arch[1]==2)
        {
            printf("SPARC arhitecture Big Edian\n");
        }
        char orgl;
        fread(&orgl,1,1,fp);
        if(orgl==1)
        {
            printf("Original and current version of ELF\n");
        }
        else
        {
            printf("Not original and current version of ELF \n");
        }
        char ABI;
        fread(&ABI,1,1,fp);
        switch(ABI)
        {
            case 0:
                printf("System V\n");
                break;
            case 1:
                printf("HP-UX\n");
                break;
            case 2:
                printf("NetBSD\n");
                break;
            case 3:
                printf("Linux\n");
                break;
            case 4:
                printf("GNU Hurd \n");
                break;
            case 6:
                printf("Solaris \n");
                break;
            case 7:
                printf("AIX\n");
                break;
            case 8:
                printf("IRIX\n");
                break;
            case 9:
                printf("FreeBSD\n");
                break;
            case 'A':
                printf("Tru64");
                break;
            case 'B':
                printf("Novell Modesto \n");
                break;
            case 'C':
                printf("OpenBSD\n");
                break;
            case 'D':
                printf("OpenVMS\n");
                break;
            case 'E':
                printf("NonStop Kernel\n");
                break;
            case 'F':
                printf("Aros\n");
                break;
            case 10:
                printf("Fenix OS\n");
                break;
            case 11:
                printf("Cloud ABI\n");
                break;
            case 12:
                printf("Stratus Technologies OpenVOS\n");
                break;
        }
        char junk[8];
        fread(&junk,8,1,fp);
        char exec[2];
        fread(&exec,2,1,fp);
        if(strcmp(exec,"0x02"))
        {
            printf("Executable\n");
        }
        else if(strcmp(exec,"0x00"))
        {
            printf("Unkown type\n");
        }
        else if(strcmp(exec, "0x01"))
        {
            printf("Relocatable file\n");
        }
        else if(strcmp(exec,"0x03"))
        {
            printf("Shared object \n");
        }
        else if(strcmp(exec,"0x04"))
        {
            printf("Core file \n");
        }
        else if(strcmp(exec,"0xFE00") || strcmp(exec,"0xFEFF"))
        {
            printf("Reserved inclusive range. Operating system specific.\n");
        }
        else if(strcmp(exec,"0xFF00") || strcmp(exec, "0xFFFF"))
        {
            printf("Reserved inclusive range. Processor specific.\n");
        }
        char instrset[2];
        fread(&instrset,2,1,fp);
        if(strcmp(instrset,"0x3E"))
        {
            printf("AMD x86-64\n");
        }
        else if(strcmp(instrset,"0x03"))
        {
            printf("x86\n");
        }
        else if(strcmp(instrset,"0x00"))
        {
            printf("No specific instruction set \n");
        }
        else if(strcmp(instrset,"0x01"))
        {
            printf("AT&T WE 32100\n");
        }
        else if(strcmp(instrset,"0x02"))
        {
            printf("SPARC\n");
        }
        else if(strcmp(instrset,"0x03"))
        {
            printf("x86\n");
        }
        else if(strcmp(instrset,"0x04"))
        {
            printf("Motorola 68000 (M68k) \n");
        }
        else if(strcmp(instrset,"0x05"))
        {
            printf("Motorola 88000 (M88k)\n");
        }
        else if(strcmp(instrset,"0x06"))
        {
            printf("Intel MCU\n");
        }
        else if(strcmp(instrset,"0x07"))
        {
            printf("Intel 80860\n");
        }
        else if(strcmp(instrset,"0x08"))
        {
            printf("	MIPS \n");
        }
        else if(strcmp(instrset,"0x09"))
        {
            printf("	IBM System/370\n");
        }
        else if(strcmp(instrset,"0x0A"))
        {
            printf("MIPS RS3000 Little-endian\n");
        }
        //
        else if(strcmp(instrset,"0x0E"))
        {
            printf("	Hewlett-Packard PA-RISC\n");
        }
        else if(strcmp(instrset,"0x13"))
        {
            printf("Intel 80960 \n");
        }
        else if(strcmp(instrset,"0x14"))
        {
            printf("PowerPC\n");
        }
        else if(strcmp(instrset,"0x15"))
        {
            printf("PowerPC (64-bit) \n");
        }
        else if(strcmp(instrset,"0x16"))
        {
            printf("S390, including S390x\n");
        }
        else if(strcmp(instrset,"0x17"))
        {
            printf("IBM SPU/SPC \n");
        }
        else if(strcmp(instrset,"0x24"))
        {
            printf("NEC V800\n");
        }
        else if(strcmp(instrset,"0x25"))
        {
            printf("Fujitsu FR20\n");
        }
        else if(strcmp(instrset,"0x26"))
        {
            printf("TRW RH-32\n");
        }
        else if(strcmp(instrset,"0x27"))
        {
            printf("Motorola RCE \n");
        }
        else if(strcmp(instrset,"0x28"))
        {
            printf("ARM (up to ARMv7/Aarch32)\n");
        }
        else if(strcmp(instrset,"0x29"))
        {
            printf("Digital Alpha\n");
        }
        //
        else if(strcmp(instrset,"0x2A"))
        {
            printf("SuperH\n");
        }
        else if(strcmp(instrset,"0x2B"))
        {
            printf("SPARC Version 9 \n");
        }
        else if(strcmp(instrset,"0x2C"))
        {
            printf("Siemens TriCore embedded processor\n");
        }
        else if(strcmp(instrset,"0x2D"))
        {
            printf("Argonaut RISC Core\n");
        }
        else if(strcmp(instrset,"0x2E"))
        {
            printf("	Hitachi H8/300\n");
        }
        else if(strcmp(instrset,"0x2F"))
        {
            printf("Hitachi H8/300H \n");
        }
        else if(strcmp(instrset,"0x30"))
        {
            printf("Hitachi H8S\n");
        }
        else if(strcmp(instrset,"0x31"))
        {
            printf("Hitachi H8/500\n");
        }
        else if(strcmp(instrset,"0x32"))
        {
            printf("IA-64\n");
        }
        else if(strcmp(instrset,"0x33"))
        {
            printf("Stanford MIPS-X \n");
        }
        else if(strcmp(instrset,"0x34"))
        {
            printf("Motorola ColdFire\n");
        }
        else if(strcmp(instrset,"0x35"))
        {
            printf("Motorola M68HC12\n");
        }
        else if(strcmp(instrset,"0x36"))
        {
            printf("Fujitsu MMA Multimedia Accelerator\n");
        }
        else if(strcmp(instrset,"0x37"))
        {
            printf("Siemens PCP\n");
        }
        else if(strcmp(instrset,"0x38"))
        {
            printf("Sony nCPU embedded RISC processor \n");
        }
        else if(strcmp(instrset,"0x39"))
        {
            printf("Denso NDR1 microprocessor\n");
        }
        else if(strcmp(instrset,"0x3A"))
        {
            printf("Motorola Star*Core processor\n");
        }
        else if(strcmp(instrset,"0x3B"))
        {
            printf("Toyota ME16 processor\n");
        }
        else if(strcmp(instrset,"0x3C"))
        {
            printf("STMicroelectronics ST100 processor \n");
        }
        else if(strcmp(instrset,"0x3D"))
        {
            printf("Advanced Logic Corp. TinyJ embedded processor family\n");
        }
        else if(strcmp(instrset,"0x8C"))
        {
            printf("TMS320C6000 Family\n");
        }
        //
         else if(strcmp(instrset,"0xAF"))
        {
            printf("MCST Elbrus e2k\n");
        }
        else if(strcmp(instrset,"0xB7"))
        {
            printf("ARM 64-bits \n");
        }
        else if(strcmp(instrset,"0xF3"))
        {
            printf("RISC-V \n");
        }
        else if(strcmp(instrset,"0xF7"))
        {
            printf("Berkeley Packet Filter\n");
        }
        else if(strcmp(instrset,"0x101"))
        {
            printf("WDC 65C816\n");
        }
        fread(&junk,4,1,fp);
        if(bit_64)
        {
            bit_op=8;
        }
        else
        {
            bit_op=4;
        }
        u_int16_t memadr;
        fread(&memadr,bit_op,1,fp);
        printf("Entry point adress :  0x%x \n",memadr);
        u_int16_t phoff;
        fread(&phoff,bit_op,1,fp);
        printf("Start of program header  : %d ( bytes in file ) \n",phoff);
        u_int32_t eshoff;
        fread(&eshoff,4,1,fp);
        printf("Start of section headers %d (bytes in file )\n",eshoff);
        u_int32_t flags;
        fread(&flags,bit_op,1,fp);
        printf("Flag : \t 0x%x \n",flags);
        u_int8_t size_h;
        u_int8_t p_h;
        fread(&size_h,2,1,fp);
        printf("Size of header file is : %d\n",size_h);
        fread(&p_h,2,1,fp);
        printf("Size of program headers is : %d \n",p_h);
        u_int8_t all;
        fread(&all,2,1,fp);
        printf("Number of program headers is : %d \n",all);
        fread(&all,2,1,fp);
        printf("Size of section headers is : %d\n",all);
        fread(&all,2,1,fp);
        printf("Number of section headers is : %d\n",all);
        fread(&all,2,1,fp);
        printf("Section header string table index : %d \n",all);
    }


}

unsigned long int filesize(FILE* fp)
{
    long l;
    fseek(fp,0,SEEK_END);
    l=ftell(fp);
    fseek(fp,0,SEEK_SET);
    return l;
}

int main(int argc,char* argv[])
{
    FILE* fp;
    if(argc<3)
    {
        printf("We need more arguments \n");
        exit(EXIT_FAILURE);
    }
    fp=fopen(argv[1],"rb");
    if(!fp)
    {
        printf("Failed to open file %s for reading \n",argv[1]);
        exit(EXIT_FAILURE);
    }
    printf("Size of file in bytes is : %u \n",filesize(fp));
    readelf(fp,argv[2]);
    fclose(fp);
    return 0;
}