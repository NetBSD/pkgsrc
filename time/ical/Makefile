# $NetBSD: Makefile,v 1.2 2000/12/18 00:21:55 wiz Exp $
# $FreeBSD Id: Makefile,v 1.15 1998/02/07 22:59:16 hoek Exp
#

DISTNAME=	ical-2.2.1
CATEGORIES=	time
MASTER_SITES=	http://members.nbci.com/majahj/ical/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://members.nbci.com/majahj/ical/

DEPENDS+=	tk>=8.3.2:../../x11/tk

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-tclconfig=${PREFIX}/lib \
		--with-tclsh=${PREFIX}/bin/tclsh \
		--with-tkconfig=${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
