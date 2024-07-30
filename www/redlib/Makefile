# $NetBSD: Makefile,v 1.1 2024/07/30 17:05:19 vins Exp $

DISTNAME=	redlib-0.35.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=redlib-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/redlib/redlib/
COMMENT=	Private front-end for Reddit
LICENSE=	gnu-agpl-v3

CONFLICTS+=	libreddit-[0-9]*
SUPERSEDES+=	libreddit-[0-9]*
PREV_PKGPATH=	www/libreddit

.include "cargo-depends.mk"

DEPENDS+=	daemonize-[0-9]*:../../sysutils/daemonize

RCD_SCRIPTS=	redlib

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=	${EGDIR}/redlib.conf \
		${PKG_SYSCONFDIR}/redlib.conf

INSTALLATION_DIRS=	bin share/examples/${PKGBASE}

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/redlib \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/redlib.conf ${DESTDIR}${EGDIR}

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
