# $NetBSD: Makefile,v 1.1.1.1 1999/12/20 12:02:55 rh Exp $
#

DISTNAME=	galway-0.33
CATEGORIES=	www x11 gnome
MASTER_SITES=	http://erin.netpedia.net/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://erin.netpedia.net/galway.html

DEPENDS+=	guile-gtk-*:../../devel/guile-gtk

NO_BUILD=	YES

do-configure:
	(cd ${WRKSRC} ; for i in *.scm ; do				\
	    ${SED} -e 's:/usr/local:${PREFIX}:g' <$$i >$$i.cfg ;	\
	    ${MV} $$i.cfg $$i ;						\
	    ${CHMOD} +x $$i ;						\
	done)

do-install:
	(cd ${WRKSRC} && ./install.scm)

.include "../../mk/bsd.pkg.mk"
