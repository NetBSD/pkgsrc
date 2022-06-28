# $NetBSD: buildlink3.mk,v 1.5 2022/06/28 11:37:50 wiz Exp $

BUILDLINK_TREE+=	swish-e

.if !defined(SWISH_E_BUILDLINK3_MK)
SWISH_E_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swish-e+=	swish-e>=2.4.5nb1
BUILDLINK_ABI_DEPENDS.swish-e+=	swish-e>=2.4.5nb19
BUILDLINK_PKGSRCDIR.swish-e?=	../../www/swish-e

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # SWISH_E_BUILDLINK3_MK

BUILDLINK_TREE+=	-swish-e
