# $NetBSD: buildlink3.mk,v 1.5 2020/04/21 12:56:17 jaapb Exp $

BUILDLINK_TREE+=	ocsigen-toolkit

.if !defined(OCSIGEN_TOOLKIT_BUILDLINK3_MK)
OCSIGEN_TOOLKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocsigen-toolkit+=	ocsigen-toolkit>=2.0.0
BUILDLINK_ABI_DEPENDS.ocsigen-toolkit+=	ocsigen-toolkit>=2.5.0
BUILDLINK_PKGSRCDIR.ocsigen-toolkit?=	../../www/ocsigen-toolkit

.endif	# OCSIGEN_TOOLKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocsigen-toolkit
