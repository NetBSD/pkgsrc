# $NetBSD: buildlink3.mk,v 1.1 2018/06/05 16:10:43 jaapb Exp $

BUILDLINK_TREE+=	ocsigen-toolkit

.if !defined(OCSIGEN_TOOLKIT_BUILDLINK3_MK)
OCSIGEN_TOOLKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocsigen-toolkit+=	ocsigen-toolkit>=1.1.0
BUILDLINK_PKGSRCDIR.ocsigen-toolkit?=	../../www/ocsigen-toolkit

.endif	# OCSIGEN_TOOLKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocsigen-toolkit
