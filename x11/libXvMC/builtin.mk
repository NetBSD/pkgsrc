# $NetBSD: builtin.mk,v 1.3 2017/06/01 13:30:26 jlam Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILTIN_PKG:=	libXvMC

BUILTIN_FIND_FILES_VAR:=	PC_LIBXVMC LIB_XVMCW
BUILTIN_FIND_FILES.PC_LIBXVMC=	${X11BASE}/lib/pkgconfig/xvmc.pc
BUILTIN_FIND_FILES.PC_LIBXVMC+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xvmc.pc
.if ${SHLIB_TYPE} == "dylib"
BUILTIN_FIND_FILES.LIB_XVMCW=	${X11BASE}/lib/libXvMCW.dylib
.else
BUILTIN_FIND_FILES.LIB_XVMCW=	${X11BASE}/lib/libXvMCW.so
.endif

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.libXvMC=	no
.elif !defined(IS_BUILTIN.libXvMC)
IS_BUILTIN.libXvMC=	no
.  if empty(PC_LIBXVMC:M__nonexistent__) && \
      empty(LIB_XVMCW:M__nonexistent__)
IS_BUILTIN.libXvMC=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libXvMC

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libXvMC)
.  if ${PREFER.libXvMC} == "pkgsrc"
USE_BUILTIN.libXvMC=	no
.  else
USE_BUILTIN.libXvMC=	${IS_BUILTIN.libXvMC}
.    if defined(BUILTIN_PKG.libXvMC) && \
        !empty(IS_BUILTIN.libXvMC:M[yY][eE][sS])
USE_BUILTIN.libXvMC=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libXvMC}
.        if !empty(USE_BUILTIN.libXvMC:M[yY][eE][sS])
USE_BUILTIN.libXvMC!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libXvMC:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libXvMC
.endif
MAKEVARS+=	USE_BUILTIN.libXvMC

.include "../../mk/x11.builtin.mk"
