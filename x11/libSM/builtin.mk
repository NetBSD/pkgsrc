# $NetBSD: builtin.mk,v 1.1.10.1 2008/09/26 21:15:18 cube Exp $

BUILTIN_PKG:=	libSM

BUILTIN_FIND_FILES_VAR:=	H_SM
BUILTIN_FIND_FILES.H_SM=	${X11BASE}/include/X11/SM/SM.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.libSM=	no
.elif !defined(IS_BUILTIN.libSM)
IS_BUILTIN.libSM=	no
.  if empty(H_SM:M__nonexistent__)
IS_BUILTIN.libSM=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libSM

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libSM)
.  if ${PREFER.libSM} == "pkgsrc"
USE_BUILTIN.libSM=	no
.  else
USE_BUILTIN.libSM=	${IS_BUILTIN.libSM}
.    if defined(BUILTIN_PKG.libSM) && \
        !empty(IS_BUILTIN.libSM:M[yY][eE][sS])
USE_BUILTIN.libSM=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libSM}
.        if !empty(USE_BUILTIN.libSM:M[yY][eE][sS])
USE_BUILTIN.libSM!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libSM:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libSM
.endif
MAKEVARS+=	USE_BUILTIN.libSM

.include "../../mk/x11.builtin.mk"
