# $NetBSD: Makefile,v 1.18.2.1 2002/06/23 19:05:00 jlam Exp $
#

DISTNAME=		gnome-applets-1.4.0.4
PKGREVISION=		1
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-applets/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Applets for GNOME

BUILD_DEPENDS+=		xml-i18n-tools-[0-9]*:../../textproc/xml-i18n-tools
DEPENDS+=		gnome-core>=1.4.0.4nb1:../../x11/gnome-core
DEPENDS+=		libgtop>=1.0.12nb2:../../devel/libgtop

USE_GMAKE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
CPPFLAGS+=		-I${LOCALBASE}/include

AUTOGEN_ENV=		NOCONFIGURE=1
AUTOGEN_ENV+=		srcdir=${WRKSRC}

.include "../../mk/bsd.pkg.mk"
