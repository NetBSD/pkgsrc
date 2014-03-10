# $NetBSD: builtin.mk,v 1.5 2014/03/10 11:05:52 jperkin Exp $

BUILTIN_PKG:=	libX11
PKGCONFIG_FILE.libX11=		${X11BASE}/lib/pkgconfig/x11.pc
PKGCONFIG_FILE.libX11+=		${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/x11.pc

BUILTIN_FIND_FILES_VAR:=	H_XLIB
BUILTIN_FIND_FILES.H_XLIB=	${X11BASE}/include/X11/Xlib.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.libX11=	no
.elif !defined(IS_BUILTIN.libX11)
IS_BUILTIN.libX11=	no
.  if empty(H_XLIB:M__nonexistent__)
IS_BUILTIN.libX11=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libX11

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libX11)
.  if ${PREFER.libX11} == "pkgsrc"
USE_BUILTIN.libX11=	no
.  else
USE_BUILTIN.libX11=	${IS_BUILTIN.libX11}
.    if defined(BUILTIN_PKG.libX11) && \
        !empty(IS_BUILTIN.libX11:M[yY][eE][sS])
USE_BUILTIN.libX11=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libX11}
.        if !empty(USE_BUILTIN.libX11:M[yY][eE][sS])
USE_BUILTIN.libX11!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libX11:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libX11
.endif
MAKEVARS+=	USE_BUILTIN.libX11

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
