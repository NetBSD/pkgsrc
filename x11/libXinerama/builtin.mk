# $NetBSD: builtin.mk,v 1.1.10.1 2008/09/13 04:44:41 cube Exp $

BUILTIN_PKG:=	libXinerama

BUILTIN_FIND_FILES_VAR:=	LIB_XINERAMA
BUILTIN_FIND_FILES.LIB_XINERAMA=${X11BASE}/lib/pkgconfig/xinerama.pc

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.libXinerama=	no
.elif !defined(IS_BUILTIN.libXinerama)
IS_BUILTIN.libXinerama=	no
.  if empty(LIB_XINERAMA:M__nonexistent__)
IS_BUILTIN.libXinerama=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libXinerama

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libXinerama)
.  if ${PREFER.libXinerama} == "pkgsrc"
USE_BUILTIN.libXinerama=	no
.  else
USE_BUILTIN.libXinerama=	${IS_BUILTIN.libXinerama}
.    if defined(BUILTIN_PKG.libXinerama) && \
        !empty(IS_BUILTIN.libXinerama:M[yY][eE][sS])
USE_BUILTIN.libXinerama=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libXinerama}
.        if !empty(USE_BUILTIN.libXinerama:M[yY][eE][sS])
USE_BUILTIN.libXinerama!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libXinerama:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libXinerama
.endif
MAKEVARS+=	USE_BUILTIN.libXinerama
