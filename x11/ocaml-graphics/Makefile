# $NetBSD: Makefile,v 1.1.1.1 2004/12/24 17:17:49 jmmv Exp $

.include "../../lang/ocaml/Makefile.common"

PKGNAME=		${DISTNAME:S/ocaml/ocaml-graphics/}

COMMENT+=		(graphics library)

USE_X11=		yes

CONFIGURE_ARGS+=	-x11include ${X11BASE}/include
CONFIGURE_ARGS+=	-x11lib ${X11BASE}/lib
CONFIGURE_ARGS+=	-no-tk

BUILD_DIRS=		${WRKSRC}/otherlibs/graph
BUILD_TARGET=		all
INSTALL_TARGET=		install
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc")
BUILD_TARGET+=		allopt
INSTALL_TARGET+=	installopt
PLIST_SUBST+=		OPT=
.else
PLIST_SUBST+=		OPT='@comment '
.endif

BUILDLINK_DEPMETHOD.ocaml=	full

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
