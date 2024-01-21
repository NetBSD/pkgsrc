# $NetBSD: buildlink3.mk,v 1.1 2024/01/21 10:46:27 mef Exp $
#

BUILDLINK_TREE+=	r-rcppdate

.if !defined(R_RCPPDATE_BUILDLINK3_MK)
R_RCPPDATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.r-rcppdate+=	R-RcppDate>=0.0.3
BUILDLINK_PKGSRCDIR.r-rcppdate?=	../../time/R-RcppDate

.endif # R_RCPPDATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-r-rcppdate
