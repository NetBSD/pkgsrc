# $NetBSD: builtin.mk,v 1.2 2004/03/29 05:43:36 jlam Exp $

_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(IS_BUILTIN.Xrandr)
IS_BUILTIN.Xrandr=	no
.  if exists(${_X11_TMPL})
IS_BUILTIN.Xrandr!=							\
	if ${GREP} -q BuildRandRLibrary ${_X11_TMPL}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    if !empty(IS_BUILTIN.Xrandr:M[yY][eE][sS])
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
_XRANDR_1.0=	4.2 4.2.* 4.3 4.3.[0-9] 4.3.[0-9].* 4.3.[1-8][0-9]* 4.3.9[0-8]*
.      if !defined(_XF86_VERSION)
_X11_CONFIG_VERSION_DEF=	${X11BASE}/lib/X11/config/version.def
_XF86_VERSION=	3.3
.        if exists(${_X11_CONFIG_VERSION_DEF})
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
BUILDLINK_VARS+=	_XF86_VERSION
.      endif
.      for _xrandr_version_ in ${_XRANDR_VERSIONS}
.        for _pattern_ in ${_XRANDR_${_xrandr_version_}}
.          if !empty(_XF86_VERSION:M${_pattern_})
_XRANDR_VERSION?=	${_xrandr_version_}
.          endif
.        endfor
.      endfor
_XRANDR_VERSION?=	1.0
BUILTIN_PKG.Xrandr=	Xrandr-${_XRANDR_VERSION}
BUILDLINK_VARS+=	BUILTIN_PKG.Xrandr
.    endif
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.Xrandr
.endif	# IS_BUILTIN.Xrandr

.if defined(USE_BUILTIN.randrext) && !empty(USE_BUILTIN.randrext:M[nN][oO])
USE_BUILTIN.Xrandr=	no
.endif
.if defined(USE_BUILTIN.Xrender) && !empty(USE_BUILTIN.Xrender:M[nN][oO])
USE_BUILTIN.Xrandr=	no
.endif

.if !defined(USE_BUILTIN.Xrandr)
USE_BUILTIN.Xrandr?=	${IS_BUILTIN.Xrandr}

.  if defined(BUILTIN_PKG.Xrandr)
USE_BUILTIN.Xrandr=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.Xrandr}
.      if !empty(USE_BUILTIN.Xrandr:M[yY][eE][sS])
USE_BUILTIN.Xrandr!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.Xrandr}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif	# USE_BUILTIN.Xrandr

CHECK_BUILTIN.Xrandr?=	no
.if !empty(CHECK_BUILTIN.Xrandr:M[nN][oO])

.if !empty(USE_BUILTIN.Xrandr:M[nN][oO])
BUILDLINK_DEPENDS.Xrandr+=	Xrandr>=1.0.1
BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.8
.endif

.if !empty(USE_BUILTIN.Xrandr:M[yY][eE][sS])
BUILDLINK_PREFIX.Xrandr=	${X11BASE}
USE_BUILTIN.randrext=		yes
USE_BUILTIN.Xrender=		yes
.endif

.endif	# CHECK_BUILTIN.Xrandr
