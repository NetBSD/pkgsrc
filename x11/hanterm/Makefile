# $NetBSD: Makefile,v 1.27 2020/01/18 23:35:49 rillig Exp $

DISTNAME=	hanterm-3.1.6
PKGREVISION=	6
CATEGORIES=	x11 korean
MASTER_SITES=	http://download.kldp.net/hanterm/hanterm/3.1.6/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hanterm.kldp.net/
COMMENT=	X11R6-based xterm hacked for managing Korean languages

USE_IMAKE=	YES

SPECIAL_PERMS+=	bin/hanterm ${SETUID_ROOT_PERMS}

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
