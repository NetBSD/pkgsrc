# $NetBSD: buildlink3.mk,v 1.1 2021/09/08 15:30:54 mef Exp $
#

BUILDLINK_TREE+=	r-tzdb

.if !defined(R_TZDB_BUILDLINK3_MK)
R_TZDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.r-tzdb+=	R-tzdb>=0.1.2
BUILDLINK_PKGSRCDIR.r-tzdb?=	../../time/R-tzdb

.endif # R_TZDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-r-tzdb
