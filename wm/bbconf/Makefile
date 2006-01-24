# $NetBSD: Makefile,v 1.13 2006/01/24 07:32:39 wiz Exp $
#

DISTNAME=	bbconf-1.4
PKGREVISION=	2
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
