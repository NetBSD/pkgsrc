# $NetBSD: Makefile,v 1.1 2020/05/22 01:51:00 markd Exp $

DISTNAME=	datetime2-it-fulltext
PKGNAME=	tex-${DISTNAME}-1.6
TEXLIVE_REV=	54779

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/datetime2-it-fulltext
COMMENT=	Italian full text styles for the datetime2 package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-datetime2-[0-9]*:../../time/tex-datetime2
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
