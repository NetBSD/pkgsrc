# $NetBSD: builtin.mk,v 1.4.16.1 2008/09/26 19:59:46 cube Exp $

# TODO: builtin.mk failed to use native on XFree86
# the two headers are identical with native XFree86

BUILTIN_PKG:=	randrproto

BUILTIN_FIND_FILES_VAR:=	H_RANDR
BUILTIN_FIND_FILES.H_RANDR=	${X11BASE}/include/X11/extensions/randr.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.randrproto=	no
.elif !defined(IS_BUILTIN.randrproto)
IS_BUILTIN.randrproto=	no
#
# Here, we skip checking whether the files are under ${LOCALBASE} since
# we'll consider this X11 package to be built-in even if it's a part
# of one of the pkgsrc-installed X11 distributions.
#
.  if empty(H_RANDR:M__nonexistent__)
IS_BUILTIN.randrproto=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.randrproto

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.randrproto) && \
    !empty(IS_BUILTIN.randrproto:M[yY][eE][sS]) && \
    empty(H_RANDR:M__nonexistent__)
BUILTIN_VERSION.randrproto!=						\
	${AWK} '/\#define[ 	]*RANDR_MAJOR/ { M = $$3 }		\
		/\#define[ 	]*RANDR_MINOR/ { m = "."$$3 }		\
		END { printf "%s%s\n", M, m }'				\
		${H_RANDR}
BUILTIN_PKG.randrproto=	randrproto-${BUILTIN_VERSION.randrproto}
.endif
MAKEVARS+=	BUILTIN_PKG.randrproto

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.randrproto)
.  if ${PREFER.randrproto} == "pkgsrc"
USE_BUILTIN.randrproto=	no
.  else
USE_BUILTIN.randrproto=	${IS_BUILTIN.randrproto}
.    if defined(BUILTIN_PKG.randrproto) && \
        !empty(IS_BUILTIN.randrproto:M[yY][eE][sS])
USE_BUILTIN.randrproto=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.randrproto}
.        if !empty(USE_BUILTIN.randrproto:M[yY][eE][sS])
USE_BUILTIN.randrproto!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.randrproto:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.randrproto
.endif
MAKEVARS+=	USE_BUILTIN.randrproto

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###

.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.randrproto?=	no
.if !empty(CHECK_BUILTIN.randrproto:M[nN][oO])

.  if !empty(USE_BUILTIN.randrproto:M[nN][oO])
BUILDLINK_API_DEPENDS.randrproto+=	randrproto>=1.0
.  endif

.endif	# CHECK_BUILTIN.randrproto
