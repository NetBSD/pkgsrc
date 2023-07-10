# $NetBSD: Makefile,v 1.5 2023/07/10 19:43:05 pin Exp $

DISTNAME=	typst-0.6.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=typst/}
GITHUB_PROJECT=	typst
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://typst.app/
COMMENT=	Markup-based typesetting system
LICENSE=	apache-2.0

DISTFILES=	${DEFAULT_DISTFILES}
SVG2PDF_REV=	35f4bb87fb677473661c6d12919e01a6d64a716d
DISTFILES+=	svg2pdf-${SVG2PDF_REV}.tar.gz
SITES.svg2pdf-${SVG2PDF_REV}.tar.gz+= -${MASTER_SITE_GITHUB:=typst/}svg2pdf/archive/${SVG2PDF_REV}.tar.gz

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

post-extract:
	mv ${WRKDIR}/svg2pdf-* ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/typst ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
