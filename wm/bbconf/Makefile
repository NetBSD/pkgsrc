# $NetBSD: Makefile,v 1.2 2002/09/20 21:27:15 jlam Exp $
#

DISTNAME=	bbconf-1.4
CATEGORIES=	wm
MASTER_SITES=	http://bbconf.sourceforge.net/code/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://bbconf.sourceforge.net/
COMMENT=	configuration tool for the blackbox window manager

USE_BUILDLINK2=		YES
USE_X11=		YES

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/admin/ltconfig

.include "../../x11/qt2-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
