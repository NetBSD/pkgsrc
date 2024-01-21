# $NetBSD: buildlink3.mk,v 1.1 2024/01/21 10:46:27 mef Exp $
#

BUILDLINK_TREE+=	r-rcppcctz

.if !defined(R_RCPPCCTZ_BUILDLINK3_MK)
R_RCPPCCTZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.r-rcppcctz+=	R-RcppCCTZ>=0.2.12
BUILDLINK_PKGSRCDIR.r-rcppcctz?=	../../time/R-RcppCCTZ

.endif # R_RCPPCCTZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-r-rcppcctz
