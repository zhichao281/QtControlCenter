package.path = ".\\?.lua"

serpent = require('serpent')
--lua脚本中的全局变量在c语言中也是全局的吗

vbar_config_t = {qr=1,dm=0,bar=0,beep=1,wled=1,rled=0,bled=0,outp="hid",com_con="115200-N-8-1",prefix="vguang",postfix="18",wrap=1,fv="6.0.0.1",ov="2017/02/15"}

function writecfg()
    local file = io.open("./config.txt", "w+")
    if(file) then
		file:write(serpent.line(vbar_config_t))
		file:close()
	end
end
	

function readcfg()
    local file = io.open("./config.txt", "r")
    assert(file)
    if file then
		data = file:read("*a")
		file:close()
	end
	if data then
		local ok
		ok ,vbar_config_t = serpent.load(data)
	end
	
end
function merge( tDest, tSrc )
    for k, v in pairs( tSrc ) do
        tDest[k] = v
    end
end

function updatecfg(str)
	assert(str)
	local vbar_config_d
	local ok
		ok, vbar_config_t = serpent.load(str)
end

function getvalue_num(key)
	print("in lua : key is ")
	print(key)
	if vbar_config_t[key] ~= nil then
		print(vbar_config_t[key])
		return vbar_config_t[key]
	else
		print(vbar_config_t[key])
		print(vbar_config_t[key])
		return -1
	end
end

function getvalue_str(key)
print("in lua : key is ")
	print(key)
	if vbar_config_t[key] ~= nil then
	
	print(vbar_config_t[key])
		return vbar_config_t[key]
	else
	print(vbar_config_t[key])
		local str = ""
		return str
	end
end

