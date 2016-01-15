# $NetBSD: Makefile,v 1.1 2016/01/15 08:58:21 wiz Exp $

DISTNAME=	latexdiff
PKGNAME=	tex-${DISTNAME}-1.1.1
TEXLIVE_REV=	39223

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latexdiff
COMMENT=	Determine and mark up significant differences between LaTeX files
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	perl:run
REPLACE_PERL+=	texmf-dist/scripts/latexdiff/*.pl

INSTALLATION_DIRS=	bin

post-install:
	${LN} ${DESTDIR}${PREFIX}/share/texmf-dist/scripts/latexdiff/latexdiff-vc.pl ${DESTDIR}${PREFIX}/bin/latexdiff-vc
	${LN} ${DESTDIR}${PREFIX}/share/texmf-dist/scripts/latexdiff/latexdiff.pl ${DESTDIR}${PREFIX}/bin/latexdiff
	${LN} ${DESTDIR}${PREFIX}/share/texmf-dist/scripts/latexdiff/latexrevise.pl ${DESTDIR}${PREFIX}/bin/latexrevise

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
