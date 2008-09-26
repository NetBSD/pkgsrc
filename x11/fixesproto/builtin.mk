# $NetBSD: builtin.mk,v 1.6.16.1 2008/09/26 21:15:18 cube Exp $

BUILTIN_PKG:=	fixesproto

BUILTIN_FIND_FILES_VAR:=		H_XFIXESPROTO H_XFIXESWIRE
BUILTIN_FIND_FILES.H_XFIXESPROTO=	\
	${X11BASE}/include/X11/extensions/xfixesproto.h
BUILTIN_FIND_FILES.H_XFIXESWIRE=	\
	${X11BASE}/include/X11/extensions/xfixeswire.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.fixesproto=	no
.elif !defined(IS_BUILTIN.fixesproto)
IS_BUILTIN.fixesproto=	no
#
# Here, we skip checking whether the files are under ${LOCALBASE} since
# we'll consider this X11 package to be built-in even if it's a part
# of one of the pkgsrc-installed X11 distributions.
#
.  if empty(H_XFIXESPROTO:M__nonexistent__) && \
      empty(H_XFIXESWIRE:M__nonexistent__)
IS_BUILTIN.fixesproto=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.fixesproto

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.fixesproto)
.  if ${PREFER.fixesproto} == "pkgsrc"
USE_BUILTIN.fixesproto=	no
.  else
USE_BUILTIN.fixesproto=	${IS_BUILTIN.fixesproto}
.    if defined(BUILTIN_PKG.fixesproto) && \
        !empty(IS_BUILTIN.fixesproto:M[yY][eE][sS])
USE_BUILTIN.fixesproto=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.fixesproto}
.        if !empty(USE_BUILTIN.fixesproto:M[yY][eE][sS])
USE_BUILTIN.fixesproto!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.fixesproto:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.fixesproto
.endif
MAKEVARS+=	USE_BUILTIN.fixesproto

.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.fixesproto?=	no
.if !empty(CHECK_BUILTIN.fixesproto:M[nN][oO])

# following so old pkg-config name fixesext.pc will be available
# this is temporary and can be removed once not used
BUILDLINK_TARGETS+=	fixesext-symlink-pc

fixesext-symlink-pc:
	src=${BUILDLINK_PREFIX.fixesproto}/lib/pkgconfig/fixesproto.pc \
	dst=${BUILDLINK_DIR}/lib/pkgconfig/fixesext.pc; \
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig; \
	if ${TEST} -f $${src}; then \
		${LN} -sf $${src} $${dst}; \
	fi

.endif	# CHECK_BUILTIN.fixesproto
