# $NetBSD: Makefile,v 1.15 2020/01/18 23:35:36 rillig Exp $
#

DISTNAME=	bbdate-0.2.4
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bbtools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bbtools.sourceforge.net/download.php?file=3
COMMENT=	Display the current date

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
