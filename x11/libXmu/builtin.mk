# $NetBSD: builtin.mk,v 1.4 2024/04/03 21:26:00 wiz Exp $

BUILTIN_PKG:=	libXmu

BUILTIN_FIND_FILES_VAR:=	H_XMU
BUILTIN_FIND_FILES.H_XMU=	${X11BASE}/include/X11/Xmu/Xmu.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.libXmu=	no
.elif !defined(IS_BUILTIN.libXmu)
IS_BUILTIN.libXmu=	no
.  if empty(H_XMU:M__nonexistent__)
IS_BUILTIN.libXmu=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.libXmu

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libXmu)
.  if ${PREFER.libXmu} == "pkgsrc"
USE_BUILTIN.libXmu=	no
.  else
USE_BUILTIN.libXmu=	${IS_BUILTIN.libXmu}
.    if defined(BUILTIN_PKG.libXmu) && \
        ${IS_BUILTIN.libXmu:tl} == yes
USE_BUILTIN.libXmu=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libXmu}
.        if ${USE_BUILTIN.libXmu:tl} == yes
USE_BUILTIN.libXmu!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libXmu:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libXmu
.endif
MAKEVARS+=		USE_BUILTIN.libXmu

.include "../../mk/x11.builtin.mk"
