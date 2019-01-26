# $NetBSD: Makefile,v 1.6 2019/01/26 10:54:00 markd Exp $

DISTNAME=	latexdiff.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.3.0
TEXLIVE_REV=	48926

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latexdiff
COMMENT=	Documentation for tex-latexdiff
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	bash:run perl:run
REPLACE_PERL+=	texmf-dist/doc/support/latexdiff/latexdiff
REPLACE_PERL+=	texmf-dist/doc/support/latexdiff/latexdiff-fast
REPLACE_BASH+=	texmf-dist/doc/support/latexdiff/contrib/latexdiff-wrap

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
