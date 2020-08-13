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
		(extract-thai-na (cddr nlist) thaistr) '()))
       (t
	(error "invalid parsing for complete var"))))
     
     ;; not finished
     (t
      (append (extract-thai-na (car nlist) thaistr)
	      (extract-thai-na (cdr nlist) thaistr) '())))))

(defun thai-word-table-save(filename &optional alist)
  "save thai words extracted from a nested-alist table to
filename in utf8 format.  default is to save 'thai-word-table if
no alist argument given."
  (interactive)
  (let ((thaiwords)
	(elem)
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
      (write-region nil nil filename)
      (buffer-string))))

;; 'thai-tis620 is default for emacs <= 28
(defun thai-update-word-table-utf8 (file &optional append)
  "Update Thai word table by replacing the current word list with
FILE, which is in utf-8.  If called with a prefix argument, FILE
is appended instead to the current word list.  Does the same as
'thai-update-word-table, except that function expects
'thai-tis620 encoding"
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
