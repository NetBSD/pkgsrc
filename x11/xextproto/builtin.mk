# $NetBSD: builtin.mk,v 1.10 2014/07/18 14:30:15 jperkin Exp $

BUILTIN_PKG:=	xextproto

BUILTIN_FIND_FILES_VAR:=		H_XEXTPROTO PC_XEXTPROTO
BUILTIN_FIND_FILES.H_XEXTPROTO=	\
	${X11BASE}/include/X11/extensions/extutil.h
BUILTIN_FIND_FILES.PC_XEXTPROTO=	${X11BASE}/lib/pkgconfig/xextproto.pc
BUILTIN_FIND_FILES.PC_XEXTPROTO+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xextproto.pc
BUILTIN_FIND_FILES.PC_XEXTPROTO+=	${X11BASE}/share/pkgconfig/xextproto.pc

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.xextproto=	no
.elif !defined(IS_BUILTIN.xextproto)
IS_BUILTIN.xextproto=	no
#
# Here, we skip checking whether the files are under ${LOCALBASE} since
# we'll consider this X11 package to be built-in even if it's a part
# of one of the pkgsrc-installed X11 distributions.
#
.  if empty(H_XEXTPROTO:M__nonexistent__)
IS_BUILTIN.xextproto=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.xextproto

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.xextproto) && \
    !empty(IS_BUILTIN.xextproto:M[yY][eE][sS])
.  if empty(PC_XEXTPROTO:M__nonexistent__)
BUILTIN_VERSION.xextproto!=	${SED} -n -e 's/Version: //p' ${PC_XEXTPROTO}
.  else
BUILTIN_VERSION.xextproto=	1.0.1
.  endif
BUILTIN_PKG.xextproto=	xextproto-${BUILTIN_VERSION.xextproto}
.endif
MAKEVARS+=	BUILTIN_PKG.xextproto

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.xextproto)
.  if ${PREFER.xextproto} == "pkgsrc"
USE_BUILTIN.xextproto=	no
.  else
USE_BUILTIN.xextproto=	${IS_BUILTIN.xextproto}
.    if defined(BUILTIN_PKG.xextproto) && \
        !empty(IS_BUILTIN.xextproto:M[yY][eE][sS])
USE_BUILTIN.xextproto=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.xextproto}
.        if !empty(USE_BUILTIN.xextproto:M[yY][eE][sS])
USE_BUILTIN.xextproto!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.xextproto:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.xextproto
.endif
MAKEVARS+=	USE_BUILTIN.xextproto

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###

.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.xextproto?=	no
.if !empty(CHECK_BUILTIN.xextproto:M[nN][oO])

# If we are using the builtin version, check whether it has a xextproto.pc
# file or not.  If the latter, generate a fake one.
.  if !empty(USE_BUILTIN.xextproto:M[Yy][Ee][Ss]) && \
      !empty(PC_XEXTPROTO:M__nonexistent__)
BUILDLINK_TARGETS+=	xextproto-fake-pc

xextproto-fake-pc:
	${RUN} \
	for dir in lib lib${LIBABISUFFIX} share; do \
		${TEST} -f ${BUILDLINK_PREFIX.xextproto}/$${dir}/pkgconfig/xextproto.pc && exit; \
	done; \
	src=${BUILDLINK_PREFIX.xextproto}/lib/pkgconfig/xextproto.pc; \
	dst=${BUILDLINK_DIR}/lib/pkgconfig/xextproto.pc; \
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig; \
	if ${TEST} -f $${src}; then \
		${LN} -sf $${src} $${dst}; \
	else \
		{ ${ECHO} "Name: XExtensions"; \
	   	${ECHO} "Description: Sundry X extension headers"; \
	   	${ECHO} "Version: ${BUILTIN_VERSION.xextproto}"; \
	   	${ECHO} "Cflags: -I${BUILDLINK_PREFIX.xextproto}/include"; \
		} >$${dst}; \
	fi
.  endif

.endif	# CHECK_BUILTIN.xextproto
