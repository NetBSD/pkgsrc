# $NetBSD: builtin.mk,v 1.3 2004/03/30 17:04:06 jlam Exp $

_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(IS_BUILTIN.Xrender)
IS_BUILTIN.Xrender=	no
.  if exists(${_X11_TMPL})
IS_BUILTIN.Xrender!=							\
	if ${GREP} -q BuildRenderLibrary ${_X11_TMPL}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.    if !empty(IS_BUILTIN.Xrender:M[yY][eE][sS])
#
# Create an appropriate package name for the built-in Xrender distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
# Xrender doesn't provide a method of discovering the version number of
# the software.  Match up Xrender versions with XFree86 versions for an
# approximate determination of the Xrender version.
#
_XRENDER_VERSIONS=	0.8.3  0.8.2  0.8.1  0.8  0.2  0.1
_XRENDER_0.1=	4.0 4.0.* 4.1 4.1.[0-9] 4.1.[0-9].* 4.1.[1-8][0-9]* 4.1.9[0-8]*
_XRENDER_0.2=	4.1.99.* 4.2 4.2.[0-9] 4.2.[0-9].* 4.2.[1-8][0-9]* 4.2.9[0-8]*
_XRENDER_0.8=	4.2.99.* 4.3 4.3.[0-9] 4.3.[0-9].* 4.3.[1-8][0-9]* 4.3.9[0-8]*
.      if !defined(XF86_VERSION)
_X11_CONFIG_VERSION_DEF=	${X11BASE}/lib/X11/config/version.def
XF86_VERSION=	3.3
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
XF86_VERSION=	${_XF86_MAJOR}.${_XF86_MINOR}
.          else
_F86_VERSION=	${_XF86_MAJOR}.${_XF86_MINOR}.${_XF86_TEENY}
.          endif
.        endif
BUILDLINK_VARS+=	XF86_VERSION
.      endif
.      for _xrender_version_ in ${_XRENDER_VERSIONS}
.        for _pattern_ in ${_XRENDER_${_xrender_version_}}
.          if !empty(XF86_VERSION:M${_pattern_})
_XRENDER_VERSION?=	${_xrender_version_}
.          endif
.        endfor
.      endfor
_XRENDER_VERSION?=	0.1
BUILTIN_PKG.Xrender=	Xrender-${_XRENDER_VERSION}
BUILDLINK_VARS+=	BUILTIN_PKG.Xrender
.    endif
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.Xrender
.endif	# IS_BUILTIN.Xrender

#.if defined(USE_BUILTIN.render) && !empty(USE_BUILTIN.render:M[nN][oO])
#USE_BUILTIN.Xrender=	no
#.endif

.if !defined(USE_BUILTIN.Xrender)
USE_BUILTIN.Xrender?=	${IS_BUILTIN.Xrender}

.  if defined(BUILTIN_PKG.Xrender)
USE_BUILTIN.Xrender=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.Xrender}
.      if !empty(USE_BUILTIN.Xrender:M[yY][eE][sS])
USE_BUILTIN.Xrender!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.Xrender}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif	# USE_BUILTIN.Xrender

CHECK_BUILTIN.Xrender?=	no
.if !empty(CHECK_BUILTIN.Xrender:M[nN][oO])

.if !empty(USE_BUILTIN.Xrender:M[nN][oO])
BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.8.2
BUILDLINK_DEPENDS.render+=	render>=0.8
.endif

.if !empty(USE_BUILTIN.Xrender:M[yY][eE][sS])
BUILDLINK_PREFIX.Xrender=	${X11BASE}
USE_BUILTIN.render=		yes
.endif

.endif	# CHECK_BUILTIN.Xrender
