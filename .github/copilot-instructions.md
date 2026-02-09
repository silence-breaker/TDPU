# TDPU Development Instructions

## Project Overview
This repository contains the hardware implementation of a Tensor/Transformer Deep Processing Unit (TDPU) aimed at the Fudan Microelectronics "FPAI" competition. The core objective is to design custom FPGA hardware operators (Custom IP) for accelerating 1.58-bit (ternary) LLM inference on the FMQL30TAI-WuJing development board.

The current implementation focuses on a **Vector Multiplication Core (`vec_multi_core`)** that performs efficient dot product operations with ternary weights (-1, 0, +1).

## Architecture & Code Structure

### Core Hardware (SystemVerilog)
- **Location**: `TDPU/` directory.
- **`vec_multi_core.sv`**: The main compute engine.
  - **Inputs**: 
    - `i_data`: Array of 8-bit signed integers (Activations).
    - `i_weight`: Array of 2-bit ternary weights (Weights).
    - Control signals: `i_data_valid`, `i_load_weight`.
  - **Processing**:
    1. **Weight Latching**: Weights are stored in internal registers when `i_load_weight` is high.
    2. **PE Layer**: Parallel multiplication (or rather, selection/negation due to ternary weights).
    3. **Adder Tree**: A pipelined binary adder tree sums up partial results.
  - **Outputs**: `o_result` (32-bit accumulated sum), `o_data_ready`.
- **`package_def.sv`**: Defines the 1.58-bit weight types (`weight_t` enum: `W_POS`, `W_NEG`, `W_ZERO`).

### Verification (Verilator + C++)
- **`sim_main.cpp`**: The C++ testbench for Verilator.
  - Handles signal driving, clock generation, and result checking.
  - Defines helper lambdas for setting wide vector inputs (`set_all_inputs`, `set_all_weights`).
  - **Key Note**: SystemVerilog `packed arrays` (e.g., `logic [15:0][7:0]`) are mapped to `C` arrays of `uint32_t` chunks in Verilator. Use bitwise operations carefully when driving `top->i_data` or `top->i_weight`.

## Development Workflow

### 1. Building and Testing
The verification workflow is automated via a shell script.

- **Command**: Run `./run_sim.sh` from the `TDPU/` directory.
- **What it does**:
  1. Formats SystemVerilog code (using `verible-verilog-format` if available).
  2. Compiles SV to C++ using `verilator`.
  3. Builds the simulation executable.
  4. Runs the simulation (`./obj_dir/Vvec_multi_core`).
  5. Generates waveform traces (`waveform.vcd`).

### 2. Signal Timing & Latency
- The design is **pipelined**.
- **Input**: Data is consumed when `i_data_valid` is high.
- **Output**: Result is valid when `o_data_ready` is high.
- **Latency**: There is a delay between input and output due to the pipeline stages (PE stage + Adder Tree stages). Ensure tests wait enough cycles for `o_data_ready`.

### 3. Data Representation
- **Weights (1.58-bit)**:
  - `W_POS` (2'b10, Value +1)
  - `W_NEG` (2'b00, Value -1)
  - `W_ZERO` (2'b01, Value 0)
- **Activations**: 8-bit signed standard integers.

## Coding Standards
- **SystemVerilog**: Use `always_ff` for sequential logic and `always_comb` for combinational logic. Explicitly handle reset (`rst_n`).
- **File extensions**: Use `.sv` for SystemVerilog.
- **Tools**: Prefer `verilator` for fast simulation and linting over heavier commercial tools during the dev loop.

## Common Tasks
- **Adding a new pipeline stage**: Update the `vec_multi_core` logic and verify timing in `sim_main.cpp`.
- **Changing vector width**: Modify `parameter int LEN` in `vec_multi_core.sv` and ensure the C++ testbench (`set_all_inputs`) logic adapts to the new width (handling 128-bit vs 256-bit mapping correctly).
