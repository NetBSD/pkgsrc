# $NetBSD: builtin.mk,v 1.1 2004/09/21 17:42:21 xtraeme Exp $

_H_XFIXES=		${X11BASE}/include/X11/extensions/Xfixes.h

.if !defined(IS_BUILTIN.Xfixes)
IS_BUILTIN.Xfixes=     no
.  if exists(${_H_XFIXES})
IS_BUILTIN.Xfixes=     yes
.  endif
.endif  # IS_BUILTIN.Xfixes

USE_BUILTIN.Xfixes?=   ${IS_BUILTIN.Xfixes}
