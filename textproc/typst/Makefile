# $NetBSD: Makefile,v 1.10 2024/03/18 09:04:32 pin Exp $

DISTNAME=	typst-0.11.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=typst/}
GITHUB_PROJECT=	typst
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://typst.app/
COMMENT=	Markup-based typesetting system
LICENSE=	apache-2.0

.include "cargo-depends.mk"

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
TYPST-DEV-ASSETS_REV=	e0ef7ad46f28a440c41bc8e78563ace86cc02678
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		typst-dev-assets-${TYPST-DEV-ASSETS_REV}.tar.gz
SITES.typst-dev-assets-${TYPST-DEV-ASSETS_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=typst/}typst-dev-assets/archive/${TYPST-DEV-ASSETS_REV}.tar.gz

USE_TOOLS+=	pkg-config perl gmake

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

INSTALLATION_DIRS=	bin

post-extract:
	mv ${WRKDIR}/typst-dev-assets-* ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/typst \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
