# $NetBSD: Makefile,v 1.6 2000/06/15 11:28:55 hubertf Exp $

DISTNAME=		ascp-1.0.2
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.afterstep.org/apps/ascp/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://hubble.colorado.edu/~nwanua/htmldir/ascp.html

DEPENDS+=		afterstep-1.8.*:../../x11/afterstep
DEPENDS+=		gtk+-1.2.*:../../x11/gtk

USE_X11BASE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		"LIBS= -lgnumalloc"

post-install:
	@${CHMOD} a+x ${PREFIX}/share/afterstep/ascp/icons
	@${CHMOD} -R a+r ${PREFIX}/share/afterstep/ascp

.include "../../mk/bsd.pkg.mk"
