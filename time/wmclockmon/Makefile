# $NetBSD: Makefile,v 1.5 2007/01/16 23:11:52 joerg Exp $
#

DISTNAME=	wmclockmon-0.8.1
PKGREVISION=	1
CATEGORIES=	time x11
MASTER_SITES=   http://tnemeth.free.fr/projets/programmes/

MAINTAINER=	poff@sixbit.org
HOMEPAGE=	http://tnemeth.free.fr/projets/dockapps.html
COMMENT=	Windowmaker dockapp for time/date

GNU_CONFIGURE=	yes

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
