#!/bin/sh

#*****************************************************************************#
#*  Author        : Дракончик												 *#
#*  Machine       : Personal Computer  										 *#
#*  Language      : Shell Script                                             *#
#*                                                                           *#
#*  File Contents : Converting all the .png into .sprite for Libdragon       *#
#*  File Attribute: SOURCE                                                   *#
#*  File Name     : spriteConverter.sh                                       *#
#*                                                                           *#
#*****************************************************************************#

MKSPRITE="$HOME/N64Development/Tools/mksprite"
PATH0="Graphics/"
PATH1="Background/"
PATH2="Images/"
PATH3="Sprites/"
cd $PATH0
cd $PATH1
$MKSPRITE *.png
ls
cd ..
cd $PATH2
$MKSPRITE *.png
ls
cd ..
cd $PATH3
$MKSPRITE *.png
ls
