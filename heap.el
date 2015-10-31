;;; First function found that can read a file and I understood
(defun read-file (filePath)
  "Return a string of a file's contents at filePath."
  (with-temp-buffer
    "Put file in a string."
    (insert-file-contents filePath)
    (buffer-string)))

;; Just added split-string on the buffer-string so I had a list of strings
(defun read-lines (filePath)
  "Return a list of lines of a file at filePath."
  (with-temp-buffer
    "Put file in a string and split string on new lines."
    (insert-file-contents filePath)
    (split-string (buffer-string) "\n" t)))

;; This is required for my loop
(require 'cl-lib)

(cl-loop for string in (read-lines "num.txt")
      collect (string-to-number string))

(make-array 7 :adjustable t :fill-pointer 0)


