# $NetBSD: buildlink3.mk,v 1.4 2017/02/12 06:24:55 ryoon Exp $
#

BUILDLINK_TREE+=	libmatekbd

.if !defined(LIBMATEKBD_BUILDLINK3_MK)
LIBMATEKBD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmatekbd+=	libmatekbd>=1.8.0
BUILDLINK_ABI_DEPENDS.libmatekbd?=	libmatekbd>=1.14.1nb3
BUILDLINK_PKGSRCDIR.libmatekbd?=	../../x11/libmatekbd

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# LIBMATEKBD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmatekbd
