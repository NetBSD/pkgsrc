# $NetBSD: Makefile,v 1.6 1998/10/15 19:51:09 agc Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1996/11/15 09:55:44 asami Exp
#

DISTNAME=	xgas
PKGNAME=        xgas-1.0
CATEGORIES=     x11
MASTER_SITES=   ftp://ftp.tut.ac.jp/.h3/X11/X11R6/contrib/programs/

MAINTAINER=     nakai@mlab.t.u-tokyo.ac.jp

USE_IMAKE=      yes

post-install:
	@chmod 755 ${PREFIX}/bin/xgas
	@chown bin.bin ${PREFIX}/bin/xgas

.include "../../mk/bsd.pkg.mk"
