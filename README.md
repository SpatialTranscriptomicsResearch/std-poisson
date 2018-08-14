This is code to perform Poisson regression for Spatial Transcriptomics data as described in [this publication](https://doi.org/10.1038/s41467-018-04724-5):

*Spatial maps of prostate cancer transcriptomes reveal an unexplored landscape of heterogeneity*<br>
Emelie Berglund, Jonas Maaskola, Niklas Schultz, Stefanie Friedrich, Maja Marklund, Joseph Bergenstråhle, Firas Tarish, Anna Tanoglidi, Sanja Vickovic, Ludvig Larsson, Fredrik Salmén, Christoph Ogris, Karolina Wallenborg, Jens Lagergren, Patrik Ståhl, Erik Sonnhammer, Thomas Helleday & Joakim Lundeberg<br>
Nature Communications, volume 9, Article number: 2419 (2018)


Whereas you can find [here](https://github.com/SpatialTranscriptomicsResearch/std-nb) the code for the Negative Binomial regression model described in<br>
*Charting Tissue Expression Anatomy by Spatial Transcriptome Deconvolution*<br>
Jonas Maaskola, Ludvig Bergenstråhle, Aleksandra Jurek, José Fernández Navarro, Jens Lagergren, Joakim Lundeberg<br>
doi: https://doi.org/10.1101/362624

## Dependencies

In order to compile it, you need two libraries:
* [Boost](http://www.boost.org/), version 1.58.0 or newer
* [Armadillo](http://arma.sourceforge.net/), version 6.400 or newer

## Compiling
You build and install the code as follows.
Note that ```<INSTALL_PREFIX>``` is a path below which the program will be installed.
This could be e.g. ```$HOME/local``` to install into a user-local prefix.

```sh
cd build
./gen_build.sh -DCMAKE_INSTALL_PREFIX=<INSTALL_PREFIX>
make
make install
```

The above will build both a release and a debug version of the code. Please use `make release` or `make debug` in place of `make` above if you want to build only the release or debug version. The binary for the release version will be called `std` and the binary for the debug version will be called `std-dbg`.

Note that ```<INSTALL_PREFIX>/bin``` and ```<INSTALL_PREFIX>/lib``` have to be included in your ```PATH``` and ```LD_LIBRARY_PATH``` environment variables, respectively.

To do this you have to have lines like the following

```sh
export PATH=<INSTALL_PREFIX>/bin:$PATH
export LD_LIBRARY_PATH=<INSTALL_PREFIX>/lib:$LD_LIBRARY_PATH
```

to your ```$HOME/.bashrc``` file (or similar in case you are a shell other than bash).

## Related
Note that you can find script to analyse the output of this package in [another git repository](https://gits-15.sys.kth.se/maaskola/multiScoopIBP-scripts).
