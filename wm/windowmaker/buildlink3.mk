# $NetBSD: buildlink3.mk,v 1.1 2004/02/25 19:02:39 minskim Exp $
#
# This Makefile fragment is included by packages that use windowmaker.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
WINDOWMAKER_BUILDLINK3_MK:=	${WINDOWMAKER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	windowmaker
.endif

.if !empty(WINDOWMAKER_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			windowmaker
BUILDLINK_DEPENDS.windowmaker+=		windowmaker>=0.80.2nb3
BUILDLINK_PKGSRCDIR.windowmaker?=		../../wm/windowmaker

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hermes/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"

.endif # WINDOWMAKER_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
