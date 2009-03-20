# $NetBSD: buildlink3.mk,v 1.16 2009/03/20 19:25:39 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	Xfixes

.if !defined(XFIXES_BUILDLINK3_MK)
XFIXES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Xfixes+=	Xfixes>=2.0.0
BUILDLINK_ABI_DEPENDS.Xfixes+=	Xfixes>=2.0.1nb2
BUILDLINK_PKGSRCDIR.Xfixes?=	../../x11/Xfixes

.include "../../mk/x11.buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.endif # XFIXES_BUILDLINK3_MK

BUILDLINK_TREE+=	-Xfixes
