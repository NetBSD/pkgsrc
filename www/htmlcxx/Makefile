# $NetBSD: Makefile,v 1.1 2014/02/16 22:58:51 wiz Exp $

DISTNAME=	htmlcxx-0.85
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=htmlcxx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://htmlcxx.sourceforge.net/
COMMENT=	Simple non-validating CSS1 and HTML parser for C++
LICENSE=	gnu-lgpl-v2 AND apache-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	htmlcxx.pc.in

.include "../../mk/bsd.pkg.mk"
