# $NetBSD: Makefile,v 1.3 2002/12/24 06:10:32 wiz Exp $
#

DISTNAME=		gtk-engines-1.9.0
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtk-engines/1.9/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme engines for GTK+ version 2

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_X11=		yes

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
