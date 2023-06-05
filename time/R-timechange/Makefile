# $NetBSD: Makefile,v 1.1 2023/06/05 11:41:20 mef Exp $

R_PKGNAME=	timechange
R_PKGVER=	0.2.0
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Efficient Manipulation of Date-Times
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++11

.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
