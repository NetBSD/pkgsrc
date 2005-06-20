# $NetBSD: version.mk,v 1.2 2005/06/20 22:13:10 jlam Exp $
#
# This Makefile fragment is included by Makefiles that need to access
# the X11_TYPE and version number of a XFree86 distribution.
#
# The following variables are provided by this file:
#
#    BUILTIN_X11_TYPE.XFree86 is the X11_TYPE of the XFree86 distribution
#	and is simply "XFree86".
#
#    BUILTIN_X11_VERSION.XFree86 is the version number of the XFree86
#	distribution detected on the system.
#

BUILTIN_X11_TYPE.XFree86=	XFree86

BUILTIN_FIND_FILES_VAR:=		CF_XFREE86 CF_XFREE86_VERSION
BUILTIN_FIND_FILES.CF_XFREE86=		${X11BASE}/lib/X11/config/xfree86.cf
BUILTIN_FIND_FILES.CF_XFREE86_VERSION=	${X11BASE}/lib/X11/config/version.def
.include "../../mk/buildlink3/find-files.mk"

.if !defined(BUILTIN_X11_VERSION.XFree86) && \
    exists(${CF_XFREE86}) && exists(${CF_XFREE86_VERSION})
BUILTIN_X11_VERSION.XFree86!=						\
	${AWK} '/\#define[ 	]*XF86_VERSION_MAJOR/ { M = $$3 }	\
		/\#define[ 	]*XF86_VERSION_MINOR/ { m = "."$$3 }	\
		/\#define[ 	]*XF86_VERSION_PATCH/ { p = "."$$3 }	\
		/\#define[ 	]*XF86_VERSION_SNAP/ { s = "."$$3 }	\
		/\#define[ 	]*XFree86Version/ {			\
			V = $$3;					\
			if (M == "") M = int(V / 1000) % 10;		\
			if (m == "") m = "."(int(V / 100) % 10);	\
			if (p == "") p = "."(int(V / 10) % 10);		\
			if (s == "") s = "."(V % 10);			\
		}							\
		END { if (s == ".0") s = "";				\
		      if (p == ".0" && s == "") p = "";			\
		      printf "%s%s%s%s\n", M, m, p, s }'		\
		${CF_XFREE86_VERSION}
.endif
MAKEVARS+=	BUILTIN_X11_VERSION.XFree86
