# DeathTracker

This is the DeathTracker Mod

For now, you can only see your death stats through the file for each level.
This mod will be updated with features as it ages.

Plans for the future:
    * Track in practice mod toggle
    * In-game stat viewer
    * Track attempts in custom levels
    * Ability to export the file to an external program to view it in a graph

(How to read files!)
You can access your files through ".\AppData\Local\GeometryDash\geode\mods\zelfmonco.deathtracker"
Each file is named after the level ID of the main level: level_[level ID].txt.
Reading the file is easiest in an IDE such as Visual Studio Code where you can see line numbers.
0% is on line one and 1% is on line 2 and so on.
You can subtract one from the line number to get your percentage using this.
The number on each line represents how many deaths you have said percent.
