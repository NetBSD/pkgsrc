# $NetBSD: Makefile,v 1.11 2011/04/22 13:44:53 obache Exp $
#

DISTNAME=	gchore-1.0
PKGREVISION=	9
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gchore/}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://gchore.sourceforge.net/
COMMENT=	Chore reminder tool with gtk UI

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
INSTALLATION_DIRS=	bin

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
