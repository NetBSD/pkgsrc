# $NetBSD: pear.mk,v 1.1 2003/12/17 19:02:07 jdolecek Exp $
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

EXTRACT_SUFX=	.tgz

PKGNAME=	pear-${DISTNAME}
CATEGORIES+=	www

MASTER_SITE_PEAR_PACKAGE+= \
	http://pear.php.net/get/
MASTER_SITES+=	${MASTER_SITE_PEAR_PACKAGE}

PEAR_CMD=	${PREFIX}/bin/pear
PEAR_LIB=	lib/php

_PEAR_PKG=	${DISTNAME:C/-.*//:tl}

# Dynamic PLIST
# The package.xml 'parsing' is a bit crude, but enough for now. Eventually
# should write a small PHP script for this, using real XML parser.
PEAR_GENERATE_PLIST=	\
	${ECHO} "@comment The following lines are automatically generated"; \
	${ECHO} "${PEAR_LIB}/.registry/${_PEAR_PKG}.reg";	\
	${FGREP} '<file role="php"' ${WRKDIR}/package.xml | ${SED} -e 's,.*<file role="php",<,' -e 's,<.*baseinstalldir="\([^"]*\)",\1/<,' -e 's,<.* name=",,' -e 's,".*,,' -e "s,^/*,${PEAR_LIB}/,"; \
	${FGREP} '<file role="php"' ${WRKDIR}/package.xml | ${SED} -e 's,.*<file role="php",<,' -e 's,<.*baseinstalldir="\([^"]*\)",\1/<,' -e 's,<.* name=",,' -e 's,".*,,' -e 's,//*,/,g' -e 's,/[^/]*$$,,' | ${FGREP} '/' | ${SORT} -ru | ${SED} -e "s,^,@dirrm ${PEAR_LIB}/,";
GENERATE_PLIST+=	${PEAR_GENERATE_PLIST}

NO_BUILD=	# defined

post-extract:
	@cd ${WRKSRC} && ${LN} -s ${WRKDIR}/package.xml
	cd ${WRKSRC} && ${PEAR_CMD} package-validate package.xml

do-install:
	cd ${WRKSRC} && ${PEAR_CMD} install package.xml

.endif  # _PEAR_PACKAGE_MK
