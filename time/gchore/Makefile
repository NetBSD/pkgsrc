# $NetBSD: Makefile,v 1.73 2026/11/11 11:56:03 wiz Exp $
#

DISTNAME=	gchore-1.0
PKGREVISION=	67
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gchore/}

MAINTAINER=	root@garbled.net
HOMEPAGE=	https://gchore.sourceforge.net/
COMMENT=	Chore reminder tool with gtk UI

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
INSTALLATION_DIRS=	bin

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
