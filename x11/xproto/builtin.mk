# $NetBSD: builtin.mk,v 1.3.18.1 2008/09/26 21:15:20 cube Exp $

BUILTIN_PKG:=	xproto

BUILTIN_FIND_FILES_VAR:=	H_XFUNCPROTO
BUILTIN_FIND_FILES.H_XFUNCPROTO=	${X11BASE}/include/X11/Xfuncproto.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.xproto=	no
.elif !defined(IS_BUILTIN.xproto)
IS_BUILTIN.xproto=	no
.  if empty(H_XFUNCPROTO:M__nonexistent__)
IS_BUILTIN.xproto=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.xproto

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.xproto)
.  if ${PREFER.xproto} == "pkgsrc"
USE_BUILTIN.xproto=	no
.  else
USE_BUILTIN.xproto=	${IS_BUILTIN.xproto}
.    if defined(BUILTIN_PKG.xproto) && \
        !empty(IS_BUILTIN.xproto:M[yY][eE][sS])
USE_BUILTIN.xproto=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.xproto}
.        if !empty(USE_BUILTIN.xproto:M[yY][eE][sS])
USE_BUILTIN.xproto!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.xproto:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.xproto
.endif
MAKEVARS+=	USE_BUILTIN.xproto

.include "../../mk/x11.builtin.mk"
