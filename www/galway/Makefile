# $NetBSD: Makefile,v 1.3 2001/09/27 23:18:52 jlam Exp $
#

DISTNAME=	galway-0.33
CATEGORIES=	www x11 gnome
MASTER_SITES=	http://erin.netpedia.net/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://erin.netpedia.net/galway.html
COMMENT=	Web editor programmed in Scheme

DEPENDS+=	guile-gtk-[0-9]*:../../devel/guile-gtk

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
