# $NetBSD: builtin.mk,v 1.3 2005/06/01 18:03:30 jlam Exp $

BUILTIN_PKG:=	render

BUILTIN_FIND_FILES_VAR:=	H_RENDER
BUILTIN_FIND_FILES.H_RENDER=	${X11BASE}/include/X11/extensions/render.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.render)
IS_BUILTIN.render=	no
#
# Here, we skip checking whether the files are under ${LOCALBASE} since
# we'll consider this X11 package to be built-in even if it's a part
# of one of the pkgsrc-installed X11 distributions.
#  
.  if exists(${H_RENDER})
IS_BUILTIN.render=	yes
.  endif
.endif
MAKEVARS+=      IS_BUILTIN.render

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.render) && \
    !empty(IS_BUILTIN.render:M[yY][eE][sS]) && \
    exists(${H_RENDER})
BUILTIN_VERSION.render!=						\
	${AWK} '/\#define[ 	]*RENDER_MAJOR/ { M = $$3 }		\
		/\#define[ 	]*RENDER_MINOR/ { m = "."$$3 }		\
		END { printf "%s%s\n", M, m }'				\
		${H_RENDER}
BUILTIN_PKG.render=	render-${BUILTIN_VERSION.render}
.endif
MAKEVARS+=	BUILTIN_PKG.render

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.render)
.  if ${PREFER.render} == "pkgsrc"
USE_BUILTIN.render=	no
.  else
USE_BUILTIN.render=	${IS_BUILTIN.render}
.    if defined(BUILTIN_PKG.render) && \
        !empty(IS_BUILTIN.render:M[yY][eE][sS])
USE_BUILTIN.render=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.render}
.        if !empty(USE_BUILTIN.render:M[yY][eE][sS])
USE_BUILTIN.render!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.render:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.render
.endif
MAKEVARS+=	USE_BUILTIN.render

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.render?=	no
.if !empty(CHECK_BUILTIN.render:M[nN][oO])

.  if !empty(USE_BUILTIN.render:M[nN][oO])
BUILDLINK_DEPENDS.render+=	render>=0.8
.  endif

.  if !empty(USE_BUILTIN.render:M[yY][eE][sS])
BUILDLINK_PREFIX.render=	${X11BASE}
.    include "../../mk/x11.buildlink3.mk"
.    include "../../mk/x11.builtin.mk"
.  endif

.endif	# CHECK_BUILTIN.render
