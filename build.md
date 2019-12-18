# Build Tips

##  Spectre-mitigated libraries
If you get a CMake error saying:
```
error MSB8040: Spectre-mitigated libraries are required for this project.
```
Then install additional build tools:
* Start Visual Studio Installer 
* Modify Visaul Studio
* Click Individual Components
* Under "Compilers > build tools > and runtimes" find your MSVC version (ex. v14.23)
* Select the "spectre-mitigated libs" nearby that matches your MSVC version
* Click Modify