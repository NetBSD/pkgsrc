# $NetBSD: Makefile,v 1.1 2020/05/22 01:50:58 markd Exp $

DISTNAME=	datetime2-en-fulltext
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	36705

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/datetime2-en-fulltext
COMMENT=	English Full Text styles for the datetime2 package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-fmtcount-[0-9]*:../../print/tex-fmtcount
DEPENDS+=	tex-datetime2-[0-9]*:../../time/tex-datetime2

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
