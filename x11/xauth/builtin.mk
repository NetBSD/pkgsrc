# $NetBSD: builtin.mk,v 1.5 2024/03/03 21:00:07 wiz Exp $

BUILTIN_PKG:=	xauth

BUILTIN_FIND_FILES_VAR:=	XAUTH
BUILTIN_FIND_FILES.XAUTH=	${X11BASE}/bin/xauth

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.xauth)
.  if empty(XAUTH:M__nonexistent__)
IS_BUILTIN.xauth=	yes
.  else
IS_BUILTIN.xauth=	no
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.xauth

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.xauth) && \
    ${IS_BUILTIN.xauth:tl} == yes && \
    empty(XAUTH:M__nonexistent__)

# we're more worried about existence, rather than actual version
BUILTIN_VERSION.xauth=	11.7

BUILTIN_PKG.xauth=	xauth-${BUILTIN_VERSION.xauth}
.endif
MAKEVARS+=		BUILTIN_PKG.xauth

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.xauth)
.  if ${PREFER.xauth} == "pkgsrc"
USE_BUILTIN.xauth=	no
.  else
USE_BUILTIN.xauth=	${IS_BUILTIN.xauth}
.    if defined(BUILTIN_PKG.xauth) && \
        ${IS_BUILTIN.xauth:tl} == yes
USE_BUILTIN.xauth=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.xauth}
.        if ${USE_BUILTIN.xauth:tl} == yes
USE_BUILTIN.xauth!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.xauth:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.xauth
.endif

# Now set up the appropriate prefix for xauth
.if ${USE_BUILTIN.xauth:tl} == yes
XAUTHBASE=		${X11BASE}
.else
XAUTHBASE=		${PREFIX}
.endif
