# $NetBSD: Makefile,v 1.42 2010/07/20 02:08:35 obache Exp $
#

DISTNAME=	evolution-webcal-2.28.0
PKGREVISION=	2
CATEGORIES=	time gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/evolution-webcal/2.28/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.novell.com/products/desktop/features/evolution.html
COMMENT=	GNOME URL handler for web-published iCal calendar files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	YES

GCONF_SCHEMAS=		evolution-webcal.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
