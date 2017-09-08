# $NetBSD: Makefile,v 1.1 2017/09/08 22:23:04 markd Exp $

DISTNAME=	csvsimple
PKGNAME=	tex-${DISTNAME}-1.20
TEXLIVE_REV=	41597

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/csvsimple
COMMENT=	Simple CSV file processing
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
