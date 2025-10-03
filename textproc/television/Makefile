# $NetBSD: Makefile,v 1.4 2025/10/03 15:56:00 pin Exp $

DISTNAME=	television-0.13.5
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=alexpasmantier/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://alexpasmantier.github.io/television
COMMENT=	Cross-platform, fast and extensible general purpose fuzzy finder
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=		1.87.0
INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/examples/television

post-build:
	${CP} ${FILESDIR}/files.toml ${WRKDIR}/files.toml

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/tv.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tv.1
	${INSTALL_DATA} ${WRKDIR}/files.toml \
		${DESTDIR}${PREFIX}/share/examples/television

# The following are not strictly necessary but functionallity will
# be limited without these. Hence, make sure they are installed.
DEPENDS+=	git-base-[0-9]*:../../devel/git-base
# Please note that within pkgsrc the resulting binary for sysutils/fd-find
# has been renamed to 'fdfind' to avoid conflicts with misc/fd
# Due to this, the default 'files.toml' provided with this package
# needs to be adapted to reflect the renamed binary.
DEPENDS+=	fd-find-[0-9]*:../../sysutils/fd-find
DEPENDS+=	bat-[0-9]*:../../textproc/bat

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
