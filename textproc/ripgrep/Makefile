# $NetBSD: Makefile,v 1.13 2021/03/05 21:49:56 pin Exp $

DISTNAME=	ripgrep-12.1.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=BurntSushi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/BurntSushi/ripgrep/
COMMENT=	Line-oriented search tool
LICENSE=	unlicense

.include "cargo-depends.mk"

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		pcre2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rg ${DESTDIR}${PREFIX}/bin

DEPENDS+=	pcre2-[0-9]*:../../devel/pcre2

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
