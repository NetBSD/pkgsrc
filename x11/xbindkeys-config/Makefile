# $NetBSD: Makefile,v 1.9 2004/10/03 00:18:39 tv Exp $

DISTNAME=	xbindkeys_config-0.1.2
PKGNAME=	xbindkeys-config-0.1.2
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://www.netchampagne.com/xbindkeys_config/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.netchampagne.com/xbindkeys_config/
COMMENT=	Tool to configure xbindkeys graphically

DEPENDS+=	xbindkeys-[0-9]*:../xbindkeys

USE_BUILDLINK3=		yes
USE_X11=		# defined

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
