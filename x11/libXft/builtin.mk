# $NetBSD: builtin.mk,v 1.1 2013/06/05 12:12:07 tron Exp $

.if !defined(USE_BUILTIN.fontconfig)
.include "../../fonts/fontconfig/builtin.mk"
.endif
.if !defined(USE_BUILTIN.Xrender)
.include "../../x11/Xrender/builtin.mk"
.endif

BUILTIN_PKG:=	libXft

BUILTIN_FIND_FILES_VAR:=	H_XFT2
BUILTIN_FIND_FILES.H_XFT2=	${X11BASE}/include/X11/Xft/Xft.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.libXft)
.  if empty(H_XFT2:M__nonexistent__)
IS_BUILTIN.libXft=	yes
.  else
IS_BUILTIN.libXft=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libXft

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.libXft) && \
    !empty(IS_BUILTIN.libXft:M[yY][eE][sS]) && \
    empty(H_XFT2:M__nonexistent__)
#
# Extract the version number from the header file, but if it's not
# there, then pretend it's from version 2.0.
#
BUILTIN_VERSION.libXft!=							\
	${AWK} 'BEGIN { M = 2; m = ".0"; r = "" }			\
		/\#define[ 	]*XFT_MAJOR/ { M = $$3 }		\
		/\#define[ 	]*XFT_MINOR/ { m = "."$$3 }		\
		/\#define[ 	]*XFT_REVISION/ { r = "."$$3 }		\
		END { printf "%s%s%s\n", M, m, r }'			\
		${H_XFT2}
BUILTIN_PKG.libXft=	libXft-${BUILTIN_VERSION.libXft}
.endif
MAKEVARS+=	BUILTIN_PKG.libXft

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
#
# These are dependencies of libXft.  If we need to use the pkgsrc
# versions of any of these, then also use the pkgsrc version of
# libXft.
#
.if !empty(USE_BUILTIN.Xrender:M[nN][oO])
USE_BUILTIN.libXft=	no
.endif
.if !empty(USE_BUILTIN.fontconfig:M[nN][oO])
USE_BUILTIN.libXft=	no
.endif

.if !defined(USE_BUILTIN.libXft)
.  if ${PREFER.libXft} == "pkgsrc"
USE_BUILTIN.libXft=	no
.  else
USE_BUILTIN.libXft=	${IS_BUILTIN.libXft}
.    if defined(BUILTIN_PKG.libXft) && \
        !empty(IS_BUILTIN.libXft:M[yY][eE][sS])
USE_BUILTIN.libXft=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libXft}
.        if !empty(USE_BUILTIN.libXft:M[yY][eE][sS])
USE_BUILTIN.libXft!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libXft:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libXft
.endif
MAKEVARS+=	USE_BUILTIN.libXft

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###

.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.libXft?=	no
.if !empty(CHECK_BUILTIN.libXft:M[nN][oO])

.  if !empty(USE_BUILTIN.libXft:M[nN][oO])
BUILDLINK_API_DEPENDS.libXft+=	libXft>=2.1.10
.  endif

.endif	# CHECK_BUILTIN.libXft
