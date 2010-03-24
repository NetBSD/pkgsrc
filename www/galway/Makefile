# $NetBSD: Makefile,v 1.21 2010/03/24 19:43:29 asau Exp $
#

DISTNAME=	galway-0.33
PKGREVISION=	13
CATEGORIES=	www x11 gnome
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rh@NetBSD.org
COMMENT=	Web editor programmed in Scheme

NO_BUILD=	yes

do-configure:
	cd ${WRKSRC}; for i in *.scm; do				\
		${SED}	-e "s|/usr/local|${PREFIX}|g"			\
			-e "s|^\(exec\) guile |\1 ${PREFIX}/${GUILE_SUBDIR}/bin/guile |g"	\
			-e "s|^\(exec\) guile-gtk |\1 ${PREFIX}/${GUILE_SUBDIR}/bin/guile |g"	\
			-e "s|guile-config|${PREFIX}/${GUILE_SUBDIR}/bin/guile |g"		\
			-e "s|(gtk |(gtk-1.2 |g"			\
			-e "s|(eval |(primitive-eval |g"		\
			-e "s|(gtk-pixmap-new|&-from-file|g"		\
			< $$i > $$i.cfg;				\
		${MV} $$i.cfg $$i;					\
		${CHMOD} +x $$i;					\
	done

do-install:
	cd ${WRKSRC} && ./install.scm

.include "../../devel/guile-gtk/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
