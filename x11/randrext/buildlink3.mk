# $NetBSD: buildlink3.mk,v 1.1 2004/02/16 21:50:26 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RANDREXT_BUILDLINK3_MK:=	${RANDREXT_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(RANDREXT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		randrext
BUILDLINK_DEPENDS.randrext+=	randrext>=1.0
BUILDLINK_PKGSRCDIR.randrext?=	../../x11/randrext
BUILDLINK_DEPMETHOD.randrext?=	build
.endif	# RANDREXT_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.randrext?=	NO

_X11_EXTENSIONS_RANDR_H=	${X11BASE}/include/X11/extensions/randr.h

.if !defined(BUILDLINK_IS_BUILTIN.randrext)
BUILDLINK_IS_BUILTIN.randrext=	NO
.  if exists(${_X11_EXTENSIONS_RANDR_H})
BUILDLINK_IS_BUILTIN.randrext=	YES
.    if !empty(BUILDLINK_CHECK_BUILTIN.randrext:M[nN][oO])
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
_RANDR_PKG=	randr-${_RANDR_VERSION}
BUILDLINK_IS_BUILTIN.randrext?=	YES
.      for _depend_ in ${BUILDLINK_DEPENDS.randrext}
.        if !empty(BUILDLINK_IS_BUILTIN.randrext:M[yY][eE][sS])
BUILDLINK_IS_BUILTIN.randrext!=		\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${_RANDR_PKG}; then	\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.        endif
.      endfor
.    endif
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.randrext=${BUILDLINK_IS_BUILTIN.randrext}
.endif

.if !empty(BUILDLINK_IS_BUILTIN.randrext:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.randrext=	YES
.else
BUILDLINK_USE_BUILTIN.randrext=	NO
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    !empty(BUILDLINK_IS_BUILTIN.randrext:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.randrext=	YES
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.randrext=	NO
.endif
.if !empty(PREFER_NATIVE:Mrandr) && \
    !empty(BUILDLINK_IS_BUILTIN.randrext:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.randrext=	YES
.endif
.if !empty(PREFER_PKGSRC:Mrandr)
BUILDLINK_USE_BUILTIN.randrext=	NO
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.randrext:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.randrext=	YES
.endif

.if !empty(BUILDLINK_USE_BUILTIN.randrext:M[nN][oO])
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	randrext
.  endif
.endif

.if !empty(RANDREXT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.randrext+=	randrext>=1.0
.  if !empty(BUILDLINK_USE_BUILTIN.randrext:M[yY][eE][sS])
BUILDLINK_PREFIX.randrext=	${X11BASE}
.  endif
USE_X11=	yes
.endif	# RANDREXT_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
