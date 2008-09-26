# $NetBSD: builtin.mk,v 1.2.8.1 2008/09/26 21:15:20 cube Exp $

BUILTIN_PKG:=	xineramaproto

BUILTIN_FIND_FILES_VAR:=		PC_XINERAMAPROTO
BUILTIN_FIND_FILES.PC_XINERAMAPROTO=	${X11BASE}/lib/pkgconfig/xineramaproto.pc

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.xineramaproto=	no
.elif !defined(IS_BUILTIN.xineramaproto)
IS_BUILTIN.xineramaproto=	no
.  if empty(PC_XINERAMAPROTO:M__nonexistent__)
IS_BUILTIN.xineramaproto=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.xineramaproto

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.xineramaproto) && \
    !empty(IS_BUILTIN.xineramaproto:M[yY][eE][sS]) && \
    empty(PC_XINERAMAPROTO:M__nonexistent__)
BUILTIN_VERSION.xineramaproto!= ${SED} -n -e 's/Version: //p' ${PC_XINERAMAPROTO}
BUILTIN_PKG.xineramaproto= xineramaproto-${BUILTIN_VERSION.xineramaproto}
.endif
MAKEVARS+=      BUILTIN_PKG.xineramaproto

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.xineramaproto)
.  if ${PREFER.xineramaproto} == "pkgsrc"
USE_BUILTIN.xineramaproto=	no
.  else
USE_BUILTIN.xineramaproto=	${IS_BUILTIN.xineramaproto}
.    if defined(BUILTIN_PKG.xineramaproto) && \
        !empty(IS_BUILTIN.xineramaproto:M[yY][eE][sS])
USE_BUILTIN.xineramaproto=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.xineramaproto}
.        if !empty(USE_BUILTIN.xineramaproto:M[yY][eE][sS])
USE_BUILTIN.xineramaproto!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.xineramaproto:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.xineramaproto
.endif
MAKEVARS+=	USE_BUILTIN.xineramaproto

.include "../../mk/x11.builtin.mk"
