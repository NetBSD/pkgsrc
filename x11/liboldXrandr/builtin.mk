# $NetBSD: builtin.mk,v 1.1.16.1 2008/09/26 21:15:19 cube Exp $

BUILTIN_PKG:=	Xrandr

BUILTIN_FIND_FILES_VAR:=	H_XRANDR
BUILTIN_FIND_FILES.H_XRANDR=	${X11BASE}/include/X11/extensions/Xrandr.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.Xrandr)
IS_BUILTIN.Xrandr=	no
.  if empty(H_XRANDR:M__nonexistent__)
BUILTIN_IMAKE_CHECK:=	Xrandr:BuildRandRLibrary
.    include "../../mk/buildlink3/imake-check.mk"
IS_BUILTIN.Xrandr=	${BUILTIN_IMAKE_CHECK.Xrandr}
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.Xrandr

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.Xrandr) && \
    !empty(IS_BUILTIN.Xrandr:M[yY][eE][sS]) && \
    empty(H_XRANDR:M__nonexistent__)
#
# Xrandr doesn't provide a method of discovering the version number of
# the software.  Match up Xrandr versions with X11 versions for an
# approximate determination of the Xrandr version.
#
_BLTN_XRANDR_VERSIONS=		1.0.2  1.0.1  1.0  0.99
_BLTN_XRANDR_0.99.XFree86=	4.2 4.2.*
_BLTN_XRANDR_1.0.XFree86=	4.3 4.3.[0-9] 4.3.[0-9].*		\
				4.3.[1-8][0-9]* 4.3.9[0-8]*		\
				4.3.99.* 4.[4-9]* 4.[1-9][0-9]*
_BLTN_XRANDR_1.0.xorg=		6.[7-9]* 6.[1-9][0-9]*
.  for _version_ in ${_BLTN_XRANDR_VERSIONS}
.    for _pattern_ in ${_BLTN_XRANDR_${_version_}.${BUILTIN_X11_TYPE.${X11_TYPE}}}
.      if defined(BUILTIN_X11_VERSION.${X11_TYPE}) && \
          !empty(BUILTIN_X11_VERSION.${X11_TYPE}:M${_pattern_})
BUILTIN_VERSION.Xrandr?=	${_version_}
.      endif
.    endfor
.  endfor
.  if defined(BUILTIN_VERSION.Xrandr)
BUILTIN_PKG.Xrandr=	Xrandr-${BUILTIN_VERSION.Xrandr}
.  endif
.endif
MAKEVARS+=	BUILTIN_PKG.Xrandr

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
#
# These are dependencies of Xrandr.  If we need to use the pkgsrc
# versions of any of these, then also use the pkgsrc version of
# Xrandr.
#
.if defined(USE_BUILTIN.Xrender) && !empty(USE_BUILTIN.Xrender:M[nN][oO])
USE_BUILTIN.Xrender=	no
.endif
.if defined(USE_BUILTIN.randrproto) && !empty(USE_BUILTIN.randrproto:M[nN][oO])
USE_BUILTIN.randrproto=	no
.endif

.if !defined(USE_BUILTIN.Xrandr)
.  if ${PREFER.Xrandr} == "pkgsrc"
USE_BUILTIN.Xrandr=	no
.  else
USE_BUILTIN.Xrandr=	${IS_BUILTIN.Xrandr}
.    if defined(BUILTIN_PKG.Xrandr) && \
        !empty(IS_BUILTIN.Xrandr:M[yY][eE][sS])
USE_BUILTIN.Xrandr=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.Xrandr}
.        if !empty(USE_BUILTIN.Xrandr:M[yY][eE][sS])
USE_BUILTIN.Xrandr!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.Xrandr:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.Xrandr
.endif
MAKEVARS+=	USE_BUILTIN.Xrandr

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###

.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.Xrandr?=	no
.if !empty(CHECK_BUILTIN.Xrandr:M[nN][oO])

.  if !empty(USE_BUILTIN.Xrandr:M[nN][oO])
BUILDLINK_API_DEPENDS.Xrandr+=	Xrandr>=1.0.1
BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.8
.  endif

.  if !empty(USE_BUILTIN.Xrandr:M[yY][eE][sS])
BUILDLINK_PREFIX.Xrandr=	${X11BASE}
USE_BUILTIN.Xrender=		yes
USE_BUILTIN.randrproto=		yes
.  endif

.endif	# CHECK_BUILTIN.Xrandr
