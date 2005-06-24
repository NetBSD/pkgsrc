# $NetBSD: builtin.mk,v 1.2 2005/06/24 05:21:31 jlam Exp $

BUILTIN_PKG:=	xorg-libs

BUILTIN_FIND_FILES_VAR:=	CF_XORG
BUILTIN_FIND_FILES.CF_XORG=	${X11BASE}/lib/X11/config/xorg.cf

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.xorg-libs)
IS_BUILTIN.xorg-libs=	no
.  if empty(CF_XORG:M${LOCALBASE}/*) && exists(${CF_XORG})
IS_BUILTIN.xorg-libs=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.xorg-libs

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.xorg-libs) && \
    !empty(IS_BUILTIN.xorg-libs:M[yY][eE][sS]) && \
    exists(${CF_XORG})
.  include "${BUILDLINK_PKGSRCDIR.xorg-libs}/version.mk"
BUILTIN_PKG.xorg-libs=	xorg-libs-${BUILTIN_X11_VERSION.xorg}
.endif
MAKEVARS+=	BUILTIN_PKG.xorg-libs

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.xorg-libs)
.  if ${PREFER.xorg-libs} == "pkgsrc"
USE_BUILTIN.xorg-libs=	no
.  else
USE_BUILTIN.xorg-libs=	${IS_BUILTIN.xorg-libs}
.    if defined(BUILTIN_PKG.xorg-libs) && \
        !empty(IS_BUILTIN.xorg-libs:M[yY][eE][sS])
USE_BUILTIN.xorg-libs=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.xorg-libs}
.        if !empty(USE_BUILTIN.xorg-libs:M[yY][eE][sS])
USE_BUILTIN.xorg-libs!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.xorg-libs:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.xorg-libs
.endif
MAKEVARS+=	USE_BUILTIN.xorg-libs

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.xorg-libs?=	no
.if !empty(CHECK_BUILTIN.xorg-libs:M[nN][oO])

.  if !empty(USE_BUILTIN.xorg-libs:M[yY][eE][sS])
BUILDLINK_PREFIX.xorg-libs=	${X11BASE}
BUILDLINK_FILES.xorg-libs+=	lib/pkgconfig/xorg-libs.pc
.  endif

# XXX
# XXX xorg-libs provides some X11 pieces that pkgsrc should currently
# XXX treat as "built-in" so that extra dependencies on the pkgsrc
# XXX versions aren't pulled in.
# XXX
USE_BUILTIN.Xfixes=	yes
USE_BUILTIN.Xcomposite=	yes

.endif	# CHECK_BUILTIN.xorg-libs
