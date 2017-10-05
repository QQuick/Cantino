$destination = "C:\Users\info_000\Documents\Arduino\libraries\cantino"
Remove-Item $destination -recurse
Copy-Item .\library $destination -recurse