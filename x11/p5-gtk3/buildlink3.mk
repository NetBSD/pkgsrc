# $NetBSD: buildlink3.mk,v 1.11 2024/04/07 07:35:26 wiz Exp $

BUILDLINK_TREE+=	p5-gtk3

.if !defined(P5_GTK3_BUILDLINK3_MK)
P5_GTK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-gtk3+=	p5-gtk3>=0.038
BUILDLINK_ABI_DEPENDS.p5-gtk3?=	p5-gtk3>=0.038nb11
BUILDLINK_PKGSRCDIR.p5-gtk3?=	../../x11/p5-gtk3

.include "../../x11/gtk3/buildlink3.mk"
.endif	# P5_GTK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-gtk3
