# $NetBSD: Makefile,v 1.33 2008/04/30 13:38:16 jmmv Exp $
#

DISTNAME=	evolution-webcal-2.12.0
PKGREVISION=	1
CATEGORIES=	time gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/evolution-webcal/2.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.novell.com/products/desktop/features/evolution.html
COMMENT=	GNOME URL handler for web-published iCal calendar files

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	YES

GCONF_SCHEMAS=		evolution-webcal.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../net/libsoup-devel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
