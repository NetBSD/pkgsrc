# $NetBSD: ext.mk,v 1.1 2021/02/14 11:56:57 otis Exp $
#
# NGINX Unit extension package framework, for bundled extensions.
#
# Just include this file, define MODNAME, define PKGREVISION if necessary,
# add dependencies, and add the appropriate --with-configure-arg, then include
# bsd.pkg.mk.
#
# used by wip/unit-perl/Makefile
# used by wip/unit-php/Makefile
# used by wip/unit-python/Makefile
# used by wip/unit-ruby/Makefile

.if !defined(UNITEXT_MK)
UNITEXT_MK=	defined

.include "../../wip/unit/version.mk"

DISTINFO_FILE=	${.CURDIR}/../../wip/unit/distinfo
PATCHDIR=	${.CURDIR}/../../wip/unit/patches

.include "../../mk/bsd.prefs.mk"

.if !defined(MODNAME)
PKG_FAIL_REASON+=	"MODNAME should be defined"
.endif

PKGMODNAME?=	${MODNAME}.unit

PLIST_SUBST+=	PKGMODNAME=${MODNAME}.unit
PLIST_SUBST+=	SHLIB_SUFFIX=${SHLIB_SUFFIX}
PLIST_SUBST+=	UNIT_EXTENSION_DIR=${UNIT_EXTENSION_DIR}

PLIST_SRC+=	${.CURDIR}/../../wip/unit/PLIST.module

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

.include "${.CURDIR}/../../wip/unit/common.mk"
