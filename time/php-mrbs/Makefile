# $NetBSD: Makefile,v 1.6 2024/02/28 16:41:42 taca Exp $
#

DISTNAME=	mrbs-1.11.4
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	time www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mrbs/}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mrbs.sourceforge.io/
COMMENT=	Meeting Room Booking System
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pax

DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=${PHP_BASE_VERS}:../../converters/php-iconv

.include "options.mk"

USE_LANGUAGES=	# none

EGDIR=		share/examples/mrbs
DOCDIR=		share/doc/mrbs
MRBSDIR=	share/mrbs

CONF_FILES+=	${EGDIR}/config.inc.php ${MRBSDIR}/config.inc.php

.for f in ${FAQ_FILES}
CONF_FILES+=	${EGDIR}/site_faq/${f} ${MRBSDIR}/site_faq/${f}
.endfor

FAQ_FILES=	site_faq.html site_faq_cs.html site_faq_de.html \
		site_faq_es.html site_faq_fr.html site_faq_it.html \
		site_faq_nl.html site_faq_sv.html

PLIST_SUBST+=		EGDIR=${EGDIR} DOCDIR=${DOCDIR} MRBSDIR=${MRBSDIR}
PRINT_PLIST_AWK+=	/^${DOCDIR:S|/|\\/|g}/ \
			{ sub(/^${DOCDIR:S|/|\\/|g}/, "$${DOCDIR}"); }
PRINT_PLIST_AWK+=	/^${EGDIR:S|/|\\/|g}/ \
			{ sub(/^${EGDIR:S|/|\\/|g}/, "$${EGDIR}"); }
PRINT_PLIST_AWK+=	/^${MRBSDIR:S|/|\\/|g}/ \
			{ sub(/^${MRBSDIR:S|/|\\/|g}/, "$${MRBSDIR}"); }

INSTALLATION_DIRS+=	${MRBSDIR} ${EGDIR}/site_faq ${DOCDIR}

NO_BUILD=	yes

pre-install:
	${TEST} -f ${WRKSRC}/web/config.inc.php-sample && \
		${MV} ${WRKSRC}/web/config.inc.php-sample \
			${WRKSRC}/web/config.inc.php
	${RM} -f ${WRKSRC}/web/.htaccess*

do-install:
	${INSTALL_DATA}	${WRKSRC}/web/config.inc.php ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA}	${FILESDIR}/ht-access \
		${DESTDIR}${PREFIX}/${MRBSDIR}/.htaccess
	for file in ${FAQ_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/web/site_faq/$$file \
		${DESTDIR}${PREFIX}/${EGDIR}/site_faq; \
	done
	for file in ${WRKSRC}/*; do \
		if ${TEST} -f $$file ; then \
			${INSTALL_DATA} $$file ${DESTDIR}${PREFIX}/${DOCDIR}; \
		fi; \
	done
	cd ${WRKSRC}/web && ${FIND} . -type f \
		\! -name '*.orig' \! -name config.inc.php  \! -name .htaccess \
		\! -path './site_faq/*' \
		-print | \
		${PAX} -rw -pmp ${DESTDIR}${PREFIX}/${MRBSDIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
