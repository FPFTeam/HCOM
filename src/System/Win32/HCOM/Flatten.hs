-- This file is licensed under the New BSD License
{-# LANGUAGE MultiParamTypeClasses #-}
{-# LANGUAGE FlexibleInstances #-}
{-# LANGUAGE FunctionalDependencies #-}

--
-- Flatten.hs:
--
-- Convert nested tuples in to a flat tuple.
--

module System.Win32.HCOM.Flatten(Flatten(..)) where

-- Nested tuples are built up by the operations in a 'Stack', which
-- generally takes the results so far and sticks it in a pair with the
-- latest result. This type class is used to take the nested tuple,
-- and convert it into a big flattened tuple which we might actually
-- feel happy returning to the user. It saves extra boilerplate in the
-- interface definitions.

class Flatten a b | a -> b where
    flatten :: a -> b

instance Flatten () () where
    flatten = const ()

instance Flatten ((),a)   a where
    flatten      ((),a) = a

instance Flatten (((),a),b)   (a,b) where
    flatten      (((),a),b) = (a,b)

instance Flatten ((((),a),b),c)   (a,b,c) where
    flatten      ((((),a),b),c) = (a,b,c)

instance Flatten (((((),a),b),c),d)   (a,b,c,d) where
    flatten      (((((),a),b),c),d) = (a,b,c,d)

instance Flatten ((((((),a),b),c),d),e)   (a,b,c,d,e) where
    flatten      ((((((),a),b),c),d),e) = (a,b,c,d,e)

instance Flatten (((((((),a),b),c),d),e),f)   (a,b,c,d,e,f) where
    flatten      (((((((),a),b),c),d),e),f) = (a,b,c,d,e,f)

instance Flatten ((((((((),a),b),c),d),e),f),g)   (a,b,c,d,e,f,g) where
    flatten      ((((((((),a),b),c),d),e),f),g) = (a,b,c,d,e,f,g)

instance Flatten (((((((((),a),b),c),d),e),f),g),h)   (a,b,c,d,e,f,g,h) where
    flatten      (((((((((),a),b),c),d),e),f),g),h) = (a,b,c,d,e,f,g,h)
