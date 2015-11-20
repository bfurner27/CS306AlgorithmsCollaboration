; big numbers library
(require 'calc.el)

				    
;retrieved from: http://math.stackexchange.com/questions/1073118/find-the-leftmost-most-significant-digits-of-a-large-exponent-calculation-say


;; function we are using:
;floor(10^(exp*log(2;10)-floor(exp*log(2;10))) * 10^(numDigits-1))

(defun pow2digits (exp numDigits)
  (let ((n (* exp (log10 2)))) 
       (floor
	(*
	 (expt 10 (- n (floor n)))
	 (expt 10 (- numDigits 1))))))
pow2digits

(pow2digits 2829282928 8)

(calc-precision 100)

(calc-eval "10^($*log10(2) - floor($*log10(2))) * 10 ^ ($$ - 1)" nil 1000 100)



