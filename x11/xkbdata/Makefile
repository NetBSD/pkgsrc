# $NetBSD: Makefile,v 1.5 2020/01/18 23:36:09 rillig Exp $
#

DISTNAME=		xkbdata-1.0.1
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=data/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Xorg keyboard maps and layouts

CONFLICTS+=		xkeyboard-config-[0-9]*

GNU_CONFIGURE=		yes

DEPENDS+=		xkbcomp-[0-9]*:../../x11/xkbcomp

.include "../../mk/bsd.pkg.mk"
