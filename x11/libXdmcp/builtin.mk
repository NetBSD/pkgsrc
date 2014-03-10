# $NetBSD: builtin.mk,v 1.5 2014/03/10 11:56:02 jperkin Exp $

BUILTIN_PKG:=	libXdmcp

BUILTIN_FIND_FILES_VAR:=	H_XDMCP
BUILTIN_FIND_FILES.H_XDMCP=	${X11BASE}/include/X11/Xdmcp.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if ${X11BASE} == ${LOCALBASE}
IS_BUILTIN.libXdmcp=	no
.elif !defined(IS_BUILTIN.libXdmcp)
IS_BUILTIN.libXdmcp=	no
.  if empty(H_XDMCP:M__nonexistent__)
IS_BUILTIN.libXdmcp=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libXdmcp

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libXdmcp)
.  if ${PREFER.libXdmcp} == "pkgsrc"
USE_BUILTIN.libXdmcp=	no
.  else
USE_BUILTIN.libXdmcp=	${IS_BUILTIN.libXdmcp}
.    if defined(BUILTIN_PKG.libXdmcp) && \
        !empty(IS_BUILTIN.libXdmcp:M[yY][eE][sS])
USE_BUILTIN.libXdmcp=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libXdmcp}
.        if !empty(USE_BUILTIN.libXdmcp:M[yY][eE][sS])
USE_BUILTIN.libXdmcp!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libXdmcp:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libXdmcp
.endif
MAKEVARS+=	USE_BUILTIN.libXdmcp

.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.libXdmcp?=	no
.if !empty(CHECK_BUILTIN.libXdmcp:M[nN][oO])

# If we are using the builtin version, check whether it has a xdmcp.pc
# file or not.  If the latter, generate a fake one.
.  if !empty(USE_BUILTIN.libXdmcp:M[Yy][Ee][Ss])
BUILDLINK_TARGETS+=	xdmcp-fake-pc

xdmcp-fake-pc:
	${RUN} \
	for dir in lib lib${LIBABISUFFIX} share; do \
		${TEST} -f ${BUILDLINK_PREFIX.libXdmcp}/$${dir}/pkgconfig/xdmcp.pc && exit; \
	done; \
	src=${BUILDLINK_PREFIX.libXdmcp}/lib/pkgconfig/xdmcp.pc; \
	dst=${BUILDLINK_DIR}/lib/pkgconfig/xdmcp.pc; \
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig; \
	if ${TEST} -f $${src}; then \
		${LN} -sf $${src} $${dst}; \
	else \
		req=""; \
		if ${TEST} -f \
			${BUILDLINK_PREFIX.xproto}/lib/pkgconfig/xproto.pc; then \
			req="xproto"; \
		fi; \
		{ ${ECHO} "Name: Xdmcp"; \
	   	${ECHO} "Description: X Display Manager Control Protocol library"; \
	   	${ECHO} "Version: 0.99"; \
		${ECHO} "Requires: $${req}"; \
	   	${ECHO} "Cflags: -I${BUILDLINK_PREFIX.libXdmcp}/include"; \
		${ECHO} "Libs: -L${BUILDLINK_PREFIX.libXdmcp}/lib" \
		"${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libXdmcp}/lib" \
		"-lXdmcp"; \
		} >$${dst}; \
	fi
.  endif

.endif	# CHECK_BUILTIN.libXdmcp
