# $NetBSD: buildlink3.mk,v 1.9 2021/12/08 16:02:55 adam Exp $
#

BUILDLINK_TREE+=	libmatekbd

.if !defined(LIBMATEKBD_BUILDLINK3_MK)
LIBMATEKBD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmatekbd+=	libmatekbd>=1.8.0
BUILDLINK_ABI_DEPENDS.libmatekbd+=	libmatekbd>=1.24.1
BUILDLINK_PKGSRCDIR.libmatekbd?=	../../x11/libmatekbd

.include "../../x11/libxklavier/buildlink3.mk"
.endif	# LIBMATEKBD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmatekbd
