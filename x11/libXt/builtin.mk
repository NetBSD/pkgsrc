# $NetBSD: builtin.mk,v 1.1.10.1 2008/09/26 21:15:19 cube Exp $

BUILTIN_PKG:=	libXt

BUILTIN_FIND_FILES_VAR:=	H_XTOS
BUILTIN_FIND_FILES.H_XTOS=	${X11BASE}/include/X11/Xtos.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.libXt=	no
.elif !defined(IS_BUILTIN.libXt)
IS_BUILTIN.libXt=	no
.  if empty(H_XTOS:M__nonexistent__)
IS_BUILTIN.libXt=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libXt

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libXt)
.  if ${PREFER.libXt} == "pkgsrc"
USE_BUILTIN.libXt=	no
.  else
USE_BUILTIN.libXt=	${IS_BUILTIN.libXt}
.    if defined(BUILTIN_PKG.libXt) && \
        !empty(IS_BUILTIN.libXt:M[yY][eE][sS])
USE_BUILTIN.libXt=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libXt}
.        if !empty(USE_BUILTIN.libXt:M[yY][eE][sS])
USE_BUILTIN.libXt!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libXt:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libXt
.endif
MAKEVARS+=	USE_BUILTIN.libXt

.include "../../mk/x11.builtin.mk"
