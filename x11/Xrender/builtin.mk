# $NetBSD: builtin.mk,v 1.17.22.1 2008/09/26 21:15:18 cube Exp $

BUILTIN_PKG:=	Xrender

BUILTIN_FIND_FILES_VAR:=	H_XRENDER
BUILTIN_FIND_FILES.H_XRENDER=	${X11BASE}/include/X11/extensions/Xrender.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.Xrender)
IS_BUILTIN.Xrender=	no
.  if empty(H_XRENDER:M__nonexistent__)
BUILTIN_IMAKE_CHECK:=	Xrender:BuildRenderLibrary
.    include "../../mk/buildlink3/imake-check.mk"
IS_BUILTIN.Xrender=	${BUILTIN_IMAKE_CHECK.Xrender}
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.Xrender

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.Xrender) && \
    !empty(IS_BUILTIN.Xrender:M[yY][eE][sS]) && \
    empty(H_XRENDER:M__nonexistent__)
#
# Xrender doesn't provide a method of discovering the version number of
# the software.  Match up Xrender versions with X11 versions for an
# approximate determination of the Xrender version.
#
_BLTN_XRENDER_VERSIONS=		0.8.3  0.8.2  0.8.1  0.8  0.2  0.1
_BLTN_XRENDER_0.1.XFree86=	4.0 4.0.* 4.1 4.1.[0-9] 4.1.[0-9].*	\
				4.1.[1-8][0-9]* 4.1.9[0-8]*
_BLTN_XRENDER_0.2.XFree86=	4.1.99.* 4.2 4.2.[0-9] 4.2.[0-9].*	\
				4.2.[1-8][0-9]* 4.2.9[0-8]*
_BLTN_XRENDER_0.8.XFree86=	4.2.99.* 4.3 4.3.[0-9] 4.3.[0-9].*	\
				4.3.[1-8][0-9]* 4.3.9[0-8]*		\
				4.3.99.* 4.[4-9]* 4.[1-9][0-9]*
_BLTN_XRENDER_0.8.xorg=		6.[7-9]* 6.[1-9][0-9]*
.  for _version_ in ${_BLTN_XRENDER_VERSIONS}
.    for _pattern_ in ${_BLTN_XRENDER_${_version_}.${BUILTIN_X11_TYPE.${X11_TYPE}}}
.      if defined(BUILTIN_X11_VERSION.${X11_TYPE}) && \
          !empty(BUILTIN_X11_VERSION.${X11_TYPE}:M${_pattern_})
BUILTIN_VERSION.Xrender?=	${_version_}
.      endif
.    endfor
.  endfor
.  if defined(BUILTIN_VERSION.Xrender)
BUILTIN_PKG.Xrender=	Xrender-${BUILTIN_VERSION.Xrender}
.  endif
.endif
MAKEVARS+=	BUILTIN_PKG.Xrender

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
#
# These are dependencies of Xrender.  If we need to use the pkgsrc
# versions of any of these, then also use the pkgsrc version of
# Xrender.
#
#.if defined(USE_BUILTIN.render) && !empty(USE_BUILTIN.render:M[nN][oO])
#USE_BUILTIN.render=	no
#.endif

.if !defined(USE_BUILTIN.Xrender)
.  if ${PREFER.Xrender} == "pkgsrc"
USE_BUILTIN.Xrender=	no
.  else
USE_BUILTIN.Xrender=	${IS_BUILTIN.Xrender}
.    if defined(BUILTIN_PKG.Xrender) && \
        !empty(IS_BUILTIN.Xrender:M[yY][eE][sS])
USE_BUILTIN.Xrender=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.Xrender}
.        if !empty(USE_BUILTIN.Xrender:M[yY][eE][sS])
USE_BUILTIN.Xrender!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.Xrender:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.Xrender
.endif
MAKEVARS+=	USE_BUILTIN.Xrender

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###

.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.Xrender?=	no
.if !empty(CHECK_BUILTIN.Xrender:M[nN][oO])

.  if !empty(USE_BUILTIN.Xrender:M[nN][oO])
BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.8.2
BUILDLINK_API_DEPENDS.render+=	Xrender>=0.8
.  endif

.  if !empty(USE_BUILTIN.Xrender:M[yY][eE][sS])
BUILDLINK_PREFIX.Xrender=	${X11BASE}
USE_BUILTIN.render=		yes
.  endif

# If we are using the builtin version, check whether it has a xrender.pc file
# or not.  If the latter, generate a fake one.
.  if !empty(USE_BUILTIN.Xrender:M[Yy][Ee][Ss])
BUILDLINK_TARGETS+=	Xrender-fake-pc

Xrender-fake-pc:
	${_PKG_SILENT}${_PKG_DEBUG} \
	src=${BUILDLINK_PREFIX.Xrender}/lib/pkgconfig/xrender.pc \
	dst=${BUILDLINK_DIR}/lib/pkgconfig/xrender.pc; \
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig; \
	if ${TEST} -f $${src}; then \
		${LN} -sf $${src} $${dst}; \
	else \
		{ ${ECHO} "Name: Xrender"; \
	   	${ECHO} "Description: X Render Library"; \
	   	${ECHO} "Version: 0.8.4"; \
	   	${ECHO} "Cflags: -I${BUILDLINK_PREFIX.Xrender}/include"; \
	   	${ECHO} "Libs: -L${BUILDLINK_PREFIX.Xrender}/lib" \
	       	"${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.Xrender}/lib" \
		    "-lXrender"; \
		} >$${dst}; \
	fi
.  endif

.endif	# CHECK_BUILTIN.Xrender
