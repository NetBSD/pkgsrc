#
# $NetBSD: Makefile,v 1.4 2001/10/15 17:25:09 martti Exp $
#

DISTNAME=		cvsweb-1.112
CATEGORIES=		net
MASTER_SITES=		http://stud.fh-heilbronn.de/~zeller/download/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://stud.fh-heilbronn.de/~zeller/cgi/cvsweb.cgi/
COMMENT=		Web interface for browsing a CVS repository

DEPENDS+=		apache{,6}-[0-9]*:../../www/apache

USE_PERL5=		# defined

WRKSRC=			${WRKDIR}/cvsweb
NO_CONFIGURE=		# defined

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

.include "../../mk/bsd.prefs.mk"

APACHE_SYSCONFDIR?=	${LOCALBASE}/etc/httpd

FILES_SUBST=		APACHE_SYSCONFDIR=${APACHE_SYSCONFDIR}
FILES_SUBST+=		CAT=${CAT:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

do-build:
	${MV} ${WRKSRC}/cvsweb.cgi ${WRKSRC}/cvsweb.cgi.bak
	${SED}	-e 's,/usr/bin/perl,${PERL5},'				\
		-e 's,/usr/local/web/apache/conf/,${APACHE_SYSCONFDIR}/,' \
	    ${WRKSRC}/cvsweb.cgi.bak > ${WRKSRC}/cvsweb.cgi

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

do-install:
	${INSTALL_SCRIPT_DIR} ${PREFIX}/libexec/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/cvsweb.cgi ${PREFIX}/libexec/cgi-bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cvsweb
	${INSTALL_DATA} ${WRKSRC}/cvsweb.conf \
		${PREFIX}/share/examples/cvsweb/cvsweb.conf.default
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
