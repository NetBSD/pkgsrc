# $NetBSD: builtin.mk,v 1.1 2009/08/20 17:59:10 joerg Exp $

BUILTIN_PKG:=	libXp

BUILTIN_FIND_FILES_VAR:=	H_PRINTPROTO
BUILTIN_FIND_FILES.H_PRINTPROTO= ${X11BASE}/include/X11/extensions/Print.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.libXp=	no
.elif !defined(IS_BUILTIN.libXp)
IS_BUILTIN.libXp=	no
.  if empty(H_PRINTPROTO:M__nonexistent__)
IS_BUILTIN.libXp=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libXp

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libXp)
.  if ${PREFER.libXp} == "pkgsrc"
USE_BUILTIN.libXp=	no
.  else
USE_BUILTIN.libXp=	${IS_BUILTIN.libXp}
.    if defined(BUILTIN_PKG.libXp) && \
        !empty(IS_BUILTIN.libXp:M[yY][eE][sS])
USE_BUILTIN.libX11=	yes
.    endif
.  endif  # PREFER.libXp
.endif
MAKEVARS+=	USE_BUILTIN.libXp

.include "../../mk/x11.builtin.mk"
