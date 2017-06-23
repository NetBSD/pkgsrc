# $NetBSD: Makefile,v 1.1 2017/06/23 23:23:56 markd Exp $

DISTNAME=	lwarp
PKGNAME=	tex-${DISTNAME}-0.32
TEXLIVE_REV=	44552

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/lwarp
COMMENT=	Converts LaTeX to HTML
LICENSE=	lppl-1.3c

DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex

REPLACE_TEXLUA=	bin/lwarpmk

INSTALLATION_DIRS+=	bin

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/lwarp/lwarpmk.lua ${WRKSRC}/bin/lwarpmk

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
