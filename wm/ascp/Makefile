# $NetBSD: Makefile,v 1.2 2001/02/17 17:21:30 wiz Exp $
#

DISTNAME=		ascp-1.0.3
CATEGORIES=		x11 wm
MASTER_SITES=		ftp://ftp.afterstep.org/apps/ascp/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://hubble.colorado.edu/~nwanua/htmldir/ascp.html
COMMENT=		Configuration utility for AfterStep

DEPENDS+=		afterstep-1.8.*:../../wm/afterstep
DEPENDS+=		gtk+-1.2.*:../../x11/gtk

GNU_CONFIGURE=		yes
USE_X11=		yes

CONFIGURE_ENV+=		GTK_CONFIG="${X11PREFIX}/bin/gtk-config"

IGNORE=			"Not for Afterstep 1.8.x!"

pre-configure:
	${RM} ${WRKSRC}/config.cache

post-install:
	@${CHMOD} a+x ${PREFIX}/share/afterstep/ascp/icons
	@${CHMOD} -R a+r ${PREFIX}/share/afterstep/ascp

.include "../../mk/bsd.pkg.mk"
