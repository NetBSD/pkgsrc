# $NetBSD: builtin.mk,v 1.1 2004/10/08 03:59:36 xtraeme Exp $

_COMPOSITE_H=	${X11BASE}/include/X11/extensions/xcomposite.h

.if !defined(IS_BUILTIN.Xcomposite)
IS_BUILTIN.Xcomposite=     no
.  if exists(${_COMPOSITE_H})
IS_BUILTIN.Xcomposite=     yes
.  endif
.endif  # IS_BUILTIN.Xcomposite

USE_BUILTIN.Xcomposite?=   ${IS_BUILTIN.Xcomposite}
