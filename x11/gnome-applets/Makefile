# $NetBSD: Makefile,v 1.13 2001/04/07 10:58:33 rh Exp $
#

DISTNAME=		gnome-applets-1.4.0.1
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/releases/gnome-1.4/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Applets for GNOME

BUILD_DEPENDS+=		xml-i18n-tools-*:../../textproc/xml-i18n-tools
DEPENDS+=		gnome-core>1.4.0:../../x11/gnome-core
DEPENDS+=		libgtop>=1.0.12:../../devel/libgtop

USE_GMAKE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=		-I${LOCALBASE}/include

AUTOGEN_ENV=		NOCONFIGURE=1
AUTOGEN_ENV+=		srcdir=${WRKSRC}

.include "../../mk/bsd.pkg.mk"
