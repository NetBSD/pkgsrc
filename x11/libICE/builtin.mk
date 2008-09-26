# $NetBSD: builtin.mk,v 1.1.10.1 2008/09/26 21:15:18 cube Exp $

BUILTIN_PKG:=	libICE

BUILTIN_FIND_FILES_VAR:=	H_ICE
BUILTIN_FIND_FILES.H_ICE=	${X11BASE}/include/X11/ICE/ICE.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.libICE=	no
.elif !defined(IS_BUILTIN.libICE)
IS_BUILTIN.libICE=	no
.  if empty(H_ICE:M__nonexistent__)
IS_BUILTIN.libICE=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libICE

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libICE)
.  if ${PREFER.libICE} == "pkgsrc"
USE_BUILTIN.libICE=	no
.  else
USE_BUILTIN.libICE=	${IS_BUILTIN.libICE}
.    if defined(BUILTIN_PKG.libICE) && \
        !empty(IS_BUILTIN.libICE:M[yY][eE][sS])
USE_BUILTIN.libICE=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libICE}
.        if !empty(USE_BUILTIN.libICE:M[yY][eE][sS])
USE_BUILTIN.libICE!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libICE:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libICE
.endif
MAKEVARS+=	USE_BUILTIN.libICE

.include "../../mk/x11.builtin.mk"
