# $NetBSD: Makefile,v 1.1 2015/01/31 12:23:14 bouyer Exp $
#

DISTNAME=	mrbs-1.4.11
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mrbs}/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://mrbs.sourceforge.net/
COMMENT=	Meeting Room Booking System
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=5.3.0:../../converters/php-iconv

.include "options.mk"

USE_LANGUAGES=	# none
EGDIR=	${PREFIX}/share/examples/mrbs
CONF_FILES=	${EGDIR}/config.inc.php ${PREFIX}/share/mrbs/config.inc.php
CONF_FILES+=	${EGDIR}/site_faq/site_faq.html ${PREFIX}/share/mrbs/site_faq/site_faq.html
CONF_FILES+=	${EGDIR}/site_faq/site_faq_cs.html ${PREFIX}/share/mrbs/site_faq/site_faq_cs.html
CONF_FILES+=	${EGDIR}/site_faq/site_faq_de.html ${PREFIX}/share/mrbs/site_faq/site_faq_de.html
CONF_FILES+=	${EGDIR}/site_faq/site_faq_es.html ${PREFIX}/share/mrbs/site_faq/site_faq_es.html
CONF_FILES+=	${EGDIR}/site_faq/site_faq_fr.html ${PREFIX}/share/mrbs/site_faq/site_faq_fr.html
CONF_FILES+=	${EGDIR}/site_faq/site_faq_it.html ${PREFIX}/share/mrbs/site_faq/site_faq_it.html
CONF_FILES+=	${EGDIR}/site_faq/site_faq_nl.html ${PREFIX}/share/mrbs/site_faq/site_faq_nl.html
CONF_FILES+=	${EGDIR}/site_faq/site_faq_sv.html ${PREFIX}/share/mrbs/site_faq/site_faq_sv.html


NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/mrbs
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}/site_faq
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mrbs
	${INSTALL_DATA}	${WRKSRC}/web/config.inc.php  ${DESTDIR}${EGDIR}/
	${INSTALL_DATA}	${WRKSRC}/web/.htaccess  ${DESTDIR}${EGDIR}/
	for file in \
	    site_faq.html \
	    site_faq_cs.html \
	    site_faq_de.html \
	    site_faq_es.html \
	    site_faq_fr.html \
	    site_faq_it.html \
	    site_faq_nl.html \
	    site_faq_sv.html \
	    ; do ${INSTALL_DATA} ${WRKSRC}/web/site_faq/$$file ${DESTDIR}${EGDIR}/site_faq; \
	done


	for file in \
	    AUTHENTICATION \
	    COPYING \
	    ChangeLog \
	    INSTALL \
	    LANGUAGE \
	    NEWS \
	    README \
	    README.nwauth \
	    README.sqlapi \
	    UPGRADE \
	    auth_ldap.pl \
	    auth_ldapsearch.pl \
	    auth_pam.pl \
	    badpw.pl \
	    checklang.php \
	    convert_db_to_utf8.php \
	    crypt_passwd.example \
	    crypt_passwd.pl \
	    destroy.pg.sql \
	    grant.pg.sql \
	    help_report.html \
	    purge.my.sql \
	    purge.pg.sql \
	    sample-data.sql \
	    smb_auth.c \
	    tables.my.pre41.sql \
	    tables.my.sql \
	    tables.pg.pre73.sql \
	    tables.pg.sql \
	    testdata.php \
	    upgrade.my.sql \
	    upgrade2.my.sql \
	    upgrade2.pg.sql \
	    upgrade3.my.sql \
	    ; do ${INSTALL_DATA} ${WRKSRC}/$$file ${DESTDIR}${PREFIX}/share/doc/mrbs/; \
	done

	cd ${WRKSRC}/web && ${FIND} . -type f \
		\! -name '*.orig' \! -name config.inc.php  \! -name .htaccess \
		\! -path './site_faq/*' \
		-print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/share/mrbs

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
