# $NetBSD: builtin.mk,v 1.1.10.1 2008/09/26 21:15:18 cube Exp $

BUILTIN_PKG:=	kbproto

BUILTIN_FIND_FILES_VAR:=	H_XKB
BUILTIN_FIND_FILES.H_XKB=	${X11BASE}/include/X11/extensions/XKB.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.kbproto=	no
.elif !defined(IS_BUILTIN.kbproto)
IS_BUILTIN.kbproto=	no
.  if empty(H_XKB:M__nonexistent__)
IS_BUILTIN.kbproto=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.kbproto

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.kbproto)
.  if ${PREFER.kbproto} == "pkgsrc"
USE_BUILTIN.kbproto=	no
.  else
USE_BUILTIN.kbproto=	${IS_BUILTIN.kbproto}
.    if defined(BUILTIN_PKG.kbproto) && \
        !empty(IS_BUILTIN.kbproto:M[yY][eE][sS])
USE_BUILTIN.kbproto=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.kbproto}
.        if !empty(USE_BUILTIN.kbproto:M[yY][eE][sS])
USE_BUILTIN.kbproto!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.kbproto:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.kbproto
.endif
MAKEVARS+=	USE_BUILTIN.kbproto

.include "../../mk/x11.builtin.mk"
