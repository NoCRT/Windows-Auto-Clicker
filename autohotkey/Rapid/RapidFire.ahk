; This script clicks at 15 cps

;#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
#Warn  ; Enable warnings to assist with detecting common errors.
;SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.
Suspend, on ; set script to be suspended by default

;Home::Suspend
;Home::SoundPlay, %A_WinDir%\auto_off.wav

Home::
Suspend, permit
if (A_IsSuspended = "0")
{
    SoundPlay, auto_off.wav
    ;TrayTip, Suspended, %A_ScriptName%, , 1
}
Else
{
    SoundPlay, auto_on.wav
    ;TrayTip, UnSuspended, %A_ScriptName%, , 1
}
Suspend, Toggle

LButton::
Loop
{
SetMouseDelay 30
Click
If (GetKeyState("LButton","P")=0)
Break
}