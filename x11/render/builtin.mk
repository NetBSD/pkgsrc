# $NetBSD: builtin.mk,v 1.2 2004/03/29 05:43:36 jlam Exp $

_X11_EXTENSIONS_RENDER_H=	${X11BASE}/include/X11/extensions/render.h

.if !defined(IS_BUILTIN.render)
IS_BUILTIN.render=	no
.  if exists(${_X11_EXTENSIONS_RENDER_H})
IS_BUILTIN.render=	yes
#
# Create an appropriate package name for the built-in render distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc version
# or if the built-in one is sufficient.
#
_RENDER_MAJOR!=	\
	${AWK} '/\#define[ 	]*RENDER_MAJOR/ { print $$3 }'		\
		${_X11_EXTENSIONS_RENDER_H}
_RENDER_MINOR!=	\
	${AWK} '/\#define[ 	]*RENDER_MINOR/ { print "."$$3 }'	\
		${_X11_EXTENSIONS_RENDER_H}
_RENDER_VERSION=	${_RENDER_MAJOR}${_RENDER_MINOR}
BUILTIN_PKG.render=	render-${_RENDER_VERSION}
BUILDLINK_VARS+=	BUILTIN_PKG.render
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.render
.endif	# IS_BUILTIN.render

.if !defined(USE_BUILTIN.render)
USE_BUILTIN.render?=	${IS_BUILTIN.render}

.  if defined(BUILTIN_PKG.render)
USE_BUILTIN.render=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.render}
.      if !empty(USE_BUILTIN.render:M[yY][eE][sS])
USE_BUILTIN.render!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.render}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif	# USE_BUILTIN.render

CHECK_BUILTIN.render?=	no
.if !empty(CHECK_BUILTIN.render:M[nN][oO])

.if !empty(USE_BUILTIN.render:M[nN][oO])
BUILDLINK_DEPENDS.render+=	render>=0.8
.endif

.if !empty(USE_BUILTIN.render:M[yY][eE][sS])
BUILDLINK_PREFIX.render=	${X11BASE}
USE_X11=			yes
.endif

.endif	# CHECK_BUILTIN.render
