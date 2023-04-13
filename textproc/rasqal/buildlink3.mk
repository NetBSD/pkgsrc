# $NetBSD: buildlink3.mk,v 1.42 2023/04/13 12:13:08 wiz Exp $

BUILDLINK_TREE+=	rasqal

.if !defined(RASQAL_BUILDLINK3_MK)
RASQAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rasqal+=	rasqal>=0.9.17
BUILDLINK_ABI_DEPENDS.rasqal+=	rasqal>=0.9.33nb27
BUILDLINK_PKGSRCDIR.rasqal?=	../../textproc/rasqal

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../textproc/raptor2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # RASQAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-rasqal
