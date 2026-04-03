# $NetBSD: Makefile,v 1.2 2026/04/03 01:16:24 markd Exp $

DISTNAME=	markdown
PKGNAME=	tex-${DISTNAME}-3.14.1
TEXLIVE_REV=	78531

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/markdown
COMMENT=	Converting and rendering markdown documents inside TeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-lt3luabridge-[0-9]*:../../devel/tex-lt3luabridge
DEPENDS+=	tex-lua-tinyyaml-[0-9]*:../../devel/tex-lua-tinyyaml

REPLACE_TEXLUA=	texmf-dist/scripts/markdown/markdown2tex.lua

INSTALLATION_DIRS+=	bin

post-install:
	ln -s ${PREFIX}/share/texmf-dist/scripts/markdown/markdown2tex.lua ${DESTDIR}${PREFIX}/bin/markdown2tex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
