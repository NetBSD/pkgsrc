# $NetBSD: buildlink3.mk,v 1.2 2025/02/08 03:20:14 taca Exp $

BUILDLINK_TREE+=	php-json

.if !defined(PHP_JSON_BUILDLINK3_MK)
PHP_JSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php-json+=	${PHP_PKG_PREFIX}-json>0
BUILDLINK_PKGSRCDIR.php-json?=		../../textproc/php-json
BUILDLINK_DEPMETHOD.php-json?=		build
BUILDLINK_INCDIRS.php-json?=		${PHP_INCDIR}/ext/json
.endif  # PHP_JSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-php-json
