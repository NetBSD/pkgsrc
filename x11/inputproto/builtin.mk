# $NetBSD: builtin.mk,v 1.1 2008/01/05 15:27:08 tron Exp $

BUILTIN_PKG:=	inputproto

BUILTIN_FIND_FILES_VAR:=	H_XI
BUILTIN_FIND_FILES.H_XI=	${X11BASE}/include/X11/extensions/XI.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.inputproto=	no
.elif !defined(IS_BUILTIN.inputproto)
IS_BUILTIN.inputproto=	no
.  if empty(H_XI:M__nonexistent__)
IS_BUILTIN.inputproto=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.inputproto

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.inputproto)
.  if ${PREFER.inputproto} == "pkgsrc"
USE_BUILTIN.inputproto=	no
.  else
USE_BUILTIN.inputproto=	${IS_BUILTIN.inputproto}
.    if defined(BUILTIN_PKG.inputproto) && \
        !empty(IS_BUILTIN.inputproto:M[yY][eE][sS])
USE_BUILTIN.inputproto=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.inputproto}
.        if !empty(USE_BUILTIN.inputproto:M[yY][eE][sS])
USE_BUILTIN.inputproto!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.inputproto:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.inputproto
.endif
MAKEVARS+=	USE_BUILTIN.inputproto
