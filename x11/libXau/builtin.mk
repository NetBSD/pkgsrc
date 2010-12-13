# $NetBSD: builtin.mk,v 1.4 2010/12/13 07:51:45 obache Exp $

BUILTIN_PKG:=	libXau

BUILTIN_FIND_FILES_VAR:=	H_XAUTH
BUILTIN_FIND_FILES.H_XAUTH=	${X11BASE}/include/X11/Xauth.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.libXau=	no
.elif !defined(IS_BUILTIN.libXau)
IS_BUILTIN.libXau=	no
.  if empty(H_XAUTH:M__nonexistent__)
IS_BUILTIN.libXau=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libXau

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libXau)
.  if ${PREFER.libXau} == "pkgsrc"
USE_BUILTIN.libXau=	no
.  else
USE_BUILTIN.libXau=	${IS_BUILTIN.libXau}
.    if defined(BUILTIN_PKG.libXau) && \
        !empty(IS_BUILTIN.libXau:M[yY][eE][sS])
USE_BUILTIN.libXau=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libXau}
.        if !empty(USE_BUILTIN.libXau:M[yY][eE][sS])
USE_BUILTIN.libXau!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libXau:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libXau
.endif
MAKEVARS+=	USE_BUILTIN.libXau

.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.libXau?=	no
.if !empty(CHECK_BUILTIN.libXau:M[nN][oO])

# If we are using the builtin version, check whether it has a xau.pc
# file or not.  If the latter, generate a fake one.
.  if !empty(USE_BUILTIN.libXau:M[Yy][Ee][Ss])
BUILDLINK_TARGETS+=	xau-fake-pc

xau-fake-pc:
	${RUN} \
	src=${BUILDLINK_PREFIX.libXau}/lib/pkgconfig/xau.pc; \
	dst=${BUILDLINK_DIR}/lib/pkgconfig/xau.pc; \
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig; \
	if ${TEST} -f $${src}; then \
		${LN} -sf $${src} $${dst}; \
	else \
		req=""; \
		if ${TEST} -f \
			${BUILDLINK_PREFIX.xproto}/lib/pkgconfig/xproto.pc; then \
			req="xproto"; \
		fi; \
		{ ${ECHO} "Name: Xau"; \
	   	${ECHO} "Description: X authorization file management library"; \
	   	${ECHO} "Version: 1.0.1"; \
		${ECHO} "Requires: $${req}"; \
	   	${ECHO} "Cflags: -I${BUILDLINK_PREFIX.libXau}/include"; \
		${ECHO} "Libs: -L${BUILDLINK_PREFIX.libXau}/lib" \
		"${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libXau}/lib" \
		"-lXau"; \
		} >$${dst}; \
	fi
.  endif

.endif	# CHECK_BUILTIN.libXau
