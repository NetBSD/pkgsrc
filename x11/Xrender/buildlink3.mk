# $NetBSD: buildlink3.mk,v 1.22 2004/02/16 21:04:39 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XRENDER_BUILDLINK3_MK:=	${XRENDER_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(XRENDER_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		Xrender
BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.2
BUILDLINK_PKGSRCDIR.Xrender?=	../../x11/Xrender
.endif	# XRENDER_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.Xrender?=	NO

_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(BUILDLINK_IS_BUILTIN.Xrender)
BUILDLINK_IS_BUILTIN.Xrender=	NO
.  if exists(${_X11_TMPL})
_IS_BUILTIN.Xrender!=							\
	if ${GREP} -q BuildRenderLibrary ${_X11_TMPL}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
BUILDLINK_IS_BUILTIN.Xrender= ${_IS_BUILTIN.Xrender}
.    if !empty(BUILDLINK_CHECK_BUILTIN.Xrender:M[nN][oO]) && \
        !empty(_IS_BUILTIN.Xrender:M[yY][eE][sS])
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
_XRENDER_0.1=		4.0 4.0.* 4.1 4.1.[0-8][0-9]* 4.1.9[0-8]*
_XRENDER_0.2=		4.1.99.* 4.2 4.2.[0-8][0-9]* 4.2.9[0-8]*
_XRENDER_0.8=		4.2.99.* 4.3 4.3.[0-8][0-9]* 4.3.9[0-8]*
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
.      for _xrender_version_ in ${_XRENDER_VERSIONS}
.        for _pattern_ in ${_XRENDER_${_xrender_version_}}
.          if !empty(_XF86_VERSION:M${_pattern_})
_XRENDER_VERSION?=	${_xrender_version_}
.          endif
.        endfor
.      endfor
_XRENDER_VERSION?=	0.1
_XRENDER_PKG=		Xrender-${_XRENDER_VERSION}

BUILDLINK_IS_BUILTIN.Xrender?=	YES
.      for _depend_ in ${BUILDLINK_DEPENDS.Xrender}
.        if !empty(BUILDLINK_IS_BUILTIN.Xrender:M[yY][eE][sS])
BUILDLINK_IS_BUILTIN.Xrender!=		\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${_XRENDER_PKG}; then	\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.        endif
.      endfor
.    endif
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.Xrender=${BUILDLINK_IS_BUILTIN.Xrender}
.endif

.if !empty(BUILDLINK_IS_BUILTIN.Xrender:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.Xrender=	YES
.else
BUILDLINK_USE_BUILTIN.Xrender=	NO
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    !empty(BUILDLINK_IS_BUILTIN.Xrender:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.Xrender=	YES
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.Xrender=	NO
.endif
.if !empty(PREFER_NATIVE:MXrender) && \
    !empty(BUILDLINK_IS_BUILTIN.Xrender:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.Xrender=	YES
.endif
.if !empty(PREFER_PKGSRC:MXrender)
BUILDLINK_USE_BUILTIN.Xrender=	NO
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.Xrender:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.Xrender=	YES
.endif

.if !empty(BUILDLINK_USE_BUILTIN.Xrender:M[nN][oO])
BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.8.2
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=		Xrender
.  endif
.endif

.if !empty(XRENDER_BUILDLINK3_MK:M+)
.  if !empty(BUILDLINK_USE_BUILTIN.Xrender:M[yY][eE][sS])
BUILDLINK_PREFIX.Xrender=	${X11BASE}
.  endif
USE_X11=	yes
.  if !empty(BUILDLINK_DEPENDS.Xrender:MXrender>=0.8*)
BUILDLINK_DEPENDS.render+=	render>=0.8
.  endif
.  include "../../x11/render/buildlink3.mk"
.endif	# XRENDER_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
