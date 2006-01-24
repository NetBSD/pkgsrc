# $NetBSD: Makefile,v 1.14 2006/01/24 07:32:39 wiz Exp $
#

DISTNAME=	evolution-webcal-2.4.1
PKGREVISION=	3
CATEGORIES=	time gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/evolution-webcal/2.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.novell.com/products/evolution/
COMMENT=	GNOME URL handler for web-published iCal calendar files

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	YES

GCONF2_SCHEMAS=		evolution-webcal.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../net/libsoup-devel/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
