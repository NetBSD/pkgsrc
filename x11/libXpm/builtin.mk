# $NetBSD: builtin.mk,v 1.3 2022/11/19 21:34:31 wiz Exp $

BUILTIN_PKG:=	libXpm

BUILTIN_FIND_FILES_VAR:=	H_XPM
BUILTIN_FIND_FILES.H_XPM=	${X11BASE}/include/X11/xpm.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.libXpm=	no
.elif !defined(IS_BUILTIN.libXpm)
IS_BUILTIN.libXpm=	no
.  if empty(H_XPM:M__nonexistent__)
IS_BUILTIN.libXpm=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.libXpm

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libXpm)
.  if ${PREFER.libXpm} == "pkgsrc"
USE_BUILTIN.libXpm=	no
.  else
USE_BUILTIN.libXpm=	${IS_BUILTIN.libXpm}
.    if defined(BUILTIN_PKG.libXpm) && \
        ${IS_BUILTIN.libXpm:tl} == yes
USE_BUILTIN.libX11=	yes
.    endif
.  endif  # PREFER.libXpm
.endif
MAKEVARS+=		USE_BUILTIN.libXpm

.include "../../mk/x11.builtin.mk"
