# $NetBSD: Makefile,v 1.18 2025/12/03 18:23:52 pin Exp $

DISTNAME=	typst-0.14.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=typst/}
GITHUB_PROJECT=	typst
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://typst.app/
COMMENT=	Markup-based typesetting system
LICENSE=	apache-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.89.0

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
TYPST-DEV-ASSETS_REV=	03addcfb64f3f95209464a521e6aa49645bd271a
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
