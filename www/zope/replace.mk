# $NetBSD: replace.mk,v 1.1.1.1 2007/12/18 15:27:23 taca Exp $
#

.if !defined(_ZOPE_REPLACE_MK)
_ZOPE_REPLACE_MK=	# defined

# fix shebang line.
#
# REPLACE_PYTHON_DIRS	replace shebang line of files under specified
#			directories.
# REPLACE_PYTHON_PAT	specify pattern to match target files under
#			REPLACE_PYTHON_DIRS directories.
#
.if defined(REPLACE_PYTHON_DIRS) && !empty(REPLACE_PYTHON_DIRS)

.for f in ${REPLACE_PYTHON_PAT}
_REPLACE_PYTHON_PAT+= -o -name "${f}"
.endfor
_REPLACE_PYTHON_FIND_ARGS=\( ${_REPLACE_PYTHON_PAT:S/-o//1} \)

pre-configure: replace-python-dirs

replace-python-dirs:
	${_PKG_SILENT}${_PKG_DEBUG}${FIND} ${REPLACE_PYTHON_DIRS} \
	    -type f ${_REPLACE_FILE_FIND_ARGS} -print | \
	    while read f; do \
		${SED}	-e '1s| *[a-z0-9_/\.-][a-z0-9_/\.-]*/env *||g' \
		    -e '1s| *[a-z0-9_/\.-]*python.*|${PYTHONBIN}|' $$f \
			> $$f.tmp; \
		if ${CMP} -s $$f $$f.tmp; then \
			${RM} $$f.tmp; \
		else \
			${MV} $$f.tmp $$f; \
		fi; \
	    done
.endif # defined(REPLACE_PYTHON_DIRS)

.include "../../lang/python/application.mk"
.endif
