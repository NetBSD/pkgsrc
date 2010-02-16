# $NetBSD: buildlink3.mk,v 1.4 2010/02/16 13:35:40 wiz Exp $

BUILDLINK_TREE+=	libgnomekbd

.if !defined(LIBGNOMEKBD_BUILDLINK3_MK)
LIBGNOMEKBD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnomekbd+=	libgnomekbd>=2.18.0
BUILDLINK_ABI_DEPENDS.libgnomekbd?=	libgnomekbd>=2.28.2nb1
BUILDLINK_PKGSRCDIR.libgnomekbd?=	../../x11/libgnomekbd

.include "../../x11/libxklavier/buildlink3.mk"
.endif # LIBGNOMEKBD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnomekbd
