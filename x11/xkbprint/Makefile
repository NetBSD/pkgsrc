# $NetBSD: Makefile,v 1.3 2015/04/17 07:11:36 wiz Exp $

DISTNAME=		xkbprint-1.0.4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Generate printable description of a XKB keyboard description

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
