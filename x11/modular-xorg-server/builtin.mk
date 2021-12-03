# $NetBSD: builtin.mk,v 1.2 2021/12/03 13:44:01 ryoon Exp $

BUILTIN_PKG:=	modular-xorg-server

BUILTIN_FIND_FILES_VAR:=	XORG_SERVER
BUILTIN_FIND_FILES.XORG_SERVER=	${X11BASE}/bin/Xorg

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.modular-xorg-server)
.  if empty(XORG_SERVER:M__nonexistent__)
IS_BUILTIN.modular-xorg-server=	yes
.  else
IS_BUILTIN.modular-xorg-server=	no
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.modular-xorg-server

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.modular-xorg-server) && \
    !empty(IS_BUILTIN.modular-xorg-server:M[yY][eE][sS]) && \
    empty(XORG_SERVER:M__nonexistent__)

# we're more worried about existence, rather than actual version
BUILTIN_VERSION.modular-xorg-server=	1.20.13
BUILTIN_PKG.modular-xorg-server=	modular-xorg-server-${BUILTIN_VERSION.modular-xorg-server}
.endif
MAKEVARS+=		BUILTIN_PKG.modular-xorg-server

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.modular-xorg-server)
.  if ${PREFER.modular-xorg-server} == "pkgsrc"
USE_BUILTIN.modular-xorg-server=	no
.  else
USE_BUILTIN.modular-xorg-server=	${IS_BUILTIN.modular-xorg-server}
.    if defined(BUILTIN_PKG.modular-xorg-server) && \
        !empty(IS_BUILTIN.modular-xorg-server:M[yY][eE][sS])
USE_BUILTIN.modular-xorg-server=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.modular-xorg-server}
.        if !empty(USE_BUILTIN.modular-xorg-server:M[yY][eE][sS])
USE_BUILTIN.modular-xorg-server!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.modular-xorg-server:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.modular-xorg-server
.endif

# Now set up the appropriate prefix for modular-xorg-server
.if !empty(USE_BUILTIN.modular-xorg-server:M[yY][eE][sS])
XORG_SERVERBASE=		${X11BASE}
.else
XORG_SERVERBASE=		${PREFIX}
.endif
