# $NetBSD: interpreter.mk,v 1.1 2007/01/12 08:44:48 rillig Exp $
#
# Package-settable variables:
#
# REPLACE_TK_TIX
#	The list of files whose interpreter will be corrected.
#
# See also:
#	replace-interpreter
#

.if !defined(TK_TIX_INTERPRETER_MK)
TK_TIX_INTERPRETER_MK=	# defined

REPLACE_INTERPRETER+=	tk-Tix
REPLACE.tk-Tix.old=	.*/tixwish
REPLACE.tk-Tix.new=	${LOCALBASE}/bin/tixwish
REPLACE_FILES.tk-Tix=	${REPLACE_TK_TIX}

.endif
