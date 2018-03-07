# $NetBSD: buildlink3.mk,v 1.5 2018/03/07 11:57:35 wiz Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	libXdamage

.if !defined(LIBXDAMAGE_BUILDLINK3_MK)
LIBXDAMAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXdamage+=	libXdamage>=1.0.3
BUILDLINK_PKGSRCDIR.libXdamage?=	../../x11/libXdamage

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.endif # LIBXDAMAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXdamage
