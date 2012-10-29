# $NetBSD: Makefile,v 1.28 2012/10/29 05:06:20 asau Exp $

DISTNAME=		gtkstep-1.10
PKGREVISION=		7
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		# gone AWOL in 2001 or so
COMMENT=		GTK theme-engine to yield a NEXTSTEP(tm) look and feel

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/share/themes/Step/gtk/gtkrc.in
	${INSTALL_DATA} ${WRKSRC}/step/Theme/gtk/gtkrc \
	  ${DESTDIR}${PREFIX}/share/themes/Step/gtk

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
