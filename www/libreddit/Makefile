# $NetBSD: Makefile,v 1.7 2023/10/24 22:11:29 wiz Exp $

DISTNAME=	libreddit-0.30.1.20230714
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=libreddit/}
GITHUB_TAG=	2815dc5209465295c93ada3656f17da63ad0f5b5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libreddit/libreddit/
COMMENT=	Private front-end for Reddit
LICENSE=	gnu-agpl-v3

.include "cargo-depends.mk"

DEPENDS+=	daemonize-[0-9]*:../../sysutils/daemonize

RCD_SCRIPTS=	libreddit

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=	${EGDIR}/libreddit.conf \
		${PKG_SYSCONFDIR}/libreddit.conf

INSTALLATION_DIRS=	bin share/examples/${PKGBASE}

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/libreddit \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/libreddit.conf ${DESTDIR}${EGDIR}

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
