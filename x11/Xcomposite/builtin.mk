# $NetBSD: builtin.mk,v 1.4 2004/10/09 06:40:48 xtraeme Exp $

_XCOMPOSITE_H=	${X11BASE}/include/X11/extensions/xcomposite.h
_XCOMPOSITE_PC=	${X11BASE}/lib/pkgconfig/xcomposite.pc

.if !defined(IS_BUILTIN.Xcomposite)
IS_BUILTIN.Xcomposite=     no
.  if exists(${_XCOMPOSITE_H}) && exists(${_XCOMPOSITE_PC})
IS_BUILTIN.Xcomposite=     yes
.  endif
.endif  # IS_BUILTIN.Xcomposite

USE_BUILTIN.Xcomposite?=   ${IS_BUILTIN.Xcomposite}
