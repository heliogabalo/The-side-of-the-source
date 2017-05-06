DSDT - Differentiated System Description Table - is the biggest and most complex ACPI table. The minimal length is 36 bytes, in reality it is about 20 kb or even more. This table
describes devices and methods for accessing them. These methods can contain arithmetic and logical expressions, representing a program written in a C-like programming language.
Correcting this table means you need to have some sort of programming knowledge. Clover offers an option to automatically apply corrections, however it is important to understand
that an artificial intelligence was not created yet and that the automatic method is far from being complete. It is better to do the corrections manually.
Why does it need to be fixed at all? DSDT patching was created with the intention to fix device HPET - High Precision Events Timer. The point is that OS X includes a kext named
AppleIntelCPUPowerManagement for power management control (SpeedStep), which - by all means - needs interrupts IRQ 0 and 8. Otherwise it will create a kernel panic. This kext can
either be removed or blocker, however you can alternatively correct the DSDT to ensure a normal behaviour of this kext.

Nr. 1 : This is a necessity. Does Mac OS X really need HPET? Not really, but BIOS vendors tend to be slow and they just started writing the correct parameters. Usually a DSDT will
still need to be corrected.

Nr. 2 : A DSDT contains certain dependencies on the operating system like Windows 98, Windows 2001, Windows 2006 or Linux. Mac OS X uses identifier Darwin, which usually is
missing. Even if it is not, it was created for FreeBSD. Mac OS X makes great use of the ACPI system and uses a DSDT to its maximum, as does Windows 2001; but not Linux, Windows 98
and not Windows 2006. It is always correct to mask the system as Windows 2001. Even if you find Darwin in your DSDT, mask it as Windows2001.
Many BIOS variants can use the variable OSYS = 0x07D2, but not 0x07D6, 0x07D9 or 0x2410 as written into a real Mac's DSDT.

Nr. 3 : The vendor of a motherboard's and thus the creator of a DSDT, cannot predict the devices you will be using (CPU, video card, etc.). They should be written into the DSDT
however! Vice versa, devices like the internal speaker, floppy drive or parallel port should be excluded. Their drivers do not exist and are not even needed. Additionally it is
often necessary to add or remove framebuffers/ports to devices like video cards or SATA controllers.
The DSDT is is written into the BIOS and is used by the system in AML binary code. It can be de-/compiled using IASL, which translates binary code into human readable DSL source
code. A user will use this path to apply corrections: AML>DSL>edit>DSL>AML - this is the next point.

Nr. 4 : The last part is made impossible because of syntax and logical errors initially present in the OEM DSDT. You will need to correct them, too. Additionally, you can fix
other mistakes, which prevent the PC from sleeping or waking up, or add new devices. (It is a bit strange, compiling/decompiling is not a strictly reversible operation and will
change the table or even prevent further compiler operations. From my point of view the compiler is not bug-free. Non-conformance to the specification, however, should be
considered as a warning, not as an error).

When you reached this step you can instruct Clover to use your modified DSDT by placing it into the directory EFI/CLOVER/OEM/xxx/ACPI/patched or - when the computer's name is not
known yet - into EFI/CLOVER/ACPI/patched. Alternatively the OS can have its own DSDT in the root of the system partition.
Where can you obtain the initial DSDT that needs to be patched? There are different ways involving Windows, Linux or OS X. If you were able to start Clover somehow, you can enter
its GUI and press F4. If Clover was installed on a FAT32 partition, then it will be able to save all ORM ACPI tables, including DSDT and FADT. The process can take a while,
especially when saving many tables to a USB flash drive. This is especially useful when you have no access to other means of extracting the table set, for example with AIDA64.
Also you can save the patched DSDT variant: enter Options in CloverGUI, change the DSDT mask, exit Options and press F5. A DSDT with the specified patches will be saved, which are
represented in the file name, for example: DSDT-F597.aml. You can save multiple variants for comparison.
Now you can edit the DSDT and if you are not really comfortable doing this, Clover offers some automatic patches:

 DSDT mask
 
  AddDTGP_0001 bit(0)
  
  For injecting device properties you can - apart from DeviceProperties - use a variant involving method _DSM (Device Specific Method), which is written into the DSDT table. _DSM is
  widely used since OS X 10.5. It contains properties for a device and makes use of the method DTGP, which is universal for all devices. This fix simply adds the DTGP method for
  later use with other fixes. It has no significance on its own.
  
   FixDarwin_0002 bit(1)
   
   Provide a set of corrections to DSDT to make your system "Darwin" identified as "Windows 2001" like the most ACPI system. More ACPI devices will work in this mode. Old way this
   bit also provide fixes: FIX_WAK_200000, DeleteUnused_400000, FIX_ACST_4000000, FIX_S3D_2000000, AddPNLF_1000000, FIX_ADP1_800000
   
    FixShutdown_0004 bit(2)
    
    A condition is added to method _PTS: if the argument is 5 (shutdown), then no other actions shall be performed. Many reports confirmed this option to fix shutdown issues with ASUS
    boards, maybe even with other vendors. Some DSDT tables already contain such a condition and it is advised to turn the fix off in this case.
    
     AddMCHC_0008 bit(3)
     
     Added device MCHC to DSDT. For my board H61M this is obligatory, else KP. Old way also included AddIMEI_80000.
     
      FixHPET_0010 bit(4)
      
      Add IRQ(0, 8, 11) to device HPET. Obligatory for OSX <=10.8. But I see Mavericks can work without it. Old way also included FIX_RTC_20000, FIX_TMR_40000.
      
       FakeLPC_0020 bit(5)
       
       Changes the DeviceID of the LPC controller to allow the loading of kext AppleLPC. This fix is necessary when the chipset is not recognised by OS X. However, the list of supported
       Intel and NForce chipsets is so big that the fix is rarely needed. Verify if AppleLPC is loaded and use this fix, if it is not. Moreover, the kext can unload itself even if the
       chipset is supported.
       
        FixIPIC_0040 bit(6)
        
        Removes the interrupt from device IPIC. Helpful for Power button will work.
        
         FixSBUS_0080 bit(7)
         
         Adds an SMBusController to the device tree, which fixes a warning about its absence in the system log. Helps to sleep/wake.
         
          FixDisplay_0100 bit(8)
          
          Create device GFX0 if still absent. It is needed for correct Power Management but the device is usually absent in DSDT because it is not a part of the motherboard. Added also
          device HDAU that is HDMI sound device on the videocard. If we set FakeID in config.plist it will be inserted here. Old way this patch will affect all video cards, included
          embedded Intel GFX. New way Intel will be patched separately.
          
           FixIDE_0200 bit(9)
           
           10.6.1 introduces a kernel panic related to AppleIntelPIIXATA. There are two options to solve the problem: using a patched kext or patching the DSDT. Probably not needed for
           recent systems.
           
            FixSATA_0400 bit(10)
