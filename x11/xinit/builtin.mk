# $NetBSD: builtin.mk,v 1.1 2021/12/03 13:03:01 nia Exp $

BUILTIN_PKG:=	xinit

BUILTIN_FIND_FILES_VAR:=	XINIT
BUILTIN_FIND_FILES.XINIT=	${X11BASE}/bin/xinit

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.xinit)
.  if empty(XINIT:M__nonexistent__)
IS_BUILTIN.xinit=	yes
.  else
IS_BUILTIN.xinit=	no
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.xinit

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.xinit) && \
    !empty(IS_BUILTIN.xinit:M[yY][eE][sS]) && \
    empty(XINIT:M__nonexistent__)

# we're more worried about existence, rather than actual version
BUILTIN_VERSION.xinit=	11.7

BUILTIN_PKG.xinit=	xinit-${BUILTIN_VERSION.xinit}
.endif
MAKEVARS+=		BUILTIN_PKG.xinit

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.xinit)
.  if ${PREFER.xinit} == "pkgsrc"
USE_BUILTIN.xinit=	no
.  else
USE_BUILTIN.xinit=	${IS_BUILTIN.xinit}
.    if defined(BUILTIN_PKG.xinit) && \
        !empty(IS_BUILTIN.xinit:M[yY][eE][sS])
USE_BUILTIN.xinit=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.xinit}
.        if !empty(USE_BUILTIN.xinit:M[yY][eE][sS])
USE_BUILTIN.xinit!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.xinit:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.xinit
.endif

# Now set up the appropriate prefix for xinit
.if !empty(USE_BUILTIN.xinit:M[yY][eE][sS])
XINITBASE=		${X11BASE}
.else
XINITBASE=		${PREFIX}
.endif
