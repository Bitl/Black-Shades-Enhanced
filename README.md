# Black Shades Enhanced

Hello everyone. Very recently, I figured out how to compile the code of Black Shades' Windows port, which I documented here:

```
I might have figured out how to compile the Windows version of the game properly.
 
Black Shades uses SDL 1.2.5 for **Visual C++ 6**, the OpenAL **1.0** SDK, GLUT v37 beta, and optionally the Vorbis OGG api (IDK what version you need because I didn't compile it with the ogg sdk but you might find it by searching around).
 
Additionally, you need to have Visual C++ 6.0, a Windows XP machine or virtual machine (due to incompatibility issues), and of course, the source code which you can find here: https://forums.wolfire.com/viewtopic.php?f=2&t=1355&p=174394.
 
All you need to do really is to reconfigure the directory in VC6 and compile, which is really as easy as it sounds!
 
If my compiled file works (I'm gonna test it later on today) I plan on adding a higher FPS limit, improved customlevels.txt editing, and other things. IDK yet.
```

About 7 years ago, there was a [forum post](https://forums.wolfire.com/viewtopic.php?t=15294) detailing the possible modding that could be done with Black Shades, however nothing was really done with it. 1-2 years ago, I decided to try to compile it on VS 2013 to no avail.

But recently I figured out a way to compile it, and thus the Black Shades Enhanced mod was born.

**What is included?**

As of v1.0.0:
- Increased the FPS limit from 90 to 300.
- Allows the user to set the FPS limit in the config.txt
- Allows the user to run the game in windowed mode.
- Added an icon for use in Windowed Mode.
- Added SQL_Image support

**Images:**

![1](https://github.com/Bitl/Black-Shades-Enhanced/raw/master/images/img1.png)

![2](https://github.com/Bitl/Black-Shades-Enhanced/raw/master/images/img2.png)

![3](https://github.com/Bitl/Black-Shades-Enhanced/raw/master/images/img3.png)

**Credits:**

All credits go to Wolfire Games and David for the creation of Black Shades.

**Download and Source Code:**

Downloads: https://github.com/Bitl/Black-Shades-Enhanced/releases
Source: https://github.com/Bitl/Black-Shades-Enhanced
Issues page: https://github.com/Bitl/Black-Shades-Enhanced/issues

Feel feee to contribute if you're interested in making new features for the mod!