`define ClkCycle 1

module TestBench;
	reg Clk, Rst;

	CPU cpu(Rst, Clk);

	initial begin
		Clk = 1'b0;
		Rst = 1'b0;
		# 10
		Rst = 1'b1;
		# 500
		$finish;
	end

	always #(`ClkCycle) Clk = ~Clk;
	
	initial begin
		$dumpfile("file.dump");
		$dumpvars(0, cpu);
	end
endmodule
