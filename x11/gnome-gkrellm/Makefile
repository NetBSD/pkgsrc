# $NetBSD: Makefile,v 1.3 2001/11/14 05:02:47 damon Exp $

DISTNAME=	gkrellm-gnome
PKGNAME=	gnome-gkrellm-0.1
CATEGORIES=	gnome sysutils
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/Plugins/

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://web.wt.net/~billw/gkrellm/Plugins.html
COMMENT=	gkrellm gnome plugin

DEPENDS+=       gkrellm-1.2.*:../../sysutils/gkrellm
DEPENDS+=	gnome-libs>=1.2.1:../gnome-libs

USE_GMAKE=	yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../mk/bsd.pkg.mk"
