# $NetBSD: Makefile,v 1.42 2004/04/26 05:51:57 snj Exp $
#

DISTNAME=		gnome-applets-1.4.0.4
PKGREVISION=		11
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-applets/1.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Applets for GNOME

BUILD_DEPENDS+=		xml-i18n-tools-[0-9]*:../../textproc/xml-i18n-tools

BUILDLINK_DEPENDS.gnome-panel=	gnome-panel<2.0

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES

.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
