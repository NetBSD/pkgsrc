This is a collection of utilities to separate Thai words by spaces
(word tokenization).  They can separate stdin, files, or text as
arguments.  It includes 3 separate utilities:

st-emacs:  emacs-script using emacs lisp thai-word library
           https://www.gnu.org/software/emacs/
st-icu:    basic C++ program using the ICU library
           http://site.icu-project.org/
st-swath:  sh script wrapper to simplfy args to the swath program
           https://linux.thai.net/projects/swath

All scripts should be able to take a filename, stdin, or arguments as
input, e.g., :

      # st-swath แมวและหมา
or
      # echo "แมวและหมา" | st-swath
or      
      # st-swath < thaifile.txt
or
      # st-swath "แมวหมา" พ่อและแม่
      
You will most likely need to set LC_ALL or LC_CTYPE to an approriate
unicode value, e.g., en_US.UTF-8 or C.UTF-8, in the environment for
them to work properly.  These tools are setup to only support UTF-8
encodings.

Note that it is not possible to split Thai words 100% accurately
without context and meaning.  These programs use dictionary-based word
splitting.

Also included in the package is a combined thai word dictionary and
corresponding .tri file, and emacs lisp .el file for reading and
dumping out dictionary files.

st-emacs and st-swath are setup to use the combined dictionary with
words from the emacs 'thai-word library, swath dictionary words, and
the icu thai library words.

st-icu uses its own built in library.  To customise the icu
dictionary, you apparently would have to modify
  icu4c/source/data/brkitr/dictionaries/thaidict.txt
and rebuild icu library, and then rebuild the whole thing.

There is also 

See also swath(1), libthai(1), emacs(1), locale(1), uconv(1), iconv(1)

TODO - fix st-icu to use all the combined dictionary words.
