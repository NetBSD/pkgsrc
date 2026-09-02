# $NetBSD: Makefile,v 1.48 2026/09/02 19:05:07 wiz Exp $
#

DISTNAME=	gselt-1.2
PKGREVISION=	46
CATEGORIES=	x11
MASTER_SITES=	http://offog.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://offog.org/code/gselt.html
COMMENT=	Display a menu of actions that can be done with an X selection
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
