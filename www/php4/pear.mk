# $NetBSD: pear.mk,v 1.7 2004/04/24 23:03:25 xtraeme Exp $
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

USE_BUILDLINK3=			YES
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

# whether @dirrm for baseinstalldir should be included in PLIST
PEAR_DIRRM_BASEDIR?=	# empty

# Dynamic PLIST, generated via a helper PHP script, which parses the package
# XML config file.
PEAR_GENERATE_PLIST=	\
	${ECHO} "@comment The following lines are automatically generated"; \
	PEAR_LIB="${PEAR_LIB}" WRKSRC="${WRKSRC}" \
	PEAR_DIRRM_BASEDIR="${PEAR_DIRRM_BASEDIR}" \
	${PREFIX}/bin/php ${PKGDIR}/../../www/php4/pear_plist.php;
GENERATE_PLIST+=	${PEAR_GENERATE_PLIST}

NO_BUILD=	# defined

post-extract:
	@cd ${WRKSRC} && ${LN} -s ${WRKDIR}/package.xml

do-install:
	cd ${WRKSRC} && ${PEAR_CMD} install package.xml

.endif  # _PEAR_PACKAGE_MK
