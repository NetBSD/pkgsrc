# $NetBSD: Makefile,v 1.3 2020/01/18 23:35:43 rillig Exp $

DISTNAME=	htmlcxx-0.85
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=htmlcxx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://htmlcxx.sourceforge.net/
COMMENT=	Simple non-validating CSS1 and HTML parser for C++
LICENSE=	gnu-lgpl-v2 AND apache-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	htmlcxx.pc.in

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
