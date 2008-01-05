# $NetBSD: buildlink3.mk,v 1.22 2008/01/05 20:45:59 rillig Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PYGTK2_BUILDLINK3_MK:=	${PYGTK2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pygtk2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npygtk2}
BUILDLINK_PACKAGES+=	pygtk2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pygtk2

.if !empty(PYGTK2_BUILDLINK3_MK:M+)
.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.8.4
BUILDLINK_ABI_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.8.5nb1
BUILDLINK_PKGSRCDIR.pygtk2?=	../../x11/py-gtk2
.endif	# PYGTK2_BUILDLINK3_MK

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
