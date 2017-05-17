`timescale 10 ns / 1 ns

module testbench;
    
    reg Clk;
    reg Rst;
    
    integer i;

    initial begin
        $dumpfile("testbench.vcd");
        $dumpvars(0,testbench);
        // $readmemh("./code/xdb_1.txt",mips.IM.im_128k,32'H0C00,32'H0C0e);
        $readmemh("final_hex.txt",mips.IM.im_128k,32'H0C00,32'H0C8F);
        Clk = 0;
        forever #10 Clk=!Clk;
    end

    initial begin
            Rst = 1;
        #20 Rst = 0;
        #2500 begin
            for (i=0; i<32; i=i+1) begin
                 $display("Register[%2d] = %h",i,mips.RF.rf[i]);
            end
            for (i=0; i<'h80; i=i+4) begin
                 $display("DM[%3d] = %h%h%h%h",i,mips.DM.dm_4k[i+3],mips.DM.dm_4k[i+2],mips.DM.dm_4k[i+1],mips.DM.dm_4k[i+0]);
            end          
        end
      //  #10 $finish;   
    end  
    
    mips mips(Clk,Rst);

endmodule
