# $NetBSD: ext.mk,v 1.2 2021/02/14 13:43:39 otis Exp $
#
# NGINX Unit extension package framework, for bundled extensions.
#
# Just include this file, define MODNAME, define PKGREVISION if necessary,
# add dependencies, and add the appropriate --with-configure-arg, then include
# bsd.pkg.mk.
#
# used by www/unit-perl/Makefile
# used by www/unit-php/Makefile
# used by www/unit-python/Makefile
# used by www/unit-ruby/Makefile

.if !defined(UNITEXT_MK)
UNITEXT_MK=	defined

.include "../../www/unit/version.mk"

DISTINFO_FILE=	${.CURDIR}/../../www/unit/distinfo
PATCHDIR=	${.CURDIR}/../../www/unit/patches

.include "../../mk/bsd.prefs.mk"

.if !defined(MODNAME)
PKG_FAIL_REASON+=	"MODNAME should be defined"
.endif

PKGMODNAME?=	${MODNAME}.unit

PLIST_SUBST+=	PKGMODNAME=${MODNAME}.unit
PLIST_SUBST+=	SHLIB_SUFFIX=${SHLIB_SUFFIX}
PLIST_SUBST+=	UNIT_EXTENSION_DIR=${UNIT_EXTENSION_DIR}

PLIST_SRC+=	${.CURDIR}/../../www/unit/PLIST.module

INSTALLATION_DIRS+=	${UNIT_EXTENSION_DIR}

.if ${OBJECT_FMT} == "SOM"
SHLIB_SUFFIX=		sl
.else
SHLIB_SUFFIX=		so
.endif

do-build:
	cd ${WRKSRC} && ${MAKE} ${MODNAME}

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/${PKGMODNAME}.${SHLIB_SUFFIX} \
		${DESTDIR}${PREFIX}/${UNIT_EXTENSION_DIR}

.endif  # UNITEXT_MK

.include "${.CURDIR}/../../www/unit/common.mk"
