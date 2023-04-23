# $NetBSD: Makefile,v 1.2 2023/04/23 20:14:35 wiz Exp $

DISTNAME=	typst-0.2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=typst/}
GITHUB_PROJECT=	typst
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://typst.app/
COMMENT=	Markup-based typesetting system
LICENSE=	apache-2.0

# patched out for now, let's hope it lasts.
#DISTFILES=	${DEFAULT_DISTFILES}
# Depends on an unpublished crates. Can't use cargo.mk to fetch it.
#IAI_REV=	3f0f92736408ebce6545808b98e0cb2aea89b7dd
#DISTFILES+=	iai-${IAI_REV}.tar.gz
#SITES.iai-${IAI_REV}.tar.gz+= -${MASTER_SITE_GITHUB:=reknih/}iai/archive/${IAI_REV}.tar.gz

.include "cargo-depends.mk"

#CARGO_ARGS=	${DEFAULT_CARGO_ARGS} -p typst-cli

INSTALLATION_DIRS=	bin

#post-extract:
#	mv ${WRKDIR}/iai-* ${WRKDIR}/vendor/iai

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/typst ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
