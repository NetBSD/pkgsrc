# $NetBSD: Makefile,v 1.6 2000/08/15 14:17:44 wiz Exp $

DISTNAME=		gtk-engines-0.8
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gtk-engines/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		imlib-*:../../graphics/imlib

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
