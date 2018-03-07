# $NetBSD: buildlink3.mk,v 1.3 2018/03/07 11:57:38 wiz Exp $

BUILDLINK_TREE+=	libxshmfence

.if !defined(LIBXSHMFENCE_BUILDLINK3_MK)
LIBXSHMFENCE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxshmfence+=	libxshmfence>=1.2
BUILDLINK_PKGSRCDIR.libxshmfence?=	../../x11/libxshmfence

.include "../../x11/xorgproto/buildlink3.mk"
.endif	# LIBXSHMFENCE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxshmfence
