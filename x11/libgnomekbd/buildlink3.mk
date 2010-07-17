# $NetBSD: buildlink3.mk,v 1.5 2010/07/17 12:17:51 wiz Exp $

BUILDLINK_TREE+=	libgnomekbd

.if !defined(LIBGNOMEKBD_BUILDLINK3_MK)
LIBGNOMEKBD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnomekbd+=	libgnomekbd>=2.18.0
BUILDLINK_ABI_DEPENDS.libgnomekbd?=	libgnomekbd>=2.28.2nb2
BUILDLINK_PKGSRCDIR.libgnomekbd?=	../../x11/libgnomekbd

.include "../../x11/libxklavier/buildlink3.mk"
.endif # LIBGNOMEKBD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnomekbd
