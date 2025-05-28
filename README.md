# pGRAMSBalloon

## Main Software Repository for the pGRAMS Balloon Flight

This repository is meant to collect the various software repositories being
used on the pGRAMS balloon flight. Each repository is included as a git 
submodule so it links to a specific _commit_ in a repository. The aim is
to ensure the versions of software match which is important, especially for
iner-computer communication.

To use the repository, clone it with 
```
git clone https://github.com/NevisNeutrinos/pGRAMSBalloon.git
```
and run 
```
git submodule update --init --recursive
```
where the `init` will initialize your local git configuration file and 
`update` will fetch the files of the submodules. The `recursive` command
will fetch files of nested submodules which is the case for the TPC readout
software.
