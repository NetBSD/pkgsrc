# $NetBSD: buildlink3.mk,v 1.3 2016/03/12 08:34:33 fhajny Exp $

.include "../../lang/php/phpversion.mk"

BUILDLINK_TREE+=	${PHP_PKG_PREFIX}-propro

.if !defined(${PHP_PKG_PREFIX}_PROPRO_BUILDLINK3_MK)
${PHP_PKG_PREFIX}_PROPRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.${PHP_PKG_PREFIX}-propro+=	${PHP_PKG_PREFIX}-propro>=1.0.0<2
BUILDLINK_PKGSRCDIR.${PHP_PKG_PREFIX}-propro?=		../../www/php-propro
.endif	# ${PHP_PKG_PREFIX}_PROPRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-${PHP_PKG_PREFIX}-propro
