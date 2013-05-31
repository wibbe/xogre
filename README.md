Extended Ogre
=============

This is an alternative scene graph implementation on top of Ogre 3D (www.ogre3d.org). It completely replaces
the default scene graph in Ogre with a streamlined and more cache friendly variant.


Building
========

Execute the following to build and install the library.

    cd <Project root>
    mkdir build
    cd build
    cmake -DOGRE_PATH=<Path to Ogre3D> -DBOOST_PATH=<Path to Boost> -DZZIP_PATH=<Path to ZZip> -DFREE_IMAGE_PATH=<Path to FreeImage> -DCMAKE_INSTALL_PREFIX=<Install path> -DCMAKE_BUILD_TYPE=Release ..
    make && make install
