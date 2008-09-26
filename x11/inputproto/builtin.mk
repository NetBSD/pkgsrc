# $NetBSD: builtin.mk,v 1.2.8.1 2008/09/26 21:15:18 cube Exp $

BUILTIN_PKG:=	inputproto

BUILTIN_FIND_FILES_VAR:=		PC_INPUTPROTO
BUILTIN_FIND_FILES.PC_INPUTPROTO=	${X11BASE}/lib/pkgconfig/inputproto.pc

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.inputproto=	no
.elif !defined(IS_BUILTIN.inputproto)
IS_BUILTIN.inputproto=	no
.  if empty(PC_INPUTPROTO:M__nonexistent__)
IS_BUILTIN.inputproto=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.inputproto

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.inputproto) && \
    !empty(IS_BUILTIN.inputproto:M[yY][eE][sS]) && \
    empty(PC_INPUTPROTO:M__nonexistent__)
BUILTIN_VERSION.inputproto!= ${SED} -n -e 's/Version: //p' ${PC_INPUTPROTO}
BUILTIN_PKG.inputproto= inputproto-${BUILTIN_VERSION.inputproto}
.endif
MAKEVARS+=      BUILTIN_PKG.inputproto

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

.include "../../mk/x11.builtin.mk"
