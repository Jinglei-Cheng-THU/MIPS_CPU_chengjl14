`define CACHE_LINE_LEN	128	//每行128bit，16字节，4字
`define CACHE_LINE_OFF	4	//行内偏移位4bit
`define CACHE_GROUPS	64	//64组，每组4关联行
`define CACHE_GROUP_IDX	6	//组间6bit寻址
`define CACHE_TAG_LEN	(32 - `CACHE_LINE_OFF - `CACHE_GROUP_IDX)
`define TLB_LENGTH	16


`define ALUFN_ADD	4'h0
`define ALUFN_SUB	4'h1
`define ALUFN_SLL	4'h2
`define ALUFN_SRL	4'h3
`define ALUFN_SRA	4'h4
`define ALUFN_ROTR	4'h5
`define ALUFN_AND	4'h6
`define ALUFN_OR	4'h7
`define ALUFN_XOR	4'h8
`define ALUFN_NOR	4'h9
`define ALUFN_SLT	4'ha
`define ALUFN_SLTU	4'hb

