# $NetBSD: Makefile,v 1.13 2005/03/18 13:02:49 wiz Exp $
#

DISTNAME=	galway-0.33
PKGREVISION=	7
CATEGORIES=	www x11 gnome
MASTER_SITES=	http://erin.netpedia.net/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://erin.netpedia.net/galway.html
COMMENT=	Web editor programmed in Scheme

DEPENDS+=	guile-gtk-0.19*:../../devel/guile14-gtk

USE_BUILDLINK3=	yes
NO_BUILD=	yes

do-configure:
	cd ${WRKSRC}; for i in *.scm; do				\
		${SED}	-e "s|/usr/local|${PREFIX}|g"			\
			-e "s|^\(exec\) guile |\1 ${PREFIX}/${GUILE14_SUBDIR}/bin/guile |g"	\
			-e "s|guile-config|${PREFIX}/${GUILE14_SUBDIR}/bin/guile |g"		\
			< $$i > $$i.cfg;				\
		${MV} $$i.cfg $$i;					\
		${CHMOD} +x $$i;					\
	done

do-install:
	cd ${WRKSRC} && ./install.scm

.include "../../lang/guile14/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
