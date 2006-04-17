# $NetBSD: Makefile,v 1.16 2006/04/17 13:46:49 wiz Exp $
#

DISTNAME=	bbconf-1.4
PKGREVISION=	4
CATEGORIES=	wm
MASTER_SITES=	http://bbconf.sourceforge.net/code/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bbconf.sourceforge.net/
COMMENT=	Configuration tool for the blackbox window manager


GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/admin/ltconfig

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/qt2-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
