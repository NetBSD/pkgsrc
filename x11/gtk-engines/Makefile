# $NetBSD: Makefile,v 1.7 2000/10/17 23:47:01 jlam Exp $

DISTNAME=		gtk-engines-0.10
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gtk-engines/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		imlib-*:../../graphics/imlib

GNU_CONFIGURE=		# defined
USE_X11BASE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
