# $NetBSD: Makefile,v 1.15 2023/04/01 11:44:56 markd Exp $

DISTNAME=	latexdiff.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.3.3
TEXLIVE_REV=	64980

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
