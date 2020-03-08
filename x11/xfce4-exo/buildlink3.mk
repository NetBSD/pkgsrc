# $NetBSD: buildlink3.mk,v 1.34 2020/03/08 16:48:34 wiz Exp $

BUILDLINK_TREE+=	xfce4-exo

.if !defined(XFCE4_EXO_BUILDLINK3_MK)
XFCE4_EXO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-exo+=	xfce4-exo>=0.10.4
BUILDLINK_ABI_DEPENDS.xfce4-exo+=	xfce4-exo>=0.12.11nb1
BUILDLINK_PKGSRCDIR.xfce4-exo?=		../../x11/xfce4-exo

.include "../../x11/libxfce4ui/buildlink3.mk"
.endif	# XFCE4_EXO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-exo
