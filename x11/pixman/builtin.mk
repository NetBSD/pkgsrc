# $NetBSD: builtin.mk,v 1.2 2008/09/16 11:41:33 tron Exp $

BUILTIN_PKG:=	pixman

BUILTIN_FIND_FILES_VAR:=	H_PIXMAN
BUILTIN_FIND_FILES.H_PIXMAN=	${X11BASE}/include/pixman-1/pixman.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.pixman=	no
.elif !defined(IS_BUILTIN.pixman)
IS_BUILTIN.pixman=	no
.  if empty(H_PIXMAN:M__nonexistent__)
IS_BUILTIN.pixman=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.pixman

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.pixman)
.  if ${PREFER.pixman} == "pkgsrc"
USE_BUILTIN.pixman=	no
.  else
USE_BUILTIN.pixman=	${IS_BUILTIN.pixman}
.    if defined(BUILTIN_PKG.pixman) && \
        !empty(IS_BUILTIN.pixman:M[yY][eE][sS])
USE_BUILTIN.pixman=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.pixman}
.        if !empty(USE_BUILTIN.pixman:M[yY][eE][sS])
USE_BUILTIN.pixman!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.pixman:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.pixman
.endif
MAKEVARS+=	USE_BUILTIN.pixman

.if !empty(USE_BUILTIN.pixman:M[yY][eE][sS])
BUILDLINK_PREFIX.pixman=	${X11BASE}
BUILDLINK_PASSTHRU_DIRS+=	${X11BASE}/include ${X11BASE}/lib
.endif
