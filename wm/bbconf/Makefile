# $NetBSD: Makefile,v 1.5 2003/07/21 17:33:58 martti Exp $
#

DISTNAME=	bbconf-1.4
CATEGORIES=	wm
MASTER_SITES=	http://bbconf.sourceforge.net/code/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://bbconf.sourceforge.net/
COMMENT=	Configuration tool for the blackbox window manager

USE_BUILDLINK2=		YES
USE_X11=		YES

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/admin/ltconfig

.include "../../x11/qt2-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
