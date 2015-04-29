# $NetBSD: buildlink3.mk,v 1.2 2015/04/29 16:09:43 tnn Exp $

BUILDLINK_TREE+=	libxshmfence

.if !defined(LIBXSHMFENCE_BUILDLINK3_MK)
LIBXSHMFENCE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxshmfence+=	libxshmfence>=1.2
BUILDLINK_PKGSRCDIR.libxshmfence?=	../../x11/libxshmfence

.include "../../x11/xproto/buildlink3.mk"
.endif	# LIBXSHMFENCE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxshmfence
