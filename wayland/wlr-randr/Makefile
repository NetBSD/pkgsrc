# $NetBSD: Makefile,v 1.1 2026/04/15 07:52:28 kikadf Exp $

DISTNAME=		wlr-randr-0.5.0
CATEGORIES=		wayland
MASTER_SITE_GITLAB=	https://gitlab.freedesktop.org/
MASTER_SITES=		${MASTER_SITE_GITLAB:=emersion/}
GITLAB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		kikadf.01@gmail.com
HOMEPAGE=		https://gitlab.freedesktop.org/emersion/wlr-randr
COMMENT=		Utility to manage outputs of a Wayland compositor
LICENSE=		mit

USE_TOOLS+=		pkg-config
WRKSRC=			${WRKDIR}/wlr-randr-${GITLAB_TAG}

.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../mk/bsd.pkg.mk"
