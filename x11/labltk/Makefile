# $NetBSD: Makefile,v 1.3 2005/06/14 21:00:41 minskim Exp $

.include "../../lang/ocaml/Makefile.common"

PKGNAME=		${DISTNAME:S/ocaml/labltk/}

COMMENT=		Tk bindings for ocaml


CONFIGURE_ARGS+=	-x11include ${X11BASE}/include
CONFIGURE_ARGS+=	-x11lib ${X11BASE}/lib
CONFIGURE_ARGS+=	-tkdefs "-I${BUILDLINK_PREFIX.tk}/include  -I${BUILDLINK_PREFIX.tcl}/include"
CONFIGURE_ARGS+=	-tklibs "`${SH} -c '. ${TCLCONFIG_SH}; . ${TKCONFIG_SH}; ${ECHO} $$TK_LIBS $$TCL_LIBS'`"

BUILD_TARGET=		world
INSTALL_DIRS=		${WRKSRC}/otherlibs/labltk
INSTALL_TARGET=		install
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc")
BUILD_TARGET+=		opt opt.opt
INSTALL_TARGET+=	installopt
PLIST_SRC=		${.CURDIR}/PLIST.opt ${.CURDIR}/PLIST
.endif

BUILDLINK_DEPMETHOD.ocaml=	full
BUILDLINK_DEPMETHOD.${BDB_TYPE}=build

.include "../../lang/ocaml/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
