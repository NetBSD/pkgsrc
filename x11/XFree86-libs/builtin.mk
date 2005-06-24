# $NetBSD: builtin.mk,v 1.1.2.1 2005/06/24 09:08:32 salo Exp $

BUILTIN_PKG:=	XFree86-libs

BUILTIN_FIND_FILES_VAR:=	CF_XFREE86
BUILTIN_FIND_FILES.CF_XFREE86=	${X11BASE}/lib/X11/config/xfree86.cf

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.XFree86-libs)
IS_BUILTIN.XFree86-libs=	no
.  if empty(CF_XFREE86:M${LOCALBASE}/*) && exists(${CF_XFREE86})
IS_BUILTIN.XFree86-libs=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.XFree86-libs

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.XFree86-libs) && \
    !empty(IS_BUILTIN.XFree86-libs:M[yY][eE][sS]) && \
    exists(${CF_XFREE86})
.  include "${BUILDLINK_PKGSRCDIR.XFree86-libs}/version.mk"
BUILTIN_PKG.XFree86-libs=	XFree86-libs-${BUILTIN_X11_VERSION.XFree86}
.endif
MAKEVARS+=	BUILTIN_PKG.XFree86-libs

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.XFree86-libs)
.  if ${PREFER.XFree86-libs} == "pkgsrc"
USE_BUILTIN.XFree86-libs=	no
.  else
USE_BUILTIN.XFree86-libs=	${IS_BUILTIN.XFree86-libs}
.    if defined(BUILTIN_PKG.XFree86-libs) && \
        !empty(IS_BUILTIN.XFree86-libs:M[yY][eE][sS])
USE_BUILTIN.XFree86-libs=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.XFree86-libs}
.        if !empty(USE_BUILTIN.XFree86-libs:M[yY][eE][sS])
USE_BUILTIN.XFree86-libs!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.XFree86-libs:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.XFree86-libs
.endif
MAKEVARS+=	USE_BUILTIN.XFree86-libs

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.XFree86-libs?=	no
.if !empty(CHECK_BUILTIN.XFree86-libs:M[nN][oO])

.  if !empty(USE_BUILTIN.XFree86-libs:M[yY][eE][sS])
BUILDLINK_PREFIX.XFree86-libs=	${X11BASE}
BUILDLINK_FILES.XFree86-libs+=	lib/pkgconfig/XFree86-libs.pc
.  endif

.endif	# CHECK_BUILTIN.XFree86-libs
