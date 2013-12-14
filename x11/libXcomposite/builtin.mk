# $NetBSD: builtin.mk,v 1.1 2013/12/14 09:54:52 tron Exp $

BUILTIN_PKG:=	libXcomposite

BUILTIN_FIND_FILES_VAR:=		H_XCOMPOSITE
BUILTIN_FIND_FILES.H_XCOMPOSITE=	\
	${X11BASE}/include/X11/extensions/Xcomposite.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.libXcomposite)
.  if empty(H_XCOMPOSITE:M__nonexistent__)
IS_BUILTIN.libXcomposite=	yes
.  else
IS_BUILTIN.libXcomposite=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libXcomposite

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libXcomposite)
.  if ${PREFER.libXcomposite} == "pkgsrc"
USE_BUILTIN.libXcomposite=	no
.  else
USE_BUILTIN.libXcomposite=	${IS_BUILTIN.libXcomposite}
.    if defined(BUILTIN_PKG.libXcomposite) && \
        !empty(IS_BUILTIN.libXcomposite:M[yY][eE][sS])
USE_BUILTIN.libXcomposite=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libXcomposite}
.        if !empty(USE_BUILTIN.libXcomposite:M[yY][eE][sS])
USE_BUILTIN.libXcomposite!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libXcomposite:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libXcomposite
.endif
MAKEVARS+=	USE_BUILTIN.libXcomposite

.include "../../mk/x11.builtin.mk"
