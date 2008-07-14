# $NetBSD: Makefile,v 1.22 2008/07/14 12:56:20 joerg Exp $
#

DISTNAME=	xpenguins-2.2
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	http://xpenguins.seul.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xpenguins.seul.org/
COMMENT=	Little penguins walking along the tops of your windows

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
