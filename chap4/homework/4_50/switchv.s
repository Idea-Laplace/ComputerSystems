00000000000011d0 <switchv>:
    11d0:	f3 0f 1e fa          	endbr64
    11d4:	b8 dd 0d 00 00       	mov    $0xddd,%eax
    11d9:	48 83 ff 05          	cmp    $0x5,%rdi
    11dd:	77 0b                	ja     11ea <switchv+0x1a>
    11df:	48 8d 05 3a 0e 00 00 	lea    0xe3a(%rip),%rax        # 2020 <CSWTCH.2>
    11e6:	48 8b 04 f8          	mov    (%rax,%rdi,8),%rax
    11ea:	c3                   	ret
