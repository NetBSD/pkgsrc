# $NetBSD: Makefile,v 1.4 1999/10/27 17:14:10 agc Exp $

DISTNAME=		ascp-1.0.2
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.afterstep.org/apps/ascp/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://hubble.colorado.edu/~nwanua/htmldir/ascp.html

BROKEN=			Version mismatches for asclock

DEPENDS+=		afterstep-1.6.10:../../x11/afterstep
DEPENDS+=		gtk+-1.2.*:../../x11/gtk

USE_X11BASE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		"LIBS= -lgnumalloc"

post-install:
	@${CHMOD} a+x ${PREFIX}/share/afterstep/ascp/icons
	@${CHMOD} -R a+r ${PREFIX}/share/afterstep/ascp

.include "../../mk/bsd.pkg.mk"
