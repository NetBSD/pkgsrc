# $NetBSD: Makefile,v 1.4 2026/01/27 08:40:43 wiz Exp $

DISTNAME=	gkrellm-reminder-2.1.0
PKGREVISION=	3
CATEGORIES=	time sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL} # Upstream doesn't distribute tarballs.

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.srcbox.net/gkrellm/gkrellm-reminder
COMMENT=	GKrellM plugin to remind you of events
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
