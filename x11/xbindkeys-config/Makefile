# $NetBSD: Makefile,v 1.1.1.1 2002/07/11 14:25:25 tron Exp $

DISTNAME=	xbindkeys_config-0.1.2
PKGNAME=	xbindkeys-config-0.1.2
CATEGORIES=	x11
MASTER_SITES=	http://www.netchampagne.com/xbindkeys_config/

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://www.netchampagne.com/xbindkeys_config/
COMMENT=	Tool to configure xbindkeys graphically

DEPENDS+=	xbindkeys-[0-9]*:../xbindkeys

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
