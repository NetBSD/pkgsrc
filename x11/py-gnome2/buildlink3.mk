# $NetBSD: buildlink3.mk,v 1.8 2004/10/03 00:18:37 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_GNOME2_BUILDLINK3_MK:=	${PY_GNOME2_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pygnome2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npygnome2}
BUILDLINK_PACKAGES+=	pygnome2

.if !empty(PY_GNOME2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pygnome2+=	${PYPKGPREFIX}-gnome2>=2.0.0nb4
BUILDLINK_RECOMMENDED.pygnome2?=	${PYPKGPREFIX}-gnome2>=2.0.2nb1
BUILDLINK_PKGSRCDIR.pygnome2?=	../../x11/py-gnome2
.endif	# PY_GNOME2_BUILDLINK3_MK

.include "../../net/py-ORBit/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/libzvt/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
