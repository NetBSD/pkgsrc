# $NetBSD: builtin.mk,v 1.1 2008/01/05 15:41:58 tron Exp $

# TODO: builtin.mk failed to use native on XFree86
# the two headers are identical with native XFree86

BUILTIN_PKG:=	xineramaproto

BUILTIN_FIND_FILES_VAR:=	H_XINERAMA
BUILTIN_FIND_FILES.H_XINERAMA=	${X11BASE}/include/X11/extensions/Xinerama.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.xineramaproto=	no
.elif !defined(IS_BUILTIN.xineramaproto)
IS_BUILTIN.xineramaproto=	no
#
# Here, we skip checking whether the files are under ${LOCALBASE} since
# we'll consider this X11 package to be built-in even if it's a part
# of one of the pkgsrc-installed X11 distributions.
#
.  if empty(H_XINERAMA:M__nonexistent__)
IS_BUILTIN.xineramaproto=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.xineramaproto

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.xineramaproto) && \
    !empty(IS_BUILTIN.xineramaproto:M[yY][eE][sS]) && \
    empty(H_XINERAMA:M__nonexistent__)
BUILTIN_VERSION.xineramaproto!=						\
	${AWK} '/\#define[ 	]*XINERAMA_MAJOR/ { M = $$3 }		\
		/\#define[ 	]*XINERAMA_MINOR/ { m = "."$$3 }		\
		END { printf "%s%s\n", M, m }'				\
		${H_XINERAMA}
BUILTIN_PKG.xineramaproto=	xineramaproto-${BUILTIN_VERSION.xineramaproto}
.endif
MAKEVARS+=	BUILTIN_PKG.xineramaproto

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.xineramaproto)
.  if ${PREFER.xineramaproto} == "pkgsrc"
USE_BUILTIN.xineramaproto=	no
.  else
USE_BUILTIN.xineramaproto=	${IS_BUILTIN.xineramaproto}
.    if defined(BUILTIN_PKG.xineramaproto) && \
        !empty(IS_BUILTIN.xineramaproto:M[yY][eE][sS])
USE_BUILTIN.xineramaproto=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.xineramaproto}
.        if !empty(USE_BUILTIN.xineramaproto:M[yY][eE][sS])
USE_BUILTIN.xineramaproto!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.xineramaproto:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.xineramaproto
.endif
MAKEVARS+=	USE_BUILTIN.xineramaproto

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.xineramaproto?=	no
.if !empty(CHECK_BUILTIN.xineramaproto:M[nN][oO])

.  if !empty(USE_BUILTIN.xineramaproto:M[nN][oO])
BUILDLINK_API_DEPENDS.xineramaproto+=	xineramaproto>=1.0
.  endif

.  if !empty(USE_BUILTIN.xineramaproto:M[yY][eE][sS])
BUILDLINK_PREFIX.xineramaproto=	${X11BASE}
.    include "../../mk/x11.buildlink3.mk"
.    include "../../mk/x11.builtin.mk"
.  endif

.endif	# CHECK_BUILTIN.xineramaproto
