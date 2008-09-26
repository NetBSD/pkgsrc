# $NetBSD: builtin.mk,v 1.4.18.1 2008/09/26 21:15:18 cube Exp $

BUILTIN_PKG:=	compositeproto

BUILTIN_FIND_FILES_VAR:=		H_COMPOSITE H_COMPOSITEPROTO
BUILTIN_FIND_FILES.H_COMPOSITE=		\
	${X11BASE}/include/X11/extensions/composite.h
BUILTIN_FIND_FILES.H_COMPOSITEPROTO=	\
	${X11BASE}/include/X11/extensions/compositeproto.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.compositeproto=	no
.elif !defined(IS_BUILTIN.compositeproto)
IS_BUILTIN.compositeproto=	no
#
# Here, we skip checking whether the files are under ${LOCALBASE} since
# we'll consider this X11 package to be built-in even if it's a part
# of one of the pkgsrc-installed X11 distributions.
#
.  if empty(H_COMPOSITE:M__nonexistent__) && \
      empty(H_COMPOSITEPROTO:M__nonexistent__)
IS_BUILTIN.compositeproto=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.compositeproto

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.compositeproto)
.  if ${PREFER.compositeproto} == "pkgsrc"
USE_BUILTIN.compositeproto=	no
.  else
USE_BUILTIN.compositeproto=	${IS_BUILTIN.compositeproto}
.    if defined(BUILTIN_PKG.compositeproto) && \
        !empty(IS_BUILTIN.compositeproto:M[yY][eE][sS])
USE_BUILTIN.compositeproto=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.compositeproto}
.        if !empty(USE_BUILTIN.compositeproto:M[yY][eE][sS])
USE_BUILTIN.compositeproto!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.compositeproto:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.compositeproto
.endif
MAKEVARS+=	USE_BUILTIN.compositeproto

.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.compositeproto?=		no
.if !empty(CHECK_BUILTIN.compositeproto:M[nN][oO])

# following so old pkg-config name compositeext.pc will be available
BUILDLINK_TARGETS+=	compositeext-symlink-pc

compositeext-symlink-pc:
	src=${BUILDLINK_PREFIX.compositeproto}/lib/pkgconfig/compositeproto.pc \
	dst=${BUILDLINK_DIR}/lib/pkgconfig/compositeext.pc; \
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig; \
	if ${TEST} -f $${src}; then \
		${LN} -sf $${src} $${dst}; \
	fi

.endif	# CHECK_BUILTIN.compositeproto
