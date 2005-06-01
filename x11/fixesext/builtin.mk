# $NetBSD: builtin.mk,v 1.4 2005/06/01 18:03:28 jlam Exp $

BUILTIN_PKG:=	fixesext

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
.if !defined(IS_BUILTIN.fixesext)
IS_BUILTIN.fixesext=	no
#
# Here, we skip checking whether the files are under ${LOCALBASE} since
# we'll consider this X11 package to be built-in even if it's a part
# of one of the pkgsrc-installed X11 distributions.
#  
.  if exists(${H_XFIXESPROTO}) && exists(${H_XFIXESWIRE})
IS_BUILTIN.fixesext=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.fixesext

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.fixesext)
.  if ${PREFER.fixesext} == "pkgsrc"
USE_BUILTIN.fixesext=	no
.  else
USE_BUILTIN.fixesext=	${IS_BUILTIN.fixesext}
.    if defined(BUILTIN_PKG.fixesext) && \
        !empty(IS_BUILTIN.fixesext:M[yY][eE][sS])
USE_BUILTIN.fixesext=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.fixesext}
.        if !empty(USE_BUILTIN.fixesext:M[yY][eE][sS])
USE_BUILTIN.fixesext!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.fixesext:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.fixesext
.endif
MAKEVARS+=	USE_BUILTIN.fixesext
