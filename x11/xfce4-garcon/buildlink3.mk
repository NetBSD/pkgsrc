# $NetBSD: buildlink3.mk,v 1.7 2020/03/08 16:48:34 wiz Exp $

BUILDLINK_TREE+=	xfce4-garcon

.if !defined(XFCE4_GARCON_BUILDLINK3_MK)
XFCE4_GARCON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-garcon+=	xfce4-garcon>=0.4.0
BUILDLINK_ABI_DEPENDS.xfce4-garcon+=	xfce4-garcon>=0.6.4nb1
BUILDLINK_PKGSRCDIR.xfce4-garcon?=	../../x11/xfce4-garcon

.include "../../x11/libxfce4ui/buildlink3.mk"
.endif	# XFCE4_GARCON_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-garcon
