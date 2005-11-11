# $NetBSD: Makefile,v 1.12 2005/11/11 19:13:09 tonio Exp $
#

DISTNAME=	bbconf-1.4
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	http://bbconf.sourceforge.net/code/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://bbconf.sourceforge.net/
COMMENT=	Configuration tool for the blackbox window manager


GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/admin/ltconfig

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/qt2-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
