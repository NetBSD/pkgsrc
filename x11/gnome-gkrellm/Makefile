# $NetBSD: Makefile,v 1.9 2004/01/03 18:49:56 reed Exp $

DISTNAME=	gkrellm-gnome
PKGNAME=	gnome-gkrellm-0.1
PKGREVISION=	4
CATEGORIES=	gnome sysutils
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/Plugins/

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://web.wt.net/~billw/gkrellm/Plugins.html
COMMENT=	gkrellm gnome plugin

USE_BUILDLINK2=	yes
USE_GMAKE=	yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../sysutils/gkrellm/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
