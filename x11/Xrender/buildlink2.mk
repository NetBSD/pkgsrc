# $NetBSD: buildlink2.mk,v 1.12 2004/02/16 21:03:14 jlam Exp $

.if !defined(XRENDER_BUILDLINK2_MK)
XRENDER_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.Xrender?=	Xrender>=0.2
BUILDLINK_PKGSRCDIR.Xrender?=	../../x11/Xrender

# Check if we got Xrender distributed with XFree86 4.x or if we need to
# depend on the Xrender package.
#
_REQUIRE_BUILTIN_XRENDER?=	NO

_X11_TMPL=	${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(_BUILTIN_XRENDER)
_BUILTIN_XRENDER=	NO
.  if exists(${_X11_TMPL})
_IS_BUILTIN.Xrender!=							\
	if ${GREP} -q BuildRenderLibrary ${_X11_TMPL}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
_BUILTIN_XRENDER= ${_IS_BUILTIN.Xrender}
.    if !empty(_IS_BUILTIN.Xrender:M[yY][eE][sS])
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

_BUILTIN_XRENDER?=	YES
.      for _depend_ in ${BUILDLINK_DEPENDS.Xrender}
.        if !empty(_BUILTIN_XRENDER:M[yY][eE][sS])
_BUILTIN_XRENDER!=							\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${_XRENDER_PKG}; then	\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.        endif
.      endfor
.    endif
.  endif
MAKEFLAGS+=	_BUILTIN_XRENDER=${_BUILTIN_XRENDER}
.endif

.if !empty(_BUILTIN_XRENDER:M[yY][eE][sS])
_NEED_XRENDER=	NO
.else
_NEED_XRENDER=	YES
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    ${_BUILTIN_XRENDER} == "YES"
_NEED_XRENDER=	NO
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
_NEED_XRENDER=	YES
.endif
.if !empty(PREFER_NATIVE:MXrender) && \
    ${_BUILTIN_XRENDER} == "YES"
_NEED_XRENDER=	NO
.endif
.if !empty(PREFER_PKGSRC:MXrender)
_NEED_XRENDER=	YES
.endif

.if !empty(_REQUIRE_BUILTIN_XRENDER:M[yY][eE][sS])
_NEED_XRENDER=	NO
.endif

.if ${_NEED_XRENDER} == "YES"
BUILDLINK_PACKAGES+=			Xrender
EVAL_PREFIX+=	BUILDLINK_PREFIX.Xrender=Xrender
BUILDLINK_PREFIX.Xrender_DEFAULT=	${X11PREFIX}
#
# If we depend on the package, depend on the latest version
# with a library minor bump.
#
BUILDLINK_DEPENDS.Xrender=	Xrender>=0.8.2
BUILDLINK_DEPENDS.render=	render>=0.8
.else
BUILDLINK_PREFIX.Xrender=	${X11BASE}
.endif

BUILDLINK_FILES.Xrender=	include/X11/extensions/Xrender.h
BUILDLINK_FILES.Xrender+=	include/X11/extensions/extutil.h
BUILDLINK_FILES.Xrender+=	include/X11/extensions/region.h
BUILDLINK_FILES.Xrender+=	include/X11/extensions/render.h
BUILDLINK_FILES.Xrender+=	include/X11/extensions/renderproto.h
BUILDLINK_FILES.Xrender+=	lib/libXrender.*

USE_X11=	yes

.include "../../x11/render/buildlink2.mk"

BUILDLINK_TARGETS+=		Xrender-buildlink

Xrender-buildlink: _BUILDLINK_USE

.endif	# XRENDER_BUILDLINK2_MK
