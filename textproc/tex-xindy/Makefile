# $NetBSD: Makefile,v 1.7 2020/08/31 18:12:18 wiz Exp $

DISTNAME=	xindy
PKGNAME=	tex-${DISTNAME}-2.5.1
PKGREVISION=	4
TEXLIVE_REV=	43948

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xindy
COMMENT=	General-purpose index processor
LICENSE=	gnu-gpl-v2

DEPENDS+=	xindy>=2.5.1:../../textproc/xindy

USE_TOOLS+=	perl:run

REPLACE_PERL+=	texmf-dist/scripts/xindy/*.pl

INSTALLATION_DIRS+=	bin

post-install:
	${LN} -sf ${PREFIX}/share/texmf-dist/scripts/xindy/texindy.pl ${DESTDIR}${PREFIX}/bin/texindy
	${LN} -sf ${PREFIX}/share/texmf-dist/scripts/xindy/xindy.pl ${DESTDIR}${PREFIX}/bin/xindy

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
