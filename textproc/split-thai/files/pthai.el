;; Copyright (c) 2021 Sean Cole <scole@NetBSD.org>
;; All rights reserved.
;;
;; Redistribution and use in source and binary forms, with or without
;; modification, are permitted provided that the following conditions
;; are met:
;;
;; 1. Redistributions of source code must retain the above copyright
;;    notice, this list of conditions and the following disclaimer.
;; 2. Redistributions in binary form must reproduce the above copyright
;;    notice, this list of conditions and the following disclaimer in the
;;    documentation and/or other materials provided with the distribution.
;;
;; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
;; "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
;; TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
;; PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
;; BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
;; CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
;; SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
;; INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
;; CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
;; ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
;; POSSIBILITY OF SUCH DAMAGE.

;; utilities for working with thai text in emacs buffers.  includes
;; functions to split/unsplit thai strings, thai time conversion,
;; download and play mp3 audio for thai words from thai-language.com,
;; clickthai-online.com, and thai2english.com, and currency
;; conversions from x-rates.com.  Also, it can look up thai words if
;; vocabulary files are created.  The 'customize interface is available
;; for a few settings.
;;
;; HOW TO USE
;; - in ~/.emacs/init.el, add library path and a require, e.g.:
;;     (add-to-list 'load-path "ST_SHARE_DIR")
;;     (require 'pthai)
;;   or load module directly:
;;     (load-file "ST_SHARE_DIR/pthai.el")
;;
;; - also in ~/.emacs/init.el, possibly bind keys to some commonly
;;   used functions:
;;	(global-set-key [f8] 'pthai-lookup)
;;      (global-set-key [f9] 'pthai-say-word)
;;      (global-set-key [f10] 'pthai-say-line)
;; - 'customize can be used to set or add paths to words lists and
;;   dictionaries
;; - M-x apropos pthai for available functions
;;
;; TODO
;; - make info file for this module
;; - when splitting, handle unknown/misspelled words better
;; - look up word definitions on the fly (?)
;; - keep original spacing when possible when splitting (?)
;; - interface with pkgsrc/textproc/translate-shell (?),
;;   not sure about licensing issues
;; - don't try to download and say single letters in pthai-say except maybe ๆ. this
;;   happens sometimes when word misspelled or unknown words found
;; - do better breaking of words with ๆ in dictionaries, like สั้นๆ
;; - for pthai-rwb, maybe use non-brute-force/dynamic-programming algorithm
;; - get byte compile working
;; - get initial loading of default wordlist and sample dictionary working
;;   with customize*
;; - create directories as needed through customize interface (?)
;;     pthai-default-directory    ~/.emacs.d/pthai
;;     pthai-audio-directory      ~/.emacs.d/pthai/audio      or specified
;;     dictionaries               ~/.emacs.d/pthai/dictionary or specified w/ pthai-dictionary-list
;;     wordlists                  ~/.emacs.d/pthai/wordlist   or specified w/ pthai-wordlist-list

;; known issues:
;; - doesn't always handle "long" strings well
;; - pthai-say-word after pthai-split line, last word is not always played.
;;   this seems to be emacs *shell* issue
;; - when linting or compiling file, need to "(require 'seq)" first(?)
;;
(require 'cus-edit)   ;; custom* customize*
(require 'ido)        ;; ido-completing-read*
(require 'mule-util)  ;; nested alist functions
(require 'seq)        ;; seq-* functions   
(require 'subr-x)     ;; string-trim* functions
(require 'thai-word)  ;; thai-word-table
(require 'thingatpt)  ;; thing-at-point*
(require 'url)        ;; url-* functions

;; xxx "special" vars to set before loading module, not the emacs way?
(unless (boundp 'pthai-bootstrap)
  (defvar pthai-bootstrap nil "nil unless building for pkgsrc"))

(unless (boundp 'pthai-verbose-wordloads)
  (defvar pthai-verbose-wordloads t
    "if non-nil, display word counts when loading dictionaries or wordlists"))

;; "normal" module variables
(defvar pthai-default-directory (concat user-emacs-directory "pthai/")
  "default pthai directory (ensure ends with directory separator)")

(defvar pthai-wordlist (make-hash-table :test 'equal)
  "hash table of thai words mapped to 1")

(defvar pthai-dictionary (make-hash-table :test 'equal)
    "thaiword => '( def eng_class thai_class where definition, eng_classifiers, thai_classifiers are all lists of strings.  empty definitions should be defined as nil \"ไก่\" => ( '(\"chicken\") nil '(\"ตัว\") )")

(defvar pthai-misc-punctuation-regexp
  (regexp-opt
   (list "~" "`" "!" "@" "#" "\$" "%" "^" "&" "*" "(" ")"
	 "-" "_" "=" "+" "\\" "|" "{" "}" "[" "]"
	 ";" ":" "'" "\"" "<" ">" "." "," "/" "?"
	 "ๆ" "ฯาฯ" "ฯ" "฿" "๏" "๚" "๛"))
  "regexp of misc punctuation used for word splitting")

(defvar pthai-rwb-tmp nil "temporary variable for pthai-rwb") 

(defgroup pthai nil
  "Pthai dictionary, wordlist, and word-splitting."
  :group 'applications)

(defcustom pthai-use-external-splitters t
  "use external programs to help word splitting, which may be slower"
  :group 'pthai
  :type 'boolean)

(defcustom pthai-split-mode "biggest"
  "Type of word splitting"
  :group 'pthai
  :set (lambda (sym val) (set-default sym val))
  :type '(radio (const :tag "biggest words possible/fewest words" :value "biggest")
		(const :tag "smallest words possible/most words" :value "smallest")
		(const :tag "interactively display choices" :value "interactive")))

(defcustom pthai-mp3-player nil
  "default command of audio player for mp3 files"
  :group 'pthai
  :type 'string)

(defcustom pthai-mp3-player-flags nil
  "default command flag arguments used for pthai-mp3-player"
  :group 'pthai
  :type '(repeat string))

(defun pthai-directory-create(dir)
  "prompt user to create a directory if it doesn't exist"
  (unless (file-directory-p dir)
    (if (yes-or-no-p (concat dir " does not exist, create?"))
	(or (make-directory dir)
	    (error "failed to create dir %s" dir)))))

(defcustom pthai-audio-directory
  (concat pthai-default-directory "audio")
  "directory where mp3 audio files are download and saved to, as
well as read from"
  :group 'pthai
  :set (lambda (sym val)
	 (set-default sym val)
	 (unless load-in-progress
	   (pthai-directory-create val)))
  :type 'directory)

;; utilities to manipulate the 'thai-word-table from the 'thai-word
;; library.  these functions should be merged into the 'thai-word
;; module itself, but that module looks to have been written when
;; 'thai-tis620 encoding was commonly used instead of utf-8 for thai
;;
;; 'thai-word-table uses a nested-alist from mule-util which looks
;; like this:
;;  '(3585 1                       ;; ก      word   ก
;;    (3591 1                      ;;  ง     word   กง
;;          (3585 t                ;;    ก               
;;                (3634 t          ;;     า              
;;                      (3619 1))));;      ร word   กงการ
;;    (3585 1                      ;;  ก     word   กก 
;;          (3621 1))))            ;;   ล    word   กกล
;;

(defun pthai-twt-extract(nlist thaistr)
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
	(pthai-twt-extract (cddr nlist) thaistr))
       ;; 1 => word at this depth
       ((equal complete 1)
	(append (list thaistr)
		(pthai-twt-extract (cddr nlist) thaistr)))
       (t
	(error "invalid parsing for complete var"))))
     
     ;; not finished
     (t
      (append (pthai-twt-extract (car nlist) thaistr)
	      (pthai-twt-extract (cdr nlist) thaistr))))))

(defun pthai-twt-in-p(thaiword)
 "return t if thaiword is in 'thai-word-table, nil otherwise"
  (let ((result
	 (lookup-nested-alist
	  thaiword thai-word-table (length thaiword) 0 t)))
    (and (listp result)
	 (integerp (car result))
	 (= 1 (car result)))))

(defun pthai-twt-table-save(filename &optional alist)
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

    (unless (nested-alist-p alist)
      (error "Invalid argument %s" alist))

    ;; remove 'thai-words from 'thai-word-table
    (setq alist (cdr alist))

    (with-temp-buffer
      ;; process per-letter list one at a time.  could process whole
      ;; list at once but maybe try to conserve memory resources
      (while (setq elem (car alist))
	(setq alist (cdr alist))
	(setq thaiwords (pthai-twt-extract elem ""))
	
    	(dolist (elem thaiwords)
	  (insert elem "\n")))

      (sort-lines nil (point-min) (point-max))
      (setq line_count (count-lines (point-min) (point-max)))
      (write-region nil nil filename)
      line_count)))

(defun pthai-twt-count (&optional alist)
  "Count number of words in a nested alist. if no arg given,
count 'thai-word-table words"
  (interactive)
  (let ((count 0)
	(elem)
	(thaiwords))
    ;; default list or not
    (setq alist (or alist thai-word-table))
    (unless (nested-alist-p alist)
      (error "Invalid argument %s" alist))
    ;; remove 'thai-words from 'thai-word-table
    (setq alist (cdr alist))
    (while (setq elem (car alist))
      (setq alist (cdr alist))
      (setq thaiwords (pthai-twt-extract elem ""))
      (setq count (+ count (length thaiwords))))
    count))

(defun pthai-twt-update (file &optional append)
  "Update Thai word table by replacing the current word list with
FILE, which is utf-8.  If called with optional append argument,
FILE is appended instead to the current word list.  Does the same
as 'thai-update-word-table, except that function expects
'thai-tis620 encoding which appears to be the default format for
at least emacs version <= 28.0"
  (interactive "FThai word table file: \nP")
  (let* ((coding-system-for-read 'utf-8)
	 (coding-system-for-write 'utf-8)
	 (buffer-file-coding-system 'utf-8)
	 (temp_file (make-temp-file "pthai-twt-update-620_")))
    (unwind-protect
	(with-temp-buffer
	  (insert-file-contents file)
	  (setq coding-system-for-write 'thai-tis620)
	  (write-file temp_file))
      (thai-update-word-table temp_file append)
      (delete-file temp_file)
      (if pthai-verbose-wordloads
	  (message "%d words in 'thai-word-table" (pthai-twt-count)))
      thai-word-table)))

(defun pthai-split-tokenizer(text)
 "subdivide text string into list of string tokens for hopefully
more optimal word splitting, e.g., แมว99ไก่แม่ => '(แมว 99 ไก่แม่)"
  (let (tmp tlist
	    (misc_punc (concat "^\\(" pthai-misc-punctuation-regexp "+\\)")))
    (while (> (length text) 0)
      ;; misc punctuation, numbers, thai text w/o numbers, thai numbers, non-thai text
      (or (string-match misc_punc text)
	  (string-match "^\\([\u0e00-\u0e4f\u0e5a-\u0e7f]+\\)" text)
	  (string-match "^\\([\u0e50-\u0e59\.]+\\)" text)
	  (string-match "^\\(\\Ct+\\)" text)
	  (error (concat "invalid text/match for : " text)))
      (setq tmp (match-string 1 text))
      (setq text (replace-match "" t nil text))
      ;; if match contains arabic number or space, split up more
      (if (string-match-p "[0-9 \f\t\n\r\v]" tmp)
	  (setq tlist (append (reverse (pthai-split-subtokenizer tmp)) tlist))
	(setq tlist (cons tmp tlist))))
    (reverse tlist)))

(defun pthai-split-subtokenizer(text)
  "subdivide string into string list of numbers, whitespace, and
non-numbers/non-whitespace.  helper function for
pthai-split-tokenizer"
  (let (tmp tlist)
    (while (> (length text) 0)
      (or (string-match "^\\([0-9]+\\)" text)             ;; number
	  (string-match "^\\([ \f\t\n\r\v]+\\)" text)     ;; whitespace
	  (string-match "^\\([^0-9 \f\t\n\r\v]+\\)" text) ;; other
	  (error "invalid match"))
      (setq tmp (match-string 1 text))
      (setq text (replace-match "" t nil text))
      (setq tlist (cons tmp tlist)))
    (reverse tlist)))

(defun pthai-split-all(text)
  "function to split up thai text string using various
programs. returns all found word segmentations as a list of
strings, where each string is a group of words separated by
spaces"
  (let (tmp x slist olist)
    (dolist (tmp (pthai-split-tokenizer text))
      (if (string-match-p "^\\Ct+$" tmp)
	  ;; no thai chars, just keep as is
	  (setq olist (nconc olist (list (list tmp))))
	;; else match thai chars
	(setq slist (pthai-thai-break-words tmp))    ;; thai-break-words
	(when pthai-use-external-splitters
	  (dolist (x (list "st-icu" "st-swath"))     ;; st-icu st-swath
	    (if (executable-find x)
		(setq slist
		      (append
		       (split-string
			(shell-command-to-string
			 (concat x " \"" tmp "\"")) "\n" t)
		       slist)))))
	;; pthai-rwb & st-wordbreak are recursive, only use with smaller strings
	(when (< (length tmp) 60)
	  (setq slist (append (pthai-rwb tmp) slist))
	  (and pthai-use-external-splitters
	       (executable-find "st-wordbreak")
	       (setq slist
		     (append
		      (split-string
		       (shell-command-to-string
			(concat "st-wordbreak -a " " \"" tmp "\"")) "\n" t)
		      slist))))
	(setq slist (seq-uniq slist))
	(setq olist (nconc olist (list slist)))))

    (if (<= (length olist) 1)
	(setq olist (car olist))
      (setq olist (pthai-combinate olist))
      (setq olist (mapcar 'pthai-join-strings olist)))

    (setq olist (seq-uniq olist))))

(defun pthai-split-string(text &optional smode)
  "split up thai string into thai words.  words are broken up
either by biggest, smallest or interactively depending on
'pthai-split-mode setting.  split mode can be specified with
optional arg smode using same values as 'pthai-split-mode
setting.  returns a string containing words separated by spaces"
  (interactive "sword: ")
   (let (slist)
    (setq smode (or smode pthai-split-mode))
    (setq slist (pthai-split-all text))
    (setq slist (sort slist (lambda (a b) (< (length (split-string a))
    					     (length (split-string b))))))
    (cond
     ((< (length slist) 1)
      text)
     ((or (= (length slist) 1)
     	  (string= smode "biggest"))
      (car slist))
     ((string= smode "smallest")
      (car (reverse slist)))
     ((string= smode "interactive")
      (ido-completing-read "split words: " slist))
     (t
      (car slist)))))

(defun pthai-cycle-split-mode()
  "cycle to next word splitting mode. return string of current
mode. message user when called interactively"
  (interactive)
  (cond ((string= pthai-split-mode "biggest")
	 (setq pthai-split-mode "smallest"))
	((string= pthai-split-mode "smallest")
	 (setq pthai-split-mode "interactive"))
	((string= pthai-split-mode "interactive")
	 (setq pthai-split-mode "biggest")))
  (if (called-interactively-p 'any)
      (message pthai-split-mode))
  pthai-split-mode)

(defun pthai-thai-break-words(text)
  "split thai string using thai-break-words from 'thai-word
library. returns list of lines with word-strings separated by
spaces"
  (with-temp-buffer
    (insert text)
    (goto-char (point-min))
    (thai-break-words " ")
    (split-string (buffer-string) "\n" t)))

(defun pthai-join-strings(alist)
  "join list of strings to form a string of words, only adding
  spaces where needed, ('a ' 'b' ' d ') => 'a b d '"
  (let (n tmp rlist
	  (f_space "^[ \t\n\r]+")
	  (b_space "[ \t\n\r]+$"))

    (if (<= (length alist) 1)
	(setq rlist alist)
      (dotimes (n (- (length alist) 1))
	(setq tmp (nth n alist))
	(setq rlist (cons tmp rlist))
	(unless (or (string-match-p b_space tmp)
		    (string-match-p f_space (nth (+ 1 n) alist)))
	  (setq rlist (cons " " rlist))))
      (setq rlist (cons (nth (- (length alist) 1) alist) rlist))
      (setq rlist (reverse rlist)))
    (string-join rlist)))

(defun pthai-unsplit-line()
  "remove spaces for thai words in line starting at point"
  (interactive)
  (pthai-unsplit-region (point) (line-end-position)))

(defun pthai-unsplit-buffer()
  "remove spaces for thai words in buffer"
  (interactive)
  (pthai-unsplit-region (point-min) (point-max)))

(defun pthai-unsplit-region(&optional p1 p2)
  "remove space and tabs from thai words in region"
  (interactive)
  (let ((num_rexp     "\\([0-9\u0e50-\u0e59]+\\)")
	(nonnum_rexp  "\\([\u0e00-\u0e4f\u0e5a-\u0e7f]\\)")
	(thai_rexp    "\\(\\ct+\\)")
	(nonthai_rexp "\\(\\Ct+\\)")
	(tmp_regexp))
    (cond
     ((and p1 p2)
      nil)
     ((use-region-p)
      (setq p1 (region-beginning))
      (setq p2 (region-end)))
     (t
      (error "no region/text selected")))
    (save-restriction
      (narrow-to-region p1 p2)
      (goto-char (point-min))
      (setq tmp_regexp (concat nonnum_rexp "\\([ \t]+\\)" nonnum_rexp))
      ;; remove spaces between thai words excluding numbers
      (while (re-search-forward tmp_regexp nil t)
	(replace-match (concat (match-string 1) (match-string 3)))))
    (goto-char p1)))

(defun pthai-split-region(&optional p1 p2)
  "in a region defined by p1 and p2, split thai words into
subwords in separated by spaces"
  (interactive)
  (let (line)
    (cond
     ((and p1 p2)
      nil)
     ((use-region-p)
      (setq p1 (region-beginning))
      (setq p2 (region-end)))
     (t
      (error "no region/text selected")))
    (save-excursion
      (save-restriction
	(narrow-to-region p1 p2)
	(goto-char (point-min))
	(while (not (eobp))
	  (setq line
		(buffer-substring-no-properties (line-beginning-position)
						(line-end-position)))
	  (when (string-match-p "\\ct" line)
	    (kill-line)
	    (insert (mapconcat 'pthai-split-string (pthai-split-tokenizer line) "")))
	  (forward-line 1))
	(goto-char p1)))))

(defun pthai-split-word()
  "split thai word at point"
  (interactive)
  (let (bounds p1 p2)
    (setq bounds (bounds-of-thing-at-point 'word))
    (setq p1 (car bounds))
    (setq p2 (cdr bounds))
    (unless (and p1 p2)
      (error "word not found"))
    (pthai-split-region p1 p2)))

(defun pthai-split-line()
  "split thai words from point to end of line"
  (interactive)
  (pthai-split-region (point) (line-end-position)))

(defun pthai-split-buffer()
  "split thai words in buffer"
  (interactive)
  (pthai-split-region (point-min) (point-max)))

(defun pthai-combinate(a)
  "take a list of lists, returns a list of lists with 1 element
 from each list combined:
 '((A B) (1) (c d)) => '((A 1 c) (A 1 d) (B 1 c) (B 1 d))"
  (let (ans_elem ans_list left_elem left_list tmp_elem tmp_list)
    (setq ans_list (mapcar 'list (car a)))
    (setq left_list a)
    (while (setq left_list (cdr left_list))
      (setq tmp_list nil)
      (dolist (ans_elem ans_list)
	(dolist (left_elem (nth 0 left_list))
	  (setq tmp_elem (append ans_elem (list left_elem)))
	  (setq tmp_list (append tmp_list (list tmp_elem)))))
      (setq ans_list tmp_list))
    ans_list))

(defun pthai-url-clickthai(thaiword)
  "return mp3 url for a thai word from clickthai-online.com or
nil if unavailable"
  (let ((url "https://www.clickthai-online.com/wbtde/dictionary.php")
	(url-request-method "POST")
	(url-request-extra-headers
	 `(("Content-Type" . "application/x-www-form-urlencoded; charset=utf-8")))
	(url-request-data
	 (concat "action=search&search=" (url-encode-url thaiword)))
	(play_url "http://www.clickthai-online.com/cgi-bin/playmp3.pl?")
	(sound_url)
	(tmp)
	(tmp_url))
    (with-current-buffer (url-retrieve-synchronously url)
      (goto-char (point-min))
      ;; <a href="javascript:play('../cgi-bin/playmp3.pl?322476');">วัน</a>
      (while (and (not sound_url)
		  (re-search-forward "playmp3\\.pl\\?\\([0-9]+\\)');\">\\(.*\\)</a>" nil t))
	(and (setq tmp (decode-coding-string (match-string 2) 'utf-8))
	     (setq tmp_url (concat play_url (match-string 1)))
	     (string= tmp thaiword)
	     (setq sound_url tmp_url))))
    sound_url))

(defun pthai-url-thai-language(thaiword)
  "return mp3 url for a thai word from thai-language.com or nil
if unavailable"
  (let* ((title_word)
	 ;; <title>thai-language.com - แมว</title>
	 (title_regexp "<title>thai-language.com - \\(.*\\)</title>")
	 (id)
	 ;; <link rel="canonical" href="http://www.thai-language.com/id/131188" />
	 (id_regexp "<link rel=\"canonical\" href=\"http://www.thai-language.com/id/\\([0-9]+\\)\"")
	 (click_regexp)
	 (sound_url)
	 (tmmode 0) ;;  exact=0 contains=1 starts_with=2 ends_with=3
	 (mp3_url "http://thai-language.com/mp3/")
	 (url "http://thai-language.com/dict")
	 (url-request-method "POST")
	 (url-request-extra-headers
	  `(("Content-Type" . "application/x-www-form-urlencoded; charset=utf-8")))
	 (url-request-data
	  (concat "action=/default.aspx&tmode="
		  (number-to-string tmmode) "&search=" (url-encode-url thaiword))))
    (with-current-buffer (url-retrieve-synchronously url)
      (and (goto-char (point-min))
	   (re-search-forward title_regexp nil t 1)
	   (setq title_word (decode-coding-string (match-string 1) 'utf-8)))
      (and (goto-char (point-min))
	   (re-search-forward id_regexp nil t 1)
	   (setq id (match-string 1)))
      (and id
	   (goto-char (point-min))
	   ;; <a onClick=PlayAudioFile('/mp3/E131188.mp3') style='cursor:pointer;'>
	   ;;   <img src='/img/speaker.gif' /></a>
	   (setq click_regexp
		 (concat "a onClick=PlayAudioFile('/mp3/\\([A-Z]" id "\\.mp3\\)') "))
	   (re-search-forward click_regexp nil t 1)
	   (setq sound_url (concat mp3_url (match-string 1)))))
    ;; title_word needs to match thaiword because query may return
    ;; other pages, e.g., "บักหำ" returns page for "หำ"
    ;;(message (concat "title=" title_word " id=" id " url=" sound_url)) ;; debug
    (and title_word
	 (string= title_word thaiword)
	 id
	 sound_url)))

(defun pthai-url-thai2english(thaiword)
  "return mp3 url for a thai word from thai2english.com or nil if
unavailable"
  (let* ((t2e_url "https://www.thai2english.com")
	 (fetch_url (url-encode-url (concat t2e_url "/search?q=" thaiword)))
	 (id_match (concat t2e_url "/dictionary/\\([0-9]+\\)\\.html"))
	 (speaker_url "https://ast.thai2english.com/img/circle-icons/speaker.svg")
	 (sounds_url "https://ast.thai2english.com/sounds/"))
    (with-current-buffer (url-retrieve-synchronously fetch_url)
      (goto-char (point-min))
      (and (search-forward speaker_url nil t)
	   (goto-char (point-min))
	   (re-search-forward id_match nil t 1)
	   (concat sounds_url (match-string 1) ".mp3")))))

(defun pthai-x-rates-currencies()
 "from www.x-rates.com, get an alist of supported currencies and their names
'((\"USD\" . \"US Dollar\") (\"THB\" . \"Thai Baht\") ... )"
  (let ((x_url "https://www.x-rates.com")
	(clist)
	;; match a string like
	;;<li><a href='https://www.x-rates.com/table/?from=ARS' onclick="submitConverterArgs(this)" rel='ratestable'>Argentine Peso</a></li>
	(currency_rexp
	 (concat "<li><a href='https://www.x-rates.com/table/\\?from=\\([A-Z]\\{3\\}\\)' "
		 "onclick=.* rel='ratestable'>\\(.*\\)</a></li>")))
    (with-current-buffer (url-retrieve-synchronously x_url)
      (goto-char (point-min))
      (while (re-search-forward currency_rexp nil t)
	(setq clist (cons (cons (match-string 1) (match-string 2)) clist))))
    (unless (> (length clist) 40)
      (error "error fetching currency types"))
    (reverse clist)))

(defun pthai-x-rates-convert(from to amount)
  "convert a currency (USD THB ...) amount to another currency,
from x-rates.com.  returns converted amount as a number.  message
user conversion info if called interactively"
  (let ((x_url "https://www.x-rates.com")
	(curr_alist (pthai-x-rates-currencies))
	(from_name)
	(to_name)
	(url)
	(mstr)
	(converted))
    (unless (and amount (numberp amount) (> amount 0.0))
      (error "invalid monetary amount"))
    (setq amount (number-to-string amount))
    ;; sanity check dollar & baht, and then look up names
    (unless (and (assoc "USD" curr_alist)
		 (assoc "THB" curr_alist)
		 (setq to_name (cdr (assoc to curr_alist)))
		 (setq from_name (cdr (assoc from curr_alist))))
      (error (concat "unknown currency to/from type(s): to=" to " from=" from)))
    ;; fetch current rates, then match something like
    ;; <a href='https://www.x-rates.com/graph/?from=USD&amp;to=THB'>30.171404</a>
    (setq url (concat x_url "/table/?from=" from "&amount=" amount))
    (setq mstr (concat "?from=" from "&amp;to=" to "'>"))
    (with-current-buffer (url-retrieve-synchronously url)
      (goto-char (point-min))
      (and (search-forward mstr nil t)
	   (re-search-forward "\\([0-9\.]+\\)" nil t)
	   (setq converted (format "%3.2f" (string-to-number (match-string 1))))))
    (unless converted
      (error (concat "download conversion match not found for " url)))
    (if (not (or executing-kbd-macro noninteractive))
	(message "%s %s = %s %s" amount from_name converted to_name))
    (string-to-number converted)))

(defun pthai-currency-dollar-to-baht(&optional amount)
  "convert us dollars to baht"
  (interactive)
  (unless (numberp amount)
    (setq amount (read-number "dollars: " 1)))
  (pthai-x-rates-convert "USD" "THB" amount))

(defun pthai-currency-baht-to-dollar(&optional amount)
  "convert baht to us dollars"
  (interactive)
  (unless (numberp amount)
    (setq amount (read-number "baht: " 1)))
  (pthai-x-rates-convert "THB" "USD" amount))

(defun pthai-currency-dollar-to-euro(&optional amount)
  "convert us dollars to euros"
  (interactive)
  (unless (numberp amount)
    (setq amount (read-number "dollars: " 1)))
  (pthai-x-rates-convert "USD" "EUR" amount))

(defun pthai-currency-euro-to-dollar(&optional amount)
  "convert euros to us dollars"
  (interactive)
  (unless (numberp amount)
    (setq amount (read-number "euros: " 1)))
  (pthai-x-rates-convert "EUR" "USD" amount))

(defun pthai-currency-dollar-to-pound(&optional amount)
  "convert us dollars to british pounds"
  (interactive)
  (unless (numberp amount)
    (setq amount (read-number "dollars: " 1)))
  (pthai-x-rates-convert "USD" "GBP" amount))

(defun pthai-currency-pound-to-dollar(&optional amount)
  "convert british pounds to us dollars"
  (interactive)
  (unless (numberp amount)
    (setq amount (read-number "pounds: " 1)))
  (pthai-x-rates-convert "GBP" "USD" amount))

(defun pthai-randomize(lst)
  "take a list and return it in random order"
  (let (rlst n)
    (while lst
      (setq n (random (length lst)))
      (setq rlst (cons (nth n lst) rlst))
      ;; drop nth element
      (setq lst (append (seq-take lst n) (seq-drop lst (1+ n)))))
    rlst))

(defun pthai-soundurl(thaiword)
  "return mp3 sound url for thai word from either thai-language,
clickthai or thai2english, or nil if not found. returns nil if no
thaiword given"
  (let ((fetchers (list 'pthai-url-clickthai
			'pthai-url-thai-language
			'pthai-url-thai2english))
	(tmp)
	(url))
    (when (string-match-p "\\ct+" thaiword)
      (setq fetchers (pthai-randomize fetchers))
      (while (and (not url) fetchers)
	(setq tmp (car fetchers))
	(setq fetchers (cdr fetchers))
	(setq url (funcall tmp thaiword))))
    url))

(defun pthai-download(thaiword)
  "fetch mp3 soundfile for thai word download from web to default
audio directory. returns path to downloaded file or nil if unable
to download"
  (let ((file (pthai-soundpath thaiword))
	(url (pthai-soundurl thaiword)))
    (and (string-match-p "\\ct+" thaiword)
	 url
	 (url-copy-file url file t)
	 file)))

(defun pthai-soundpath(thaiword)
  "generate default sound path for a thaiword. file may or may
not already exist"
  (unless (and pthai-audio-directory
	       (file-directory-p pthai-audio-directory))
    (error "pthai-audio-directory \"%s\" not found"  pthai-audio-directory))
  (expand-file-name (concat pthai-audio-directory "/" thaiword ".mp3")))

(defun pthai-soundfile-downloaded-p(thaiword)
  "return non-nil if a soundfile download already attempted for a
thai word"
  (file-exists-p (pthai-soundpath thaiword)))

(defun pthai-soundfile-playable-p(thaiword)
  "return non-nil if a soundfile downloaded successfully for a
thai word"
  (and (pthai-soundfile-downloaded-p thaiword)
       (> (file-attribute-size (file-attributes (pthai-soundpath thaiword))) 0)
       t))

(defun pthai-soundfiles-available-p(tlist)
  "return non-nil if the all sound files for a list of thai words
are available in audio directory"
  (let (tmp)
    (setq tlist (mapcar 'pthai-soundfile-playable-p tlist))
    (setq tmp (seq-filter (lambda (x) x) tlist))
    (= (length tmp) (length tlist))))

(defun pthai-soundfiles-sort(tlist)
  "sort list of list of thai strings in order of most available
audio files as a percentage, or containing the biggest words"
  (sort tlist
	(lambda (a b)
	  (let (a_total a_found a_percent b_total b_found b_percent)
	    (setq a_total (length a))
	    (setq b_total (length b))
	    (setq a_found (length (seq-filter (lambda (x) x) (mapcar 'pthai-soundfile-playable-p a))))
	    (setq b_found (length (seq-filter (lambda (x) x) (mapcar 'pthai-soundfile-playable-p b))))
	    (setq a_percent (round (* 100.0 (/ (float a_found) (float a_total)))))
	    (setq b_percent (round (* 100.0 (/ (float b_found) (float b_total)))))
	    (cond
	     ;; use biggest length of first word if all rest same
	     ((and (= a_total b_total)
		   (= a_percent b_percent))
	      (> (length (car a)) (length (car b))))
	     ;; use biggest words if percentage same
	     ((= a_percent b_percent)
	      (< a_total b_total))
	     ;; else highest percent of words available
	     (t
	      (> a_percent b_percent)))))))

(defun pthai-say(&optional text force_dl no_message)
  "split up text string, download and play audio for thai
words. return definitions of words as a string.  also say arabic
or thai numbers in thai.  how words are split depends on variable
'pthai-split-mode and words in dictionary and wordlist"
  (interactive "sword: ")
  (let (audio-p tmp tlist word words defs)
    (unless text
      (setq text (read-string "word: ")))
    (setq text (downcase (string-trim text)))

    ;; check input word as given, subdividing as necessary
    (cond
     ;; empty string, do nothing
     ((< (length text) 1)
      nil)
     ;; "known" thai word
     ((pthai-any-p text)
      (setq tlist (list text)))
     ;; non-thai word that has thai-word definition
     ((and (string-match-p "^\\Ct+$" text)
	   (setq tmp (pthai-lookup text)))
      (setq tlist tmp))
     ;; everything else: thai words, mixed, english words.  doing
     ;; multiple splits here trying to keep the string lengths "small"
     (t
      (setq tlist
	    (apply #'append
		   (mapcar 'split-string
			   (mapcar 'pthai-split-string (split-string text)))))))

    ;; "translate" each word if not thai
    (dolist (word tlist)
      (cond
       ;; number
       ((or (string-match-p "^[0-9]+$" word)
	    (string-match-p "^[๐๑๒๓๔๕๖๗๘๙]+$" word))
	(setq words (cons word words)))
       ;; non-thai word with definition
       ((and (string-match-p "^\\Ct+$" word)
	     (setq tmp (pthai-lookup word)))
	(setq words (nconc tmp words)))
       ;; thai word, non-thai word w/o definition, remainder
       (t
	(setq words (cons word words)))))
    (setq words (reverse words))
      
    ;; play audio and display meaning for each word when possible
    (dolist (word words)
      (cond
       ;; arabic numbers & thai numbers more than one digit
       ((or (string-match-p "^[0-9]+" word)
	    (string-match-p "^[๐๑๒๓๔๕๖๗๘๙]\\{2,\\}" word))
	(pthai-say-number word)
	(setq tmp (format "%s = %s" word (pthai-number word)))
	(setq defs (cons tmp defs)))
       ;; english words, implies thai meaning not found
       ((string-match-p "[A-Za-z]" word)
	(setq tmp (format "? = %s" word))
	(unless no_message (message tmp))
	(setq defs (cons tmp defs)))
       ;; thai strings & single thai digits
       ((string-match-p "^\\ct+$" word)
	(setq audio-p t)
	(catch 'pthai-say-word
	  ;; file already there and no forced download
	  (and (not force_dl)
	       (pthai-soundfile-playable-p word)
	       (pthai-play-thaiword word)
	       (throw 'pthai-say-word t))
	  ;; file not there or forced download, and word in dictionary
	  (when (and (or force_dl (not (pthai-soundfile-downloaded-p word)))
		     (pthai-any-p word))
	    (if (not (pthai-download word))
		(write-region "" nil (pthai-soundpath word))
	      (pthai-play-thaiword word)
	      (throw 'pthai-say-word t)))
	  ;; split up word into possible combinations
	  (setq tlist (mapcar 'split-string (pthai-split-all word)))
	  ;; delete original since if here it wasn't playable
	  ;;(setq tlist (delete (list word) tlist))
	  ;; sort by fewest missing pieces
	  (setq tlist
		(sort tlist
		      (lambda (a b)
			(< (length (seq-filter
				    (lambda (x) x) (mapcar 'pthai-soundfile-playable-p a)))
			   (length (seq-filter
				    (lambda (x) x) (mapcar 'pthai-soundfile-playable-p b)))))))
	  ;; play if all pieces found
	  (dolist (tmp tlist)
	    (when (pthai-soundfiles-available-p tmp)
	      (mapc 'pthai-play-thaiword tmp)
	      (throw 'pthai-say-word t)))
	  ;; for each split group, try to download missing pieces and play if successful
	  (dolist (tmp tlist)
	    (mapc (lambda (x)
		    (when (or force_dl (not (pthai-soundfile-downloaded-p x)))
		      (or (pthai-download x)
			  (write-region "" nil (pthai-soundpath x)))))
		  tmp)
	    (when (pthai-soundfiles-available-p tmp)
	      (mapc 'pthai-play-thaiword tmp)
	      (throw 'pthai-say-word t)))
	  ;; if any audio available, play the splitting with the most
	  ;; words available e.g., เสื้อโค้ทน้ำผลไม้ปั่นแม่น้ำใจ
	  (setq tlist (pthai-soundfiles-sort tlist))
	  (when (and (setq tmp (car tlist))
		     (seq-contains-p (mapcar 'pthai-soundfile-playable-p tmp) 't))
	    (mapc (lambda (x)
		    (and (pthai-soundfile-playable-p x)
			 (pthai-play-thaiword x)))
		  tmp)
	    (throw 'pthai-say-word t))
	  ;; if made it here, no audio found for word(s)
	  (setq audio-p nil))

	;; message meaning after playing
	(setq tmp (or (pthai-lookup word)
		      (and (pthai-classifier-p word) (list "classifier"))))
	(if tmp
	    (setq tmp (format "%s = %s" word (string-join tmp ", ")))
	  (setq tmp (format "%s = ?" word)))
	(when (and (not audio-p) (not no_message))
	  (setq tmp (concat tmp " (audio not found)")))
	(unless no_message (message tmp))
	(setq defs (cons tmp defs)))))
    (setq defs (reverse defs))
    ;; message all defs found at end
    (unless (or no_message (not defs))
      (message (string-join defs "\n")))
    defs))

(defun pthai-play-thaiword(thaiword &optional exe exe_args)
 "play mp3 audio file for thai word, assumes thaiword in default
sound directory.  depends on external mp3 player. optionally,
pass executable and list of command args to play audio
or set 'pthai-mp3-player/'pthai-mp3-player-flags. returns t if
playing successful"
 ;; there is play-sound-file built-in with emacs but it only supports
 ;; .wav or .au, not .mp3
 (let
     ;; list of command and its args.  args for quiet not required
     ;; since output discarded anyway
     ((commands (list (list "mpg123" "-q")
		      (list "afplay")
		      (list "mplayer" "-really-quiet")
		      (list "mpv" "--really-quiet")
		      (list "play" "-q") ;; sox
		      (list "amp" "-q")
		      (list "mpg321" "-q")))
      (command)
      (tmp))
   ;; custom setting
   (when pthai-mp3-player
     (if (not pthai-mp3-player-flags)
	 (setq tmp (list pthai-mp3-player))
       (setq tmp (cons pthai-mp3-player pthai-mp3-player-flags)))
     (setq commands (cons tmp commands)))
   ;; passed-in commands
   (when exe
     (if (not exe_args)
	 (setq tmp (list exe))
       (setq tmp (cons exe exe_args)))
     (setq commands (cons tmp commands)))
   ;; find first audio command available, from passed-in command,
   ;; custom setting or default values
   (setq command
	 (seq-find (lambda (x) (executable-find (car x))) commands))
   
   (cond
    ((not command)
     (error "no mp3 player found"))
    ((not (pthai-soundfile-playable-p thaiword))
     (error "file not playable or existing: %s" (pthai-soundpath thaiword)))
    (t
     (setq tmp
	    (apply #'call-process (car command) nil nil nil
		   (append (cdr command)
			   (list (expand-file-name (pthai-soundpath thaiword))))))
     (unless (= tmp 0)
       (error "non-zero exit (%d) for \"%s %s\""
	      tmp
	      (string-join command " ")
	      (pthai-soundpath thaiword)))
     tmp))))

(defun pthai-say-word(&optional thaiword force_dl)
  "download and play audio for thai word.  if no word given, get
word at point. if no word at point, prompt user.  optionally
force downloading of audio.  see also pthai-say"
  (interactive)
  (setq thaiword (or thaiword
		     (thing-at-point 'word t)
		     (read-string "thai word: ")))
  (pthai-say thaiword force_dl))

(defun pthai-say-line(&optional thailine force_dl)
  "download and play audio for current thai line, optionally force
downloading of audio"
  (interactive)
  (setq thailine (or thailine
		     (thing-at-point 'line)
		     (read-string "thai line: ")))
  (setq thailine (string-trim thailine))
  (pthai-say thailine force_dl))

(defun pthai-say-buffer(&optional force_dl)
  "download and play audio for words in buffer, optionally force
downloading of audio"
  (interactive)
  (let (line)
    (goto-char (point-min))
    ;; process line-by-line to help reduce memory/stack usage
    (save-excursion
      (while (not (eobp))
	(setq line
	      (buffer-substring-no-properties (line-beginning-position)
					      (line-end-position)))
	(setq line (string-trim line))
	(pthai-say line force_dl)
	(forward-line 1)))))

(defun pthai-say-region(&optional force_dl)
  "download and play audio for highlighted region"
  (interactive)
  (save-excursion
    (let (line region)
      (unless (use-region-p)
	(error "no region selected"))
      (setq region (buffer-substring-no-properties
		    (region-beginning) (region-end)))
      (with-temp-buffer
	(insert region)
	(pthai-say-buffer force_dl)))))

(defun pthai-say-number(num)
 "say number (thai or arabic) in thai. if arabic number, first
convert to thai. returns thai number (string), or nil if can't
convert.  only integers < abs(10 million) are supported.  for
interactive use, use 'pthai-say instead"
  (let* ((powers '(("1" . "เอ็ด") ("10" . "สิบ") ("20" . "ยี่สิบ")
		  ("100" . "ร้อย") ("1000" . "พัน") ("10000" . "หมื่น")
		  ("100000" . "แสน") ("1000000" . "ล้าน")))
	(fn2w (lambda (x) (cdr (assoc x powers))))
	(negative "ลบ")
	(max_num 9999999)
	(is_neg)
	(anum)
	(rnum)
	(tlist)
	(tmp)
	(power)
	(n))
    (unless (stringp num)
      (setq num (number-to-string num)))
    ;; negative number
    (when (string-match-p "^-" num)
      (setq num (replace-regexp-in-string "^-" "" num))
      (setq is_neg t))
    (unless (string-match-p "^[0-9๐๑๒๓๔๕๖๗๘๙]+" num)
      (error (concat "not valid number " num)))
    (if (string-match-p "^[๐๑๒๓๔๕๖๗๘๙]+" num)
	(setq num (pthai-number num)))
    (unless (string-match-p "^[0-9]+$" num)
      (setq num (replace-regexp-in-string "[^0-9]" "" num)))
    (setq anum (string-to-number num))
    (cond ((> anum max_num)
	   (warn (concat "audio only for numbers <= abs(" (number-to-string max_num) ")")))
	  ((< anum 10)
	   (setq tlist (list anum)))
	  (t
	   (setq rnum (reverse (split-string (pthai-number num) "" t)))
	   ;; digit 1
	   (setq tmp (nth 0 rnum))
	   (cond ((string= "๑" tmp)
		  (setq tlist (cons (funcall fn2w "1") tlist)))
		 ((not (string= "๐" tmp))
		  (setq tlist (cons tmp tlist))))
	   ;; digit 2
	   (when (setq tmp (nth 1 rnum))
	     (cond ((string= "๑" tmp)
		    (setq tlist (cons (funcall fn2w "10") tlist)))
		   ((string= "๒" tmp)
		    (setq tlist (cons (funcall fn2w "20") tlist)))
		   ((not (string= "๐" tmp))
		    (setq tlist (cons (funcall fn2w "10") tlist))
		    (setq tlist (cons tmp tlist)))))
	   ;; digits 3-7
	   (setq power "10")
	   (dotimes (n 5)
	     (when (setq tmp (nth (+ n 2) rnum))
	       (setq power (concat power "0"))
	       (when (not (string= tmp "๐"))
		 (setq tlist (cons (funcall fn2w power) tlist))
		 (setq tlist (cons tmp tlist)))))))
    ;; convert all to strings
    (setq tlist
	  (mapcar (lambda (x) (if (numberp x) (number-to-string x) x))
		  tlist))
    ;; convert all arabic numbers to thai
    (setq tlist
	  (mapcar (lambda (x) (if (string-match-p "^[0-9]+" x)
				  (pthai-number x) x))
		  tlist))
    ;; negative
    (if is_neg (setq tlist (cons negative tlist)))
    ;; say the number
    (dolist (tmp tlist)
      (pthai-say tmp))
    ;; return thai number as a string
    (setq tmp (pthai-number num))
    (if is_neg (setq tmp (concat "-" tmp)))
    (if (called-interactively-p 'any)
	(message tmp))
    tmp))

(defun pthai-rwb(thaistr)
  "return list of space separated string of possible word breaks
for a thai string, uses recursion.  can only handle thai words"
  (cond ((<= (length thaistr) 0)
	 nil)
	((string-match-p "\\Ct" thaistr)
	 (error (concat "cannot split non-thai strings: " thaistr)))
	(t (let ((retval))
	     (setq thaistr (replace-regexp-in-string "[[:space:]]+" "" thaistr))
	     (setq pthai-rwb-tmp nil)
	     (pthai-rwb-helper thaistr (length thaistr) "")
	     (setq retval pthai-rwb-tmp)
	     (setq pthai-rwb-tmp nil)
	     (or retval
		 (list thaistr))))))

(defun pthai-rwb-helper(str n result)
  "recursive helper function for pthai-rwb"
  (let ((i 1)
	(prefix)
	(ss))
    (catch 'done
      (while (<= i n)
	(setq prefix (substring-no-properties str 0 i))
	(when (pthai-any-p prefix)
	  (when (= i n)
	    (setq result (concat result prefix))
	    (setq pthai-rwb-tmp (cons result pthai-rwb-tmp))
	    (throw 'done nil))
	  (setq ss (substring-no-properties str i nil))
	  (pthai-rwb-helper ss (length ss) (concat result prefix " ")))
	(setq i (1+ i))))))

(defun pthai-number(&optional num)
  "convert a number between thai and arabic, and vice versa.
message user converted value if called interactively"
  (interactive)
  (let ((nlist '(("0" . "๐") ("1" . "๑") ("2" . "๒") ("3" . "๓")
		 ("4" . "๔") ("5" . "๕") ("6" . "๖") ("7" . "๗")
		 ("8" . "๘") ("9" . "๙")))
	(numa)
	(res))
    (unless num
      (setq num (read-string "number: ")))
    (unless (stringp num)
      (setq num (number-to-string num)))
    (setq numa (split-string num "" t))
    (if (string-match-p "[0-9]+" num)
	(setq res
	      (mapconcat (lambda(x) (or (cdr (assoc x nlist)) x)) numa ""))
      (setq res
	    (mapconcat (lambda(x) (or (car (rassoc x nlist)) x)) numa "")))
    (if (called-interactively-p 'any)
	(message res))
    res))

(defun pthai-parse-hour-minute-second(timestr &optional thaitime)
  "parse hour-minute-second strings like 7 1pm 12:32pm 22:07
9:45p.m. 0645 3.27am 15:23:55 or \"now\".  returns list of (SEC
MIN HOUR), with nil for each element not parsed"
  (let ((ampm_rexp "\\([AaPp]\.?[Mm]\.?\\)$")
	am_pm second minute hour tlist)
    ;; "now"
    (if (string-match-p "^[Nn][Oo][Ww]$" timestr)
	(setq timestr
	      (nth 3 (split-string
		      (pthai-time-now (not thaitime))))))
    ;; strip out anything that doesn't look like a time
    (setq timestr
	  (replace-regexp-in-string "[^0-9:\.pPaAmM]" "" timestr))
    ;; determine am/pm and remove from string
    (when (string-match-p ampm_rexp timestr)
      (if (string-match-p "[Aa]" timestr)
	  (setq am_pm "am")
	(setq am_pm "pm"))
      (setq timestr
	    (replace-regexp-in-string ampm_rexp "" timestr)))
    ;; parse hour/minute/seconds digits
    (cond
     ;; 1 or 2 digit, 1 11
     ((string-match "^\\([0-9]\\{1,2\\}\\)$" timestr)
      (setq hour (match-string 1 timestr))
      (setq minute "0")
      (setq second "0"))
     ;; 4 digits, 0645
     ((string-match "^\\([0-9]\\{4\\}\\)$" timestr)
      (setq hour (substring timestr 0 2))
      (setq minute (substring timestr 2 4))
      (setq second "0"))
     ;; 6 digits, 064532
     ((string-match "^\\([0-9]\\{6\\}\\)$" timestr)
      (setq hour (substring timestr 0 2))
      (setq minute (substring timestr 2 4))
      (setq second (substring timestr 4 6)))
     ;; 12:32 22:07 3.27 2:35
     ((string-match "^\\([0-9]\\{1,2\\}\\)[:\.]\\([0-9]\\{1,2\\}\\)$" timestr)
      (setq hour (match-string 1 timestr))
      (setq minute (match-string 2 timestr))
      (setq second "0"))
     ;; 12:43:54 or 12.43.54
     ((string-match
       "^\\([0-9]\\{1,2\\}\\)[:\.]\\([0-9]\\{1,2\\}\\)[:\.]\\([0-9]\\{1,2\\}\\)$" timestr)
      (setq hour (match-string 1 timestr))
      (setq minute (match-string 2 timestr))
      (setq second (match-string 3 timestr))))
    ;; convert to strings
    (if second (setq second (string-to-number second)))
    (if minute (setq minute (string-to-number minute)))
    (if hour (setq hour (string-to-number hour)))
    ;; adjust/sanity checks for am/pm
    (when (and am_pm hour)
      (cond
       ((and am_pm (> hour 12))
	(setq hour nil))
       ((and (string= am_pm "am") (= 12 hour))
	(setq hour 0))
       ((and (string= am_pm "pm") (< hour 12))
	(setq hour (+ 12 hour)))))
    ;; return nil unless all seem valid
    (if (and hour (>= hour 0) (<= hour 24)
	     minute (>= minute 0) (< minute 60)
	     second (>= second 0) (< second 60))
	(list second minute hour)
      (list nil nil nil))))

(defun pthai-time-loc2th(timestr &optional reverse)
"convert an hour:minute:second time string to thai time. use
\"now\" for current time.  if optional reverse, convert thai time
to local time"
  (interactive "stime: ")
  (let* ((c_time (current-time))
	 (time_format (concat "%a %b %e %H:%M:%S %Z %Y"))
	 (thai_offset (* 7 3600)) ;; UTC+7 or ICT or +07 or "Asia/Bangkok"
	 (thai_zone (current-time-zone nil thai_offset))
	 (tlist)
	 (enc_time) (loc_fts) (thai_fts) (o_str))
    ;; keep reading until valid second/minute/hour
    (while (not
	    (and (setq tlist (pthai-parse-hour-minute-second timestr reverse))
		 (nth 0 tlist)
		 (nth 1 tlist)
		 (nth 2 tlist)))
      (setq timestr (read-string "time: ")))
    (cond
     ;; thai time
     (reverse
      (setq tlist (append tlist (nthcdr 3 (decode-time c_time thai_zone))))
      (setq enc_time (apply 'encode-time tlist))
      (setq loc_fts (format-time-string time_format enc_time (current-time-zone)))
      (setq thai_fts (format-time-string time_format enc_time thai_zone))
      (setq o_str (concat "thai time = " thai_fts "\n" "time      = " loc_fts)))
     ;; local time
     (t
      (setq tlist (append tlist (nthcdr 3 (decode-time c_time))))
      (setq enc_time (apply 'encode-time tlist))
      (setq loc_fts (format-time-string time_format enc_time (current-time-zone)))
      (setq thai_fts (format-time-string time_format enc_time thai_zone))
      (setq o_str (concat "time      = " loc_fts "\n" "thai time = " thai_fts))))
    (message o_str)))

(defun pthai-time-th2loc(timestr)
"convert a thai time (hour/minute/second) to local time.  use
\"now\" for current time"
  (interactive "stime: ")
  (pthai-time-loc2th timestr t))

(defun pthai-time-now(&optional loctime)
  "return thai current time.  if optional loctime, return current
local time. message user time if called interactively"
  (interactive "P")
  (let ((c_zone (current-time-zone))
	(t_zone (current-time-zone nil (* 7 3600)))
	(time_format (concat "%a %b %e %H:%M:%S %Z %Y"))
	(tstr))
    (setq tstr
	  (format-time-string time_format (current-time)
			      (if loctime c_zone t_zone)))
    (if (called-interactively-p 'any)
	(message tstr))
    tstr))

(defun pthai-say-time(timestr)
  "say a time in thai, use time like 1pm, 12:45pm, 17:34.  use
\"now\" for current time. returns time string"
  (interactive "stime: ")
  (let (tlist hour minute mhour tmp)
    (while (not (and (setq tlist (pthai-parse-hour-minute-second timestr))
		     (setq minute (nth 1 tlist))
		     (setq hour (nth 2 tlist))))
      (setq timestr (read-string "time: ")))
    (setq mhour (mod hour 6))
    ;; get hour
    (cond
     ;; 12am = เที่ยงคืน or หกทุ่ม or สองยาม
     ((or (< hour 1) (and (= hour 24) (= minute 0)))
      (setq tmp (random 4))
      (cond ((< tmp 2)
	     (setq tlist (list "เที่ยงคืน")))
	    ((= tmp 2)
	     (setq tlist (list "หกทุ่ม")))
	    (t
	     (setq tlist (list "สองยาม")))))
     ;; 1am 2am 3am 4am 5am = ตี + number[1-5]
     ((< hour 6)
      (setq tlist (list "ตี" hour)))
     ;; 6am = หก โมง เช้า or ตีหก or ย่ำรุ่ง
     ((< hour 7)
      (setq tmp (random 4))
      (cond ((< tmp 2)
	     (setq tlist (list "หก" "โมง" "เช้า")))
	    ((= tmp 2)
	     (setq tlist (list "ตีหก")))
	    (t
	     (setq tlist (list "ย่ำรุ่ง")))))
     ;; 7am 8am 9am 10am 11am = 1-5  + โมง + เช้า
     ;;                       = 7-11 + โมง + (เช้า)
     ((< hour 12)
      (if (= 0 (random 2))     ;; 1-5
	  (if (= mhour 1)
	      (setq tlist (list "โมง" "เช้า"))
	    (setq tlist (list mhour "โมง" "เช้า")))
	(setq tlist (list hour "โมง"))  ;; 7-11
	(if (= 0 (random 2))
	    (setq tlist (append tlist (list "เช้า"))))))
     ;; 12pm = เที่ยงวัน
     ((< hour 13)
      (setq tlist (list "เที่ยงวัน")))
     ;; 1pm 2pm 3pm 4pm 5pm   = บ่าย + number[1-5] + โมง or
     ;;             4pm       = สี่ +  โมง + เย็น or
     ;;             5pm       = ห้า + โมง + เย็น
     ((< hour 18)
      (cond
       ((= hour 13) ;; 1pm
	(setq tlist (list "บ่าย" "โมง")))
       ((or (= hour 14) (= hour 15))
	(setq tlist (list "บ่าย" mhour "โมง")))
       ((= hour 16) ;; 4pm
	(if (= 0 (random 2))
	    (setq tlist (list "สี่" "โมง" "เย็น"))
	  (setq tlist (list "บ่าย" mhour "โมง"))))
       (t           ;; 5pm
	(if (= 0 (random 2))
	    (setq tlist (list "ห้า" "โมง" "เย็น"))
	  (setq tlist (list "บ่าย" mhour "โมง"))))))
     ;; 6pm = หก โมง เย็น or ย่ำค่ำ
     ((< hour 19)
      (if (= 0 (random 3))
	  (setq tlist (list "ย่ำค่ำ"))
	(setq tlist (list "หก" "โมง" "เย็น"))))
     ;; 7pm 8pm 9pm 10pm 11pm = number[1-5] + ทุ่ม
     ((< hour 24)
      (setq tlist (list mhour "ทุ่ม")))
     (t
      (error (concat "bad hour " hour))))
    ;; minutes are appended 10:07am = สิบ โมง (เช้า) + เจ็ด นาที
    (unless (or (= minute 0) (= hour 24))
      (setq tlist (append tlist (list minute "นาที"))))
    ;; convert everything to strings
    (setq tlist (mapcar (lambda (x) (if (numberp x) (number-to-string x) x))
			tlist))
    ;; play audio
    (dolist (tmp tlist)
      (pthai-say tmp))
    (setq tmp
	  (concat (number-to-string hour) ":" (format "%02d" minute)))
    (message tmp)
    tmp))

(defun pthai-wordlist-read-thai-word-table(&optional clear)
  "read 'thai-word-table from 'thai-word into wordlist,
  optionally clearing existing wordlist"
  (interactive)
  (let ((temp_file (make-temp-file (concat "thai-word-table-" user-login-name)))
	(count 0))
    (if clear
	(clrhash pthai-wordlist))
    (with-temp-file temp_file
      (insert (string-join (pthai-twt-extract (cdr thai-word-table) "") "\n"))
      (goto-char (point-min))
      (while (not (eobp))
	(setq count (+ 1 count))
	(forward-line)))
    (pthai-wordlist-read temp_file)
    (delete-file temp_file)
    count))

(defun pthai-parse-word-files(files)
  "take a list of files and directories, return full paths of
  files, and non-dotfiles in directories"
  (let (tmp dfiles rfiles)
    (while files
      (setq files (mapcar 'expand-file-name files))
      (setq files (sort (seq-uniq files) 'string-lessp))
      (setq tmp (car files))
      (setq files (cdr files))
      (when tmp
	(cond
	 ;; skip dot files
	 ((string-match "^\\." (file-name-nondirectory tmp))
	  nil)
	 ;; save list of files in dirs, skipping dot files and subdirs
	 ((file-directory-p tmp)
	  (setq dfiles (directory-files tmp nil "^\\([^.]\\|\\.[^.]\\|\\.\\..\\)"))
	  (setq dfiles (mapcar (lambda (x) (concat tmp "/" x)) dfiles))
	  (setq dfiles (seq-filter (lambda (x) (not (file-directory-p x))) dfiles))
	  (setq files (append files dfiles)))
	 ;; normal file
	 ((file-exists-p tmp)
	  (setq rfiles (append rfiles (list tmp)))))))
    (setq rfiles (sort (seq-uniq rfiles) 'string-lessp))))

(defcustom pthai-wordlist-list
  (list (concat pthai-default-directory "wordlist"))
  "list of files that contain thai word lists. note
'thai-word-table from 'thai-word is used as well"
  :group 'pthai
  :set (lambda (sym val)
	 (set-default sym val)
	 (if (seq-find #'file-exists-p val)
	     (pthai-wordlist-readall t)))
  :type '(repeat file))

(defun pthai-wordlist-readall(&optional clear)
  "read wordlists from pthai-wordlist-list, optionally clearing
previously loaded words. returns count of unique words"
  (interactive "P")
  (let (tmp)
    (if clear
	(clrhash pthai-wordlist))
    (dolist (tmp (pthai-parse-word-files pthai-wordlist-list))
      (pthai-wordlist-read tmp))
    (pthai-wordlist-read-thai-word-table)
    (setq tmp (hash-table-count pthai-wordlist))
    (if pthai-verbose-wordloads
	(message "%d unique words in pthai-wordlist" tmp))
    tmp))
    
(defun pthai-wordlist-read(fname &optional clear)
  "read a wordlist file into 'pthai-wordlist hash. return count
of words in file.  assumes file is in utf-8 format and 1 word per
line at start of line. returns count of words"
  (interactive "fenter path to wordlist: \n")
  (let ((coding-system-for-read 'utf-8)
	(coding-system-for-write 'utf-8)
	(buffer-file-coding-system 'utf-8)
	(count 0))
    (unless (and (> (length fname) 0)
		 (setq fname (expand-file-name fname))
		 (file-exists-p fname)
		 (not (file-directory-p fname)))
      (error (concat "invalid wordlist \"" fname "\"")))
    (if clear
	(clrhash pthai-wordlist))
    (with-temp-buffer
      (insert-file-contents fname)
      (goto-char (point-min))
      (while (re-search-forward "^\\(\\ct+\\)$" nil t)
	(setq count (+ 1 count))
	(puthash (match-string 1) 1 pthai-wordlist)))
    (if pthai-verbose-wordloads
	(message "%d words in %s" count fname))
    count))

(defun pthai-wordlist-add-word(thaiword)
  "add thai word to pthai-wordlist.  return true if word not in
list, nil if word already in list"
  (interactive "sthai word to add: ")
  (cond ((gethash thaiword pthai-wordlist)
	 nil)
	(t
	 (puthash thaiword 1 pthai-wordlist)
	 t)))

(defun pthai-wordlist-remove-word(thaiword)
  "remove thai word from pthai-wordlist. return t if word was in
wordlist, nil otherwise"
  (interactive "sthai word to remove: ")
  (cond ((gethash thaiword pthai-wordlist)
	 (remhash thaiword pthai-wordlist)
	 t)
	(t
	 nil)))

(defun pthai-dictionary-add-word(thaiword def english_class thai_class)
  "update pthai-dictionary with new entry or merge with existing
entry. thaiword is a thai string, other args can be nil, string,
or a list of strings. returns merged definition of word that was
inserted"
  (interactive)
  (let (ilist tmp)
    ;; convert to lists
    (setq ilist (mapcar (lambda(x) (if (listp x) x (list x)))
			(list def english_class thai_class)))
    ;; merge if entry already exists
    (if (setq tmp (gethash thaiword pthai-dictionary))
	(setq ilist (seq-mapn #'append ilist tmp)))
    ;; delete duplicates, nil
    (setq ilist
	  (mapcar (lambda(x) (sort (delq nil (delete-dups x)) 'string-lessp))
		  ilist))
    (puthash thaiword ilist pthai-dictionary)))

(defun pthai-dictionary-remove-word(thaiword)
  "remove word from dictionary, return t if word in dictionary,
  nil otherwise"
  (interactive "sthai word to remove: ")
  (cond ((gethash thaiword pthai-dictionary)
	 (remhash thaiword pthai-dictionary)
	 t)
	(t
	 nil)))

(defun pthai-parse-classifiers(str)
  "helper function to parse definition line and return list like
((a b c) (ก ด ห))"
  (let (eclass tclass tmp pos)
    (setq pos 0)
    (while (string-match "\\({.*?}\\)" str pos)
      (setq tmp (match-string 1 str))
      (setq pos (match-end 1))
      (if (string-match-p "\\ct+" tmp)
	  (setq tclass (append (split-string tmp " *[{} \t]+ *" t) tclass))
	(setq eclass (append (split-string tmp " *[{},\t]+ *" t) eclass))))
    (list eclass tclass)))

(defun pthai-dictionary-read(fname &optional clear)
  "read a dictionary file, adding words to pthai-dictionary hash.
if optional clear_dict arg, reset dictionary first.  returns
number of words read in file"
  (interactive "fpath to dictionary name: \n")
  (let ((coding-system-for-read 'utf-8)
	(coding-system-for-write 'utf-8)
	(buffer-file-coding-system 'utf-8)
	(count 0)
	(tword)
	(def_line)
	(class_info))
    (unless (and (> (length fname) 0)
		 (setq fname (expand-file-name fname))
		 (file-exists-p fname)
		 (not (file-directory-p fname)))
      (error (concat "invalid dictionary \"" fname "\"")))
    (if clear
	(clrhash pthai-dictionary))
    (with-temp-buffer
      (insert-file-contents fname)
      (goto-char (point-min))                  ;; remove # comments
      (while (re-search-forward "#.*$" nil t)
	(replace-match ""))
      (goto-char (point-min))                  ;; remove stuff in parentheses
      (while (re-search-forward "[ \t]*(.*?)[ \t]*" nil t)
	(replace-match " "))
      (goto-char (point-min))                  ;; consolidate spaces
      (while (re-search-forward "[ \t]+" nil t)
	(replace-match " "))
      (goto-char (point-min))                  ;; remove double quote marks
      (while (re-search-forward "\"" nil t)
	(replace-match ""))
      ;; convert all to lowercase
      (downcase-region (point-min) (point-max))
      
      (goto-char (point-min))
      (while (re-search-forward "^\\(\\ct+\\) \\(.*?\\) *$" nil t)
       	(when (and (setq tword (match-string 1))
       		   (setq def_line (match-string 2))
       		   (> (length def_line) 0))
	  (cond
	   ;; parse classifier info and strip from definition
	   ((string-match-p "[{}]" def_line)
	    (setq class_info (pthai-parse-classifiers def_line))
	    (setq def_line (replace-regexp-in-string " ?{.*?} ?" "" def_line)))
	   (t
	    (setq class_info nil)))
	  ;; save thai word, definition, classifier info	  
	  (pthai-dictionary-add-word tword
				     (split-string def_line " ?, ?" t)
				     (nth 0 class_info)
				     (nth 1 class_info))
	  (setq count (+ 1 count)))))
    (if pthai-verbose-wordloads
	(message "%d words in %s" count fname))
    count))

(defcustom pthai-dictionary-list
  (list (concat pthai-default-directory "dictionary"))
  "list of files and directories that contain thai dictionary files"
  :group 'pthai
  :set (lambda (sym val)
	 (set-default sym val)
	 (let (tmp)
	   (dolist (tmp (pthai-parse-word-files val))
	     (if (file-exists-p tmp)
		 (pthai-dictionary-read tmp)))
	   (unless pthai-bootstrap
	     (when pthai-verbose-wordloads
	       (setq tmp (hash-table-count pthai-dictionary))
	       (message "%d unique words in pthai-dictionary" tmp)))))
  :type '(repeat file))

(defun pthai-dictionary-readall(&optional clear)
  "read dictionary files defined in pthai-dictionary-list.  if
optional clear, clear existing entries.  returns total number of
words in dictionary"
  (interactive "P")
  (let ((files (pthai-parse-word-files pthai-dictionary-list))
	(tmp))
    (if clear
	(clrhash pthai-dictionary))
    (dolist (tmp files)
      (pthai-dictionary-read tmp))
    (when pthai-verbose-wordloads
      (setq tmp (hash-table-count pthai-dictionary))
      (message "%d unique words in pthai-dictionary" tmp))
    tmp))

(defun pthai-reverse-lookup(word ltype)
  "helper function for reverse look ups:
  word                 ltype      returns (list of ... or nil if not found)       example
  ====                 =====      ================                                =======
  english word         'def       thai definitions                                dog => (สุนัข หมา)
  english classifier   'eclass    thai words that are classified by english word  laws => (กฎ)
  thai classifier      'tclass    thai words that are classified by thai word     วงกบ => (กรอบ วง)"
  (let* (tmp vals rlist
	     (ltypes (list 'def 'eclass 'tclass))
	     (n (seq-position ltypes ltype)))
    (unless n
      (error "invalid ltype: %s" ltype))
    (dolist (tmp (hash-table-keys pthai-dictionary))
      (setq vals (nth n (gethash tmp pthai-dictionary)))
      (if (member word vals)
	  (setq rlist (append rlist (list tmp)))))
    (setq rlist (sort (delete-dups rlist) 'string-lessp))))

(defun pthai-dictionary-p(thaiword)
  "return non-nil if thaiword in dictionary"
  (interactive)
  (if (gethash thaiword pthai-dictionary)
      t nil))

(defun pthai-wordlist-p(thaiword)
  "return non-nil if thaiword in word list"
  (interactive)
  (if (gethash thaiword pthai-wordlist)
      t nil))

(defun pthai-any-p(thaiword)
  "return non-nil if thaiword in dictionary or word list"
  (interactive)
  (if (or (gethash thaiword pthai-wordlist)
	  (gethash thaiword pthai-dictionary))
      t nil))

(defun pthai-classifier-p(thaiword)
  "return non-nil if thaiword is a classifier in dictionary"
  (interactive "sthai word: ")
  (let (tmp)
    (if (and (setq tmp (gethash thaiword pthai-dictionary))
	     (or (nth 1 tmp) (nth 2 tmp)))
	t nil)))

(defun pthai-lookup(word)
  "look up definition of thai or english word. returns list of
english or thai words.  if called interactively, message user
definition"
  (interactive "sword: \n")
  (let (wlist)
    (setq word (downcase word))
    (if (string-match-p "\\ct+" word)
	(setq wlist (nth 0 (gethash word pthai-dictionary)))
      (setq wlist (pthai-reverse-lookup word 'def)))
    (when (called-interactively-p 'any)
      (if wlist
	  (message "%s = %s" word (string-join wlist ", "))
	(message "%s: not in dictionary" word)))
    wlist))

(defun pthai-lookup-and-insert(word)
  "look up a word (english or thai) and insert meaning at point.
if more than one definition found, select from choices found"
  (interactive "sword: ")
  (let (tlist tlen)
    (save-excursion
      (setq word (downcase word)
	    tlist (pthai-lookup word)
	    tlen (length tlist))
      (cond
       ((= 0 tlen)
	(message "%s not found in dictionary" word))
       ((= 1 tlen)
	(insert (car tlist)))
       (t
	(insert (ido-completing-read "meanings: " tlist)))))))

(defun pthai-lookup-classifier-detail(word)
  "return detailed classifier information for word. see
'pthai-lookup-classifier"
  (interactive "sword to lookup: \n")
  (pthai-lookup-classifier word t))

(defun pthai-lookup-classifier(word &optional detail)
    "return classifier information for word:
word                      return value (list of ...)
====                      ============
thai word, classifier     '( (defintions) '(eng classifiers) '(thai classifiers) ) 
thai word, not classifer  '( thai classifiers for thai word )
english word              '( thai classifiers for english word )

    message user information if called interactively. if optional
detail arg given, print out complete definitions for all
classifier words (for 2nd and 3rd cases, 1st case will by default
when interactive"
  (interactive "sword to lookup: \n")
  (let (tmp clist ret)
    (setq word (downcase word))
    (cond
     ;; thai word that is a classifier, e.g. ตัว
     ((pthai-classifier-p word)
      (setq ret (gethash word pthai-dictionary))
      (setq clist (list word)))
     ;; thai word that has classifiers, e.g. แมว
     ((string-match-p "\\ct+" word)
      (setq ret (pthai-reverse-lookup word 'tclass))
      (setq clist ret))
     ;; english word, e.g. dog
     ((string-match-p "^\\Ct+$" word)
      ;; look up classifiers directly and reverse lookup thai defs and
      ;; the classifiers for them
      (setq clist (pthai-reverse-lookup word 'eclass))
      (dolist (tmp (pthai-lookup word))
	(setq clist (append (pthai-reverse-lookup tmp 'tclass) clist)))
      (setq clist (seq-filter (lambda (x) x) clist))
      (setq clist (sort (delete-dups clist) 'string-lessp))
      (setq ret clist))
     (t
      (error "error parsing classifier info")))

    (when (or detail (called-interactively-p 'any))
      (cond
       ;; word is a classifier, print out info
       ((pthai-classifier-p word)
	(message (pthai-classifier-info word)))
       ;; found classifiers for word, print list of classifiers, or details
       ;; for each classifier found
       (clist
	(if detail
	    (message (mapconcat 'pthai-classifier-info clist "\n"))
	  (message "%s classified by: %s" word (string-join clist ", "))))
       ;; no classifier info found
       (t
	(message (pthai-classifier-info word)))))
    ret))

(defun pthai-classifier-info(word)
  "return classifer information as a string"
  (let (cinfo cistr)
    (if (not (pthai-classifier-p word))
	(setq cistr (concat "no classifier info found for " word))

      (setq cinfo (gethash word pthai-dictionary))      
      (if (nth 0 cinfo)
	  (setq cistr (concat word " = " (string-join (nth 0 cinfo) ", ") "\n"))
	(setq cistr (concat word " is a classifier\n")))
      (if (nth 1 cinfo)
	  (setq cistr (concat cistr "classifier for: "
			     (string-join (nth 1 cinfo) ", ") "\n")))
      (if (nth 2 cinfo)
	  (setq cistr (concat cistr "classifier for: "
			     (string-join (nth 2 cinfo) " ") "\n")))
      (setq cistr (string-trim-right cistr)))
    cistr))

(defun pthai-temperature-cel2fah(celsius)
  "convert celsius to fahrenheit.  message user if called
interactively"
  (interactive "ncelsius: ")
  (let (fah)
    (setq fah (+ (* celsius (/ 9.0 5.0)) 32.0))
    (if (called-interactively-p 'any)
	(message "%3.1f C = %3.1f F" celsius fah))
    fah))

(defun pthai-temperature-fah2cel(fahrenheit)
  "convert fahrenheit to celsius. message user if called
interactively"
  (interactive "nfahrenheit: ")
  (let (cel)
    (setq cel (* (- fahrenheit 32.0) (/ 5.0 9.0)))
    (if (called-interactively-p 'any)
	(message "%3.1f F = %3.1f C" fahrenheit cel))
    cel))

(defun pthai-year-greg2bud(&optional year)
  "convert gregorian year (A.D.) to buddhist year (B.E.). message
user if called interactively"
  (interactive)
  (let ((bud_year)
	(cur_year (string-to-number (format-time-string "%Y"))))
    (unless (integerp year)
      (setq year (round (read-number "year: " cur_year))))
    (setq bud_year (+ 543 year))
    (when (called-interactively-p 'any)
      (if (>= year 0)
	  (message "%d A.D. = B.E. %d" year bud_year)
	(message "%d B.C. = B.E. %d" (* -1 year) bud_year)))
    bud_year))

(defun pthai-year-bud2greg(&optional year)
  "convert buddhist year (B.E.) to gregorian year (A.D./B.C.).
message user if called interactively"
  (interactive)
  (let ((greg_year)
	(cur_year (+ 543
		     (string-to-number (format-time-string "%Y")))))
    (unless (integerp year)
      (setq year (round (read-number "year: " cur_year))))
    (setq greg_year (- year 543))
    (when (called-interactively-p 'any)
      (if (>= greg_year 0)
	  (message "B.E. %d = %d A.D." year greg_year)
	(message "B.E. %d = %d B.C. " year (* -1 greg_year))))
    greg_year))

;; initialize default wordlist and dictionary
(unless pthai-bootstrap
  (pthai-twt-update "ST_SHARE_DIR/words" t)
  (pthai-dictionary-read "ST_SHARE_DIR/sampledict.txt"))

(provide 'pthai)
