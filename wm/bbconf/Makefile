# $NetBSD: Makefile,v 1.1.1.1 2002/03/18 23:02:30 wiz Exp $
#

DISTNAME=	bbconf-1.4
CATEGORIES=	wm
MASTER_SITES=	http://bbconf.sourceforge.net/code/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://bbconf.sourceforge.net/
COMMENT=	configuration tool for the blackbox window manager

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/admin/ltconfig

.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
