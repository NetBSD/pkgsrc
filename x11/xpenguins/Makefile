# $NetBSD: Makefile,v 1.9 2001/10/23 13:15:10 jlam Exp $
#

DISTNAME=	xpenguins-2.1
CATEGORIES=	games x11
MASTER_SITES=	http://xpenguins.seul.org/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://xpenguins.seul.org/
COMMENT=	Little penguins walking along the tops of your windows

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../mk/x11.buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
