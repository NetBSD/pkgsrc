#
# $NetBSD: Makefile,v 1.1.1.1 2001/04/23 20:05:44 kim Exp $
#

DISTNAME=		cvsweb-1.93
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

do-build:
	${MV} ${WRKSRC}/cvsweb.cgi ${WRKSRC}/cvsweb.cgi.bak
	${SED} -e 's,/usr/bin/perl,${PERL5},'				\
	    -e 's,/usr/local/web/apache/conf/,${APACHE_SYSCONFDIR},'	\
	    ${WRKSRC}/cvsweb.cgi.bak > ${WRKSRC}/cvsweb.cgi

pre-install:
	${SED}	-e "s|@CAT@|${CAT}|g"					\
		-e "s|@CP@|${CP}|g"					\
		-e "s|@RM@|${RM}|g"					\
		-e "s|@APACHE_SYSCONFDIR@|${APACHE_SYSCONFDIR}|g"	\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s|@CAT@|${CAT}|g"					\
		-e "s|@CHMOD@|${CHMOD}|g"				\
		-e "s|@CP@|${CP}|g"					\
		-e "s|@APACHE_SYSCONFDIR@|${APACHE_SYSCONFDIR}|g"	\
		${PKGDIR}/INSTALL > ${INSTALL_FILE}

do-install:
	${INSTALL_SCRIPT_DIR} ${PREFIX}/libexec/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/cvsweb.cgi ${PREFIX}/libexec/cgi-bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cvsweb
	${INSTALL_DATA} ${WRKSRC}/cvsweb.conf \
		${PREFIX}/share/examples/cvsweb/cvsweb.conf.default
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
