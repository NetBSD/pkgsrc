# $NetBSD: Makefile,v 1.2 2017/09/06 10:40:36 wiz Exp $

DISTNAME=	xrootconsole-0.6
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xrootconsole/}

MAINTAINER=	inittab@unixdev.net
#HOMEPAGE=	http://xrootconsole.sourceforge.net/
COMMENT=	Windowless XConsole
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
