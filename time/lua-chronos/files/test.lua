local chronos = require("chronos")


local start = chronos.nanotime()
os.execute("sleep 1")
local stop = chronos.nanotime()

print(("sleep took %s seconds"):format(stop - start))
