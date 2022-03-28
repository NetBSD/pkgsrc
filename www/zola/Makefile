# $NetBSD: Makefile,v 1.8 2022/03/28 12:58:26 wiz Exp $

DISTNAME=	zola-0.15.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=getzola/}
GITHUB_PROJECT=	zola
GITHUB_TAG=	v0.15.3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.getzola.org/
COMMENT=	Static website generator
LICENSE=	mit
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/zola ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
