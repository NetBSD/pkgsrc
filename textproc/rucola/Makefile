# $NetBSD: Makefile,v 1.3 2026/01/05 11:05:20 wiz Exp $

DISTNAME=	rucola-0.8.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Linus-Mussmaecher/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Linus-Mussmaecher/rucola/
COMMENT=	Terminal-based markdown note manager
LICENSE=	gnu-gpl-v3

# Rucola has no requirements, but a Nerd font may be required on your
# machine to display some of the icons properly.

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config
MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}

INSTALLATION_DIRS=	share/examples/rucola

post-install:
	cd ${WRKSRC}/default-config &&	\
	for f in *.toml *.css; do	\
	  ${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/examples/rucola;	\
	done

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
