# $NetBSD: pear.mk,v 1.4 2004/04/02 21:54:49 jdolecek Exp $
#
# This Makefile fragment is intended to be included by packages that build
# and install pear packages.
#
# If you don't know what pear is, you can visit: http://pear.php.net/
#
# PEAR_CMD	this is the actual script to execute to install the
#		package.
#
# PEAR_LIB	directory under ${PREFIX} where Pear modules are installed
#

.if !defined(_PEAR_PACKAGE_MK)
_PEAR_PACKAGE_MK=       # defined

USE_BUILDLINK2=			YES
BUILDLINK_DEPMETHOD.php4=	full

.include "../../www/php4/buildlink2.mk"

.include "../../mk/bsd.prefs.mk"

EXTRACT_SUFX=	.tgz

PKGNAME=	pear-${DISTNAME}
CATEGORIES+=	www

MASTER_SITE_PEAR_PACKAGE+= \
	http://pear.php.net/get/
MASTER_SITES+=	${MASTER_SITE_PEAR_PACKAGE}

PEAR_CMD=	${PREFIX}/bin/pear
PEAR_LIB=	lib/php

_PEAR_PKG=	${DISTNAME:C/-.*//}

# Changed to not use :tl modifier since that's currently NetBSD 1.6-only
_PEAR_PKG_LC!=	${ECHO} ${_PEAR_PKG} | ${TR} '[A-Z]' '[a-z]'

# Dynamic PLIST
# The package.xml 'parsing' is a bit crude, but enough for now. Eventually
# should write a small PHP script for this, using real XML parser.
PEAR_GENERATE_PLIST=	\
	${ECHO} "@comment The following lines are automatically generated"; \
	${ECHO} "${PEAR_LIB}/.registry/${_PEAR_PKG_LC}.reg";	\
	${FGREP} '<file role="php"' ${WRKDIR}/package.xml | ${SED} -e 's,.*<file role="php",<,' -e 's,<.*baseinstalldir="\([^"]*\)",\1/<,' -e 's,<.* name=",,' -e 's,".*,,' -e "s,^/*,${PEAR_LIB}/,"; \
	${FGREP} '<file role="php"' ${WRKDIR}/package.xml | ${SED} -e 's,.*<file role="php",<,' -e 's,<.*baseinstalldir="\([^"]*\)",\1/<,' -e 's,<.* name=",,' -e 's,".*,,' -e 's,//*,/,g' -e 's,/[^/]*$$,,' | ${FGREP} '/' | ${SORT} -ru | ${SED} -e "s,^,@dirrm ${PEAR_LIB},"; \
	${FGREP} '<file role="doc"' ${WRKDIR}/package.xml | ${SED} -e 's,.*<file role="doc",<,' -e 's,<.*baseinstalldir="\([^"]*\)",\1/<,' -e 's,<.* name=",,' -e 's,".*,,' -e "s,^/*,${PEAR_LIB}/doc/${_PEAR_PKG}/,"; \
	${FGREP} '<file role="doc"' ${WRKDIR}/package.xml | ${SED} -e 's,.*<file role="doc",<,' -e 's,<.*baseinstalldir="\([^"]*\)",\1/<,' -e 's,<.* name=",,' -e 's,".*,,' -e 's,//*,/,g' -e 's,/[^/]*$$,,' | ${FGREP} '/' | ${SORT} -ru | ${SED} -e "s,^,@dirrm ${PEAR_LIB}/doc/${_PEAR_PKG},"; \
	${FGREP} -q '<file role="doc"' ${WRKDIR}/package.xml && echo "@dirrm ${PEAR_LIB}/doc/${_PEAR_PKG}"; \
	${FGREP} '<file role="test"' ${WRKDIR}/package.xml | ${SED} -e 's,.*<file role="test",<,' -e 's,<.*baseinstalldir="\([^"]*\)",\1/<,' -e 's,<.* name=",,' -e 's,".*,,' -e "s,^/*,${PEAR_LIB}/test/${_PEAR_PKG}/,"; \
	${FGREP} '<file role="test"' ${WRKDIR}/package.xml | ${SED} -e 's,.*<file role="test",<,' -e 's,<.*baseinstalldir="\([^"]*\)",\1/<,' -e 's,<.* name=",,' -e 's,".*,,' -e 's,//*,/,g' -e 's,/[^/]*$$,,' | ${FGREP} '/' | ${SORT} -ru | ${SED} -e "s,^,@dirrm ${PEAR_LIB}/test/${_PEAR_PKG},"; \
	${FGREP} -q '<file role="test"' ${WRKDIR}/package.xml && echo "@dirrm ${PEAR_LIB}/test/${_PEAR_PKG}";
GENERATE_PLIST+=	${PEAR_GENERATE_PLIST}

NO_BUILD=	# defined

post-extract:
	@cd ${WRKSRC} && ${LN} -s ${WRKDIR}/package.xml
	cd ${WRKSRC} && ${PEAR_CMD} package-validate package.xml

do-install:
	cd ${WRKSRC} && ${PEAR_CMD} install package.xml

.endif  # _PEAR_PACKAGE_MK
