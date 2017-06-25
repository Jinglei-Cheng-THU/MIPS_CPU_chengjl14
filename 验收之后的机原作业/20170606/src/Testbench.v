module TestBench;

reg         clk;
reg         rst;
integer     i, outfile, counter;

always #10 clk = ~clk;    

pipelined_mips mips(
    .clk(clk),
    .rst(rst)
);
  
initial begin

    counter = 0;
    clk = 0;
    rst = 0;
    
    #20
    rst = 1;
    
end

endmodule
