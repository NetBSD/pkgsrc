# $NetBSD: Makefile,v 1.3 2001/05/11 18:57:59 fredb Exp $
#

DISTNAME=		ascp-1.0.3
CATEGORIES=		x11 wm
MASTER_SITES=		ftp://ftp.afterstep.org/apps/ascp/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.princeton.edu/~ferguson/adw/ascp/
COMMENT=		Configuration utility for AfterStep

DEPENDS+=		afterstep-1.8.*:../../wm/afterstep
DEPENDS+=		gtk+-1.2.*:../../x11/gtk

GNU_CONFIGURE=		yes
USE_X11=		yes

CONFIGURE_ENV+=		GTK_CONFIG="${X11PREFIX}/bin/gtk-config"

# XXX Fix me. The development (currently cvs only) version of ascp
# XXX allegedly does work with afterstep-1.8.x.
IGNORE=		"${PKGNAME} is only for afterstep-1.6.x (obsolete)"

pre-configure:
	${RM} ${WRKSRC}/config.cache

post-install:
	@${CHMOD} a+x ${PREFIX}/share/afterstep/ascp/icons
	@${CHMOD} -R a+r ${PREFIX}/share/afterstep/ascp

.include "../../mk/bsd.pkg.mk"
