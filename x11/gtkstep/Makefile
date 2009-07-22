# $NetBSD: Makefile,v 1.25 2009/07/22 09:01:54 wiz Exp $

DISTNAME=		gtkstep-1.10
PKGREVISION=		6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		# gone AWOL in 2001 or so
COMMENT=		GTK theme-engine to yield a NEXTSTEP(tm) look and feel

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

post-install:
	${RM} -f ${PREFIX}/share/themes/Step/gtk/gtkrc.in
	${INSTALL_DATA} ${WRKSRC}/step/Theme/gtk/gtkrc \
	  ${PREFIX}/share/themes/Step/gtk

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
