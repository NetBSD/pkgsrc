# $NetBSD: Makefile,v 1.14 2024/12/27 21:31:16 pin Exp $

DISTNAME=	citron-v0.15.0
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	x11
MASTER_SITES=	-https://git.sr.ht/~grtcdr/citron/archive/v${PKGVERSION_NOREV}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~grtcdr/citron/
COMMENT=	System data via on-demand notifications
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/citron ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/citron.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/citron.1

.include "../../lang/rust/cargo.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
