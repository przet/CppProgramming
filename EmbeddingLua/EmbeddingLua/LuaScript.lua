-- function time!
-- Table
player = {}
player["Title"] = "master"
player["Name"] = "wilberforce"
player["Family"] = "paladin"
player["Level"] = 4

-- Alternatively:
-- player = {Title = "master",...etc}

function AddStuff(a, b)
    -- print will use std::cout apparently
    print("[LUA] AddStuff("..a..", "..b..") called \n")
    return a + b 
end



