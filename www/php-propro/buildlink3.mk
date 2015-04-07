# $NetBSD: buildlink3.mk,v 1.2 2015/04/07 23:59:40 rodent Exp $

.include "../../lang/php/phpversion.mk"

BUILDLINK_TREE+=	${PHP_PKG_PREFIX}-propro

.if !defined(${PHP_PKG_PREFIX}_PROPRO_BUILDLINK3_MK)
${PHP_PKG_PREFIX}_PROPRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.${PHP_PKG_PREFIX}-propro+=	${PHP_PKG_PREFIX}-propro>=1.0.0
BUILDLINK_PKGSRCDIR.${PHP_PKG_PREFIX}-propro?=	../../www/php-propro
.endif	# ${PHP_PKG_PREFIX}_PROPRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-${PHP_PKG_PREFIX}-propro
