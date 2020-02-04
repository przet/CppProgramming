players = {}
players[0] = {Title = "master", Name = "wilberforce", Family = "paladin", Level = 4}
players[1] = {Title = "student", Name = "henry the young", Family = "barbarian", Level = 1}


function AddStuff(a, b)
    -- print will use std::cout apparently
    print("[LUA] AddStuff("..a..", "..b..") called \n")
    return a + b 
end

function GetPlayer(n)
	return players[n]
end




