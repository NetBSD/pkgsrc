# $NetBSD: Makefile,v 1.12 2009/01/23 21:14:17 jschauma Exp $
#

DISTNAME=	bbdate-0.2.4
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bbtools/}

MAINTAINER=	pkgsrc-users@@NetBSD.org
HOMEPAGE=	http://bbtools.sourceforge.net/download.php?file=3
COMMENT=	Display the current date

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
