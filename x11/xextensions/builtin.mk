# $NetBSD: builtin.mk,v 1.2 2005/03/22 15:52:35 jmmv Exp $

_X11_EXTENSIONS_EXTUTIL_H=	${X11BASE}/include/X11/extensions/extutil.h
_X11_EXTENSIONS_PC=		${X11BASE}/lib/pkgconfig/xextensions.pc

.if !defined(IS_BUILTIN.xextensions)
IS_BUILTIN.xextensions=	no
.  if exists(${_X11_EXTENSIONS_EXTUTIL_H}) && exists(${_X11_EXTENSIONS_PC})
IS_BUILTIN.xextensions=	yes
# hardcode version for now, since there currently is only one, really
BUILTIN_PKG.xextensions=	xextensions-1.0.1
BUILDLINK_VARS+=	BUILTIN_PKG.xextensions
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.xextensions
.endif	# IS_BUILTIN.xextensions

.if !defined(USE_BUILTIN.xextensions)
USE_BUILTIN.xextensions?=	${IS_BUILTIN.xextensions}

.  if defined(BUILTIN_PKG.xextensions)
USE_BUILTIN.xextensions=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.xextensions}
.      if !empty(USE_BUILTIN.xextensions:M[yY][eE][sS])
USE_BUILTIN.xextensions!=		\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.xextensions}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif	# USE_BUILTIN.xextensions

CHECK_BUILTIN.xextensions?=	no
.if !empty(CHECK_BUILTIN.xextensions:M[nN][oO])

.if !empty(USE_BUILTIN.xextensions:M[nN][oO])
BUILDLINK_DEPENDS.xextensions+=	xextensions>=1.0
.endif

.if !empty(USE_BUILTIN.xextensions:M[yY][eE][sS])
BUILDLINK_PREFIX.xextensions=	${X11BASE}
USE_X11=			yes
.endif

.endif	# CHECK_BUILTIN.xextensions
