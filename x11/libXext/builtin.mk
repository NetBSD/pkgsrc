# $NetBSD: builtin.mk,v 1.1.10.1 2008/09/13 04:45:46 cube Exp $

BUILTIN_PKG:=	libXext

BUILTIN_FIND_FILES_VAR:=	LIB_XEXT
BUILTIN_FIND_FILES.LIB_XEXT=	${X11BASE}/lib/pkgconfig/xext.pc

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.libXext=	no
.elif !defined(IS_BUILTIN.libXext)
IS_BUILTIN.libXext=	no
.  if empty(LIB_XEXT:M__nonexistent__)
IS_BUILTIN.libXext=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libXext

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libXext)
.  if ${PREFER.libXext} == "pkgsrc"
USE_BUILTIN.libXext=	no
.  else
USE_BUILTIN.libXext=	${IS_BUILTIN.libXext}
.    if defined(BUILTIN_PKG.libXext) && \
        !empty(IS_BUILTIN.libXext:M[yY][eE][sS])
USE_BUILTIN.libXext=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libXext}
.        if !empty(USE_BUILTIN.libXext:M[yY][eE][sS])
USE_BUILTIN.libXext!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libXext:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libXext
.endif
MAKEVARS+=	USE_BUILTIN.libXext
