# $NetBSD: Makefile,v 1.23 2002/11/02 02:42:05 rh Exp $
#

DISTNAME=		gnome-applets-1.4.0.4
PKGREVISION=		2
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-applets/1.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Applets for GNOME

BUILD_DEPENDS+=		xml-i18n-tools-[0-9]*:../../textproc/xml-i18n-tools

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=        --localstatedir=${SCROLLKEEPER_DATADIR}

.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../devel/libgtop/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
