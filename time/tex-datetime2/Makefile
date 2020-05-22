# $NetBSD: Makefile,v 1.1 2020/05/22 01:50:57 markd Exp $

DISTNAME=	datetime2
PKGNAME=	tex-${DISTNAME}-1.5.6
TEXLIVE_REV=	54080

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/datetime2
COMMENT=	Formats for dates, times and time zones
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-tracklang-[0-9]*:../../print/tex-tracklang
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
