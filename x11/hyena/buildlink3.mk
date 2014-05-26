# $NetBSD: buildlink3.mk,v 1.1 2014/05/26 09:24:56 wiz Exp $

BUILDLINK_TREE+=	hyena

.if !defined(HYENA_BUILDLINK3_MK)
HYENA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hyena+=	hyena>=0.5
BUILDLINK_PKGSRCDIR.hyena?=	../../x11/hyena

.include "../../x11/gtk-sharp/buildlink3.mk"
.endif	# HYENA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hyena
