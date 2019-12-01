# d3dentryparse.py

Generates DDI entry-point stubs for D3D10 and D3D11 drivers.

Uses Clang to parse the UMD header files.
Uses Mako templating system to generate the files.

# Install

1. pip install -r requirements.txt

# Run

```
d3dentryparse.py --wdk <path> --output <path>
```