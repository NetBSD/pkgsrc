# $NetBSD: builtin.mk,v 1.5 2005/06/01 18:03:27 jlam Exp $

BUILTIN_PKG:=	compositeext

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
.if !defined(IS_BUILTIN.compositeext)
IS_BUILTIN.compositeext=	no
#
# Here, we skip checking whether the files are under ${LOCALBASE} since
# we'll consider this X11 package to be built-in even if it's a part
# of one of the pkgsrc-installed X11 distributions.
#
.  if exists(${H_COMPOSITE}) && exists(${H_COMPOSITEPROTO})
IS_BUILTIN.compositeext=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.compositeext

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.compositeext)
.  if ${PREFER.compositeext} == "pkgsrc"
USE_BUILTIN.compositeext=	no
.  else
USE_BUILTIN.compositeext=	${IS_BUILTIN.compositeext}
.    if defined(BUILTIN_PKG.compositeext) && \
        !empty(IS_BUILTIN.compositeext:M[yY][eE][sS])
USE_BUILTIN.compositeext=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.compositeext}
.        if !empty(USE_BUILTIN.compositeext:M[yY][eE][sS])
USE_BUILTIN.compositeext!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.compositeext:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.compositeext
.endif
MAKEVARS+=	USE_BUILTIN.compositeext
