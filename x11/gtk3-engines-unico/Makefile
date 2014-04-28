# $NetBSD: Makefile,v 1.1 2014/04/28 01:59:52 rodent Exp $

DISTNAME=	unico-1.0.2
PKGNAME=	gtk3-engines-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/unico/1.0/1.0.2/+download/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://launchpad.net/unico
COMMENT=	Unico Gtk+ Theming Engine for GTK+ 3.0
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "options.mk"

.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
