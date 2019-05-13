# $NetBSD: buildlink3.mk,v 1.4 2019/05/13 11:59:04 jaapb Exp $

BUILDLINK_TREE+=	ocsigen-toolkit

.if !defined(OCSIGEN_TOOLKIT_BUILDLINK3_MK)
OCSIGEN_TOOLKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocsigen-toolkit+=	ocsigen-toolkit>=2.0.0
BUILDLINK_ABI_DEPENDS.ocsigen-toolkit+=	ocsigen-toolkit>=2.1.0
BUILDLINK_PKGSRCDIR.ocsigen-toolkit?=	../../www/ocsigen-toolkit

.endif	# OCSIGEN_TOOLKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocsigen-toolkit
