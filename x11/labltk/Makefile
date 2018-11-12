# $NetBSD: Makefile,v 1.35 2018/11/12 16:10:29 jaapb Exp $

DISTNAME=	labltk-8.06.3
PKGREVISION=	5
CATEGORIES=	x11
# caution: it's the 1701, not the filename, that identifies the download
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1701/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://forge.ocamlcore.org/projects/labltk/
COMMENT=	Tk bindings for ocaml
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake
MAKE_JOBS_SAFE=	no

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	-x11include ${X11BASE}/include
CONFIGURE_ARGS+=	-x11lib ${X11BASE}/lib
CONFIGURE_ARGS+=	-use-findlib
CONFIGURE_ARGS+=	-tkdefs "-I${BUILDLINK_PREFIX.tk}/include  -I${BUILDLINK_PREFIX.tcl}/include"
CONFIGURE_ARGS+=	-tklibs "`${SH} -c '. ${TCLCONFIG_SH}; . ${TKCONFIG_SH}; ${ECHO} $$TK_LD_FLAGS $$TCL_LD_FLAGS $$TK_LIBS $$TCL_LIBS'`"

BUILD_TARGET=		all
INSTALL_TARGET=		install
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "arm") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
BUILD_TARGET+=		opt
PLIST_SRC=		${.CURDIR}/PLIST.opt ${.CURDIR}/PLIST
.endif

.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
