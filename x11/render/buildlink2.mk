# $NetBSD: buildlink2.mk,v 1.2 2004/02/16 12:39:00 jlam Exp $

.if !defined(RENDER_BUILDLINK2_MK)
RENDER_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.render?=	render>=0.2
BUILDLINK_PKGSRCDIR.render?=	../../x11/render
BUILDLINK_DEPMETHOD.render?=	build

# Check if we got render distributed with XFree86 4.x or if we need to
# depend on the render package.
#
_REQUIRE_BUILTIN_RENDER?=	NO

_RENDER_H=	${X11BASE}/include/X11/extensions/render.h

.if !defined(_BUILTIN_RENDER)
_BUILTIN_RENDER=	NO
.  if exists(${_RENDER_H})
# Create an appropriate render package name for the built-in render
# distributed with XFree86 4.x.  This package name can be used to check
# against BUILDLINK_DEPENDS.render to see if we need to install the
# pkgsrc render or if the built-in one is sufficient.
#
_RENDER_MAJOR!= \
	${AWK} '/.*\#define.*RENDER_MAJOR/ { print $$3 }' ${_RENDER_H}
_RENDER_MINOR!= \
	${AWK} '/.*\#define.*RENDER_MINOR/ { print "."$$3 }' ${_RENDER_H}
_RENDER_VERSION=	${_RENDER_MAJOR}${_RENDER_MINOR}
_RENDER_PKG=		render-${_RENDER_VERSION}
_RENDER_DEPENDS=	${BUILDLINK_DEPENDS.render}
_BUILTIN_RENDER!= \
	if ${PKG_ADMIN} pmatch '${_RENDER_DEPENDS}' ${_RENDER_PKG}; then \
		if ${GREP} -q BuildRenderLibrary ${_X11_TMPL}; then	\
			${ECHO} "YES";					\
		else							\
			${ECHO} "NO";					\
		fi;							\
	else								\
		${ECHO} "NO";						\
	fi
.  endif
MAKEFLAGS+=	_BUILTIN_RENDER=${_BUILTIN_RENDER}
.endif

.if !empty(_BUILTIN_RENDER:M[yY][eE][sS])
_NEED_RENDER=	NO
.else
_NEED_RENDER=	YES
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    ${_BUILTIN_RENDER} == "YES"
_NEED_RENDER=	NO
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
_NEED_RENDER=	YES
.endif
.if !empty(PREFER_NATIVE:Mrender) && \
    ${_BUILTIN_RENDER} == "YES"
_NEED_RENDER=	NO
.endif
.if !empty(PREFER_PKGSRC:Mrender)
_NEED_RENDER=	YES
.endif

.if !empty(_REQUIRE_BUILTIN_RENDER:M[yY][eE][sS])
_NEED_RENDER=	NO
.endif

.if ${_NEED_RENDER} == "YES"
BUILDLINK_PACKAGES+=			render
EVAL_PREFIX+=	BUILDLINK_PREFIX.render=render
BUILDLINK_PREFIX.render_DEFAULT=	${X11PREFIX}
BUILDLINK_DEPENDS.render=		render>=0.8
.else
BUILDLINK_PREFIX.render=	${X11BASE}
.endif

BUILDLINK_FILES.render=		include/X11/extensions/render.h
BUILDLINK_FILES.render+=	include/X11/extensions/renderproto.h

USE_X11=	yes

BUILDLINK_TARGETS+=		render-buildlink

render-buildlink: _BUILDLINK_USE

.endif	# RENDER_BUILDLINK2_MK
