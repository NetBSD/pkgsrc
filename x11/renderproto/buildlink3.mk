# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:25:50 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	renderproto

.if !defined(RENDERPROTO_BUILDLINK3_MK)
RENDERPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.renderproto+=	renderproto>=0.9.3nb1
BUILDLINK_PKGSRCDIR.renderproto?=	../../x11/renderproto
BUILDLINK_DEPMETHOD.renderproto?=	build
.endif # RENDERPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-renderproto
