# $NetBSD: Makefile,v 1.2 2002/09/23 23:05:42 jlam Exp $

DISTNAME=	xbindkeys_config-0.1.2
PKGNAME=	xbindkeys-config-0.1.2
CATEGORIES=	x11
MASTER_SITES=	http://www.netchampagne.com/xbindkeys_config/

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://www.netchampagne.com/xbindkeys_config/
COMMENT=	Tool to configure xbindkeys graphically

DEPENDS+=	xbindkeys-[0-9]*:../xbindkeys

USE_BUILDLINK2=		# defined
USE_X11=		# defined

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
