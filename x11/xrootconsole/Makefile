# $NetBSD: Makefile,v 1.1.1.1 2015/04/20 20:21:32 cheusov Exp $

DISTNAME=	xrootconsole-0.6
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xrootconsole/}

MAINTAINER=	inittab@unixdev.net
HOMEPAGE=	http://xrootconsole.sourceforge.net/
COMMENT=	Windowless XConsole
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
