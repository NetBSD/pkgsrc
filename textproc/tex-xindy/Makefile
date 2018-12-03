# $NetBSD: Makefile,v 1.3 2018/12/03 19:31:56 markd Exp $

DISTNAME=	xindy
PKGNAME=	tex-${DISTNAME}-2.5.1
PKGREVISION=	2
TEXLIVE_REV=	43948

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/xindy
COMMENT=	General-purpose index processor
LICENSE=	gnu-gpl-v2

DEPENDS+=	xindy>=2.5.1:../../textproc/xindy

USE_TOOLS+=	perl:run

REPLACE_PERL+=	texmf-dist/scripts/xindy/*.pl

INSTALLATION_DIRS+=	bin

post-install:
	${LN} -sf ${PREFIX}/share/texmf-dist/scripts/xindy/texindy.pl ${DESTDIR}${PREFIX}/bin/texindy
	${LN} -sf ${PREFIX}/share/texmf-dist/scripts/xindy/xindy.pl ${DESTDIR}${PREFIX}/bin/xindy

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