Fixes several SATA problems and removes yellow hard drive icons by masking the controller as ICH6. The method is controversial but it can fix the DVD drive and simply replacing
the hard drive icons is not enough in this case. An alternative is to patch the kext AppleAHCIPort.kext, see KextsToPatch.

 FixFirewire_0800 bit(11)
 
 Add device Firewire into DSDT if absent and if the device really present. Adds the property fwhub to the device.
 
  FixUSB_1000 bit(12)
  
  Tries fixing USB the countless USB issues for USB1.0, USB2.0 and USB3.0.
  
   FixLAN_2000 bit(13)
   
   Injects the property built-in to the Ethernet card, which is necessary for correct operation. Additionally injects the card's name for a better looking System Profiler. Also made
   FakeID for some known substitutions.
   
    FixAirport_4000 bit(14)
    
    Same as above for WiFi. Furthermore, the actual device is created and written into DSDT. A DeviceID will automatically written for known cards to enable airport functionality.
    
     FixHDA_8000 bit(15)
     
     Corrects sound card properties to enable the native AppleHDA driver. The name is changed from AZAL to HDEF, layout-id and PinConfiguration are injected. Adding HMDI device if
     absent.
     
      Setting for NewWay patching
      
       NewWay_80000000
       
       Define that all bits will work new way.
       
        FIX_RTC_20000
        
        Exclude IRQ(0) from RTC device.
        
         FIX_TMR_40000
         
         Exclude IRQ(8) from TMR device. This is ancient DOS device and not needed in modern computers. Just wonder it present.
         
          AddIMEI_80000
          
          This device is used for IntelHDxxx graphics. Adding them if very desirable operation. This bit also needed for use FakeID->IMEI. Do nothing for Core 2 systems.
          
           FIX_INTELGFX_100000
           
           New way IntelGFX device will not be patched without this bit.
           
            FIX_WAK_200000
            
            adding Return(Package(0)) into method _WAK if absent. This patch is for warning elimination. I don't know about working influence.
            
             DeleteUnused_400000
             
             There are not used devices like Floppy drive, LPT port and others that will be good to delete from DSDT.
 FIX_ADP1_800000
 
 Rename AC0 device to ADP1 device.
 
  AddPNLF_1000000
  
  Adding device PNLF is very useful: only with it you may have brightness control. This patch is also influence on good Sleep/Wake of the system.
  
   FIX_S3D_2000000
   
   Also resolving some Sleep/Wake problems by correcting _S3D methods.
   
    FIX_ACST_4000000
    
    Name ACST have different use for Apple and for ASUS. For ASUS it is AC adapter state. For Apple it is a replacement for _CST, c-states table. To not conflict it is needed to
    rename such names to something else.
    
     FixRegions_10000000
     
     Address of some regions in DSDT depends on many factors and may change time to time
     
     OperationRegion (GNVS, SystemMemory, 0xDE6A4E18, 0x01CD)
     
     The presence of floating regions make impossible to use custom DSDT because this region may be shifted and will not correspond to current state. This patch is intended to find all
     such regions in BIOS and correct them in custom DSDT. So now you can produce your custom DSDT with wrong regions and set this patch.
     
      Choosing the right mask
      
      How can you choose the necessary patches and how do you know which ones are harmless or dangerous? The computer will not be harmed either way. All the changes are stored memory
      only and will be removed after rebooting.
      You can try setting different combinations in CloverGUI and save them by pressing F5 in the Options menu.
      To make sure the currently patched DSDT is not creating a conflict, you can change the DSDT name in the menu - DSDT name: NO.aml. This file will not be found, Clover will extract
      the original OEM DSDT from BIOS and apply fixes set in the DSDT mask section. In case the OS did not load successfully, your previously set (working) values will be used.
      0xFFFF enables all fixes and if the OS loads successfully this way, you will know that our efforts were not for nothing. Given the descriptions above you already realised that
      some fixes are not needed for your system (for example WiFi), they can even make things worse.
      Most systems, which are neither too old, nor too new, a mask of 0xA7D7 has been proven to produce a well working OS.
      
      New way you may make patched DSDT once with full mask. Then correct patched DSDT manually. Then use this manually patched DSDT.aml loading but set FixRegions_10000000 The mask
      will be 0x90000000 = NewWay_80000000 + FixRegions_10000000