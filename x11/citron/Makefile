# $NetBSD: Makefile,v 1.9 2022/01/08 15:34:32 pin Exp $

DISTNAME=	v0.13.0
PKGNAME=	citron-${DISTNAME:S,^v,,}
CATEGORIES=	x11
MASTER_SITES=	https://git.sr.ht/~grtcdr/citron/archive/

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~grtcdr/citron/
COMMENT=	System data via on-demand notifications
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/citron-${DISTNAME}

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/citron ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/citron.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/citron.1

.include "../../lang/rust/cargo.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
