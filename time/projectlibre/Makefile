# $NetBSD: Makefile,v 1.6 2023/07/11 05:40:17 nia Exp $

DISTNAME=	projectlibre-1.9.3
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=projectlibre/}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.projectlibre.org/
COMMENT=	Project management software

USE_TOOLS+=	bash:run pax
USE_JAVA=	run
USE_JAVA2=	7

REPLACE_BASH=	projectlibre.sh

SUBST_CLASSES+=			set-java set-base

SUBST_STAGE.set-java=		post-configure
SUBST_MESSAGE.set-java=		Setting Java path.
SUBST_FILES.set-java=		projectlibre.sh
SUBST_SED.set-java=		-e '/^JAVA_EXE=/s,java,${PKG_JAVA_HOME}/bin/java,'

SUBST_STAGE.set-base=		post-configure
SUBST_MESSAGE.set-base=		Setting package base path.
SUBST_FILES.set-base=		projectlibre.sh
SUBST_SED.set-base=		-e '/^PROJECTLIBRE_HOME0=/s,^.*$$,PROJECTLIBRE_HOME0=${PREFIX}/share/${PKGBASE},'

NO_BUILD=	yes

INSTALLATION_DIRS=	bin share/${PKGBASE}

do-install:
	cd ${WRKSRC} && ${PAX} -rwpm . ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${LN} -sf ${PREFIX}/share/${PKGBASE}/projectlibre.sh ${DESTDIR}${PREFIX}/bin/projectlibre

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
