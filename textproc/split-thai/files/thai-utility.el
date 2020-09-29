(require 'thingatpt)
(require 'mule-util)
(require 'thai-word)

" nested-alist from mule-util looks like this:          "
"  '(3585 1                       ;; ก      word   ก    "
"    (3591 1                      ;;  ง     word   กง   "
"          (3585 t                ;;    ก               "
"                (3634 t          ;;     า              "
"                      (3619 1))));;      ร word   กงการ"
"    (3585 1                      ;;  ก     word   กก   "
"          (3621 1))))            ;;   ล    word   กกล  "

(defun extract-thai-na(nlist thaistr)
  "helper function to reconstruct thai words from a nested alist,
uses recursion"
  (let ((ucode)
	(complete))
    (cond
     ;; finished
     ((not nlist) nil)

     ;; (3591 1 ...
     ((integerp (car nlist))
      ;; xxx care about coding-system vars here?
      (setq ucode (char-to-string (car nlist)))
      (setq complete (cadr nlist))
      (setq thaistr (concat thaistr ucode))
      (cond
       ;; t => no word at this depth 
       ((equal complete t)
	(extract-thai-na (cddr nlist) thaistr))
       ;; 1 => word at this depth
       ((equal complete 1)
	(append (list thaistr)
		(extract-thai-na (cddr nlist) thaistr)))
       (t
	(error "invalid parsing for complete var"))))
     
     ;; not finished
     (t
      (append (extract-thai-na (car nlist) thaistr)
	      (extract-thai-na (cdr nlist) thaistr))))))

(defun thai-word-table-in-p(thaiword)
 "return t if thaiword is in 'thai-word-table, nil otherwise"
  (let ((result
	 (lookup-nested-alist
	  thaiword thai-word-table (length thaiword) 0 t)))
    (and (listp result)
	 (integerp (car result))
	 (= 1 (car result)))))

(defun thai-word-table-save(filename &optional alist)
  "save thai words extracted from a nested-alist table to
filename in utf8 format, one word per line.  default is to save
'thai-word-table if no alist argument given.  Returns number of
dictionary words."
  (interactive "FName of file to save to: \nP")
  (let ((thaiwords)
	(elem)
	(line_count)
	(coding-system-for-read 'utf-8)
	(coding-system-for-write 'utf-8)
	(buffer-file-coding-system 'utf-8))
    ;; default list or not
    (setq alist (or alist
		    thai-word-table))

    (or (nested-alist-p alist)
      (error "Invalid argument %s" alist))

    ;; remove 'thai-words from 'thai-word-table
    (setq alist (cdr alist))

    (with-temp-buffer
      ;; process per-letter list one at a time.  could process whole
      ;; list at once but maybe try to conserve memory resources
      (while (setq elem (car alist))
	(setq alist (cdr alist))
	(setq thaiwords (extract-thai-na elem ""))
	
    	(dolist (elem thaiwords)
	  (insert elem "\n")))

      (sort-lines nil (point-min) (point-max))
      (setq line_count (count-lines (point-min) (point-max)))
      (write-region nil nil filename)
      line_count)))

(defun count-words-nested-alist (&optional alist)
  "Count number of words in a nested alist. if no arg given,
count 'thai-word-table words"
  (interactive)
  (let ((count 0)
	(elem)
	(thaiwords))
    ;; default list or not
    (setq alist (or alist thai-word-table))
    (or (nested-alist-p alist)
	(error "Invalid argument %s" alist))
    ;; remove 'thai-words from 'thai-word-table
    (setq alist (cdr alist))
    (while (setq elem (car alist))
      (setq alist (cdr alist))
      (setq thaiwords (extract-thai-na elem ""))
      (setq count (+ count (length thaiwords))))
    (message "%d words in nested alist" count)
    count))

(defun thai-update-word-table-utf8 (file &optional append)
  "Update Thai word table by replacing the current word list with
FILE, which is utf-8.  If called with a prefix argument, FILE is
appended instead to the current word list.  Does the same as
'thai-update-word-table, except that function expects
'thai-tis620 encoding which appears to be the default format for
at least emacs version <= 28"
  (interactive "FThai word table file: \nP")
  (let* ((coding-system-for-read 'utf-8)
	 (coding-system-for-write 'utf-8)
	 (buffer-file-coding-system 'utf-8)
	 (temp_file (make-temp-file "thaiutf8_")))
    (unwind-protect
	(with-temp-buffer
	  (insert-file-contents file)
	  (setq coding-system-for-write 'thai-tis620)
	  (write-file temp_file))
      (thai-update-word-table temp_file append)
      (delete-file temp_file)
      thai-word-table)))

(defun thai-word-table-save-defvar(dictfile lispfile)
  "read a utf8 thai dictionary file and save to a lisp file
suitable for initializing the 'thai-word-table as a \"defvar\".
Overwrites the lisp file if it exists.  Returns count of
dictionary words."
  (interactive)
  (let ((header)
	(footer)
	(elem)
	(line_count)
	(coding-system-for-read 'utf-8)
	(coding-system-for-write 'utf-8)
	(buffer-file-coding-system 'utf-8))
    (setq header (list
		  ";; file auto-generated from thai-word-table-save-defvar"
		  ""
		  "(defvar thai-word-table"
		  "(let ((table (list 'thai-words)))"
		  "(dolist (elt"
		  "'(" ))
    (setq footer (list
		  "))"
		  "(set-nested-alist elt 1 table))"
		  "table)"
		  "\"Nested alist of Thai words.\")" ))
    (with-temp-buffer
      (insert-file-contents dictfile)
      ;; quote each thai word
      (goto-char (point-min))
      (while (search-forward-regexp "\\ct+" nil t)
	(replace-match (concat "\"" (match-string 0) "\"")))
      (setq line_count (count-lines (point-min) (point-max)))
      ;; insert lisp code for defvar 
      (goto-char (point-min))
      (dolist (elem header)
	(insert elem "\n"))
      (goto-char (point-max))
      (dolist (elem footer)
	(insert elem "\n"))
      ;; indent for lisp and save
      (lisp-mode)
      (indent-region (point-min) (point-max))
      (write-region nil nil lispfile))
    line_count))

(defun split-thai-word()
  "Break Thai word at point by inserting spaces at word
boundaries. (wrapper for 'thai-break-words)"
  (interactive)
  (let* ((start (point))
	 (bounds (bounds-of-thing-at-point 'word))
	 (p1 (car bounds))
	 (p2 (cdr bounds))
	 (instr (buffer-substring-no-properties p1 p2))
	 (outstr))
    (with-temp-buffer
      (insert instr)
      (goto-char(point-min))
      (thai-break-words " ")
      (split-thai-numbers (point-min) (point-max))
      (setq outstr (buffer-string)))
    (delete-region p1 p2)
    (insert outstr)
    (goto-char start)))

(defun split-thai-line()
  "Break Thai words from point to end of line by inserting a
space at word boundaries. (wrapper for 'thai-break-words)"
  (interactive)
  (thai-break-words " " (line-end-position))
  (split-thai-numbers (point) (line-end-position)))

(defun split-thai()
  "Break Thai words from point to end of buffer by inserting a
space at word boundaries. (wrapper for 'thai-break-words)"
  (interactive)
  (thai-break-words " " (point-max))
  (split-thai-numbers (point) (point-max)))

(defun split-thai-numbers(start_point end_point)
  "helper function to separate numbers in a buffer.
'thai-break-words doesn't always split numbers properly. this may
improve tokenization somewhat."
  ;; xxx this really should be fixed in 'thai-word lib
  (let* ((num_rexp "\\([0-9\u0e50-\u0e59]+\\)") ;; numbers
	 (nonnum_rexp "\\([\u0e00-\u0e4f\u0e5a-\u0e7f]\\)") ;; "non-numbers"
	 (trailing_rexp (concat num_rexp nonnum_rexp))
	 (leading_rexp (concat nonnum_rexp num_rexp)))
    (save-restriction
      (narrow-to-region start_point end_point)
      (goto-char (point-min))
      (while (search-forward-regexp trailing_rexp nil t)
	(replace-match (concat (match-string 1) " " (match-string 2))))
      (goto-char (point-min))
      (while (search-forward-regexp leading_rexp nil t)
	(replace-match (concat (match-string 1) " " (match-string 2))))
      (goto-char start_point))))
