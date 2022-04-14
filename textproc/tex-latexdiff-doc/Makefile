# $NetBSD: Makefile,v 1.13 2022/04/14 02:08:44 markd Exp $

DISTNAME=	latexdiff.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.3.2
TEXLIVE_REV=	61434

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latexdiff
COMMENT=	Documentation for tex-latexdiff
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	bash:run perl:run
REPLACE_PERL+=	texmf-dist/doc/support/latexdiff/latexdiff
REPLACE_PERL+=	texmf-dist/doc/support/latexdiff/latexdiff-fast
REPLACE_BASH+=	texmf-dist/doc/support/latexdiff/contrib/latexdiff-wrap

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
