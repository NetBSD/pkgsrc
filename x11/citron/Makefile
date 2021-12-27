# $NetBSD: Makefile,v 1.4 2021/12/27 09:13:06 pin Exp $

DISTNAME=	citron-0.6.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=grtcdr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/grtcdr/citron/
COMMENT=	Ditch your panel for some snazzy desktop notifications
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/citron ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
