# $NetBSD: version.mk,v 1.2 2005/06/20 22:13:10 jlam Exp $
#
# This Makefile fragment is included by Makefiles that need to access
# the X11_TYPE and version number of an X.org distribution.
#
# The following variables are provided by this file:
#
#    BUILTIN_X11_TYPE.xorg is the X11_TYPE of the X.org distribution
#	and is simply "xorg".
#
#    BUILTIN_X11_VERSION.xorg is the version number of the X.org
#	distribution detected on the system.
#

BUILTIN_X11_TYPE.xorg=	xorg

BUILTIN_FIND_FILES_VAR:=		CF_XORGVERSION CF_XORG
BUILTIN_FIND_FILES.CF_XORGVERSION=	${X11BASE}/lib/X11/config/xorgversion.def
BUILTIN_FIND_FILES.CF_XORG=		${X11BASE}/lib/X11/config/xorg.cf
.include "../../mk/buildlink3/find-files.mk"

.if !defined(BUILTIN_XORG_VERSION_FILE)
BUILTIN_XORG_VERSION_FILE=	__nonexistent__
.  if exists(${BUILTIN_X11_CONFIG_XORGVERSION_DEF})
BUILTIN_XORG_VERSION_FILE=	${BUILTIN_X11_CONFIG_XORGVERSION_DEF}
.  elif exists(${BUILTIN_X11_CONFIG_XORG_CF})
BUILTIN_XORG_VERSION_FILE=	${BUILTIN_X11_CONFIG_XORG_CF}
.  endif
.endif
MAKEVARS+=	BUILTIN_XORG_VERSION_FILE

.if !defined(BUILTIN_X11_VERSION.xorg) && \
    exists(${BUILTIN_XORG_VERSION_FILE})
BUILTIN_X11_VERSION.xorg!=						\
	${AWK} '/\#define[ 	]*XORG_VERSION_MAJOR/ { M = $$3 }	\
		/\#define[ 	]*XORG_VERSION_MINOR/ { m = "."$$3 }	\
		/\#define[ 	]*XORG_VERSION_PATCH/ { p = "."$$3 }	\
		/\#define[ 	]*XORG_VERSION_SNAP/ { s = "."$$3 }	\
		END { if (s == ".0") s = "";				\
		      if (p == ".0" && s == "") p = "";			\
		      printf "%s%s%s%s\n", M, m, p, s }'		\
		${BUILTIN_XORG_VERSION_FILE}
.endif
MAKEVARS+=	BUILTIN_X11_VERSION.xorg
