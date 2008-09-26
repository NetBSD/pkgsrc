# $NetBSD: builtin.mk,v 1.12.22.1 2008/09/26 21:15:18 cube Exp $

BUILTIN_PKG:=	Xcomposite

BUILTIN_FIND_FILES_VAR:=		H_XCOMPOSITE
BUILTIN_FIND_FILES.H_XCOMPOSITE=	\
	${X11BASE}/include/X11/extensions/Xcomposite.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.Xcomposite)
IS_BUILTIN.Xcomposite=	no
.  if empty(H_XCOMPOSITE:M__nonexistent__)
BUILTIN_IMAKE_CHECK:=	Xcomposite:BuildCompositeLibrary
.    include "../../mk/buildlink3/imake-check.mk"
IS_BUILTIN.Xcomposite=	${BUILTIN_IMAKE_CHECK.Xcomposite}
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.Xcomposite

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.Xcomposite)
.  if ${PREFER.Xcomposite} == "pkgsrc"
USE_BUILTIN.Xcomposite=	no
.  else
USE_BUILTIN.Xcomposite=	${IS_BUILTIN.Xcomposite}
.    if defined(BUILTIN_PKG.Xcomposite) && \
        !empty(IS_BUILTIN.Xcomposite:M[yY][eE][sS])
USE_BUILTIN.Xcomposite=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.Xcomposite}
.        if !empty(USE_BUILTIN.Xcomposite:M[yY][eE][sS])
USE_BUILTIN.Xcomposite!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.Xcomposite:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.Xcomposite
.endif
MAKEVARS+=	USE_BUILTIN.Xcomposite

.include "../../mk/x11.builtin.mk"
