# $NetBSD: Makefile,v 1.12 2012/10/02 17:12:13 tron Exp $
#

DISTNAME=	gselt-1.2
PKGREVISION=	11
CATEGORIES=	x11
MASTER_SITES=	http://offog.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://offog.org/code/gselt.html
COMMENT=	Display a menu of actions that can be done with an X selection
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
