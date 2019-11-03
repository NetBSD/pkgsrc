# $NetBSD: builtin.mk,v 1.13 2019/11/03 09:14:06 rillig Exp $

BUILTIN_PKG:=	Xfixes

BUILTIN_FIND_FILES_VAR:=	H_XFIXES
BUILTIN_FIND_FILES.H_XFIXES=	${X11BASE}/include/X11/extensions/Xfixes.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.Xfixes)
.  if empty(H_XFIXES:M__nonexistent__)
IS_BUILTIN.Xfixes=	yes
.  else
IS_BUILTIN.Xfixes=	no
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.Xfixes

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.Xfixes)
.  if ${PREFER.Xfixes} == "pkgsrc"
USE_BUILTIN.Xfixes=	no
.  else
USE_BUILTIN.Xfixes=	${IS_BUILTIN.Xfixes}
.    if defined(BUILTIN_PKG.Xfixes) && \
        !empty(IS_BUILTIN.Xfixes:M[yY][eE][sS])
USE_BUILTIN.Xfixes=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.Xfixes}
.        if !empty(USE_BUILTIN.Xfixes:M[yY][eE][sS])
USE_BUILTIN.Xfixes!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.Xfixes:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.Xfixes
.endif
MAKEVARS+=		USE_BUILTIN.Xfixes

.include "../../mk/x11.builtin.mk"
