# $NetBSD: buildlink3.mk,v 1.11 2004/02/19 19:12:26 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XCURSOR_BUILDLINK3_MK:=	${XCURSOR_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(XCURSOR_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		xcursor
BUILDLINK_DEPENDS.xcursor+=	xcursor>=1.0
BUILDLINK_PKGSRCDIR.xcursor?=	../../x11/xcursor
.endif	# XCURSOR_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.xcursor?=	NO

_X11_XCURSOR_XCURSOR_H=	${X11BASE}/include/X11/Xcursor/Xcursor.h

.if !defined(BUILDLINK_IS_BUILTIN.xcursor)
BUILDLINK_IS_BUILTIN.xcursor=	NO
.  if exists(${_X11_XCURSOR_XCURSOR_H})
BUILDLINK_IS_BUILTIN.xcursor=	YES
.    if !empty(BUILDLINK_CHECK_BUILTIN.xcursor:M[nN][oO])
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
_XCURSOR_PKG=	xcursor-${_XCURSOR_VERSION}

BUILDLINK_IS_BUILTIN.xcursor?=	YES
.      for _depend_ in ${BUILDLINK_DEPENDS.xcursor}
.        if !empty(BUILDLINK_IS_BUILTIN.xcursor:M[yY][eE][sS])
BUILDLINK_IS_BUILTIN.xcursor!=		\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${_XCURSOR_PKG}; then	\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.        endif
.      endfor
.    endif
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.xcursor=${BUILDLINK_IS_BUILTIN.xcursor}
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.xcursor:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.xcursor=	YES
.endif

.if !defined(BUILDLINK_USE_BUILTIN.xcursor)
.  if !empty(BUILDLINK_IS_BUILTIN.xcursor:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.xcursor=	YES
.  else
BUILDLINK_USE_BUILTIN.xcursor=	NO
.  endif

.  if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
      !empty(BUILDLINK_IS_BUILTIN.xcursor:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.xcursor=	YES
.  endif
.  if !empty(PREFER_PKGSRC:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.xcursor=	NO
.  endif
.  if !empty(PREFER_NATIVE:Mxcursor) && \
      !empty(BUILDLINK_IS_BUILTIN.xcursor:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.xcursor=	YES
.  endif
.  if !empty(PREFER_PKGSRC:Mxcursor)
BUILDLINK_USE_BUILTIN.xcursor=	NO
.  endif
.endif

.if !empty(BUILDLINK_USE_BUILTIN.xcursor:M[nN][oO])
BUILDLINK_DEPENDS.xcursor+=	xcursor>=1.1.1
BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.8
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xcursor
.  endif
.endif

.if !empty(BUILDLINK_USE_BUILTIN.xcursor:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.Xrender=	yes
.endif

.if !empty(XCURSOR_BUILDLINK3_MK:M+)
.  if !empty(BUILDLINK_USE_BUILTIN.xcursor:M[yY][eE][sS])
BUILDLINK_PREFIX.xcursor=	${X11BASE}
BUILDLINK_FILES.xcursor+=	lib/pkgconfig/xcursor.pc
.  endif
USE_X11=	yes
.  if !empty(BUILDLINK_CHECK_BUILTIN.xcursor:M[nN][oO])
.    if !empty(BUILDLINK_USE_BUILTIN.xcursor:M[nN][oO])
.      include "../../x11/Xfixes/buildlink3.mk"
.    endif
.    include "../../x11/Xrender/buildlink3.mk"
.  endif
.endif	# XCURSOR_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
