# $NetBSD: Makefile,v 1.3 2016/07/05 19:27:02 ryoon Exp $
#

DISTNAME=	gwt-2.7.0
CATEGORIES=	www
MASTER_SITES=	http://storage.googleapis.com/gwt-releases/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.gwtproject.org/
COMMENT=	Google Web Toolkit
LICENSE=	apache-2.0

NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_JAVA=	run
USE_JAVA2=	yes

USE_TOOLS+=	pax

GWTDOCDIR=	share/doc/gwt
GWTDIR=		lib/java/gwt

INSTALLATION_DIRS=	bin ${GWTDOCDIR} ${GWTDIR}

SUBST_CLASSES+=		gwt
SUBST_STAGE.gwt=	pre-configure
SUBST_MESSAGE.gwt=	Fix for GWT
SUBST_FILES.gwt+=	i18nCreator
SUBST_FILES.gwt+=	webAppCreator
SUBST_SED.gwt=		-e 's,java ,${PKG_JAVA_HOME}/bin/java ,g'
SUBST_SED.gwt+=		-e 's,HOMEDIR=.*,HOMEDIR=${PREFIX}/${GWTDIR};,g'
SUBST_SED.gwt+=		-e 's,APPDIR=.*,APPDIR=${PREFIX}/${GWTDIR};,g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/i18nCreator ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/webAppCreator ${DESTDIR}${PREFIX}/bin

	${INSTALL_DATA} ${WRKSRC}/*jar ${DESTDIR}${PREFIX}/${GWTDIR}
	${INSTALL_DATA} ${WRKSRC}/*dtd ${DESTDIR}${PREFIX}/${GWTDIR}
	${INSTALL_DATA} ${WRKSRC}/*dll ${DESTDIR}${PREFIX}/${GWTDIR}
	${INSTALL_DATA} ${WRKSRC}/*dll ${DESTDIR}${PREFIX}/${GWTDIR}

	cd ${WRKSRC} && pax -rw -pmp \
		doc samples COPYING COPYING.html \
		about.html about.txt release_notes.html \
		${DESTDIR}${PREFIX}/${GWTDOCDIR}

.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
