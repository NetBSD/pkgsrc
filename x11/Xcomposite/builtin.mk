# $NetBSD: builtin.mk,v 1.2 2004/10/08 04:01:49 xtraeme Exp $

_XCOMPOSITE_H=	${X11BASE}/include/X11/extensions/xcomposite.h

.if !defined(IS_BUILTIN.Xcomposite)
IS_BUILTIN.Xcomposite=     no
.  if exists(${_XCOMPOSITE_H})
IS_BUILTIN.Xcomposite=     yes
.  endif
.endif  # IS_BUILTIN.Xcomposite

USE_BUILTIN.Xcomposite?=   ${IS_BUILTIN.Xcomposite}
