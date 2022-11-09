# $NetBSD: Makefile,v 1.6 2022/11/09 13:14:29 joerg Exp $
#

DISTNAME=		xkbdata-1.0.1
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=data/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Xorg keyboard maps and layouts

CONFLICTS+=		xkeyboard-config-[0-9]*

GNU_CONFIGURE=		yes

DEPENDS+=		xkbcomp-[0-9]*:../../x11/xkbcomp

.include "../../mk/bsd.pkg.mk"
