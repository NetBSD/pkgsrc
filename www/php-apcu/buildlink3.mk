# $NetBSD: buildlink3.mk,v 1.2 2017/12/13 11:34:47 jperkin Exp $

BUILDLINK_TREE+=	php-apcu

.if !defined(PHP_APCU_BUILDLINK3_MK)
PHP_APCU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php-apcu+=    ${PHP_PKG_PREFIX}-apcu>=5.0.0
BUILDLINK_PKGSRCDIR.php-apcu?=	../../www/php-apcu
.endif # PHP_APCU_BUILDLINK3_MK

BUILDLINK_TREE+=	-php-apcu
