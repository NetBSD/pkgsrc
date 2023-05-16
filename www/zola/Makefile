# $NetBSD: Makefile,v 1.14 2023/05/16 15:41:00 nikita Exp $

DISTNAME=	zola-0.17.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=getzola/}
GITHUB_PROJECT=	zola
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.getzola.org/
COMMENT=	Static website generator
LICENSE=	mit

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake pkg-config

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libsass}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../www/libsass/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
