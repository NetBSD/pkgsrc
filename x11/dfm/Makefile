# $NetBSD: Makefile,v 1.1.1.1 2001/08/05 00:23:14 hubertf Exp $
#

DISTNAME=	dfm-0.99.9
CATEGORIES=	x11
MASTER_SITES=	http://www.kaisersite.de/dfm/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.kaisersite.de/dfm/
COMMENT=	Desktop File Manager

USE_X11=	yes
WRKSRC=		${WRKDIR}/dfm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-imlib-prefix=${X11PREFIX} \
		--enable-imlib-icons \
		--with-gtk-prefix=${X11BASE}

post-install:
		${MV} ${PREFIX}/man/man1/dfm.1x ${PREFIX}/man/man1/dfm.1

.include "../../x11/gtk/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
