# $NetBSD: buildlink3.mk,v 1.3 2004/03/05 19:25:41 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGTKHTML_BUILDLINK3_MK:=	${LIBGTKHTML_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgtkhtml
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgtkhtml}
BUILDLINK_PACKAGES+=	libgtkhtml

.if !empty(LIBGTKHTML_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgtkhtml+=		libgtkhtml>=2.4.1nb5
BUILDLINK_PKGSRCDIR.libgtkhtml?=	../../www/libgtkhtml

.include "../../devel/gail/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# LIBGTKHTML_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
