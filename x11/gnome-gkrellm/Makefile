# $NetBSD: Makefile,v 1.12 2004/03/12 05:50:26 snj Exp $

DISTNAME=	gkrellm-gnome
PKGNAME=	gnome-gkrellm-0.1
PKGREVISION=	4
CATEGORIES=	gnome sysutils
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/Plugins/

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://web.wt.net/~billw/gkrellm/Plugins.html
COMMENT=	gkrellm gnome plugin

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
