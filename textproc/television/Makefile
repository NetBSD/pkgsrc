# $NetBSD: Makefile,v 1.18 2026/04/02 12:17:28 pin Exp $

DISTNAME=	television-0.15.4
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=alexpasmantier/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://alexpasmantier.github.io/television
COMMENT=	Cross-platform, fast and extensible general purpose fuzzy finder
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=		1.90.0
INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/tv.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tv.1

# The following are not strictly necessary but functionallity will
# be limited without these. Hence, make sure they are installed.
DEPENDS+=	git-base-[0-9]*:../../devel/git-base
DEPENDS+=	fd-find-[0-9]*:../../sysutils/fd-find
DEPENDS+=	bat-[0-9]*:../../textproc/bat

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
