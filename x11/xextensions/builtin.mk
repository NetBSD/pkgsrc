# $NetBSD: builtin.mk,v 1.6 2005/06/15 15:26:59 jlam Exp $

BUILTIN_PKG:=	xextensions

BUILTIN_FIND_FILES_VAR:=		H_XEXTENSIONS
BUILTIN_FIND_FILES.H_XEXTENSIONS=	\
	${X11BASE}/include/X11/extensions/extutil.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.xextensions)
IS_BUILTIN.xextensions=	no
#
# Here, we skip checking whether the files are under ${LOCALBASE} since
# we'll consider this X11 package to be built-in even if it's a part
# of one of the pkgsrc-installed X11 distributions.
#  
.  if exists(${H_XEXTENSIONS})
IS_BUILTIN.xextensions=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.xextensions

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.xextensions)
.  if ${PREFER.xextensions} == "pkgsrc"
USE_BUILTIN.xextensions=	no
.  else
USE_BUILTIN.xextensions=	${IS_BUILTIN.xextensions}
.    if defined(BUILTIN_PKG.xextensions) && \
        !empty(IS_BUILTIN.xextensions:M[yY][eE][sS])
USE_BUILTIN.xextensions=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.xextensions}
.        if !empty(USE_BUILTIN.xextensions:M[yY][eE][sS])
USE_BUILTIN.xextensions!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.xextensions:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.xextensions
.endif
MAKEVARS+=	USE_BUILTIN.xextensions

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.xextensions?=	no
.if !empty(CHECK_BUILTIN.xextensions:M[nN][oO])

.  if !empty(USE_BUILTIN.xextensions:M[yY][eE][sS])
BUILDLINK_PREFIX.xextensions=	${X11BASE}
.    include "../../mk/x11.buildlink3.mk"
.    include "../../mk/x11.builtin.mk"
.  endif

# Check whether the implementation we selected has a xextensions.pc file
# or not.  If the latter, generate a fake one.
.  if exists(${BUILDLINK_PREFIX.xextensions}/lib/pkgconfig/xextensions.pc)
BUILDLINK_FILES.xextensions+=	lib/pkgconfig/fontconfig.pc
.  else
BUILDLINK_TARGETS+=	xextensions-fake-pc

xextensions-fake-pc:
	@${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig
	@{ ${ECHO} "Name: XExtensions"; \
	   ${ECHO} "Description: Sundry X extension headers"; \
	   ${ECHO} "Version: 1.0.1"; \
	   ${ECHO} "Cflags: -I${BUILDLINK_PREFIX.xextensions}/include"; \
	} >${BUILDLINK_DIR}/lib/pkgconfig/xextensions.pc
.  endif

.endif	# CHECK_BUILTIN.xextensions
