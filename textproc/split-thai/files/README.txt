NAME
     st-emacs
     st-icu
     st-swath
     st-wordbreak
     tgrep
     pthai.el

SYNOPSIS
     st-emacs|st-icu|st-swath|st-wordbreak [filename|text1 text2 ...|'blank']
     tgrep [options] FILE ...

DESCRIPTION
     This package is a collection of utilities to separate Thai words
     by spaces (word tokenization).  They can separate stdin, files,
     or text as arguments.  It includes these utilities:

     st-emacs:     emacs-script using emacs lisp thai-word library
                   https://www.gnu.org/software/emacs/
     st-icu:       basic C++ program using the ICU library
                   http://site.icu-project.org/
     st-swath:     sh script wrapper to simplfy args to the swath program
                   https://linux.thai.net/projects/swath
     st-wordbreak: perl script to brute-force separate thai words,
                   see "st-wordbreak -h"

     tgrep:        grep-like utility using perl, see "tgrep -h"

     pthai.el:     emacs library for handling thai text in an emacs buffer,
                   including word splitting
     
EXAMPLES
      split one or more text strings:
      # st-swath แมวและหมา
      # st-swath "แมวหมา" พ่อและแม่
      
      read stdin:
      # echo "แมวและหมา" | st-swath

      read from a file:
      # st-swath < thaifile.txt
      # st-swath somefile.txt

      They can also read directly from stdin:
      # st-icu
        แมวหมา   (typed in)
        แมว หมา  (output line by line)

      grep for thai words:
      # grep แมว thaifile.txt

ENVIRONMENT
     You will most likely need to set the environment variables LC_ALL
     or LC_CTYPE for proper unicode handling, e.g., en_US.UTF-8 or
     C.UTF-8.  These tools are only setup to handle UTF-8 encodings.

     A terminal capable of entering and displaying UTF-8, and some
     actual UTF-8 fonts installed on the system will also be needed.
     
EXIT STATUS
     0 for success, non zero otherwise.  For tgrep, see "tgrep -h"

NOTES
     Note that it is not possible to split Thai words 100% accurately
     without context and meaning.  All these programs use
     dictionary-based word splitting.

     Also included in the package is a combined thai word dictionary
     and corresponding .tri file, and emacs lisp .el files for reading
     and dumping out dictionary files.

     st-emacs, st-swath, and st-wordbreak are setup to use the
     combined dictionary with words from the emacs 'thai-word library,
     swath dictionary words, and the icu thai library words.

     st-icu uses its own built in library.  To customise the icu
     dictionary, you apparently would have to modify
     icu4c/source/data/brkitr/dictionaries/thaidict.txt and then
     rebuild the whole library.

     Also included in this package is an emacs library called "pthai"
     (practice-thai).  It can do word splitting, play mp3 audio for
     thai words and a few other things.
     
SEE ALSO
     swath(1), libthai(1), emacs(1), locale(1), uconv(1), iconv(1)
     trans(1) from pkgsrc/textproc/translate-shell

BUGS
     st-icu should also use the combined dictionary words.
     thai text mixed with other languages may not be handled well when
     splitting.
     this file should be converted to proper manpages.
     these utilities need better names.
