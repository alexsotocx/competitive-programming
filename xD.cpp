(define (cos x n)(cosx 1 1 1 -1 x n))
(define (cosx t u i s x n)
        (if (= i n) t
        (cosx (+ t (* u s (\ (* x x) (* (* 2 i) (- (* 2 i) 1))))) (* u (\ (* x x) (* (* 2 i) (- (* 2 i) 1))))(+ i 1)  (* -1 s)  x n)
    )
)
