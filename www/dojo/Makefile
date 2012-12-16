# $NetBSD: Makefile,v 1.4 2012/12/16 01:52:38 obache Exp $
# FreeBSD Id: ports/www/dojo/Makefile,v 1.14 2011/08/20 17:27:37 ohauer Exp

DISTNAME=		dojo-release-1.7.2
PKGNAME=		dojo-1.7.2
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=	http://download.dojotoolkit.org/release-1.7.2/

LICENSE=		modified-bsd
MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dojotoolkit.org/
COMMENT=		Open-source DHTML toolkit written in JavaScript

NO_BUILD=		yes
USE_TOOLS+=		pax

.include "../../mk/bsd.prefs.mk"

REPLACE_BASH+=			dojox/mobile/build/build.sh
CONFDIR=				${PREFIX}/etc/httpd
WWWDIR=					${PREFIX}/share/httpd/dojo
INSTALLATION_DIRS+=		${WWWDIR} ${CONFDIR}

SUBST_CLASSES+=			dojo
SUBST_STAGE.dojo=		post-patch
SUBST_FILES.dojo=		dojo.conf
SUBST_VARS.dojo=		WWWDIR

PLIST_SUBST+=			WWWDIR=${WWWDIR:S/^${PREFIX}\///:Q}
PLIST_SUBST+=			CONFDIR=${CONFDIR:S/^${PREFIX}\///:Q}
CHECK_INTERPRETER=		no
CHECK_PERMS=			no

post-extract:
	${CP} ${FILESDIR}/dojo.conf.in ${WRKSRC}/dojo.conf

do-install:
	cd ${WRKSRC} && ${PAX} -wr dijit ${DESTDIR}${WWWDIR}/
	cd ${WRKSRC} && ${PAX} -wr dojo ${DESTDIR}${WWWDIR}/
	cd ${WRKSRC} && ${PAX} -wr dojox ${DESTDIR}${WWWDIR}/
	${INSTALL_DATA} ${WRKSRC}/dojo.conf ${DESTDIR}${CONFDIR}/

.include "../../www/apache22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
