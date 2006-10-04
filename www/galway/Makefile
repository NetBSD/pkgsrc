# $NetBSD: Makefile,v 1.16 2006/10/04 22:04:09 wiz Exp $
#

DISTNAME=	galway-0.33
PKGREVISION=	8
CATEGORIES=	www x11 gnome
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rh@NetBSD.org
COMMENT=	Web editor programmed in Scheme

DEPENDS+=	guile-gtk-0.19*:../../devel/guile14-gtk

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
