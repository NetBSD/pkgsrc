# $NetBSD: Makefile,v 1.11 2005/11/11 18:50:25 tonio Exp $
#

DISTNAME=	bbconf-1.10
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bbconf/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://bbconf.sourceforge.net/
COMMENT=	Configuration tool for the blackbox window manager


GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
