# $NetBSD: builtin.mk,v 1.1 2004/09/21 17:43:42 xtraeme Exp $

_H_XFIXESPROTO=		${X11BASE}/include/X11/extensions/xfixesproto.h
_H_XFIXESWIRE=		${X11BASE}/include/X11/extensions/xfixeswire.h

.if !defined(IS_BUILTIN.fixesext)
IS_BUILTIN.fixesext=     no
.  if exists(${_H_XFIXESPROTO}) && exists(${_H_XFIXESWIRE})
IS_BUILTIN.fixesext=     yes
.  endif
.endif  # IS_BUILTIN.fixesext

USE_BUILTIN.fixesext?=   ${IS_BUILTIN.fixesext}
