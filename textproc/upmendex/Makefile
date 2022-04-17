# $NetBSD: Makefile,v 1.5 2022/04/17 10:51:47 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	upmendex-1.00
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/t-tk/upmendex-package/
COMMENT=	Multilingual index processor
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/upmendex

WRKSRC=	${WRKDIR}/${DISTNAME}/texk/upmendex

CONFIGURE_ARGS+=	--with-system-kpathsea
CONFIGURE_ARGS+=	--with-system-icu

.include "../../print/kpathsea/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
