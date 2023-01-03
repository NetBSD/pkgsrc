# $NetBSD: Makefile,v 1.48 2023/01/03 17:38:19 wiz Exp $
#

DISTNAME=	gchore-1.0
PKGREVISION=	43
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gchore/}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://gchore.sourceforge.net/
COMMENT=	Chore reminder tool with gtk UI

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
INSTALLATION_DIRS=	bin

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
