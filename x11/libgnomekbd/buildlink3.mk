# $NetBSD: buildlink3.mk,v 1.15 2022/04/18 19:10:15 adam Exp $

BUILDLINK_TREE+=	libgnomekbd

.if !defined(LIBGNOMEKBD_BUILDLINK3_MK)
LIBGNOMEKBD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnomekbd+=	libgnomekbd>=3.6.0
BUILDLINK_ABI_DEPENDS.libgnomekbd+=	libgnomekbd>=3.6.0nb11
BUILDLINK_PKGSRCDIR.libgnomekbd?=	../../x11/libgnomekbd

.include "../../x11/libxklavier/buildlink3.mk"
.endif # LIBGNOMEKBD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnomekbd
