# $NetBSD: builtin.mk,v 1.8.18.1 2008/09/26 19:59:46 cube Exp $

BUILTIN_PKG:=	renderproto

BUILTIN_FIND_FILES_VAR:=	H_RENDER
BUILTIN_FIND_FILES.H_RENDER=	${X11BASE}/include/X11/extensions/render.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.renderproto=	no
.elif !defined(IS_BUILTIN.renderproto)
IS_BUILTIN.renderproto=	no
#
# Here, we skip checking whether the files are under ${LOCALBASE} since
# we'll consider this X11 package to be built-in even if it's a part
# of one of the pkgsrc-installed X11 distributions. This does not apply
# to modular Xorg which is caught above.
#
.  if empty(H_RENDER:M__nonexistent__)
IS_BUILTIN.renderproto=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.renderproto

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.renderproto) && \
    !empty(IS_BUILTIN.renderproto:M[yY][eE][sS]) && \
    empty(H_RENDER:M__nonexistent__)
BUILTIN_VERSION.renderproto!=						\
	${AWK} '/\#define[ 	]*RENDER_MAJOR/ { M = $$3 }		\
		/\#define[ 	]*RENDER_MINOR/ { m = "."$$3 }		\
		END { printf "%s%s\n", M, m }'				\
		${H_RENDER}
BUILTIN_PKG.renderproto=	renderproto-${BUILTIN_VERSION.renderproto}
.endif
MAKEVARS+=	BUILTIN_PKG.renderproto

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.renderproto)
.  if ${PREFER.renderproto} == "pkgsrc"
USE_BUILTIN.renderproto=	no
.  else
USE_BUILTIN.renderproto=	${IS_BUILTIN.renderproto}
.    if defined(BUILTIN_PKG.renderproto) && \
        !empty(IS_BUILTIN.renderproto:M[yY][eE][sS])
USE_BUILTIN.renderproto=	yes
.      for dep in ${BUILDLINK_API_DEPENDS.renderproto}
.        if !empty(USE_BUILTIN.renderproto:M[yY][eE][sS])
USE_BUILTIN.renderproto!=							\
	if ${PKG_ADMIN} pmatch ${dep:Q} ${BUILTIN_PKG.renderproto:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.renderproto
.endif
MAKEVARS+=	USE_BUILTIN.renderproto

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###

.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.renderproto?=	no
.if !empty(CHECK_BUILTIN.renderproto:M[nN][oO])

.  if !empty(USE_BUILTIN.renderproto:M[nN][oO])
BUILDLINK_API_DEPENDS.renderproto+=	renderproto>=0.9
.  endif

.endif	# CHECK_BUILTIN.renderproto

CHECK_BUILTIN.renderproto?=	no
.if !empty(CHECK_BUILTIN.renderproto:M[nN][oO])

# this is temporary and can be removed once not used
BUILDLINK_TARGETS+=	render-symlink-pc

.PHONY: render-symlink-pc
render-symlink-pc:
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	src=${BUILDLINK_PREFIX.renderproto}/lib/pkgconfig/renderproto.pc; \
	dst=${BUILDLINK_DIR}/lib/pkgconfig/render.pc;			\
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig;			\
	if ${TEST} -f "$$src"; then					\
		${RM} -f "$$dst";					\
		${LN} -sf "$$src" "$$dst";				\
	fi

.endif	# CHECK_BUILTIN.renderproto
