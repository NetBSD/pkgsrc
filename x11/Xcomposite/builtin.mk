# $NetBSD: builtin.mk,v 1.3 2004/10/08 05:24:46 xtraeme Exp $

_XCOMPOSITE_H=	${X11BASE}/include/X11/extensions/xcomposite.h
_XCOMPOSITE_PC=	${X11BASE}/lib/X11/pkgconfig/xcomposite.pc

.if !defined(IS_BUILTIN.Xcomposite)
IS_BUILTIN.Xcomposite=     no
.  if exists(${_XCOMPOSITE_H}) && exists(${_XCOMPOSITE_PC})
IS_BUILTIN.Xcomposite=     yes
.  endif
.endif  # IS_BUILTIN.Xcomposite

USE_BUILTIN.Xcomposite?=   ${IS_BUILTIN.Xcomposite}
