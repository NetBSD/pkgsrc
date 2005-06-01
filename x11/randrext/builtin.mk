# $NetBSD: builtin.mk,v 1.3 2005/06/01 18:03:30 jlam Exp $

BUILTIN_PKG:=	randrext

BUILTIN_FIND_FILES_VAR:=	H_RANDR
BUILTIN_FIND_FILES.H_RANDR=	${X11BASE}/include/X11/extensions/randr.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.randrext)
IS_BUILTIN.randrext=	no
#
# Here, we skip checking whether the files are under ${LOCALBASE} since
# we'll consider this X11 package to be built-in even if it's a part
# of one of the pkgsrc-installed X11 distributions.
#  
.  if exists(${H_RANDR})
IS_BUILTIN.randrext=	yes
.  endif
.endif
MAKEVARS+=      IS_BUILTIN.randrext

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.randrext) && \
    !empty(IS_BUILTIN.randrext:M[yY][eE][sS]) && \
    exists(${H_RANDR})
BUILTIN_VERSION.randrext!=						\
	${AWK} '/\#define[ 	]*RANDR_MAJOR/ { M = $$3 }		\
		/\#define[ 	]*RANDR_MINOR/ { m = "."$$3 }		\
		END { printf "%s%s\n", M, m }'				\
		${H_RANDR}
BUILTIN_PKG.randrext=	randrext-${BUILTIN_VERSION.randrext}
.endif
MAKEVARS+=	BUILTIN_PKG.randrext

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.randrext)
.  if ${PREFER.randrext} == "pkgsrc"
USE_BUILTIN.randrext=	no
.  else
USE_BUILTIN.randrext=	${IS_BUILTIN.randrext}
.    if defined(BUILTIN_PKG.randrext) && \
        !empty(IS_BUILTIN.randrext:M[yY][eE][sS])
USE_BUILTIN.randrext=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.randrext}
.        if !empty(USE_BUILTIN.randrext:M[yY][eE][sS])
USE_BUILTIN.randrext!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.randrext:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.randrext
.endif
MAKEVARS+=	USE_BUILTIN.randrext

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.randrext?=	no
.if !empty(CHECK_BUILTIN.randrext:M[nN][oO])

.  if !empty(USE_BUILTIN.randrext:M[nN][oO])
BUILDLINK_DEPENDS.randrext+=	randrext>=1.0
.  endif

.  if !empty(USE_BUILTIN.randrext:M[yY][eE][sS])
BUILDLINK_PREFIX.randrext=	${X11BASE}
.    include "../../mk/x11.buildlink3.mk"
.    include "../../mk/x11.builtin.mk"
.  endif

.endif	# CHECK_BUILTIN.randrext
