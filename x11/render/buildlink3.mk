# $NetBSD: buildlink3.mk,v 1.3 2004/02/16 12:39:00 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RENDER_BUILDLINK3_MK:=	${RENDER_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(RENDER_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		render
BUILDLINK_DEPENDS.render+=	render>=0.2
BUILDLINK_PKGSRCDIR.render?=	../../x11/render
BUILDLINK_DEPMETHOD.render?=	build
.endif	# RENDER_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.render?=	NO

_X11_EXTENSIONS_RENDER_H=	${X11BASE}/include/X11/extensions/render.h

.if !defined(BUILDLINK_IS_BUILTIN.render)
BUILDLINK_IS_BUILTIN.render=	NO
.  if exists(${_X11_EXTENSIONS_RENDER_H})
BUILDLINK_IS_BUILTIN.render=	YES
.    if !empty(BUILDLINK_CHECK_BUILTIN.render:M[nN][oO])
#
# Create an appropriate package name for the built-in render distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
_RENDER_MAJOR!=	\
	${AWK} '/\#define[ 	]*RENDER_MAJOR/ { print $$3 }' ${_X11_EXTENSIONS_RENDER_H}
_RENDER_MINOR!=	\
	${AWK} '/\#define[ 	]*RENDER_MINOR/ { print "."$$3 }' ${_X11_EXTENSIONS_RENDER_H}
_RENDER_VERSION=	${_RENDER_MAJOR}${_RENDER_MINOR}
_RENDER_PKG=		render-${_RENDER_VERSION}
BUILDLINK_IS_BUILTIN.render?=	YES
.      for _depend_ in ${BUILDLINK_DEPENDS.render}
.        if !empty(BUILDLINK_IS_BUILTIN.render:M[yY][eE][sS])
BUILDLINK_IS_BUILTIN.render!=		\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${_RENDER_PKG}; then	\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.        endif
.      endfor
.    endif
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.render=${BUILDLINK_IS_BUILTIN.render}
.endif

.if !empty(BUILDLINK_IS_BUILTIN.render:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.render=	YES
.else
BUILDLINK_USE_BUILTIN.render=	NO
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    !empty(BUILDLINK_IS_BUILTIN.render:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.render=	YES
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.render=	NO
.endif
.if !empty(PREFER_NATIVE:Mrender) && \
    !empty(BUILDLINK_IS_BUILTIN.render:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.render=	YES
.endif
.if !empty(PREFER_PKGSRC:Mrender)
BUILDLINK_USE_BUILTIN.render=	NO
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.render:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.render=	YES
.endif

.if !empty(BUILDLINK_USE_BUILTIN.render:M[nN][oO])
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=		render
.  endif
.endif

.if !empty(RENDER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.render+=	render>=0.8
.  if !empty(BUILDLINK_USE_BUILTIN.render:M[yY][eE][sS])
BUILDLINK_PREFIX.render=	${X11BASE}
.  endif
USE_X11=	yes
.endif	# RENDER_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
