# $NetBSD: builtin.mk,v 1.1 2004/03/10 17:57:15 jlam Exp $

_X11_EXTENSIONS_RANDR_H=	${X11BASE}/include/X11/extensions/randr.h

.if !defined(IS_BUILTIN.randrext)
IS_BUILTIN.randrext=	no
.  if exists(${_X11_EXTENSIONS_RANDR_H})
IS_BUILTIN.randrext=	yes
#
# Create an appropriate package name for the built-in randr distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
_RANDR_MAJOR!=	\
	${AWK} '/\#define[ 	]*RANDR_MAJOR/ { print $$3 }'		\
		${_X11_EXTENSIONS_RANDR_H}
_RANDR_MINOR!=	\
	${AWK} '/\#define[ 	]*RANDR_MINOR/ { print "."$$3 }'	\
		${_X11_EXTENSIONS_RANDR_H}
_RANDR_VERSION=	${_RANDR_MAJOR}${_RANDR_MINOR}
BUILTIN_PKG.randrext=	randrext-${_RANDR_VERSION}
MAKEFLAGS+=		BUILTIN_PKG.randrext=${BUILTIN_PKG.randrext}
.  endif
MAKEFLAGS+=	IS_BUILTIN.randrext=${IS_BUILTIN.randrext}
.endif

CHECK_BUILTIN.randrext?=	no
.if !empty(CHECK_BUILTIN.randrext:M[yY][eE][sS])
USE_BUILTIN.randrext=	yes
.endif

.if !defined(USE_BUILTIN.randrext)
USE_BUILTIN.randrext?=	${IS_BUILTIN.randrext}

.  if defined(BUILTIN_PKG.randrext)
USE_BUILTIN.randrext=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.randrext}
.      if !empty(USE_BUILTIN.randrext:M[yY][eE][sS])
USE_BUILTIN.randrext!=		\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.randrext}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif	# USE_BUILTIN.randrext

.if !empty(USE_BUILTIN.randrext:M[nN][oO])
BUILDLINK_DEPENDS.randrext+=	randrext>=1.0
.endif

.if !empty(USE_BUILTIN.randrext:M[yY][eE][sS])
BUILDLINK_PREFIX.randrext=	${X11BASE}
USE_X11=			yes
.endif
