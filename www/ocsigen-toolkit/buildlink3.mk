# $NetBSD: buildlink3.mk,v 1.3 2019/01/29 13:34:57 jaapb Exp $

BUILDLINK_TREE+=	ocsigen-toolkit

.if !defined(OCSIGEN_TOOLKIT_BUILDLINK3_MK)
OCSIGEN_TOOLKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocsigen-toolkit+=	ocsigen-toolkit>=2.0.0
BUILDLINK_ABI_DEPENDS.ocsigen-toolkit+=	ocsigen-toolkit>=2.0.0
BUILDLINK_PKGSRCDIR.ocsigen-toolkit?=	../../www/ocsigen-toolkit

.endif	# OCSIGEN_TOOLKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocsigen-toolkit
