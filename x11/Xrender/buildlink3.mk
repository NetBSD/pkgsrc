# $NetBSD: buildlink3.mk,v 1.3 2003/09/13 23:21:22 jlam Exp $

.if !defined(XRENDER_BUILDLINK3_MK)
XRENDER_BUILDLINK3_MK=	# defined
BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.Xrender?=	Xrender>=0.2
BUILDLINK_PKGSRCDIR.Xrender?=	../../x11/Xrender

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
.else
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
.endif

.if ${_NEED_XRENDER} == "YES"
#
# If we depend on the package, depend on the latest version with a library
# major number bump.
#
BUILDLINK_DEPENDS.Xrender=	Xrender>=0.7
.  if !empty(BUILDLINK_DEPTH:M\+)
BUILDLINK_DEPENDS+=		Xrender
.  endif
BUILDLINK_PACKAGES+=		Xrender
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
.endif	# XRENDER_BUILDLINK3_MK
