# $NetBSD: Makefile,v 1.13 2022/04/14 02:08:44 markd Exp $

DISTNAME=	latexdiff
PKGNAME=	tex-${DISTNAME}-1.3.2
TEXLIVE_REV=	61434

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latexdiff
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
