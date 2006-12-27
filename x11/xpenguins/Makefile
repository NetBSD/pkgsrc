# $NetBSD: Makefile,v 1.21 2006/12/27 13:37:46 joerg Exp $
#

DISTNAME=	xpenguins-2.2
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	http://xpenguins.seul.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xpenguins.seul.org/
COMMENT=	Little penguins walking along the tops of your windows

GNU_CONFIGURE=	YES

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
