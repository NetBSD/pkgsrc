# $NetBSD: buildlink3.mk,v 1.4 2010/01/17 12:02:47 wiz Exp $

BUILDLINK_TREE+=	rasqal

.if !defined(RASQAL_BUILDLINK3_MK)
RASQAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rasqal+=	rasqal>=0.9.16
BUILDLINK_ABI_DEPENDS.rasqal?=	rasqal>=0.9.16nb1
BUILDLINK_PKGSRCDIR.rasqal?=	../../textproc/rasqal

.include "../../textproc/raptor/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # RASQAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-rasqal
