# $NetBSD: buildlink2.mk,v 1.4 2004/03/15 16:24:24 recht Exp $

.if !defined(XCURSOR_BUILDLINK2_MK)
XCURSOR_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.xcursor?=	xcursor>=1.0
BUILDLINK_PKGSRCDIR.xcursor?=	../../x11/xcursor

# Check if we got xcursor distributed with XFree86 4.x or if we need to
# depend on the xcursor package.
#
_REQUIRE_BUILTIN_XCURSOR?=	NO

_X11_XCURSOR_XCURSOR_H=	${X11BASE}/include/X11/Xcursor/Xcursor.h

.if !defined(_BUILTIN_XCURSOR)
_BUILTIN_XCURSOR=	NO
.  if exists(${_X11_XCURSOR_XCURSOR_H})
_BUILTIN_XCURSOR=	YES
#
# Create an appropriate package name for the built-in Xcursor distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
_XCURSOR_MAJOR!=	\
	${AWK} '/\#define[ 	]*XCURSOR_MAJOR/ { print $$3 }'		\
		${_X11_XCURSOR_XCURSOR_H}
_XCURSOR_MINOR!=	\
	${AWK} '/\#define[ 	]*XCURSOR_MINOR/ { print "."$$3 }'	\
		${_X11_XCURSOR_XCURSOR_H}
_XCURSOR_REVISION!=	\
	${AWK} '/\#define[ 	]*XCURSOR_MINOR/ { print "."$$3 }'	\
		${_X11_XCURSOR_XCURSOR_H}
_XCURSOR_VERSION=	${_XCURSOR_MAJOR}${_XCURSOR_MINOR}${_XCURSOR_REVISION}
_XCURSOR_PKG=		xcursor-${_XCURSOR_VERSION}

_BUILTIN_XCURSOR?=	YES
.    for _depend_ in ${BUILDLINK_DEPENDS.xcursor}
.      if !empty(_BUILTIN_XCURSOR:M[yY][eE][sS])
_BUILTIN_XCURSOR!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${_XCURSOR_PKG}; then	\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
MAKEFLAGS+=	_BUILTIN_XCURSOR=${_BUILTIN_XCURSOR}
.endif

.if !empty(_BUILTIN_XCURSOR:M[yY][eE][sS])
_NEED_XCURSOR=	NO
.else
_NEED_XCURSOR=	YES
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    ${_BUILTIN_XCURSOR} == "YES"
_NEED_XCURSOR=	NO
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
_NEED_XCURSOR=	YES
.endif
.if !empty(PREFER_NATIVE:Mxcursor) && \
    ${_BUILTIN_XCURSOR} == "YES"
_NEED_XCURSOR=	NO
.endif
.if !empty(PREFER_PKGSRC:Mxcursor)
_NEED_XCURSOR=	YES
.endif

.if !empty(_REQUIRE_BUILTIN_XCURSOR:M[yY][eE][sS])
_NEED_XCURSOR=	NO
.endif

.if ${_NEED_XCURSOR} == "YES"
BUILDLINK_PACKAGES+=		xcursor
EVAL_PREFIX+=	BUILDLINK_PREFIX.xcursor=xcursor
BUILDLINK_PREFIX.xcursor_DEFAULT=	${LOCALBASE}

BUILDLINK_DEPENDS.xcursor=	xcursor>=1.1.1
BUILDLINK_DEPENDS.Xrender=	Xrender>=0.8
.else
BUILDLINK_PREFIX.xcursor=	${X11BASE}
.endif

BUILDLINK_FILES.xcursor+=	include/X11/Xcursor/*.h
BUILDLINK_FILES.xcursor+=	lib/libXcursor.*

USE_X11=	yes

.include "../../x11/Xfixes/buildlink2.mk"
.include "../../x11/Xrender/buildlink2.mk"

BUILDLINK_TARGETS+=	xcursor-buildlink

xcursor-buildlink: _BUILDLINK_USE

.endif	# XCURSOR_BUILDLINK2_MK
