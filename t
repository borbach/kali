15c15
< menuentry 'Kali GNU/Linux' --class kali --class gnu-linux --class gnu --class os $menuentry_id_option 'gnulinux-simple-becf42b4-075c-4329-a9d7-69e97f1a62bb' {
---
> menuentry 'Kali GNU/Linux' --class kali --class gnu-linux --class gnu --class os $menuentry_id_option 'gnulinux-simple-6b8653b2-603b-43d2-9add-6cd6587c343e' {
18c18
< 	insmod part_msdos
---
> 	insmod part_gpt
20c20,21
< 	search --no-floppy --fs-uuid --set=root 7d8616eb-07e1-4618-aabe-82b4586794d8
---
> 	set root='hd2,gpt2'
> 	search --no-floppy --fs-uuid --set=root --hint-bios=hd1,gpt2 --hint-efi=hd1,gpt2 --hint-baremetal=ahci1,gpt2 --hint='hd2,gpt2'  535d47fb-00ce-4b6f-a694-6bfcdcf5b520
22c23
< 	linux	/vmlinuz-6.3.0-kali1-amd64 root=/dev/mapper/asus14--vg-root ro  quiet splash
---
> 	linux	/vmlinuz-6.3.0-kali1-amd64 root=/dev/mapper/asus16--vg-root ro  quiet splash
27a29,31
> 
> 
> 
