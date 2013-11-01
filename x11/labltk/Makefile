# $NetBSD: Makefile,v 1.19 2013/11/01 11:30:23 jaapb Exp $

INSTALLATION_DIRS+=	lib/ocaml/stublibs
MAKE_JOBS_SAFE=		no

.include "../../lang/ocaml/Makefile.common"

PKGNAME=		${DISTNAME:S/ocaml/labltk/}
PKGREVISION=		10

COMMENT=		Tk bindings for ocaml

CONFIGURE_ARGS+=	-x11include ${X11BASE}/include
CONFIGURE_ARGS+=	-x11lib ${X11BASE}/lib
CONFIGURE_ARGS+=	-tkdefs "-I${BUILDLINK_PREFIX.tk}/include  -I${BUILDLINK_PREFIX.tcl}/include"
CONFIGURE_ARGS+=	-tklibs "`${SH} -c '. ${TCLCONFIG_SH}; . ${TKCONFIG_SH}; ${ECHO} $$TK_LD_FLAGS $$TCL_LD_FLAGS $$TK_LIBS $$TCL_LIBS'`"

BUILD_TARGET=		world
INSTALL_DIRS=		otherlibs/labltk
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
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
