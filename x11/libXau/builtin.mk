# $NetBSD: builtin.mk,v 1.1.10.1 2008/09/26 21:15:18 cube Exp $

BUILTIN_PKG:=	libXau

BUILTIN_FIND_FILES_VAR:=	H_XAUTH
BUILTIN_FIND_FILES.H_XAUTH=	${X11BASE}/include/X11/Xauth.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.libXau=	no
.elif !defined(IS_BUILTIN.libXau)
IS_BUILTIN.libXau=	no
.  if empty(H_XAUTH:M__nonexistent__)
IS_BUILTIN.libXau=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libXau

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libXau)
.  if ${PREFER.libXau} == "pkgsrc"
USE_BUILTIN.libXau=	no
.  else
USE_BUILTIN.libXau=	${IS_BUILTIN.libXau}
.    if defined(BUILTIN_PKG.libXau) && \
        !empty(IS_BUILTIN.libXau:M[yY][eE][sS])
USE_BUILTIN.libXau=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libXau}
.        if !empty(USE_BUILTIN.libXau:M[yY][eE][sS])
USE_BUILTIN.libXau!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libXau:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libXau
.endif
MAKEVARS+=	USE_BUILTIN.libXau

.include "../../mk/x11.builtin.mk"
