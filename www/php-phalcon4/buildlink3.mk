# $NetBSD: buildlink3.mk,v 1.1 2020/11/21 14:54:14 otis Exp $

BUILDLINK_TREE+=	php-phalcon4

.if !defined(PHP_PHALCON4_BUILDLINK3_MK)
PHP_PHALCON4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php-phalcon4+=	php-phalcon4>=1.0.0
BUILDLINK_PKGSRCDIR.php-phalcon4?=	../../www/php-phalcon4
.endif	# PHP_PHALCON4_BUILDLINK3_MK

BUILDLINK_TREE+=	-php-phalcon4
