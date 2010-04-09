# $NetBSD: buildlink3.mk,v 1.5 2010/04/09 08:41:23 tnn Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	libXtst

.if !defined(LIBXTST_BUILDLINK3_MK)
LIBXTST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXtst+=	libXtst>=1.1.0
BUILDLINK_PKGSRCDIR.libXtst?=	../../x11/libXtst

.include "../../x11/recordproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.endif # LIBXTST_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXtst
