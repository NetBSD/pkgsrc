# $NetBSD: buildlink3.mk,v 1.4 2014/05/29 00:39:47 rodent Exp $

BUILDLINK_TREE+=	libxcb

.if !defined(LIBXCB_BUILDLINK3_MK)
LIBXCB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxcb+=	libxcb>=1.6
BUILDLINK_ABI_DEPENDS.libxcb+=	libxcb>=1.6
BUILDLINK_PKGSRCDIR.libxcb?=	../../x11/libxcb

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "OpenBSD"
.include "../../mk/pthread.buildlink3.mk"
.endif
.include "../../x11/xcb-proto/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.endif # LIBXCB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxcb
