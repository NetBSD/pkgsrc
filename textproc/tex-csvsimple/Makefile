# $NetBSD: Makefile,v 1.9 2024/02/03 04:36:06 markd Exp $

DISTNAME=	csvsimple
PKGNAME=	tex-${DISTNAME}-2.6.0
TEXLIVE_REV=	69494

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/csvsimple
COMMENT=	Simple CSV file processing
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
