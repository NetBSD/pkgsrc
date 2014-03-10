# $NetBSD: interpreter.mk,v 1.1 2014/03/10 14:22:01 taca Exp $
#
# Package-settable variables:
#
# REPLACE_WISH
#	THe list of files whose interpreter will be corrected.
#
# See also:
#	replace-interpreter

.if !defined(TK_INTERPRETER_MK)
TK_INTERPRETER_MK=	# defined

REPLACE_INTERPRETER+=	wish
REPLACE.wish.old=	.*/wish
REPLACE.wish.new=	${LOCALBASE}/bin/wish
REPLACE_FILES.wish=	${REPLACE_WISH}

.endif
