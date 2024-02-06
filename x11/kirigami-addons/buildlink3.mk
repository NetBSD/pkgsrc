# $NetBSD: buildlink3.mk,v 1.1 2024/02/06 03:28:25 markd Exp $

BUILDLINK_TREE+=	kirigami-addons

.if !defined(KIRIGAMI_ADDONS_BUILDLINK3_MK)
KIRIGAMI_ADDONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kirigami-addons+=	kirigami-addons>=0.11.0
BUILDLINK_PKGSRCDIR.kirigami-addons?=	../../x11/kirigami-addons

.endif	# KIRIGAMI_ADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kirigami-addons
