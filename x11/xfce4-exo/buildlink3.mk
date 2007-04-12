# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/04/12 09:50:50 martti Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_EXO_BUILDLINK3_MK:=	${XFCE4_EXO_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-exo
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-exo}
BUILDLINK_PACKAGES+=	xfce4-exo
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-exo

.if ${XFCE4_EXO_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-exo+=	xfce4-exo>=0.3.2
BUILDLINK_PKGSRCDIR.xfce4-exo?=	../../x11/xfce4-exo
.endif	# XFCE4_EXO_BUILDLINK3_MK

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
