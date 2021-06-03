# $NetBSD: Makefile,v 1.2 2021/06/03 06:35:06 markd Exp $

DISTNAME=	datetime2
PKGNAME=	tex-${DISTNAME}-1.5.7
TEXLIVE_REV=	58590

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
