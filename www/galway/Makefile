# $NetBSD: Makefile,v 1.5 2003/05/02 11:56:41 wiz Exp $
#

DISTNAME=	galway-0.33
PKGREVISION=	2
CATEGORIES=	www x11 gnome
MASTER_SITES=	http://erin.netpedia.net/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://erin.netpedia.net/galway.html
COMMENT=	Web editor programmed in Scheme

DEPENDS+=	guile-gtk>=0.19nb2:../../devel/guile-gtk

USE_BUILDLINK2=	yes
NO_BUILD=	yes

do-configure:
	cd ${WRKSRC}; for i in *.scm; do				\
		${SED}	-e "s|/usr/local|${PREFIX}|g"			\
			-e "s|^\(exec\) guile |\1 ${GUILE14} |g"	\
			-e "s|guile-config|${GUILE14_CONFIG} |g"	\
			< $$i > $$i.cfg;				\
		${MV} $$i.cfg $$i;					\
		${CHMOD} +x $$i;					\
	done

do-install:
	cd ${WRKSRC} && ./install.scm

.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
