Extended Ogre
=============

This is an alternative scene graph implementation on top of Ogre 3D (www.ogre3d.org). It completely replaces
the default scene graph in Ogre with a streamlined and more cache friendly variant.


Building
========

Execute the following to build and install the library.

    cd /path/to/project
    mkdir build
    cd build
    cmake -DOGRE_PATH=/path/to/ogre -DBOOST_PATH=/path/to/boost -DZZIP_PATH=/path/to/zzip -DFREE_IMAGE_PATH=/path/to/free-image -DCMAKE_INSTALL_PREFIX=<Install path> -DCMAKE_BUILD_TYPE=Release ..
    make && make install
