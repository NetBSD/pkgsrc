# $NetBSD: Makefile,v 1.6 2022/01/02 21:58:36 pin Exp $

DISTNAME=	v0.8.0
PKGNAME=	citron-${DISTNAME:S,^v,,}
CATEGORIES=	x11
MASTER_SITES=	https://git.sr.ht/~grtcdr/citron/archive/

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~grtcdr/citron/
COMMENT=	Ditch your panel for some snazzy desktop notifications
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/citron-${DISTNAME}

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/citron ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
