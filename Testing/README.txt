This directory contains our informal test framework - a COM server
with an interface to exercise our SAFEARRAY infrastructure, plus a
small program which exercises the HCOM SAFEARRAY interface

The program can be run inside Rational Purify to check that we're not
leaking. As there are some initialisation leaks, real leaks can be
found by tweaking the parameter to 'replicateM_' - there should be no
leaks which vary in size with the parameter, as these would be real
leaks of COM-controlled memory.
