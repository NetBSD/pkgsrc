# $NetBSD: builtin.mk,v 1.3 2014/02/05 09:42:33 obache Exp $

BUILTIN_PKG:=	libXrandr

BUILTIN_FIND_FILES_VAR:=	H_XRANDR
BUILTIN_FIND_FILES.H_XRANDR=	${X11BASE}/include/X11/extensions/Xrandr.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.libXrandr=	no
.elif !defined(IS_BUILTIN.libXrandr)
IS_BUILTIN.libXrandr=	no
.  if empty(H_XRANDR:M__nonexistent__)
IS_BUILTIN.libXrandr=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libXrandr

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libXrandr)
.  if ${PREFER.libXrandr} == "pkgsrc"
USE_BUILTIN.libXrandr=	no
.  else
USE_BUILTIN.libXrandr=	${IS_BUILTIN.libXrandr}
.    if defined(BUILTIN_PKG.libXrandr) && \
        !empty(IS_BUILTIN.libXrandr:M[yY][eE][sS])
USE_BUILTIN.libXrandr=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libXrandr}
.        if !empty(USE_BUILTIN.libXrandr:M[yY][eE][sS])
USE_BUILTIN.libXrandr!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libXrandr:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libXrandr
.endif
MAKEVARS+=	USE_BUILTIN.libXrandr

.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.libXrandr?=	no
.if !empty(CHECK_BUILTIN.libXrandr:M[nN][oO])

.  if !empty(USE_BUILTIN.libXrandr:M[nN][oO])
BUILDLINK_API_DEPENDS.randrproto+=	randrproto>=1.4
.  endif

.endif  # CHECK_BUILTIN.libXrandr
