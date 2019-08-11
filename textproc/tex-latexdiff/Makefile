# $NetBSD: Makefile,v 1.7 2019/08/11 13:24:01 wiz Exp $

DISTNAME=	latexdiff
PKGNAME=	tex-${DISTNAME}-1.3.0
PKGREVISION=	1
TEXLIVE_REV=	48926

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
