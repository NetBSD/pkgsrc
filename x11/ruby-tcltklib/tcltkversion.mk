# $NetBSD: tcltkversion.mk,v 1.1 2004/11/27 14:50:12 taca Exp $
.ifndef _RUBY_TCLTKVERSION_MK

_RUBY_TCLTKVERSION_MK=	# defined

TCL_VERSION?=	8.4
TK_VERSION?=	8.4
TCL_LIB=	tcl${TCL_VERSION:C/([0-9]+)\.([0-9]+)/\1\2/}
TK_LIB=		tk${TK_VERSION:C/([0-9]+)\.([0-9]+)/\1\2/}
TCL_DIR=	tcl${TCL_VERSION}
TK_DIR=		tk${TK_VERSION}

.endif
