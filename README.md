Just a simple example template for making coremods for [Unreal Mod Loader](https://github.com/RussellJerome/UnrealModLoader)

To get started, either clone/fork the repo, else click "Use this template".

Then do `git submodule init` then `git submodule update`

After compiling, the output should exist in x64/Release/ExampleMod.dll

If you want to change your mods name, just rename the files and class, as well as update the modname itself in the header. If you change the header file name / class name, make sure to update the stuff inside of dllmain.cpp with the new class and header file.