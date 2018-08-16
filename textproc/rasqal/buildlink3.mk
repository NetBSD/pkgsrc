# $NetBSD: buildlink3.mk,v 1.24 2018/08/16 18:54:32 adam Exp $

BUILDLINK_TREE+=	rasqal

.if !defined(RASQAL_BUILDLINK3_MK)
RASQAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rasqal+=	rasqal>=0.9.17
BUILDLINK_ABI_DEPENDS.rasqal+=	rasqal>=0.9.33nb9
BUILDLINK_PKGSRCDIR.rasqal?=	../../textproc/rasqal

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../textproc/raptor2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # RASQAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-rasqal
