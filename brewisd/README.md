
How to compile
==============

```bash
git clone git@github.com:emilianobovetti/brewis.git

cd brewis/brewisd

apt-get install opam m4 libffi-dev libssl-dev libbluetooth-dev

opam init

eval `opam config env`

opam install ocamlfind async async_ssl cohttp config-file yojson

make
```
