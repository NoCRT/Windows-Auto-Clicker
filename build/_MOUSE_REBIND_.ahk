#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
#Warn  ; Enable warnings to assist with detecting common errors.
#MaxThreads 4
#Persistent
#SingleInstance force

SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

ScrollLock::Suspend

~$LButton::
	Random, rand, 20, 30
	While GetKeyState("LButton", "P"){
        SendEvent, {Ralt Down};
	Sleep, rand ;  milliseconds
    }
    SendEvent, {RAlt Up}
return