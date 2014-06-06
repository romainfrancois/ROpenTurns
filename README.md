# ROpenTurns

[![Build Status](https://travis-ci.org/romainfrancois/ROpenTurns.png?branch=master)](https://travis-ci.org/romainfrancois/ROpenTurns)

`ROpenTurns` provides bindings between `R` and [`open turns`](http://www.openturns.org/)
through [`Rcpp`](http://rcpp.org/). 

The package has only been tested on ubuntu so far. To install it you first need
to install open turns: 

```
curl http://debian.openturns.org/openturns.org-repo.key | sudo apt-key add -
sudo add-apt-repository -y "http://ubuntu.openturns.org/dists/precise/main/"
sudo apt-get install libopenturns-dev
```

And then you should be able to install `ROpenTurns` :

```
install_github( 'romainfrancois/ROpenTurns' )
```
