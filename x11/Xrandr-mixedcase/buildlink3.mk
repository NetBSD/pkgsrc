# $NetBSD: buildlink3.mk,v 1.6 2004/02/16 22:45:34 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XRANDR_BUILDLINK3_MK:=	${XRANDR_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(XRANDR_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		Xrandr
BUILDLINK_DEPENDS.Xrandr+=	Xrandr>=1.0
BUILDLINK_PKGSRCDIR.Xrandr?=	../../x11/Xrandr
.endif	# XRANDR_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.Xrandr?=	NO

_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(BUILDLINK_IS_BUILTIN.Xrandr)
BUILDLINK_IS_BUILTIN.Xrandr=	NO
.  if exists(${_X11_TMPL})
_IS_BUILTIN.Xrandr!=							\
	if ${GREP} -q BuildRandRLibrary ${_X11_TMPL}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
BUILDLINK_IS_BUILTIN.Xrandr= ${_IS_BUILTIN.Xrandr}
.    if !empty(BUILDLINK_CHECK_BUILTIN.Xrandr:M[nN][oO]) && \
        !empty(_IS_BUILTIN.Xrandr:M[yY][eE][sS])
#
# Create an appropriate package name for the built-in Xrandr distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
# Xrandr doesn't provide a method of discovering the version number of
# the software.  Match up Xrandr versions with XFree86 versions for an
# approximate determination of the Xrandr version.
#
_XRANDR_VERSIONS=	1.0.2  1.0.1  1.0
_XRANDR_1.0=		4.2 4.2.* 4.3 4.3.[0-8][0-9]* 4.3.9[0-8]*
.      if !defined(_XF86_VERSION)
_X11_CONFIG_VERSION_DEF=	${X11BASE}/lib/X11/config/version.def
.        if !exists(${_X11_CONFIG_VERSION_DEF})
_XF86_VERSION=	3.3
.        else
_XF86_MAJOR!=	\
	${AWK} '/\#define[ 	]*XF86_VERSION_MAJOR/ { print $$3 }'	\
		${_X11_CONFIG_VERSION_DEF}
_XF86_MINOR!=	\
	${AWK} '/\#define[ 	]*XF86_VERSION_MINOR/ { print $$3 }'	\
		${_X11_CONFIG_VERSION_DEF}
_XF86_PATCH!=	\
	${AWK} '/\#define[ 	]*XF86_VERSION_PATCH/ { print $$3 }'	\
		${_X11_CONFIG_VERSION_DEF}
_XF86_SNAP!=	\
	${AWK} '/\#define[ 	]*XF86_VERSION_SNAP/ { print $$3 }'	\
		${_X11_CONFIG_VERSION_DEF}
_XF86_TEENY=	${_XF86_PATCH}.${_XF86_SNAP}
.          if !empty(_XF86_TEENY:M0.0)
_XF86_VERSION=	${_XF86_MAJOR}.${_XF86_MINOR}
.          else
_XF86_VERSION=	${_XF86_MAJOR}.${_XF86_MINOR}.${_XF86_TEENY}
.          endif
.        endif
.      endif
.      for _xrender_version_ in ${_XRANDR_VERSIONS}
.        for _pattern_ in ${_XRANDR_${_xrender_version_}}
.          if !empty(_XF86_VERSION:M${_pattern_})
_XRANDR_VERSION?=	${_xrender_version_}
.          endif
.        endfor
.      endfor
_XRANDR_VERSION?=	1.0
_XRANDR_PKG=		Xrandr-${_XRANDR_VERSION}

BUILDLINK_IS_BUILTIN.Xrandr?=	YES
.      for _depend_ in ${BUILDLINK_DEPENDS.Xrandr}
.        if !empty(BUILDLINK_IS_BUILTIN.Xrandr:M[yY][eE][sS])
BUILDLINK_IS_BUILTIN.Xrandr!=		\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${_XRANDR_PKG}; then	\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.        endif
.      endfor
.    endif
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.Xrandr=${BUILDLINK_IS_BUILTIN.Xrandr}
.endif

.if !empty(BUILDLINK_IS_BUILTIN.Xrandr:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.Xrandr=	YES
.else
BUILDLINK_USE_BUILTIN.Xrandr=	NO
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    !empty(BUILDLINK_IS_BUILTIN.Xrandr:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.Xrandr=	YES
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.Xrandr=	NO
.endif
.if !empty(PREFER_NATIVE:MXrandr) && \
    !empty(BUILDLINK_IS_BUILTIN.Xrandr:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.Xrandr=	YES
.endif
.if !empty(PREFER_PKGSRC:MXrandr)
BUILDLINK_USE_BUILTIN.Xrandr=	NO
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.Xrandr:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.Xrandr=	YES
.endif

.if !empty(BUILDLINK_USE_BUILTIN.Xrandr:M[nN][oO])
BUILDLINK_DEPENDS.Xrandr+=	Xrandr>=1.0.1
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=		Xrandr
.  endif
.endif

.if !empty(XRANDR_BUILDLINK3_MK:M+)
.  if !empty(BUILDLINK_USE_BUILTIN.Xrandr:M[yY][eE][sS])
BUILDLINK_PREFIX.Xrandr=	${X11BASE}
.  endif
USE_X11=	yes
BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.8
.  include "../../x11/randrext/buildlink3.mk"
.  include "../../x11/Xrender/buildlink3.mk"
.endif	# XRANDR_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
