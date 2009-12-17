# $NetBSD: Makefile,v 1.26 2009/12/17 18:31:46 abs Exp $

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

PKG_DESTDIR_SUPPORT= user-destdir

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/share/themes/Step/gtk/gtkrc.in
	${INSTALL_DATA} ${WRKSRC}/step/Theme/gtk/gtkrc \
	  ${DESTDIR}${PREFIX}/share/themes/Step/gtk

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
