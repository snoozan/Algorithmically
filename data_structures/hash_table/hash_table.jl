#julia behaves much like python with its use of dictionaries

for (key, value) in ["dog"=>"mammal", "lizard"=>"reptile", "cat"=>"mammal", "human"=>"mammal"]
    println("$key is a $value")
end
