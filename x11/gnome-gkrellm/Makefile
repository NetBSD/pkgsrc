# $NetBSD: Makefile,v 1.5 2003/05/02 11:57:00 wiz Exp $

DISTNAME=	gkrellm-gnome
PKGNAME=	gnome-gkrellm-0.1
PKGREVISION=	2
CATEGORIES=	gnome sysutils
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/Plugins/

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://web.wt.net/~billw/gkrellm/Plugins.html
COMMENT=	gkrellm gnome plugin

DEPENDS+=       gkrellm>=1.2.13nb1:../../sysutils/gkrellm
DEPENDS+=	gnome-libs>=1.4.1.4nb4:../gnome-libs

USE_GMAKE=	yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../mk/bsd.pkg.mk"
