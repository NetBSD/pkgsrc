# $NetBSD: buildlink.mk,v 1.2 2001/12/31 23:54:25 jlam Exp $
#
# This Makefile fragment is included by packages that use php4.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.php4 to the dependency pattern
#     for the version of php4 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(PHP4_BUILDLINK_MK)
PHP4_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

# This adds a build-dependency as php4 has no libraries.
BUILDLINK_DEPENDS.php4?=	php>=4.1.0
BUILD_DEPENDS+=			${BUILDLINK_DEPENDS.php4}:../../www/php4

EVAL_PREFIX+=			BUILDLINK_PREFIX.php4=php
BUILDLINK_PREFIX.php4_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.php4=		include/php/*/*/*.h
BUILDLINK_FILES.php4+=		include/php/*/*.h
BUILDLINK_FILES.php4+=		include/php/*.h

BUILDLINK_TARGETS.php4=		php4-buildlink
BUILDLINK_TARGETS.php4+=	php4-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.php4}

BUILDLINK_CONFIG.php4=		${BUILDLINK_PREFIX.php4}/bin/php-config
BUILDLINK_CONFIG_WRAPPER.php4=	${BUILDLINK_DIR}/bin/php-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.php4}|${BUILDLINK_CONFIG.php4}|g"

.if defined(USE_CONFIG_WRAPPER)
PHP_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.php4}
CONFIGURE_ENV+=		PHP_CONFIG="${PHP_CONFIG}"
MAKE_ENV+=		PHP_CONFIG="${PHP_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.php4}
php4-buildlink: _BUILDLINK_USE
php4-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# PHP4_BUILDLINK_MK
