# $NetBSD: Makefile,v 1.4 2002/03/13 17:37:56 fredb Exp $

DISTNAME=	gkrellm-gnome
PKGNAME=	gnome-gkrellm-0.1
PKGREVISION=	1
CATEGORIES=	gnome sysutils
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/Plugins/

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://web.wt.net/~billw/gkrellm/Plugins.html
COMMENT=	gkrellm gnome plugin

DEPENDS+=       gkrellm-1.2.*:../../sysutils/gkrellm
DEPENDS+=	gnome-libs>=1.4.1.2nb1:../gnome-libs

USE_GMAKE=	yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../mk/bsd.pkg.mk"
