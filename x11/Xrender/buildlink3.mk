# $NetBSD: buildlink3.mk,v 1.8 2003/11/10 02:26:53 fredb Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XRENDER_BUILDLINK3_MK:=	${XRENDER_BUILDLINK3_MK}+

.if !empty(XRENDER_BUILDLINK3_MK:M\+)
.  include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.Xrender?=	Xrender>=0.2
BUILDLINK_PKGSRCDIR.Xrender?=	../../x11/Xrender
.endif	# XRENDER_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.Xrender?=	NO

_X11_EXTENSIONS_RENDER_H=	${X11BASE}/include/X11/extensions/render.h
_X11_TMPL=			${X11BASE}/lib/X11/config/X11.tmpl

.if !defined(BUILDLINK_IS_BUILTIN.Xrender)
BUILDLINK_IS_BUILTIN.Xrender=	NO
.  if exists(${_X11_EXTENSIONS_RENDER_H}) && exists(${_X11_TMPL})
BUILDLINK_IS_BUILTIN.Xrender!=						\
	if ${GREP} -q BuildRenderLibrary ${_X11_TMPL}; then		\
		${ECHO} YES;						\
	else								\
		${ECHO} NO;						\
	fi
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.Xrender=${BUILDLINK_IS_BUILTIN.Xrender}
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.Xrender:M[yY][eE][sS])
_NEED_XRENDER=	NO
.endif

.if !defined(_NEED_XRENDER)
.  if !empty(BUILDLINK_IS_BUILTIN.Xrender:M[nN][oO])
_NEED_XRENDER=	YES
.  else
#
# Create an appropriate package name for the built-in Xrender distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
_XRENDER_MAJOR!=	\
	${AWK} '/\#define[ 	]*RENDER_MAJOR/ { print $$3 }' ${_X11_EXTENSIONS_RENDER_H}
_XRENDER_MINOR!=	\
	${AWK} '/\#define[ 	]*RENDER_MINOR/ { print "."$$3 }' ${_X11_EXTENSIONS_RENDER_H}
_XRENDER_VERSION=	${_XRENDER_MAJOR}${_XRENDER_MINOR}
_XRENDER_PKG=		Xrender-${_XRENDER_VERSION}
_XRENDER_DEPENDS=	${BUILDLINK_DEPENDS.Xrender}
_NEED_XRENDER!=		\
	if ${PKG_ADMIN} pmatch '${_XRENDER_DEPENDS}' ${_XRENDER_PKG}; then \
		${ECHO} "NO";						\
	else								\
		${ECHO} "YES";						\
	fi
.  endif
MAKEFLAGS+=	_NEED_XRENDER="${_NEED_XRENDER}"
.endif	# _NEED_XRENDER

.if ${_NEED_XRENDER} == "YES"
#
# If we depend on the package, depend on the latest version with a library
# minor number bump.
#
BUILDLINK_DEPENDS.Xrender=	Xrender>=0.8.2
.  if !empty(BUILDLINK_DEPTH:M\+)
BUILDLINK_DEPENDS+=		Xrender
.  endif
.endif

.if !empty(XRENDER_BUILDLINK3_MK:M\+)
.  if ${_NEED_XRENDER} == "YES"
BUILDLINK_PACKAGES+=		Xrender
.  else
BUILDLINK_PREFIX.Xrender=	${X11BASE}
.  endif
.endif	# XRENDER_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
