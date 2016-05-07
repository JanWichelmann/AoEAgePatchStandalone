## OVERVIEW

This patch (contained in the AgePatch.dll) enables a fifth "real" age, while moving the "post *" age to the next available ID. It is fully researchable and behaves the same as the original four ages (in singleplayer and multiplayer mode), except for the tech tree (see below).

The launcher starts the age2_x1.exe process and injects the AgePatch.dll. If you want to load it statically (i.e. by inserting the load code into the EXE file itself), you can find the required assembler commands in the injection.h code file.

I created this software while working on the (german) Agearena AddOn (http://www.agearena.de/forum/index.php?mode=viewforum&forum_id=7). There are no known bugs by now, so this release is considered stable.


## USAGE

> AoEAgePatchStandalone.exe PARAMS

PARAMS is the usual call to the Age of Empires process, e.g.: age2_x1.exe nostartup

For mod developers using their own Games/[MODNAME] subfolder, the call may be: 
> AoEAgePatchStandalone.exe age2_x1.exe game=[MODNAME] nostartup


## SYSTEM REQUIREMENTS

As this software is build with Microsoft Visual Studio 2013, you'll need the appropiate Visual C++ redistributable: http://www.microsoft.com/en-us/download/details.aspx?id=40784

This software overwrites some routines the UserPatch v1.4 creates, so that is required (see http://userpatch.aiscripters.net/).

Also some virus scanners may have problems with this software, as it uses DLL injection to patch the running Age of Empires II process. This method is also used by many viruses, so some virus scanners block it by default. If you have problems running this software, try to create an exception in the scanners filter rules.


## IMPORTANT INFORMATION FOR MOD DEVELOPERS

To use this patch you'll have to ensure the following things (example: new age "Renaissance"):

-> LANGUAGE.DLL IDs
- #4205: The title of the new age (e.g. "Renaissance")
- #4207: The title of the new post-age (e.g. "Post-Renaissance")
- #7104: The title of the new age (e.g. "Renaissance")
- #7105: The name of the dark age (e.g. "Dark Age")
- #11365: The abbreviation of dark age for "starting age - maximum age" selection (e.g. "Dark")
- #11366: The abbreviation of feudal age for "starting age - maximum age" selection (e.g. "Feudal")
- #11367: The abbreviation of castle age for "starting age - maximum age" selection (e.g. "Castle")
- #11368: The abbreviation of imperial age for "starting age - maximum age" selection (e.g. "Imperial")
- #11369: The abbreviation of your new age for "starting age - maximum age" selection (e.g. "Renaissance")

-> language_x1.dll IDs
- #3039: The age advancement message for your new age with '%s' player name parameter (e.g. "%s advanced to the Renaissance.")
- #3082: The 'reseed farm queue is full' message (I had to move it from #3039 to #3082)

-> empires2_x1_p1.dat IDs
- The dark age has to be moved to research ID #105 (do not forget to update the related researches like "Loom" to the new ID!)
- Your new age has to replace the dark age on ID #104

When you considered these changes, it should work fine. If I forgot something, contact me :D   
I misused this forum thread for supporting the library: http://aok.heavengames.com/cgi-bin/forums/display.cgi?action=ct&f=9,43926,,all    
Feel free to post there. Maybe I will add an official download entry there later.


## MISSING FEATURES

The patches aren't perfect: The techtree functions aren't changed, as there are very many hardcoded sections; changes would probably break them. Please consider using my tech tree replacement (https://github.com/Janworks/AoETechTree) instead.


## LEGAL INFO & CREDITS

This software is published under the MIT/X11 license. Please read the LICENSE for further information.

The general approach to do a DLL injection ist based on the Code-Project article "A More Complete DLL Injection Solution Using CreateRemoteThread" (http://www.codeproject.com/Articles/20084/A-More-Complete-DLL-Injection-Solution-Using-Creat).
I would like to thank the author for his detailed explanations and examples and recommend this article to everybody who wants to get a deeper understanding of how a DLL injection is performed.
