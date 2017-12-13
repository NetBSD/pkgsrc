# $NetBSD: buildlink3.mk,v 1.1 2017/12/13 11:42:41 jperkin Exp $

BUILDLINK_TREE+=	php-json

.if !defined(PHP_JSON_BUILDLINK3_MK)
PHP_JSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php-json+=	${PHP_PKG_PREFIX}-json>0
BUILDLINK_PKGSRCDIR.php-json?=		../../textproc/php-json
BUILDLINK_DEPMETHOD.php-json?=		build
BUILDLINK_INCDIRS.php-json?=		include/php/ext/json
.endif  # PHP_JSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-php-json
