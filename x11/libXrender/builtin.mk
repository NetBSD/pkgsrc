# $NetBSD: builtin.mk,v 1.1.10.1 2008/09/26 21:15:19 cube Exp $

BUILTIN_PKG:=	libXrender

BUILTIN_FIND_FILES_VAR:=	H_XRENDER
BUILTIN_FIND_FILES.H_XRENDER=	${X11BASE}/include/X11/extensions/Xrender.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.libXrender=	no
.elif !defined(IS_BUILTIN.libXrender)
IS_BUILTIN.libXrender=	no
.  if empty(H_XRENDER:M__nonexistent__)
IS_BUILTIN.libXrender=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libXrender

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libXrender)
.  if ${PREFER.libXrender} == "pkgsrc"
USE_BUILTIN.libXrender=	no
.  else
USE_BUILTIN.libXrender=	${IS_BUILTIN.libXrender}
.    if defined(BUILTIN_PKG.libXrender) && \
        !empty(IS_BUILTIN.libXrender:M[yY][eE][sS])
USE_BUILTIN.libXrender=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libXrender}
.        if !empty(USE_BUILTIN.libXrender:M[yY][eE][sS])
USE_BUILTIN.libXrender!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libXrender:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libXrender
.endif
MAKEVARS+=	USE_BUILTIN.libXrender

.include "../../mk/x11.builtin.mk"
