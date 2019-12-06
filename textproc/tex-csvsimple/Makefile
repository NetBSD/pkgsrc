# $NetBSD: Makefile,v 1.3 2019/12/06 19:04:12 markd Exp $

DISTNAME=	csvsimple
PKGNAME=	tex-${DISTNAME}-1.21
TEXLIVE_REV=	51010

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/csvsimple
COMMENT=	Simple CSV file processing
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
