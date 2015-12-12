(defun pow2digits (exp numDigits log10of2)
  (let ((n (calc-eval "$*$$" nil exp log10of2)))
   (calc-eval "floor(10^($ - floor($)) * 10 ^ ($$ - 1))" nil n numDigits)))

(defun findLowerLimit (searchNum)
  (calc-eval "floor(log($)/log(2))" nil searchNum))

(defun search (searchNum)
  (let ((numDigits (length searchNum))
	(lowerBound (string-to-number(findLowerLimit searchNum)))
	(log10of2 (calc-eval "log10(2)")))
    (calc-precision (* numDigits 4))
    (while (not (string= searchNum (pow2digits lowerBound numDigits log10of2)))
      (setq lowerBound (1+ lowerBound)))
    lowerBound))

