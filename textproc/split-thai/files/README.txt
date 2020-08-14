NAME
     st-emacs
     st-icu
     st-swath

SYNOPSIS
     st-emacs|st-icu|st-swath [filename|text1 text2 ...|'blank']

DESCRIPTION
     This package is a collection of utilities to separate Thai words
     by spaces (word tokenization).  They can separate stdin, files,
     or text as arguments.  It includes 3 separate utilities:

     st-emacs:  emacs-script using emacs lisp thai-word library
                https://www.gnu.org/software/emacs/
     st-icu:    basic C++ program using the ICU library
                http://site.icu-project.org/
     st-swath:  sh script wrapper to simplfy args to the swath program
                https://linux.thai.net/projects/swath

EXAMPLES
      split one or more text strings
      # st-swath แมวและหมา
      # st-swath "แมวหมา" พ่อและแม่
      
      read stdin
      # echo "แมวและหมา" | st-swath

      read from a file
      # st-swath < thaifile.txt
      # st-swath somefile.txt

      They can also read directly from stdin
      # st-icu
        แมวหมา   (typed in)
        แมว หมา  (output line by line)

ENVIRONMENT
     You will most likely need to set the environment variables LC_ALL
     or LC_CTYPE for proper unicode handling, e.g., en_US.UTF-8 or
     C.UTF-8.  These tools are only setup to handle UTF-8 encodings.

EXIT STATUS
     0 for success, non zero otherwise

NOTES
     Note that it is not possible to split Thai words 100% accurately
     without context and meaning.  All these programs use
     dictionary-based word splitting.

     Also included in the package is a combined thai word dictionary
     and corresponding .tri file, and emacs lisp .el files for reading
     and dumping out dictionary files.

     st-emacs and st-swath are setup to use the combined dictionary
     with words from the emacs 'thai-word library, swath dictionary
     words, and the icu thai library words.

     st-icu uses its own built in library.  To customise the icu
     dictionary, you apparently would have to modify
     icu4c/source/data/brkitr/dictionaries/thaidict.txt and then
     rebuild the whole library.

SEE ALSO
     swath(1), libthai(1), emacs(1), locale(1), uconv(1), iconv(1)

BUGS
     st-icu should also use the combined dictionary words.
     st-emacs and st-icu don't always split thai numbers well.
     this file should be converted to a proper manpage.
