#arrays in julia are dynamic, but adding to them/cutting them uses a special set of functions

arr = [1,2,3,4,5]
push!(arr, 6) #arr = [1,2,3,4,5,6]
println(pop!(arr))
println(arr)
