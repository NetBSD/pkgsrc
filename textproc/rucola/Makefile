# $NetBSD: Makefile,v 1.4 2026/04/30 11:51:35 pin Exp $

DISTNAME=	rucola-0.9.0
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

#RUST_REQ=	1.96.0-beta.4
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.96.0-beta.4 on amd64
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
