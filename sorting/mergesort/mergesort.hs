-- mergesort in haskell
-- author: Susan Lunn

split :: [a] -> ([a],[a])
split (x:y:zs) = let (xs, ys) = split zs
                 in (x:xs, y:ys)
split xs       = (xs, [])

merge :: (a -> a -> Bool) -> [a] -> [a] -> [a]
merge pred xs []         = xs
merge pred [] xs         = xs
merge pred (x:xs) (y:ys) 
    | pred x y           = x: merge pred xs (y:ys)
    | otherwise          = y: merge pred (x:xs) ys

mergesort :: (a -> a -> Bool) -> [a] -> [a]
mergesort pred []  = []
mergesort pred [x] = [x]
mergesort pred xs  = let (xs1, xs2) = split xs
                     in merge pred (mergesort pred xs1) (mergesort pred xs2) 

