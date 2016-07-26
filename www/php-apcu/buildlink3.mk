# $NetBSD: buildlink3.mk,v 1.1 2016/07/26 09:31:04 jdolecek Exp $

BUILDLINK_TREE+=	php-apcu

.if !defined(PHP_APCU_BUILDLINK3_MK)
CGIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php-apcu+=    ${PHP_PKG_PREFIX}-apcu>=5.0.0
BUILDLINK_PKGSRCDIR.php-apcu?=	../../www/php-apcu
.endif # PHP_APCU_BUILDLINK3_MK

BUILDLINK_TREE+=	-php-apcu
