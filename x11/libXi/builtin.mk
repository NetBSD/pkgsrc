# $NetBSD: builtin.mk,v 1.2 2019/11/03 09:14:11 rillig Exp $

BUILTIN_PKG:=		libXi
PKGCONFIG_FILE.libXi=	${X11BASE}/lib/pkgconfig/xi.pc
PKGCONFIG_FILE.libXi+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xi.pc

BUILTIN_FIND_FILES_VAR:=	H_XINPUT
BUILTIN_FIND_FILES.H_XINPUT=	${X11BASE}/include/X11/extensions/XInput.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.libXi=	no
.elif !defined(IS_BUILTIN.libXi)
IS_BUILTIN.libXi=	no
.  if empty(H_XINPUT:M__nonexistent__)
IS_BUILTIN.libXi=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.libXi

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libXi) && !defined(BUILDLINK_API_DEPENDS.libXi)
.  if ${PREFER.libXi} == "pkgsrc"
USE_BUILTIN.libXi=	no
.  else
USE_BUILTIN.libXi=	${IS_BUILTIN.libXi}
.    if defined(BUILTIN_PKG.libXi) && \
        !empty(IS_BUILTIN.libXi:M[yY][eE][sS])
USE_BUILTIN.libXi=	yes
.    endif
.  endif  # PREFER.libXi
.endif
MAKEVARS+=		USE_BUILTIN.libXi

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
